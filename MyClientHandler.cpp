//
// Created by raph on 1/13/20.
//

#include "MyClientHandler.h"
using  namespace std;
void  MyClientHandler::handlerClient(int socket){

    char buffer[1024];
    string lineProblem = "";
    string cutLine;
    bool stopRead = false;
    string str;


    while(!stopRead){
        cutLine = "";
        //read from socket
        int valread = read(socket, buffer, 1024);
        //is we can read from the socket
        if(valread && valread!=-1){
            std::cout << buffer << std::endl;
            str = buffer;
            //substr the first line mybe she isn"t completly
            isExist = str.find("\n");
            if(isExist != -1){
                cutLine = str.substr(0, isExist + 1);
                //now we have full line
                lineProblem = lineProblem + cutLine;
                //call function we have problem to solve

                close(socket);
            }
            //fill the line there are more str to add
            lineProblem = str;
        }else{
           cout<<"Failed to read from socket";
        }



    }

}
