#include <string.h>
#include <string>
#include <chrono>
#include <sstream>
#include <cstdio>
#include <cctype>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

string removePunctuation(string su) {
    for (int i = 0, len = su.size(); i < len; i++) { 
        if (ispunct(su[i])) { 
            su.erase(i--, 1); 
            len = su.size(); 
        } 
    }
    return su;
}

string lowerCase(string sl) {
    transform(sl.begin(), sl.end(), sl.begin(), [](unsigned char c){ return tolower(c); });
    return sl;
}

vector<string> split(string s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string tok;
 
    while(getline(ss, tok, delimiter)) {
        tokens.push_back(removePunctuation(lowerCase(tok)));
    }
 
    return tokens;
}

int main (int argc, char* argv[]) {
    using namespace std::chrono;

    auto t1 = chrono::high_resolution_clock::now();
    string keyLineRaw;
    string keyLine;
    fstream keyFile;
    keyFile.open(argv[1]);
    unordered_map<string, int> umap;

    if (keyFile.is_open()) {
        while (getline(keyFile, keyLineRaw)) {
            stringstream keyLineS(keyLineRaw);
            while (getline(keyLineS, keyLine, '#')) {
                if (any_of(keyLine.begin(), keyLine.end(), [](char c){ return ispunct(c); })) {
                    cerr << "Invalid character in line" << endl;
                } else if (any_of(keyLine.begin(), keyLine.end(), [](char c){ return isspace(c); })) {
                    cerr << "Too many words on a line" << endl;
                } else if (keyLine.size() > 0) {
                    umap[keyLine] = 0;
                }
                break;
            }
        }
        keyFile.close();
    } else {
        cerr << "Unable to open file" << endl;
    }

    vector<string> textToken;

    int words = 0;
    int keyWords = 0;
    int lines = 0;

    string line;
    fstream file;
    file.open(argv[2]);
    if (file.is_open()) {
        while (getline(file, line)) {
            textToken = split(line, ' ');

            words = words + textToken.size();

            unordered_map<string, int>:: iterator itr; 
                
            for (int i = 0; i < textToken.size(); i++) {
                for (itr = umap.begin(); itr != umap.end(); itr++) { 
                    if (itr -> first == textToken[i]) {
                        itr -> second ++; 
                    } 
                }
            }
            lines++;
        }
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
    }

    unordered_map<string, int>:: iterator itr; 

    cout << "**************************" << endl;
    cout << "******* Statistics *******" << endl;
    cout << "**************************" << endl;
    cout << "Total Lines Read: " << lines << endl;
    cout << "Total Words Read: " << words << endl;
    cout << "Break Down by Key Word" << endl;

    for (itr = umap.begin(); itr != umap.end(); itr++) {
        keyWords = keyWords + itr -> second;
        cout << "     " << itr -> first << ": " << itr -> second << endl; 
    }

    cout << "Total Key Words: " << keyWords << endl << endl;

    auto t2 = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>( t2 - t1 ).count();

    cout << duration << " milliseconds" << endl;
}