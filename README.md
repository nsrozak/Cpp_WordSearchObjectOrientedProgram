# Word Search and Count

## Introduction

This project uses C++, doubly linked lists, and object-oriented design. The program reads the contents of a list of files and stores the words and files in alphabetical order with doubly linked lists. After reading all files, the program outputs the number of unique words found in these files. Then, it asks the user to enter a word. The number of files that this word appears in and the number of time that this word appears in each file gets outputted by the program. 

## File Descriptions

***test_files:*** Folder containing documents used to test the program.

***main.cpp:*** main program that performs operations and interacts with the user.

***bag.h:*** Specification file for the `bag` class. Also contains implementations of member and nonmember functions because `bag` is a template class.

***dnode.h:*** Specification file for the `dnode` class. Also contains implementations of member and nonmember functions because `dnode` is a template class.

***word.h:*** Specification file for the `Word` class.

***word.cpp:*** Implementation file for the `Word` class.

***file.h:*** Specification file for the `file` class.

***file.h:*** Implementation file for the `file` class.

## Running Time

- Searching for a word: O(n)
- Inserting a word: O(1)
  - However, searching must occur before a word can be inserted

## Instructions for Running Code

Compile the program by typing `g++ main.cpp word.cpp file.cpp -o main` into the terminal. Type `./main test_files` into the terminal to run the code. When prompted by the program, type a word into the terminal. 

## Limitations

Files must only contain letters; the program does not remove grammatical and numerical elements from the words.

## Improvements

The running time will decrease to O(logn) if the program uses balanced binary search trees instead of linked lists for storing the data.
