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

using namespace std;
class PlagiarismCatcher{
private:
    vector<string> files;
    int breakSize;
    string wordQueue;
    vector<string> wordFile;
public:
    PlagiarismCatcher();
    PlagiarismCatcher(int n);
    vector<string> getFiles() const;
    void setFiles(vector<string> sFile);
    int getdir (string dir);
    void printFiles();
    int printFileContent(string fName);
    string removePunctuation(string word);
    int hashFunction(string wordQueue);
    void addFiletoHash(string fName, int n);
};

#endif //LAB_8_PLAGIARISM_CATCHER_PLAGIARISMCATCHER_H
