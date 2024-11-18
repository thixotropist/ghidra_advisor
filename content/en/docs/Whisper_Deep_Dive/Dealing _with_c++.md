---
title: Dealing with C++
linkTitle: Dealing with C++
weight: 40
---

GCC 15 uses RISCV vector instruction sequences in many initialization sequences - even when there is no need for a loop.
If we want to understand that code, we need a decent understanding of what is getting initialized.  One way to
move forward is with a small program that uses some of the same libstdc++ classes, to help us understand their memory layout
and especially the fields that may need initialization.

The first iteration of this is a toy program using `std::string`, `std::vector`, `std::pair`, `std::map`, and `std::ofstream` library code.
we generally want to know object sizes, pointers, and key internal fields.  If something like `ofstream` is constructed on the stack,
we can probably ignore any interior objects initialized within it.

```cpp
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <cstdint>

void dumpHex(const uint64_t* p, int numwords)  {
    std::cout << "\tRaw: ";
    for (int i = 0; i < numwords; i++) {
        std::cout << "0x" << std::hex << p[i];
        if (i < numwords) {
        std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

void showString(const std::string* s, const char* label) {
    std::cout << "std::string " << label << " = " << *s << std::endl;
    std::cout << "\tRaw Size = 0x" << std::hex << sizeof(*s) << std::endl;
    std::cout << "\tLength = 0x" << std::hex << s->length() << std::endl;
    dumpHex((const uint64_t*)s, 4);
}

void showVector(const std::vector<std::string>* v, const char* label) {
    std::cout << "std::vector<std::string> " << label << ":" << std::endl;
    std::cout << "\tRaw Size = 0x" << std::hex << sizeof(*v) << std::endl;
    std::cout << "\tInternal Size = " << v->size() << std::endl;
    dumpHex((const uint64_t*)v, 3);
}

void showPair(const std::pair<std::string,std::string>* p, const char* label) {
    std::cout << "std::pair<std::string,std::string> " << label << ":" << std::endl;
    std::cout << "\tRaw Size = 0x" << std::hex << sizeof(*p) << std::endl;
    dumpHex((const uint64_t*)p, 8);
}

void showMap(const std::map<std::string,std::string>* token_map, const char* label) {
    std::cout << "std::map<std::string,std::string> " << label << ":" << std::endl;
    std::cout << "\tRaw Size = 0x" << std::hex << sizeof(*token_map) << std::endl;
    std::cout << "\tInternal Size = " << token_map->size() << std::endl;
    dumpHex((const uint64_t*)token_map, 6);
}

void showOfstream(const std::ofstream* fout, const char* label) {
    std::cout << "std::ofstream " << label << ":" << std::endl;
    std::cout << "\tRaw Size = 0x" << std::hex << sizeof(*fout) << std::endl;
    dumpHex((const uint64_t*)fout, 8);
}

int main() {
    std::cout << "Initializing\n";
    std::ofstream fout("/tmp/scratch");
    showOfstream(&fout, "initialized ofstream");
    std::string xs("short string");
    showString(&xs, "short string");
    std::string x("This is a sample long string");
    showString(&x, "long string");
    std::vector<std::string> vx;
    showVector(&vx, "empty vector");
    vx.push_back(x);
    showVector(&vx, "singleton vector");

    fout << "something to fill the file" << std::endl;

    std::pair<std::string,std::string> map_element("key", "value");
    showPair(&map_element, "map_element");
    std::map<std::string,std::string> token_map;
    showMap(&token_map, "token_map, empty");
    token_map.insert(map_element);
    showMap(&token_map, "token_map, one insertion");
    fout.close();
    showOfstream(&fout, "closed ofstream");
```

Build with:

```console
$ bazel build --platforms=//platforms:riscv_gcc --copt='-march=rv64gcv' other_src:stdlibc++_exploration
```

Run this under qemu emulation :

