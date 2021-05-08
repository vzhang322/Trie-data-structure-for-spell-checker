//
// Created by Ruizhe Zhang && Shiyun Tao on 2021/5/8.
//

#include "TrieLeafNode.h"

TrieLeafNode::TrieLeafNode() {

}

TrieLeafNode::TrieLeafNode(char *suffix)
{
    leaf = true;
    word = new char[strlen(suffix)+1];
    if(word == 0){
        cerr << "out of memory2\n";
        exit(-1);
    }
    strcpy(word, suffix);
}