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
    string fname =  "C:\\Users\\chris_d0m8an5\\CLionProjects\\Cheaters\\cmake-build-debug\\sm_doc_set\\abf70402";
    vector<string> v;
    fstream currentFile;
    currentFile.open(fname);
    cout<<"file opened";

    string word;
    cout<<"word string created";

    while(currentFile>>word) {
        cout << "word found" << endl;

        v.push_back(word);
        cout << word << endl;
    }

        cout << "finishing";
        return 0;

}