```console
$ qemu-riscv64-static -L /opt/riscvx/sysroot -E LD_LIBRARY_PATH=/opt/riscvx/sysroot/riscv64-unknown-linux-gnu/lib/ bazel-bin/other_src/stdlibc++_exploration
Initializing
std::ofstream initialized ofstream:
	Raw Size = 0x200
	Raw: 0x7fbff0608d70, 0x7fbff0608bb8, 0x288a0, 0x288a0, 0x288a0, 0x0, 0x0, 0x0, 
std::string short string = short string
	Raw Size = 0x20
	Length = 0xc
	Raw: 0x7fbfe3ffe820, 0xc, 0x74732074726f6873, 0x7f00676e6972, 
std::string long string = This is a sample long string
	Raw Size = 0x20
	Length = 0x1c
	Raw: 0x2a8b0, 0x1c, 0x1c, 0x7fbfe3ffe8f0, 
std::vector<std::string> empty vector:
	Raw Size = 0x18
	Internal Size = 0
	Raw: 0x0, 0x0, 0x0, 
std::vector<std::string> singleton vector:
	Raw Size = 0x18
	Internal Size = 1
	Raw: 0x2a8e0, 0x2a900, 0x2a900, 
std::pair<std::string,std::string> map_element:
	Raw Size = 0x40
	Raw: 0x7fbfe3ffe890, 0x3, 0x79656b, 0x7fbff0411528, 0x7fbfe3ffe8b0, 0x5, 0x65756c6176, 0x7fbff14d751e, 
std::map<std::string,std::string> token_map, empty:
	Raw Size = 0x30
	Internal Size = 0
	Raw: 0x1, 0x7fbf00000000, 0x0, 0x7fbfe3ffe858, 0x7fbfe3ffe858, 0x0, 
std::map<std::string,std::string> token_map, one insertion:
	Raw Size = 0x30
	Internal Size = 1
	Raw: 0x1, 0x7fbf00000000, 0x2a940, 0x2a940, 0x2a940, 0x1, 
std::ofstream closed ofstream:
	Raw Size = 0x200
	Raw: 0x7fbff0608d70, 0x7fbff0608bb8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
```

Now we can load `bazel-bin/other_src/stdlibc++_exploration` into Ghidra and get some insight into how these standard library classes are
initialized.

`std::string` has a length of 0x20 bytes and a structure similar to:

```c
struct string { /* stdlib basic string */
    char *cstr;
    uint64_t length;
    char data[16];
};
```

If the string is 15 bytes or less, it is stored directly in `data`.  Otherwise new memory is allocated and data holds information needed to manage that allocation.

`std::vector<T>` has a length of 0x18 bytes, regardless of the component type `T`.

```c
struct vector {
    T *start;        // points to the first element in the vector
    T *end;          // points just past the last element in the vector
    T *alloc_end;    // points just past the last empty element allocated for the vector.
};
```

`std::pair<T1,T2>` is simply a concatenation of elements of type `T1` and `T2`, so a pair of strings is 0x40 bytes and a pair of string pointers is 0x10 bytes.

`std::ofstream` is a large object of 0x200 bytes.  We'll ignore its internal structure for now - and especially any `whisper.cpp` code initializing elements of that structure.

Ghidra examination of `stdlibc++_exploration` provides some insight and more than a few red herrings.

## stdlibc++_exploration

### std::vector

The three 64 bit pointers that make up a `std::vector<std::string>` are initialized inline to zero with a stanza of five vector instructions - even though that does not look optimal.

```c
  vsetivli_e8mf2tama(8);
  vmv_v_i(in_v1,0);
  vse8_v(in_v1,&vx.end);
  vse8_v(in_v1,&vx.alloc_end);
  vse8_v(in_v1,&vx);
  showVector(&vx,"empty vector");
  ```

`vx.push_back(x)` makes a copy of the string x and allocates space for both the vector element and the string copy with `operator.new`.

std::vectors are most easily recognized by their destructors:

```c
std::vector<>::~vector((vector<> *)&vx);
```

### std::ofstream

File structures like std::ofstream are easy to recognize through their constructors and destructors.  They can be confusing though, since they are likely to be reused if
multiple files are opened and closed in the same function.