/* 
 * File:   Memory.cpp
 * Author: James Joshua Msuya
 *
 * Created on November 1, 2016, 7:40 AM
 */

/*
 * Definition of functions in class Memory
 * This is a source file containing function definition of member functions in 
 * class Memory.
 * 
 */


#include <iostream>
#include "Memory.h"



using namespace std;

Memory::Memory()
{
    
    int lcv;
    for(lcv=0;lcv<50;lcv++){
        memory[lcv]=0;
    }
}

Memory::Memory(int option)
{
    
    int lcv;
    for(lcv=0;lcv<50;lcv++){
        memory[lcv]=0;
    }
}

    
void Memory::setMem(int index,int value){
    
    memory[index]=value;
       
}
    
void Memory::printAll(){
    int lcv;
    
    for(lcv=0;lcv<50;lcv++){
        
        cout<<"["<<lcv<<"]"<<" -> "<<memory[lcv]<<endl;
        
    }
    
    
}
