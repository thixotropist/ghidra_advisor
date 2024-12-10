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
}

