
/* 
 * File:   Computer.h
 * Author: James Joshua Msuya
 *
 * Created on November 1, 2016, 7:40 AM
 * 
 */

#ifndef COMPUTER_H
#define COMPUTER_H
#include "CPU.h"
#include "CPUProgam.h"
#include "Memory.h"

class Computer{
    
public:
    
    Computer(CPU cpu,CPUProgam prog, Memory mem,int option);
    
    Computer(int option);
    
    int execute();
    
    void setCPU(CPU mycp);
    
    CPU getCPU(){return (progCpu);}
    
    CPUProgam getCPUProgram(){return(progCpuProgam);}
    
    Memory getMemory(){return(progMemory);}
    
    void setCPUProgram(CPUProgam mycpuprog);
   
    void setArgNum(int num){argumentsNum=num;}
    
    void setMemory(Memory myMem);
    
    
private:
    
    Memory progMemory;
    
    int optionNum;
    
    int argumentsNum;
    
    CPU progCpu;
    
    CPUProgam progCpuProgam;
      
};


#endif /* COMPUTER_H */

