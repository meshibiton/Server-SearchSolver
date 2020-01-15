cmake_minimum_required(VERSION 3.14.3)
project(finalProjectPart2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(finalProjectPart2 main.cpp ClientHandler.h FileCacheManager.cpp FileCacheManager.h MyClientHandler.cpp MyClientHandler.h Server.h MyParallelServer.cpp MyParallelServer.h MySerialServer.cpp MySerialServer.h StringReverser.cpp  StringReverser.h Solver.h CacheManager.h Searcher.h Searchable.h State.h Matrix.h Main.h DataStrucForSearcher.h MyPriortyQueue.h SearcherAbstract.h)