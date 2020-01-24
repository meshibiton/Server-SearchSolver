#include "Server.h"
#include "FileCacheManager.h"
#include "MyClientHandler.h"
#include "MySerialServer.h"
#include "SearcherSolver.h"
#include "MyParallelServer.h"

int main(int argc, char *argv[]) {
    if(argc==2) {
        //create object of all the details that exist in cache manager
        FileCacheManager *fileCacheManager = new FileCacheManager();
        //get from the client the solution and save the information in class Fields
        MyClientHandler *myClientHandler = new MyClientHandler(new SearcherSolver(), fileCacheManager);
         Server *server = new MyParallelServer();
        //Server *server = new MySerialServer();
        //server open the port for accepting client
        server->open(stoi(argv[1]), myClientHandler);
    }
    return 0;

}