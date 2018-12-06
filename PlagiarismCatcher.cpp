//
// Created by joshu on 12/2/2018.
//
#include "PlagiarismCatcher.h"

using namespace std;

PlagiarismCatcher::PlagiarismCatcher(){
    breakSize=6;
}
PlagiarismCatcher::PlagiarismCatcher(int n){
    breakSize=n;
}

int PlagiarismCatcher::getdir(string dir) {
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
   /* for(int i = 2;i < this->files.size();i++){
        fileVector.push_back(this->files.at(i));
    }*/
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
int PlagiarismCatcher::printFileContent(string fName){
    /*int fileIdx;
    bool foundFile = false;
    for(int i = 0;i < files.size();i++){
        if(fName == files.at(i)){
            fileIdx = i;
            foundFile = true;
        }
    }
    if(!foundFile){
        return -1;
    }else{*/
        fstream currentFile;
        string fileLoc = "D:\\Documents\\EE 312\\Labs\\Lab 8-Plagiarism Catcher\\cmake-build-debug\\sm_doc_set/" + fName;
        currentFile.open(fileLoc);
        if(currentFile.is_open()){
            cout << "file opened" << endl;
        }else{
            cout << "file didn't open" << endl;
        }
        string word;
        while(currentFile >> word){
            word = removePunctuation(word);
            cout << word << endl;
        }
        return 0;
    //}
}

string PlagiarismCatcher::removePunctuation(string word) {
    for(int i = 0;i < word.length();i++){
        if(((word[i] >= 33) && (word[i] <= 47)) | ((word[i] >= 58) && (word[i] <= 64)) | ((word[i] >= 91) && (word[i] <= 96)) | ((word[i] >= 123) && (word[i] <=127))){
            word.erase(word.begin() + i);
        }
    }
    return word;
}
