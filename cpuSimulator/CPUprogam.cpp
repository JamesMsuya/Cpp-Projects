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

using namespace std;


/*The definition of member functions of class CPUProg*/

CPUProgam::CPUProgam(){
    
    
}


CPUProgam::CPUProgam(const char *filename)
			:inputfile(filename){
    
    if(nullChecker()){
        ReadFile(filename);
    }
		
}

CPUProgam::CPUProgam(int option)
            :optionNum(option){
    
}

int CPUProgam::ReadFile(const char *filename){
	fstream inputStream;
	string line;
        
       /* if(nullChecker()){*/
                inputStream.open(filename);


            while (!inputStream.eof()){

                    getline(inputStream,line);
                    information.push_back(line);

             } 
            inputStream.close();
        //}
return 0;
}

string CPUProgam::getLine(int num){
	int sizeOfFile;
	sizeOfFile=information.size();

	return(information[num]);
}

int CPUProgam::size(){
    
        return information.size();
        
}

bool CPUProgam::nullChecker(){
    fstream inputStream;
    
       
         inputStream.open(inputfile);
        if(inputStream.is_open()){
            
            return (true);
        }
        else{
            
            return (false);
        }
    
}