
# Ransom Note

Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
* You may assume that both strings contain only lowercase letters.

Example:
```
can_construct("a", "b") -> false
can_construct("aa", "ab") -> false
can_construct("aa", "aab") -> true
```

[Leetcode page](https://leetcode.com/problems/ransom-note/description/)

### How to compile
```bash
make run
```

### How to run test
```bash
make test
```

### How to debug the program
```bash
gcc -g name_of_file.c -o name_of_file
gdb name_of_file
```

#### How to start the Program
* break main
* run - Execute the program
* next - Next Line
* print &i - Print the address of the variable
* print sizeof(int) - Print sizeof the int type
* x/4xb &i - Get the raw bytes of i. I want to examinate 4 values formatted as hex numerals. byte by byte
* ptype i - Tell me the type of c expression
* x/12xb &a - a is an array

### Linking stuff and generating the program

If you have modules you have to compile one by one
```bash
gcc -c module1.c # This command generates module1.o
gcc -c program-that-depends-of-module1.c
gcc -o program.out module1.o program-that-depends-of-module1.o
./program.out
```
