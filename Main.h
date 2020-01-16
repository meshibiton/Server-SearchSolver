//
// Created by raph on 1/14/20.
//

#ifndef FINALPROJECTPART2_MAIN_H
#define FINALPROJECTPART2_MAIN_H


#include "Server.h"
#include "FileCacheManager.h"
#include "MyClientHandler.h"
#include "MySerialServer.h"
#include "SearcherSolver.h"

namespace server_side {
    namespace boot {
        class Main {
        public:
            int main(char *argv[]){
                Server *server = new MySerialServer();
                FileCacheManager *fileCacheManager = new FileCacheManager();
                MyClientHandler *myClientHandler = new MyClientHandler(new SearcherSolver(), fileCacheManager);
                //        myClientHandler->handlerClient(5600);
                server->open(atoi(argv[1]), myClientHandler);
                //        this_thread::sleep_for(chrono::microseconds(100000));
                return 0;
            }

        };
    }
}
#endif //FINALPROJECTPART2_MAIN_H
