//
// Created by raph on 1/13/20.
//
#include <algorithm>
#include <unistd.h>
#include "MyClientHandler.h"
#include "ClientHandler.h"

using namespace std;

vector<vector<double >> MyClientHandler::fromStringToVec(string row) {
    vector<double> vactorRow;
    vector<vector<double >> bigVec;
    string numString = "";


    row.erase(std::remove(row.begin(), row.end(), ' '), row.end());
    for (char &c : row) {
        if (c != ',' && c != '\n') {
            numString += c;

        } else {
            if (c == '\n'&& vactorRow.empty()&& numString =="") {
                break;

            }
            if (c == '\n') {
                vactorRow.push_back(stof(numString));
                numString = "";
                bigVec.push_back(vactorRow);
                vactorRow.clear();
            } else {
                vactorRow.push_back(stof(numString));
                numString = "";
            }
        }
    }
    return bigVec  ;
}


void MyClientHandler::handlerClient(int socket) {

    char buffer[1024];
    string lineProblem = "";
    string cutLine;
    bool stopRead = false;
    int isExist;
    string str;
    string solution;
    vector<vector<double >> vSolution;


    while (!stopRead) {
        cutLine = "";
        //read from socket
        int valread = read(socket, buffer, 1024);
        //is we can read from the socket
        if (valread && valread != -1) {
//            std::cout << buffer << std::endl;
            str = buffer;
            //substr the first line mybe she isn"t completly
            isExist = str.find("end");
            if (isExist != -1) {
                cutLine = str.substr(0, isExist);
                //now we have full line
                lineProblem = lineProblem + cutLine;
                //creat matrix for solution
                //call function we have problem to solve
                if (this->cacheManager->isExist(lineProblem)) {
                    solution = this->cacheManager->popSolution(lineProblem);

                } else {
                    //creat the matrix solution
                    vSolution = fromStringToVec(lineProblem);
                    solution = solver->solve(vSolution);
                    this->cacheManager->pushSolution(lineProblem, solution);
                }
                cout << solution << endl;
                close(socket);
                //out from the loop
                stopRead = true;
            } else {
                //fill the line there are more str to add
                lineProblem = lineProblem + str;
                buffer[1024] = {0};
            }
        } else {
            cout << "Failed to read from socket";
        }
    }

}


