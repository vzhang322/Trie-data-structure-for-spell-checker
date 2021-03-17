#include "BST.h"
#include<iostrem>
#include<cstring>
#include<cstdlib>
#include"trie.h"
using namespace std;


BST::BST(){
	root = new Node;
}

BST::BST(std::string word){
	root = new Node;
	root->data = word;
	root->left = nullptr;
	root->right = nullptr;
}

void CopyExistingTree(Node*& new_tree,Node*& existing_tree){
	if(existing_tree == nullptr){
		new_tree = nullptr;
	}else{
		new_tree = new Node;
		new_tree->data = existing_tree->data;
		CopyExistingTree(new_tree->left, existing_tree->left);
		CopyExistingTree(new_tree->right, existing_tree_tree->right);
	}
}

BST::BST(const BST& rhs){
	BST& new_rhs = const_cast<BST>(rhs);
	if(rhs.root == nullptr){
		root = nullptr;
	}else CopyExistingTree(this->root,new_rhs.root);
}

void destructor(Node*& node){
	if(node != nullptr){
		destructor(node->left);
		destructor(node->right);
		delete node;
	}
}
BST::~BST(){
	destructor(root);
}

TrieLeafnoda::TrieLeafnode(char *suffix)
{
	leaf = true;
	word = new char[strlen(suffix)+1];
	if(word == 0){
		cerr << "out of memory2\n";
		exit(-1);
	}
	strcpy_s(word,strlen(suffix) + 1, suffix);
}


TrieNonLeafnode::TrieNonLeafnode(char ch)
{
	ptrs = new TrieNonleafnode *;
	letters = new char[2];
	if(ptrs == 0 || letters == 0){
		cerr << "out of memory3\n";
		exit(1);
	}
	leaf = false;
	endOfWord = false;
	*ptrs = 0;
	*letters = ch;
	*(letters + 1) = '\0';
}

Trie::Trie(char*world):notdound(-1)
{
	root = new TrieNonleafnode(*word);
	createLeaf(*word,word+1,root);
}


void Trie::printTrie(int depth, TrieNonLeafNode *p, char *prefix)
{
    int i;
    if(p->leaf){    
        TrieLeafNode *lf = (TrieLeafNode *)p;
        for(int i = 1; i <= depth; i++)
            cout << " ";
        cout << " >>" << prefix << "|" << lf->word << endl;
    }
    else{   
        for(i = strlen(p->letters)-1; i >= 0; i--){
            if(p->ptrs[i]!= '\0'){
                prefix[depth] = p->letters[i];
                prefix[depth+1] = '\0';
                printTrie(depth + 1, p->ptrs[i], prefix);
            }
        }
        if(p->endOfWord){
            prefix[depth] = '\0';
            for(i = 1; i <= depth; i++)
                cout << " ";
            cout << ">>>" << prefix << endl;
        }
    }
}

int Trie::position(TrieNonleafnode *p, char ch){
	int i;
	for(i = 0;i < strlen(p->letters) && p->letters[i] != ch; i++)
		if(i < strlen(p->letters))
			return i;
		else
			return notFound;
}


bool Trie::WordFound(char *word)
{
	TrieNonleafnode *p = root;
	TrieLeafnode *lf;
	int pos;
	while(true){
		if(p->leaf){
			lf = (TrieLeafnode *)p;
			if(strcmp(word, lf->word) == 0)
				return true;
			else 
				return false;
		}else if(*word == '\0'){
			if(p->endOfWord)
				return true;
			else
				return false;
		}else if((pos = position(p,*word))!=notFound && p->ptrs[pos]!=0){
			p = p->ptr[pos];
			word++;
		}else
		return false;
	}

}

