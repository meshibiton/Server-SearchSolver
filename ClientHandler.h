//
// Created by raph on 1/13/20.
//

#ifndef FINALPROJECTPART2_CLIENTHANDLER_H
#define FINALPROJECTPART2_CLIENTHANDLER_H

// An abstract class
class ClientHandler
{
    // Data members of class

public:
  // Pure Virtual Function
  virtual void handlerClient(int socket)= 0;
    /* Other members */
};





#endif //FINALPROJECTPART2_CLIENTHANDLER_H
