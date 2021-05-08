//
// Created by Ruizhe Zhang && Shiyun Tao on 2021/5/8.
//

#include "TrieNonLeafNode.h"

TrieNonLeafNode::TrieNonLeafNode() {

}

TrieNonLeafNode::TrieNonLeafNode(char ch) {
    ptrs = new TrieNonLeafNode *;
    letters = new char[2];
    if (ptrs == 0 || letters == 0) {
        cerr << "out of memory3\n";
        exit(1);
    }
    leaf = false;
    endOfWord = false;
    *ptrs = 0;
    *letters = ch;
    *(letters + 1) = '\0';
}