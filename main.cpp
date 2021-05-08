#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include<ctime>
#include "Trie.h"

using namespace std;


char *Strupr(char *s) {
    char *ss;
    for (ss = s; (*s = toupper(*s)); s++);
    return ss;
}

int main(int argc, char **argv) {
    char fileName[25], dictName[25], s[80], s_o[80], ch;
    int i, lineNum = 1;
    int miss_count = 0, dict_count = 0, words_count = 0;

    clock_t loadStartTime = 0, loadEndTime = 0;
    clock_t checkStartTime = 0, checkEndTime = 0;
    clock_t sizeStartTime = 0, sizeEndTime = 0;
    clock_t unloadStartTime = 0, unloadEndTime = 0;

    if (argc == 2) {
        strcpy(dictName, "dictionary");
        strcpy(fileName, argv[1]);
    } else if (argc == 3) {
        strcpy(dictName, argv[1]);
        strcpy(fileName, argv[2]);
    } else {
        cerr << "Usage: speller [dictionary] text" << endl;
        exit(1);
    }

    ifstream dictionary(dictName);
    ifstream textFile(fileName);
    if (dictionary.fail()) {
        cerr << "cannot open 'dictionary'\n";
        exit(-1);
    }

    if (textFile.fail()) {
        cout << "cannot open " << fileName << endl;
        exit(-1);
    }

    loadStartTime = clock();
    dictionary >> s;
    dict_count = 1;
    Trie trie(Strupr(s));

    while (dictionary >> s) {
        trie.insert(Strupr(s));
        dict_count++;
    }

    loadEndTime = clock();

    // trie.printTrie();

    checkStartTime = clock();
    cout << "Misspelled words:\n";
    textFile.get(ch);
    while (!textFile.eof()) {

        while (!textFile.eof() && !isalpha(ch)) {
            if (ch == '\n')
                lineNum++;
            textFile.get(ch);
        }
        if (textFile.eof())
            break;
        for (i = 0; !textFile.eof() && isalpha(ch); i++) {
            s[i] = toupper(ch);
            s_o[i] = ch;
            textFile.get(ch);
        }
        s[i] = '\0';
        s_o[i] = '\0';
        if (!trie.wordFound(s)) {
            miss_count++;
            cout << s_o << endl;
        }
        words_count++;
    }
    checkEndTime = clock();


    dictionary.close();
    textFile.close();

    cout << endl;
    cout << setiosflags(ios::left) << fixed << setprecision(2) ;
    cout << setw(25) << "WORDS MISSPELLED:" << miss_count << endl;
    cout << setw(25) << "WORDS IN DICTIONARY:" << dict_count << endl;
    cout << setw(25) << "WORDS IN TEXT:" << words_count << endl;

    double total = 0;
    double time = (double) (loadEndTime - loadStartTime) / CLOCKS_PER_SEC;
    total += time;
    cout << setw(25) << "TIME IN load:" << time << endl;

    time = (double) (checkEndTime - checkStartTime) / CLOCKS_PER_SEC;
    total += time;
    cout << setw(25) << "TIME IN check:" << time << endl;

    time = (double) (sizeEndTime - sizeStartTime) / CLOCKS_PER_SEC;
    total += time;
    cout << setw(25) << "TIME IN size:" << time << endl;

    time = (double) (unloadEndTime - unloadStartTime) / CLOCKS_PER_SEC;
    total += time;
    cout << setw(25) << "TIME IN unload:" << time << endl;

    cout << setw(25) << "TIME IN TOTAL:" << total << endl;


    return 0;
}