//
// Created by raph on 1/13/20.
//

// CPP code to check if a key is present
// in an unordered_map
#include <bits/stdc++.h>
#include "FileCacheManager.h"

using namespace  std;

bool FileCacheManager::isExist(string problem){


    if (this->mapCachProblem.find(problem) ==  this->mapCachProblem.end()){
        return false;
    } else{
        return true;
    }
}
void FileCacheManager::pushSolution(string problem, string solution) {
    int nameFile = hashFunc(problem);
    cout<<"kkkk"+to_string(nameFile)<<endl;
    //write to file
    std::ofstream outfile (to_string (nameFile)+".txt");
    outfile << solution << std::endl;
    outfile.close();
    //map string problenm to file name
    this->mapCachProblem[problem] = to_string(nameFile)+".txt";

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

int FileCacheManager::hashFunc(string line){
    std::hash<std::string> hasher;
    auto hashed = hasher(line); //returns std::size_t
    std::cout << hashed << '\n';

}
FileCacheManager::~FileCacheManager(){

}