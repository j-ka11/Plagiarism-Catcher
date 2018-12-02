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


using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

int main()
{
    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();

    getdir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << files[i] << endl;
    }
    vector<string> v;
    fstream currentFile;
    string fileLoc = "D:\\Documents\\EE 312\\Labs\\Lab 8-Plagiarism Catcher\\cmake-build-debug\\sm_doc_set/" + files.at(2);
    currentFile.open(fileLoc);
    if(currentFile.is_open()){
        cout << "file opened" << endl;
    }
        return 0;

}
