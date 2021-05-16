# Trie-data-structure for spell checker
Version: Apple clang version 12.0.0(clang-1200.0.32.2)
Author: Vince Zhang(ID:15246626) and Shiyun Tao(ID:19023494)
Supervisor: Dr. Andre L Barczak

This is a program to implement that read a text file(.txt) and check any word spelling mistake in text file. The output will be showed total count of incorrect word text file loaded time in command line and terminial in windows 10 os and macos. Also, it compares each words from dictionary file to stored it in TRIE.

# Version Contorl
The first version of the header file uses Trie.h and TrieLeafNode.h, but we found that it does not work in Windows 10, so we further modified these two files, and the modified names are Trie1.h and TrieLeafNode1.h.

# How to setup debug environment in macos
<b>--Debug in terminal:</b>

<b>--cd folder </b>

<b>--type make </b>

<b>--Usage:./speller [dictionary] text </b>

<b>--Clean: rm speller</b>


# How to setup debug environment in Windows10
<b>--Debug in terminal:</b>

<b>--cd folder </b>

<b>--type make </b>

<b>--Usage:./speller [dictionary] text </b>

<b>--Clean: rm speller</b>
