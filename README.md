# Trie-data-structure for spell checker
Version: 
```
      Microsoft Windows [Version 10.0.18363.1199]
      macOS Big Sur [Version 11.3.1] 
```
         

G++ Version: 
```
g++ (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
Apple clang version 12.0.0(clang-1200.0.32.2) 
```

Author: Vince Zhang(ID:15246626) and Shiyun Tao(ID:19023494)
Supervisor: Dr. Andre L Barczak

This is a program to implement that read a text file(.txt) and check any word spelling mistakes. The output will be showed total count of words misspelled , total words in text file , and how long has been loaded, check,size,unload and total in command line and terminial in windows 10 os and macos. Also, it compares each words from dictionary file to stored it in TRIE.

# Version Contorl
The first version of the header file uses Trie.h and TrieLeafNode.h, but we found that it does not work in Windows 10, so we further modified these two files, and the modified names are `Trie1.h` and `TrieLeafNode1.h`. Compile in macOS, just delete `Trie1.h` and `TrieLeafNode1.h`. Before you compile in Windows 10, please delete `Trie.h` and `TrieLeafNode1.h`.

# Compile and run spell check in macos
<b> `Debug in terminal:`</b>

<b> `cd folder` </b>

<b> `type make` </b>

<b> `Usage:./speller [dictionary] text` </b>

<b> `Clean: rm speller`</b>


# Compile and run spell check in Windows10
<b> `Debug in Command line:`</b>

<b> `cd folder` </b>

<b> `type make` </b>

<b> `Usage: speller [dictionary] text` </b>

<b> `Clean: del speller.exe` </b>
