//
// Created by raph on 1/14/20.
//

#ifndef FINALPROJECTPART2_MAIN_H
#define FINALPROJECTPART2_MAIN_H
#include <iostream>
#include "MySerialServer.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MyClientHandler.h"

namespace server_side {
    namespace boot {
        class Main {
        public:
            int main(char *args[]){
                MySerialServer *mySerialServer;
                StringReverser *stringReverser=new StringReverser();
                FileCacheManager *fileCacheManager=new FileCacheManager();
                MyClientHandler *myClientHandler=new MyClientHandler(stringReverser,fileCacheManager);
                server_side:mySerialServer->open(atoi(args[0]),myClientHandler);
                return 0;
            }

        };
    }
}
#endif //FINALPROJECTPART2_MAIN_H
