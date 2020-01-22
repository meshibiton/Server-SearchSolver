#include "Server.h"
#include "FileCacheManager.h"
#include "MyClientHandler.h"
#include "MySerialServer.h"
#include "SearcherSolver.h"
#include "MyParallelServer.h"

int main(int argc, char *argv[]) {
    if(argc==2) {
        //Server *server = new MySerialServer();
//    StringReverser *stringReverser = new StringReverser();
        FileCacheManager *fileCacheManager = new FileCacheManager();

        MyClientHandler *myClientHandler = new MyClientHandler(new SearcherSolver(), fileCacheManager);
//        myClientHandler->handlerClient(5600);
         Server *server = new MyParallelServer();
        //Server *server = new MySerialServer();
        server->open(stoi(argv[1]), myClientHandler);
        //  server->open(atoi(argv[1]), myClientHandler);
//        this_thread::sleep_for(chrono::microseconds(100000));
    }
    return 0;

}