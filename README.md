Description
Speller is a program that checks the spelling of words in a text file against a dictionary. It loads the dictionary into memory using a hash table and then compares each word in the given text file to identify any misspellings.

This project is part of Harvard’s CS50 course and introduces concepts like hashing, file I/O, and memory management in C.

How It Works
The program loads a dictionary file into memory using a hash table.
It reads a text file word by word and checks each word against the dictionary.
If a word is not found in the dictionary, it is reported as a misspelling.
At the end, the program unloads the dictionary to free up memory.
Files
speller.c – The main program that ties everything together.
dictionary.c – Implements functions to load, check, and unload words in the hash table.
dictionary.h – Contains function prototypes and constants.
Makefile – Automates compilation.
texts/ – Sample text files to test the program.
dictionaries/ – Sample dictionary files.
Compilation
To compile the program, run:
make speller
Copy
Edit
make speller

Usage
To check a text file against a dictionary:
./speller [dictionary] textfile.txt

dictionary (optional): The dictionary file to use (defaults to dictionaries/large).
textfile.txt: The text file to check for spelling errors.
Example:
./speller texts/mobydick.txt

Features
✅ Efficient word lookup using a hash table
✅ Handles large dictionaries and text files
✅ Ignores case and punctuation
✅ Reports misspelled words

Notes
The default dictionary contains 143,091 words.
The load function must load all words into memory efficiently.
The unload function should free all allocated memory properly.
