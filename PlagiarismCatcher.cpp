//
// Created by joshu on 12/2/2018.
//
#include "PlagiarismCatcher.h"

using namespace std;

PlagiarismCatcher::PlagiarismCatcher(){
    n=6;
    //initializing collision vector
    for(int i = 0;i < files.size();i++){
        for(int j = 0;j < files.size();j++){
            CollisonVector.at(i).push_back(0);
        }
    }
    //initializing hash table
    for(int i = 0;i < TABLE_SIZE;i++){
        HashTable[i] = NULL;
    }
}
PlagiarismCatcher::PlagiarismCatcher(int N){

    n=N;
    for(int i = 0;i < files.size();i++){
        for(int j = 0;j < files.size();j++){
            CollisonVector.at(i).push_back(0);
        }
    }
    //initializing hash table
    for(int i = 0;i < TABLE_SIZE;i++){
        HashTable[i] = NULL;
    }
}

PlagiarismCatcher::~PlagiarismCatcher(){
    for(int i = 0;i < TABLE_SIZE;i++){
        deleteLinkedList(HashTable[i]);
    }
}

void PlagiarismCatcher::deleteLinkedList(PlagiarismCatcher::Node *currentNode) {
    if(currentNode == NULL){
        return;
    }else if(currentNode->next == NULL) {
        delete currentNode;
        return;
    }else{
        deleteLinkedList(currentNode->next);
        currentNode->next = NULL;
    }
}

int PlagiarismCatcher::getFilesSize() {
    return files.size();
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
int PlagiarismCatcher::printFileContent(){
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
    for(int i = 2;i < files.size();i++) {
        if(i == 10){
            int stop = 0;
        }
        if(i == 20){
            int stop = 0;
        }
        if(i == 25){
            int stop = 0;
        }
        fstream currentFile;
        string fileLoc =
                "D:\\Documents\\EE 312\\Labs\\Lab 8-Plagiarism Catcher\\cmake-build-debug\\sm_doc_set/" + files.at(i);
        currentFile.open(fileLoc);
        if (currentFile.is_open()) {
            cout << "file opened" << endl;
        } else {
            cout << "file didn't open" << endl;
        }
        string word;
        while (currentFile >> word) {
            word = removePunctuation(word);
            wordFile.push_back(word);
            cout << word << endl;
        }
        addFilestoHash();
    }
        return 0;
    //}
}

string PlagiarismCatcher::removePunctuation(string word) {
    if(word == "<br><br>"){
        int stop = 0;
    }
    for(int i = 0;i < word.length();i++){
        if(((word[i] >= 33) && (word[i] <= 47)) | ((word[i] >= 58) && (word[i] <= 64)) | ((word[i] >= 91) && (word[i] <= 96)) | ((word[i] >= 123) && (word[i] <=127))){
            word.erase(word.begin() + i);
            i--;
        }else if((word[i] >= 65) && (word[i] <= 90)){
            word[i] = word[i] + 32;
        }
    }
    return word;
}

int PlagiarismCatcher::hashFunction(string wordQueue){
    double functionValue = 0;
    unsigned long functionIdx;
    unsigned long moddingFactor = TABLE_SIZE;
    for(double i = 0;i < wordQueue.size();i++){
        functionValue = functionValue + (wordQueue[wordQueue.size() - i] - 1) * pow(3, i);
    }
    functionIdx = (unsigned long) functionValue;
    functionIdx = functionIdx % moddingFactor;
    return functionIdx;
}

void PlagiarismCatcher::addFilestoHash() {
    string phrase;
    for(int k = 0;k < files.size();k++) {
        for (int i = 0; i < (wordFile.size() - (this->n));) {
            if(i == wordFile.size() - 7){
                int stop = 0;
            }
            if((i + n) < wordFile.size()) {
                for (int j = 0; j < n; j++) {
                    phrase = phrase + wordFile.at(i);
                    i++;
                }
                addToTable(hashFunction(phrase), k, phrase);
                phrase = "";
                i = i - (n - 1);
            }else{
                cout << "done with this file" << endl;
                i++;
            }
        }
    }
}

void PlagiarismCatcher::addToTable(int tableidx, int fileidx, string phrase) {
    Node* myNode = new Node;
    if(phrase == "thereisareasonabledoubtin"){
        int stop = 0;
    }
    if((tableidx < 0) | (tableidx > TABLE_SIZE)){
        int stop = 0;
    }
    myNode->phrase=phrase;
    myNode->fileIdx=fileidx;
    myNode->tableIdx=tableidx;
    myNode->next=NULL;
    Node* current = HashTable[tableidx];
    while(current != NULL){
        if(current->next == NULL){
            current->next = myNode;
            HashTable[tableidx] = myNode;
            return;
        }else{
            CollisonVector.at(fileidx).at(current->fileIdx)++;
            current = current->next;
        }
    }
    HashTable[tableidx] = myNode;
}