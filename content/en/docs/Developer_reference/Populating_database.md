---
title: Populating the Database
linkTitle: Database generation
weight: 20
---

The training set consists of matched C source code and RISCV-64 disassembly code.
The C source is processed through the C preprocessor `cpp` and `indent`.  That code is then
compiled with GCC and at least two different machine architectures, then saved under `./data`.

## Populating the Training Set Database

The initial C source code is selected from the GCC riscv autovector testsuite.  We can add
custom examples of code to fill gaps or represent code patterns we might find in a Ghidra binary
under review.  Autovectored loops over structure arrays can be especially confusing to interpret,
so we will likely want extra samples of that type.

The C sources for these two test suites appear in `./gcc_riscv_testsuite` and `./custom_testsuite`.
The script `generator.py` processes these into cpp output (`*.i`), compiled libraries (`*.so`), and objdump
assembly listings (`*_objdump`) for each requested machine architecture.

For example, `gcc_riscv_testsuite/rvv/autovec/reduc/reduc-1.c` is processed by `generator.py` into:

* `data/gcc_riscv_testsuite/rvv/autovec/reduc/reduc-1_rv64gc.i`
* `data/gcc_riscv_testsuite/rvv/autovec/reduc/reduc-1_rv64gc.so`
* `data/gcc_riscv_testsuite/rvv/autovec/reduc/reduc-1_rv64gc_objdump`
* `data/gcc_riscv_testsuite/rvv/autovec/reduc/reduc-1_rv64gcv.i`
* `data/gcc_riscv_testsuite/rvv/autovec/reduc/reduc-1_rv64gcv.so`
* `data/gcc_riscv_testsuite/rvv/autovec/reduc/reduc-1_rv64gcv_objdump`

The `ingest.py` script reads everything under `./data` to populate the `sample` table in the Sqlite3 database

```sql
.schema sample
CREATE TABLE sample(id INTEGER PRIMARY KEY AUTOINCREMENT, namespace TEXT, arch TEXT, name TEXT, source TEXT, assembly TEXT);
```

Next we need to generate signatures from this table with the `sample_analytics.py` script.  At present, signatures are simple
strings.  We have three signature types at the moment.

```sql
.schema signatures
CREATE TABLE signatures(id INTEGER PRIMARY KEY AUTOINCREMENT, sample_id INTEGER, signature_type TEXT, signature_value TEXT);
select distinct signature_type from signatures;
Traits
Opcodes, sorted
Opcodes, ordered
```

* The `Traits` signature holds simple facts from the disassembly code, such as `hasLoop` if at least one backwards branch exists.
* The `Opcodes, ordered` signature is a simple list of vector and branch opcodes, concatenated in the same order as
  they are found in the disassembly.
* The `Opcodes, sorted` signature is similar to `Opcodes, ordered`, but sorted into alphanumeric order.  This may be useful if
  the compiler reorders instructions.

## Querying the Database in Advisor

{{< figure src="Workflow_advisor.svg" width="80%">}}

Users can select assembly code from Ghidra's listing window, then run analysis cells in `Advisor.ipynb` to generate reports
on the types of C code that may match the listing.  Users will likely want to iterate complex selections by adding custom
examples and repeating the match, to see if they can reproduce the C code that might have generated the vectorized assembly.
