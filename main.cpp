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
#include "HashTable.h"


using namespace std;

int main()
{
    int N=6;
    PlagiarismCatcher myCatcher(N);
    string dir = string("sm_doc_set");

    myCatcher.getdir(dir);

    myCatcher.printFiles();
    string fName = "bef1121.txt";
    for(int i = 0;i < myCatcher.getFilesSize();i++) {
        myCatcher.printFileContent(fName);
    }
    myCatcher.addFilestoHash();
    //vector<string> v;
        return 0;

}
