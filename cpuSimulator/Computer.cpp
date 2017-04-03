/* 
 * File:   CPUprogam.cpp
 * Author: James Joshua Msuya
 *
 * Created on November 1, 2016, 7:40 AM
 */

/*
 * Definition of functions in class CPUprogam
 * This is a source file containing function definition of member functions in 
 * class CPUprogam.
 * 
 */
         

#include <iostream>
#include <string>
#include <fstream>
#include "CPU.h"
#include "CPUProgam.h"
#include "Memory.h"
#include "Computer.h"

using namespace std;

Computer::Computer(CPU cpu,CPUProgam prog, Memory mem,int option)
                :progCpu(cpu),progCpuProgam(prog),progMemory(mem),optionNum(option){
    
}
    
Computer::Computer(int option)
            :optionNum(option){
    
}
   

   
void Computer::setCPU(CPU mycp){
     
    progCpu=mycp;
    
    
}

void Computer::setCPUProgram(CPUProgam mycpuprog){
    progCpuProgam=mycpuprog;

}

void Computer::setMemory(Memory myMem){
    
    progMemory=myMem;
     
}

int Computer::execute(){
    
    int count;
    int line;
    int size=progCpuProgam.size();
    string instruction;
    string temp;
   
    
    if(progCpuProgam.nullChecker()){

	if(argumentsNum==3){//this condition is to check if correct amount of input argument were entered in the terminal

		if(optionNum > 2 || optionNum < 0 ){

			cerr << "ERROR!"<< endl <<"Please input 0, 1 or 2 for option" << endl;

		}		
		else{
			while(!progCpu.halted()){
                            
                                count=progCpu.getPC();
                                if(count > size){
                                        cerr << "ERROR! " <<"Line "<<line<< endl
                                             <<"The line to be jumped is out of range" << endl;
                                        break;
                                    }
                                 else{
                                  /**/  temp=progCpuProgam.getLine(progCpu.getPC()-1);
                                    line=progCpu.getPC();
                                    instruction = progCpu.stringCleaner(temp);
                                    
                                    if(instruction=="1"){
                                        cerr << "ERROR! " << endl
                                             <<"Line "<<line<<" has syntax error." << endl;
                                        break;
                                    }
                                 }
				
                                
				if (optionNum== 0){
                                        line=progCpu.getPC();
                                       progCpu.execute(instruction,progMemory);
				}
				if (optionNum== 1){
                                    
                                    progCpu.print();
                                    cout<<endl<<endl;
                                    progCpu.execute(instruction,progMemory);
                                        
                                    }
                                if(optionNum==2){
                                    
                                    progCpu.print();
                                    progMemory.printAll();
                                    cout<<endl<<endl;
                                    progCpu.execute(instruction,progMemory);
                                }
				}

			}
		}
	
	




 	if(argumentsNum < 3){
 	
            //if the input parameter in the terminal are les than two or more than two it gives an error
            cerr << "ERROR!"<< endl;  
            cerr << "Some arguments are missing"<< endl;

 	}
        if(argumentsNum > 3){
 	
            //if the input parameter in the terminal are les than two or more than two it gives an error
            cerr << "ERROR!"<< endl;  
            cerr << "Please put only two arguments"<< endl;

 	}
	
        
}

else{
        cerr << "ERROR!"<< endl;  
	cerr << "File could not be found or opened"<< endl;
}
 return 0;   
}
 