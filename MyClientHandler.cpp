//
// Created by raph on 1/13/20.
//

#include <unistd.h>
#include "MyClientHandler.h"
#include "ClientHandler.h"

using  namespace std;
void  MyClientHandler::handlerClient(int socket){

    char buffer[1024];
    string lineProblem = "";
    string cutLine;
    bool stopRead = false;
    int isExist;
    string str;
    string solution;


    while(!stopRead){
        cutLine = "";
        //read from socket
        int valread = read(socket, buffer, 1024);
        //is we can read from the socket
        if(valread && valread!=-1){
            std::cout << buffer << std::endl;
            str = buffer;
            //substr the first line mybe she isn"t completly
            isExist = str.find("end");
            if(isExist != -1){
                cutLine = str.substr(0, isExist);
                //now we have full line
                lineProblem = lineProblem + cutLine;
                //call function we have problem to solve
                if(cm->isExist(lineProblem)){
                    solution = cm->popSolution(lineProblem);
                }else{
                    solution = this->solver->solve(lineProblem);
                    cm->pushSolution(lineProblem ,solution);
                }
                cout<<solution<<endl;
                close(socket);
            } else{
                //fill the line there are more str to add
                lineProblem = lineProblem + str;
                buffer[1024] = {0};
            }
        }else{
           cout<<"Failed to read from socket";
        }
    }

}
