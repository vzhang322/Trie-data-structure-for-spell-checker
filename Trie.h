#ifndef TRIE_SPELLCHECKER_TRIE_H
#define TRIE_SPELLCHECKER_TRIE_H

#include "TrieLeafNode.h"
#include "TrieNonLeafNode.h"

class Trie
{
public:
    Trie();
    Trie(char *);
    void printTrie();
    void insert(char *);
    bool wordFound(char *);
private:
    TrieNonLeafNode *root;
    const int notFound;
    char prefix[80];
    int position(TrieNonLeafNode *, char);
    void addCell(char, TrieNonLeafNode *, int);
    void createLeaf(char, char *, TrieNonLeafNode *);
    void printTrie(int, TrieNonLeafNode *, char *);
};


#endif //TRIE_SPELLCHECKER_TRIE_H
