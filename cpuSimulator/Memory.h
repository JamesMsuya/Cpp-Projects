

/* 
 * File:   Memory.h
 * Author: James Joshua Msuya
 *
 * Created on November 1, 2016, 7:39 AM
 */

#ifndef MEMORY_H
#define MEMORY_H
#include <string>

using namespace std;

class Memory{

public: 
    
    Memory();
    
   Memory(int option);
    
    int getMem(int index){return(memory[index]);}
    
    void setMem(int index,int value);
    
    void printAll();
    
    
    
private:

    unsigned int memory[50];


};

#endif /* MEMORY_H */