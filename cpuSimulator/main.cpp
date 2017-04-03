/* 
 * File:   main.cpp
 * Author: James Joshua Msuya
 *
 * Created on November 1, 2016, 7:40 AM
 */

#include <iostream>
#include <string>
#include <fstream>
#include "CPU.h"
#include "CPUProgam.h"
#include "Memory.h"
#include "Computer.h"

using namespace std;

int main(int argc, char const *argv[]){

    CPU myCPU1;
    int option=myCPU1.intConverter(argv[2]);
    const char* filename = argv[1];

//Testing class Memory

Memory myMemory(option);

//index, value
myMemory.setMem(0, 100);
cout << myMemory.getMem(0) << endl;

//The values of Registers and Memory are printed in this format 
//Memory Values:
//[0] -> 100
//[1] -> 0
//.
//.
//[49] -> 0
myMemory.printAll();


//Testing class CPU

CPU myCPU(option);
myCPU.execute("MOV #0, R1", myMemory);
myCPU.execute("MOV R1, #1", myMemory);
//The values of Registers and Memory are printed in this format 
//Memory Values:
//[0] -> 100
//[1] -> 0
//.
//.
//[4] -> 0
myCPU.print();

myMemory.printAll();

/************************************************************************/

/*Testing class CPUProgram*/

CPUProgam myCPUProgram(option);
myCPUProgram.ReadFile(filename);
myCPUProgram.setFilename(filename);
cout<<myCPUProgram.size()<<endl;
cout << myCPUProgram.getLine(0) << endl;
cout << myCPUProgram.getLine(myCPUProgram.size()-1) << endl;

/************************************************************************/
    
//Testing class Computer
Computer myComputer1(myCPU, myCPUProgram, myMemory, option);
Computer myComputer2(option);
myComputer2.setCPU( myComputer1.getCPU());
myComputer2.setArgNum(argc);
myComputer2.setCPUProgram(myComputer1.getCPUProgram());
myComputer2.setMemory(myComputer1.getMemory() );
myComputer2.execute();

/***********************************************************************/

    
return 0;  
}//end of main.

    