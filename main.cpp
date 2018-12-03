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
    int n=6;
    PlagiarismCatcher myCatcher;
    string dir = string("sm_doc_set");

    myCatcher.getdir(dir);

    myCatcher.printFiles();
    string fName = "bef1121.txt";
    myCatcher.printFileContent(fName);
    //vector<string> v;
        return 0;

}
