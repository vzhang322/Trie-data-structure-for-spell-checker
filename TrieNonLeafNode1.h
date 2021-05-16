#ifndef TRIE_SPELLCHECKER_TRIENONLEAFNODE_H
#define TRIE_SPELLCHECKER_TRIENONLEAFNODE_H

#include <iostream>


using namespace std;

class TrieNonLeafNode {
public:
    TrieNonLeafNode();
    TrieNonLeafNode(char);

private:
    bool leaf, endOfWord;
    char *letters;
    TrieNonLeafNode **ptrs;

    friend class Trie;
};


#endif //TRIE_SPELLCHECKER_TRIENONLEAFNODE_H
