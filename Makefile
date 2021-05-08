speller: main.cpp Trie.cpp TrieLeafNode.cpp TrieNonLeafNode.cpp 
	g++ -o speller -std=c++14 -Wall main.cpp Trie.cpp TrieLeafNode.cpp TrieNonLeafNode.cpp 

clean:
	rm speller