void Trie::addCell(char ch,TrieNonleafnode *p, int stop){
	int i, len = strlen(p->letters);
	char *s = p->letters;
	TrieNonleafnode **temp = p->ptrs;
	p->letters = new char[len+2];
	if(p->letters == 0 || p->ptrs == 0){
		cerr << "out of memory1\n";
		exit(1);
	}
	for(i = 0;i < len;i++)
		p->ptrs[i] = 0;
	if(stop < len){
		for(i = len;i >= stop + 1;i--){
			p->ptrs[i] = temp[i-1];
			p->letters[i] = s[i-1];
		}
	}
	p->letters[stop] = ch;
	for(i = stop - 1;i >= 0;i--){
		p->ptrs[i] = temp[i];
		p->letters[i] = s[i];
	}
	p->letters[len+1] = '\0';
	delete []s;
}


void Trie::createLeaf(char ch, char *suffix, TrieNonleafnode *p)
{
	int pos = position(p,ch);
	if(pos == notFound){
		for(pos = 0;pos < strlen(p->letters) && p->letters[pos] < ch;pos++);
		addCell(ch,p,pos);
	}
	p->ptrs[pos] = (TrieNonleafnode *) new TrieLeafnode(suffix);
}


void Trie::insert(char *word)
{
	TrieNonLeafnode *p=root;
	TrieLeafnode *lf;
	int offset, pos;
	char *hold, pos;
	while(true){
		if(*word=='\0'){
			if(p->endOfWord){
				cout<<" entry " <<hold<<endl;
				else
					P->endOfWord = true;
				return;
			}
			pos=Position(p, *word);
			if(pos == notFound){
				createLeaf(*word, word+1, p);
				return;
			}
			else if(pos!=notFound && P->ptrs[pos]->leaf){
				li=(TrieLeafnode *)p->ptrs[pos];
				if(strcmp(lf->word,word+1)==0){
					cout<<" entry1 "<<hold<<endl;
					return;
				}
				offset = 0;
				do{
					pos = position(p,word[offset]);
					if(strlen(world)==offset+1){
						p->ptrs[pos] = new TrieNonLeafnode(word[offset]);
						p->ptrs[pos]->endOfWord = true;
						createLeaf(lf->world[offset],lf->word + offset + 1, p->ptrs[pos]);
						return;
					}
					else if(strlen(lf->word)==offset){
						p->ptrs[pos]=new TrieNonLeafnode(word[offset+1]);
						p->ptrs[pos]->endOfWord = ture;
						createLeaf(word[offset+1], word+offset+2,p->ptrs[pos]);
						return;
					}
					p->ptrs[pos] = new TrieNonLeafnode(word[offest+1]);
					p=p->ptrs[pos];
					offset++;
				}while(word[offset]==lf->word[offset-1]);
					offset--;
				char *s="";
				if(strlen(word)>offset+2)
					s = word + offset + 2;
					createLeaf(word[offset+1],s,p);
					if(strlen(lf->word)>offset + 1)
						s = lf-> word + offset+1;
					else
						s = "";
					createLeaf(lf->word[offset], s , p);
					return;
				}
				else{
					p=p->ptrs[pos];
					word++;
				}
			}
		}
	}

bool BST::exists(std::string word) const{
	Node *temp = root;
	while(temp!=nullptr){
		if(temp->data == word){
			return true;
		}else if(temp->data > word){
			temp = temp->left;
		}else if(temp->data <word){
			temp = temp->right;
		}
	}
	return false;
}

void PreOrder(Trie *rootT){
	if(rootT == NULL) return;
	cout<< rootT->RootData()<< ' ' ;
	PreOrder(rootT->Left());
	PreOrder(rootT->right());
}

void InOrder( Trie *rootT ){
	if (rootT == NULL ) return;
	if (rootT->Left() != NULL );
	InOrder( rootT->Left() );
	cout<< rootT->RootData() ;
	InOrder( rootT->Right() );
	if(rootT->Left() != NULL );
}

void PostOrder( Tree *rootT ){
	if (rootT == NULL ) return;
	postOrder( rootT->Left() );
	postOrder( rootT->Right() );
	cout<< rootT->RootData() << ' ' ;
}

	