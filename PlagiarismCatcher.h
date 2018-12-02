//
// Created by joshu on 12/2/2018.
//

#ifndef LAB_8_PLAGIARISM_CATCHER_PLAGIARISMCATCHER_H
#define LAB_8_PLAGIARISM_CATCHER_PLAGIARISMCATCHER_H

#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class PlagiarismCatcher{
private:
public:
    int getdir (string dir, vector<string> &files);
};

#endif //LAB_8_PLAGIARISM_CATCHER_PLAGIARISMCATCHER_H
