//
// Created by joshu on 12/2/2018.
//
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "PlagiarismCatcher.h"

using namespace std;
int PlagiarismCatcher::getdir(string dir) {
    vector<string> files;
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    this->setFiles(files);
    closedir(dp);
    return 0;
}

vector<string> PlagiarismCatcher::getFiles() const {
    vector<string> fileVector;
    for(int i = 2;i < this->files.size();i++){
        fileVector.push_back(this->files.at(i));
    }
    return fileVector;
}

void PlagiarismCatcher::setFiles(vector<string> sFile) {
    for(int i = 0;i < sFile.size();i++){
        this->files.at(i) = sFile.at(i);
    }
}

void PlagiarismCatcher::printFiles() {
    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << files[i] << endl;
    }
}