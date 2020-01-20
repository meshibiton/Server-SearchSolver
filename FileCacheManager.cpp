//
// Created by raph on 1/13/20.
//

// CPP code to check if a key is present
// in an unordered_map
#include <bits/stdc++.h>
#include "FileCacheManager.h"


using namespace  std;


bool FileCacheManager::isExist(string problem){
    pthread_mutex_lock(&mutex);
    if (this->mapCachProblem.find(problem) ==  this->mapCachProblem.end()){
        pthread_mutex_unlock(&mutex);
        return false;

    } else{
        return true;
    }

}
bool FileCacheManager::isExitFile(string problem) {
    int nameFile=FileCacheManager::hashFunc(problem);
    string fileName=to_string(nameFile)+".txt";
    std::ifstream infile(fileName);
    if(infile.good()){
        //if yes we will update our cache
        this->mapCachProblem[problem] = fileName;
    }
    return infile.good();
}


void FileCacheManager::pushSolution(string problem, string solution) {
    pthread_mutex_lock(&mutex);
    int nameFile = hashFunc(problem);
    cout<<"kkkk"+to_string(nameFile)<<endl;
    //write to file
    std::ofstream outfile (to_string (nameFile)+".txt");
    outfile << solution << std::endl;
    outfile.close();
    //map string problem to file name
    this->mapCachProblem[problem] = to_string(nameFile)+".txt";
    pthread_mutex_unlock(&mutex);


}
string FileCacheManager::popSolution(string problem){
    string solution="";
    string fileName = this->mapCachProblem.find(problem)->second;
    std::ifstream file( fileName ) ; // open this file for input
    std::string line ;
    while( std::getline( file, line ) ) // for each line read from the file
    {
        // print tit out so that we can verify that all lines were read
        solution = solution + line+'\n' ;

        // do what ever with the line
    }
    file.close();

    return solution ;
}
//void FileCacheManager::updateMap(string problem, string nameFile) {
//
//}


int FileCacheManager::hashFunc(string line){
    std::hash<std::string> hasher;
    auto hashed = hasher(line); //returns std::size_t
//    std::cout << hashed << '\n';
    return hashed;

}
FileCacheManager::~FileCacheManager(){
    pthread_mutex_destroy(&mutex);
}