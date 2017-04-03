/* 
 * File:   CPU.h
 * Author: James Joshua Msuya
 *
 * Created on November 1, 2016, 7:40 AM
 */

#ifndef CPU_H
#define CPU_H
#include "Memory.h"
#include <string>

using namespace std;

class CPU{

public:
        CPU();
    
	CPU(int r1,int r2,int r3,int r4,int r5,int pc);
        
        CPU(int option);

	int getReg(string str);

	int getPC(){return (PC);}

	int getR1(){return (R1);}

	int getR2(){return (R2);}

	int getR3(){return (R3);}

	int getR4(){return (R4);}

	int getR5(){return (R5);}

	int setPC(int num){return (PC=num);}

	int mov(int reg_1,int& reg_2);

	int add(int reg_1,int reg_2);

	int sub(int reg_1,int reg_2);

	int intConverter(string str);

	int prn(int reg);

	void print();

	bool halted();

	string caseConverter(string str);

	string spaceRemoval(string str);
        
        int memoryIndex(string str);

	string stringCleaner(string str);

	int execute(string str, Memory& myMemory);

private:
	int R1;
	int R2;
	int R3;
	int R4;
	int R5;
	int PC;
        int flag;
        int optionNum;

};

#endif /* CPU_H */

