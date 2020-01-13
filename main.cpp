#include <iostream>
#include "MySerialServer.h"
#include "MyClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
namespace server_side {
    namespace boot {
        class Main {
        public:
            int main(char *args[]){
                MySerialServer *mySerialServer;
                StringReverser *stringReverser=new StringReverser();
                FileCacheManager *fileCacheManager=new FileCacheManager();
                MyClientHandler *myClientHandler=new MyClientHandler(stringReverser,fileCacheManager);
                mySerialServer->open(atoi(args[0]),myClientHandler);

            }
        };
    }
};
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}