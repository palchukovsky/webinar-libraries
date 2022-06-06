# The practice part of a webinar about libraries

## Build

```bash
cd static_lib/lib
mkdir build
cd build
cmake ..
cmake --build .
```

```bash
cd static_lib
mkdir build
cd build
cmake ..
cmake --build .
```

## Practice

### Windows, Visual C++

Using Developer Command Prompt for VS list symbols by tool [DUMPBIN](https://docs.microsoft.com/en-us/previous-versions/visualstudio/visual-studio-2013/756as972(v=vs.120)) inside "static_lib/build/sumLib.dir/Debug":

```bash
dumpbin /SYMBOLS sum.obj
```

Try to investigate part of the output
```bash
009 00000000 SECT3  notype ()    External     | ?sum@library@@YAHHH@Z (int __cdecl library::sum(int,int))
00A 00000020 SECT3  notype ()    External     | ?sum@library@@YANNN@Z (double __cdecl library::sum(double,double))
```
with the article [Visual C++ name mangling](https://en.m.wikiversity.org/wiki/Visual_C%2B%2B_name_mangling): substrings ?sum@library@@YAHHH@Z and ?sum@library@@YANNN@Z.

For example: "HHH" is "int, int and int" (as "it returns int, and accepts 2 int-arguments").

### Linux, GCC

List symbols by tool [nm (name mangling)](https://en.wikipedia.org/wiki/Nm_(Unix)) inside "static_lib/build":

```bash
nm libsumLib.a
```

Try to investigate part of the output
```bash
0000000000000020 T __ZN7library3sumEdd
0000000000000000 T __ZN7library3sumEii
```
with the article [External Names (a.k.a. Mangling)](https://itanium-cxx-abi.github.io/cxx-abi/abi.html#mangling): substrings "__ZN7library3sumEdd" and "__ZN7library3sumEii".

For example: "dd" is "double and double" (as "it accepts 2 double-arguments").

There is no info about the return type. The return type of the function is not part of the name mangling. Return types are enforced by the compiler directly based on type rules.