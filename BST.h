#pragma once

#include <iostream>
#include <string>

//Node of the tree
struct Node
{
	//Data stored in this node of the tree
	std::string data;
	//The left branch of the tree
	Node *left = nullptr;
	//The right branch of the tree
	Node *right = nullptr;
};

class BST{
private:
	//Pointer to root of the tree
	Node *root = nullptr;
public:
	//Create a binary tree
	BST();
	//Create a binary tree with an inital word to store
	BST(std::string word);
	//Create a binary tree by copying an existing tree
	BST(const BST &rhs);
	//Destructor
	~BST();
	//Checks if a word is in the tree
	bool exists(std::string word) const;
	bool isEmpty() const;
	//Clear all words 
	void clear();
	//Create preorder to represent string in the tree
	void preorder();
	//Create inorder to represent string in the tree
	void inorder();
	//Create postorder to represent string in the tree
	void postorder();
}