//
// Created by joshu on 12/2/2018.
//

#ifndef LAB_8_PLAGIARISM_CATCHER_PLAGIARISMCATCHER_H
#define LAB_8_PLAGIARISM_CATCHER_PLAGIARISMCATCHER_H

#include <string>
#include <cmath>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include "HashTable.h"

using namespace std;
class PlagiarismCatcher{
private:
    vector<string> files;
    int n;
    static const int TABLE_SIZE = 136631;
    string wordQueue;
    vector<string> wordFile;
    struct Node{
        string phrase;
        int tableIdx;
        int fileIdx;
        Node* next;
    };
    vector<vector<int>> CollisonVector;
    Node* HashTable[TABLE_SIZE];
public:
    PlagiarismCatcher();
    PlagiarismCatcher(int n);
    ~PlagiarismCatcher();
    vector<string> getFiles() const;
    void setFiles(vector<string> sFile);
    int getdir (string dir);
    void printFiles();
    int printFileContent();
    string removePunctuation(string word);
    int hashFunction(string wordQueue);
    void addFilestoHash();
    void addToTable(int tableidx, int fileidx, string phrase);
    int getFilesSize();
    void deleteLinkedList(Node* currentNode);
};

#endif //LAB_8_PLAGIARISM_CATCHER_PLAGIARISMCATCHER_H
