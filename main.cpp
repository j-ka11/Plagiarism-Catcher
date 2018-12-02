//
// Created by chris_d0m8an5 on 11/29/2018.
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

int main()
{
    PlagiarismCatcher myCatcher;
    string dir = string("sm_doc_set");

    myCatcher.getdir(dir);

    myCatcher.printFiles();
    vector<string> v;
    fstream currentFile;
    string fileLoc = "D:\\Documents\\EE 312\\Labs\\Lab 8-Plagiarism Catcher\\cmake-build-debug\\sm_doc_set/" + files.at(2);
    currentFile.open(fileLoc);
    if(currentFile.is_open()){
        cout << "file opened" << endl;
    }
        return 0;

}
