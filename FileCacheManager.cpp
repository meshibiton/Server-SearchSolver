//
// Created by raph on 1/13/20.
//

// CPP code to check if a key is present
// in an unordered_map
#include "FileCacheManager.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace  std;

bool FileCacheManager::isExist(string problem){


    if (this->mapCachProblem.find(problem) == this->mapCachProblem.end()){
        return false;
    } else{
        return true;
    }
}
void FileCacheManager::pushSolution(string problem, string solution) {
    int nameFile = hashFunc(problem);
    //write to file
    std::ofstream outfile ((nameFile)+".txt");
    outfile << solution << std::endl;
    outfile.close();
    //map string problenm to file name
    this->mapCachProblem[problem] = (nameFile)+".txt";

}
string FileCacheManager::popSolution(string problem){
    string fileName = this->mapCachProblem.find(problem)->second;
    fstream f(fileName, fstream::in );
    string solution;
    f.close();
    return solution ;
}

int FileCacheManager::hashFunc(string line){
    std::hash<std::string> hasher;
    auto hashed = hasher(line); //returns std::size_t
    std::cout << hashed << '\n';

}
