#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstring>
#include "BST.h"
#include "trie.h"

using namespace std;


char *Strupr(char *s){
	char *ss;
	for(ss = s;*s = toupper(*s);s++);
		return ss;
}

int main(int argc,char *argv){
	char fileName[25], s[80],ch;
	int i,lineNum = 1;
	ifstream dictionary("dictionary");
	if(dictionary.fail()){
		cerr<<"cannot open 'dictionary'\n";
		exit(-1);
	}
	dictionary >> s;
	trie trie(Strupr(s));
	while(dictionary >> s)
		trie.insert(Strupr(s));
	trie.printTrie();
	if(argc!=2){
		cout<<"Enter a file name: ";
		cin>>fileName;
	}else{
		strcpy(fileName)
	}
	ifstream textFile(fileName);
	if(textFile.fail()){
		cout<<"cannot open "<< fileName<<endl;
		exit(-1);
	}
	cout<<"misspelled words:\n";
	while(!textFile.eof()){
		while(true){
			if(!textFile.eof()&&!isalpha(ch)){
				if(ch=='\n')
					lineNum++;
				textFile.get(ch);
			}else break;
		}
		if(textFile.eof())
			break;
		for(i = 0;!textFile.eof()&&isalpha(ch);i++){
			s[i] = toupper(ch);
			textFile.get(ch);
		}
		s[i] = '\0';
		if(!trie.wordFound(s))
			cout << s << " on line " << lineNum << endl;
	}
	dictionary.close();
	textFile.close();

	return 0;
}