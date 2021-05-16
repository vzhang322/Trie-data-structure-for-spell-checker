
#ifndef TRIE_SPELLCHECKER_TRIELEAFNODE_H
#define TRIE_SPELLCHECKER_TRIELEAFNODE_H

#include <iostream>
#include <cstring>
using namespace std;

class TrieLeafNode {
public:
    TrieLeafNode();

    TrieLeafNode(char *);

private:
    bool leaf;
    char *word;

    friend class Trie;
};


#endif //TRIE_SPELLCHECKER_TRIELEAFNODE_H
