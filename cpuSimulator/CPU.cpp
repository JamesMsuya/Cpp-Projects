/* 
 * File:   CPU.cpp
 * Author: James Joshua Msuya
 *
 * Created on November 1, 2016, 7:40 AM
 */

/*
 * Definition of functions in class CPU
 * This is a source file containing function definition of member functions in 
 * class CPU.
 */



#include <iostream>
#include <string>
#include <fstream>
#include "CPU.h"
#include "Memory.h"
#include <cstdlib>


using namespace std;


CPU::CPU(){
    R1=0, R2=0, R3=0, R4=0, R5=0, PC=1;
}

CPU::CPU(int r1,int r2,int r3,int r4,int r5,int pc)
		:R1(r1), R2(r2), R3(r3), R4(r4), R5(r5), PC(pc){


}

CPU::CPU(int option)
            :optionNum(option){
    R1=0, R2=0, R3=0, R4=0, R5=0, PC=1;
}

int CPU::getReg(string str){
	switch(str[1]){
		case '1': return R1;break;
		case '2': return R2;break;
		case '3': return R3;break;
		case '4': return R4;break;
		case '5': return R5;break;
	}
}

int CPU::mov(int reg_1,int& reg_2){
	reg_2 = reg_1;

	return (reg_2);

}

int CPU::add(int reg_1,int reg_2){
	reg_1 += reg_2;

	return (reg_1);

}

int CPU::sub(int reg_1,int reg_2){
	reg_1 -= reg_2;

	return (reg_1);

}

int CPU::intConverter(string str){
	int length;
	int sum=0;
	int lcv;
	length = str.size();
	if(str[0]=='-'){
		str=str.substr(1);
		for (lcv = 0; lcv < length; lcv++){
			if(str[lcv]<58 && str[lcv] > 47){

			sum *= 10;
			sum += str[lcv]-'0';
			}
			else{
				break;
			}
		}
		sum=sum * -1;
	}
	else{
		for (lcv = 0; lcv < length; lcv++){
			if(str[lcv]<58 && str[lcv] > 47){

			sum *= 10;
			sum += str[lcv]-'0';
			}
			else{
				break;
			}
		}

	}
	return sum;


}

string CPU::caseConverter(string str){
	int length;
	int lcv;
	length = str.size();

	for (lcv = 0; lcv < length; lcv++){
		if(str[lcv] > 96 && str[lcv]< 123){
			str[lcv]=str[lcv]-32;

		}	
	}

return str;
}

int CPU::prn(int reg){

	cout << reg << endl;
}

void CPU::print(){
	cout << "R1 = " << R1 << endl 
             << "R2 = " << R2 << endl 
             << "R3 = " << R3 << endl 
             << "R4 = " << R4 << endl 
             << "R5 = " << R5 << endl 
             << "PC = " << PC << endl;

}

bool CPU::halted(){
	if (flag==1){
		return(true);

	}
	return (false);


}

int CPU::memoryIndex(string str){
	
	if (str[0]=='#'){
		str=str.substr(1);
	}
return(intConverter(str));
}

string CPU::spaceRemoval(string str){
	int size=str.size();
 	int lcv(0);
	for (lcv=0; lcv < size; lcv++){
 		if(str[lcv]== 32 || str[lcv]==9/*for tabs*/){
 			/*the function will advance to the next empty character*/
 		}
 		else{
 			break;
 		}
 	}
 	str=str.substr(lcv);

return (str);

}

string CPU::stringCleaner(string str){

	string instrac=" ";
 	string r1=" ";
 	string r2=" ";
 	bool r1truce,r2truce;
 	int position;
        int position2;

 	/*THis part erases the spaces before the instruction*/
 	str=spaceRemoval(str);
        
 	/*Here the main instruction is extracted from the string*/
         if(str.size() >= 3){
             
            instrac=str.substr(0,3);


            /*The spaces after instruction are cleaned*/

            str=str.substr(3);

            str=spaceRemoval(str);
            position=str.find(" ");
            instrac=caseConverter(instrac);



                if(instrac =="JMP" || instrac =="PRN" || instrac =="ADD" ||instrac =="SUB" || instrac =="MOV" || instrac =="JPN"){
                    /*here the second part of instruction is extracted*/
                    
                    if(position == -1){
                        r1=str.substr(0);
                        str="";
                    }
                    
                    if(position != -1){
                        r1=str.substr(0,position);
                        str=str.substr(position);
                    }
                       
                            if(r1[position-1]==','){     
                                    r1=r1.substr(0,position-1);
                                    str=spaceRemoval(str);
                                    position=str.find(" ");  
                                    
                                    if(position == -1){
                                        r2=str.substr(0);
                                        str="";
                                    }
                                    
                                    if(position!= -1){                                   
                                         r2=str.substr(0,position);
                                         str=str.substr(position);
                                    }
                                   
                            }
                       
                        str=spaceRemoval(str);
                        r1=caseConverter(r1);
                        r2=caseConverter(r2);
                }



                /*theses are boolean values to check if the strings r1 and r2 are empty or not*/
                r1truce=(r1==" ");
                r2truce=(r2==" ");

                int r2size=r2.size();

                        if(str[0]==';'|| str=="" || str[0]=='\n' || r2[r2size-1]=='\n'){

                                        if(!r2truce){

                                                return(instrac + " " + r1 + ","+" " + r2);

                                        }

                                        if(!r1truce ){

                                                return(instrac + " " + r1);

                                        }
                                        else{

                                                return (instrac);

                                        }

                        }

                        else{
                                /*This condition will check for error in the input line syntax*/
                                return ("1");
                        }
         }
         else{
             return("1");
         }
        
}

int CPU::execute(string str, Memory& myMemory){

	int temp;
	int size=str.size();
	string r1=" ";
	string r2=" ";
	string instrac=str.substr(0,3);
        int pos;

	if(instrac =="JMP" || instrac =="PRN" || instrac =="ADD" ||instrac =="SUB" || instrac =="MOV" || instrac =="JPN"){
		if(size > 8){

                    pos=(str.substr(4)).find(" ");
			r1=str.substr(4,pos-1);
			r2=str.substr(4+pos+1);

		}
		else{

			r1=str.substr(4);
			
		}
	}
	
	if (instrac == "MOV"){

					if(r1=="R1"){
							if(r2=="R2"){
									mov(R1,R2);
								}
							else if(r2=="R3"){
									mov(R1,R3);
								}
							else if(r2=="R4"){
									mov(R1,R4);
								}
							else if(r2=="R5"){
									mov(R1,R5);
								}
                                                        else if (r2[0]=='#'){
									int n= memoryIndex(r2);
									myMemory.setMem(n,R1);								
								}
					
							else{
								temp= intConverter(r2);
								mov(temp,R1);
								}

						}

					if(r1=="R2"){
							if(r2=="R1"){
									mov(R2,R1);
								}
							else if(r2=="R3"){
									mov(R2,R3);
								}
							else if(r2=="R4"){
									mov(R2,R4);
								}
							else if(r2=="R5"){
									mov(R2,R5);
								}
                                                        else if (r2[0]=='#'){
									int n= memoryIndex(r2);
									myMemory.setMem(n,R2);								
								}
							else{
								temp= intConverter(r2);
								mov(temp,R2);
								}

						}


					if(r1=="R3"){
							if(r2=="R1"){
									mov(R3,R1);
								}
							else if(r2=="R2"){
									mov(R3,R2);
								}
							else if(r2=="R4"){
									mov(R3,R4);
								}
							else if(r2=="R5"){
									mov(R3,R5);
								}
                                                        else if (r2[0]=='#'){
                                                                    int n= memoryIndex(r2);
                                                                    myMemory.setMem(n,R3);								
								}
							else{
								temp= intConverter(r2);
								mov(temp,R3);
								}

						}

					if(r1=="R4"){
							if(r2=="R1"){
									mov(R4,R1);
								}
							else if(r2=="R2"){
									mov(R4,R2);
								}
							else if(r2=="R3"){
									mov(R4,R3);
								}
							else if(r2=="R5"){
									mov(R4,R5);
								}
							else if (r2[0]=='#'){
                                                                    int n= memoryIndex(r2);
                                                                    myMemory.setMem(n,R4);								
								}
							else{
								temp= intConverter(r2);
								mov(temp,R4);
								}

						}
					if(r1=="R5"){
							if(r2=="R1"){
									mov(R5,R1);
								}
							else if(r2=="R2"){
									mov(R5,R2);
								}
							else if(r2=="R3"){
									mov(R5,R3);
								}
							else if(r2=="R4"){
									mov(R5,R4);
								}
                                                        else if (r2[0]=='#'){                                                        
                                                                    int n= memoryIndex(r2);
                                                                    myMemory.setMem(n,R5);								
								}
							else{
								temp= intConverter(r2);
								mov(temp,R5);
								}
						}
                                        if(r1[0]=='#'){
						int n=memoryIndex(r1);

							if(r2=="R1"){
									mov(myMemory.getMem(n),R1);
								}
							else if(r2=="R2"){
									mov(myMemory.getMem(n),R2);
								}
							else if(r2=="R3"){
									mov(myMemory.getMem(n),R3);
								}
							else if(r2=="R4"){
									mov(myMemory.getMem(n),R4);
								}
							else if(r2=="R5"){
									mov(myMemory.getMem(n),R5);
								}
							else if (r2[0]=='#'){
									int z=memoryIndex(r2);
									myMemory.setMem(z,myMemory.getMem(n));								
							}
							
							else{
                                                            
								temp= intConverter(r2);
								myMemory.setMem(n,temp);
								}
						}
					}


			else if(instrac == "ADD"){

					if(r1=="R1"){
							if(r2=="R1"){
									R1=add(R1,R1);
								}
							else if(r2=="R2"){
									R1=add(R1,R2);
								}
							else if(r2=="R3"){
									R1=add(R1,R3);
								}
							else if(r2=="R4"){
									R1=add(R1,R4);
								}
							else if(r2=="R5"){
									R1=add(R1,R5);
								}
							else if (r2[0]=='#'){
									int n=memoryIndex(r2);
									R1=add(R1,myMemory.getMem(n));								
								}
							else{
								temp= intConverter(r2);
								R1=add(R1,temp);
								}

						}

					if(r1=="R2"){
							if(r2=="R1"){
									R2=add(R2,R1);
								}
							else if(r2=="R2"){
									R2=add(R2,R2);
								}
							else if(r2=="R3"){
									R2=add(R2,R3);
								}
							else if(r2=="R4"){
									R2=add(R2,R4);
								}
							else if(r2=="R5"){
									R2=add(R2,R5);
								}
							else if (r2[0]=='#'){
									int n=memoryIndex(r2);
									R2=add(R2,myMemory.getMem(n));								
								}
							else{
								temp= intConverter(r2);
								R2=add(R2,temp);
								}

						}


					if(r1=="R3"){
							if(r2=="R1"){
									R3=add(R3,R1);
								}
							else if(r2=="R2"){
									R3=add(R3,R2);
								}
							else if(r2=="R3"){
									R3=add(R3,R3);
								}
							else if(r2=="R4"){
									R3=add(R3,R4);
								}
							else if(r2=="R5"){
									R3=add(R3,R5);
								}
                                                        else if (r2[0]=='#'){
									int n=memoryIndex(r2);
									R3=add(R3,myMemory.getMem(n));								
								}
							else{
								temp= intConverter(r2);
								R3=add(R3,temp);
								}

						}

					if(r1=="R4"){
							if(r2=="R1"){
									R4=add(R4,R1);
								}
							else if(r2=="R2"){
									R4=add(R4,R2);
								}
							else if(r2=="R3"){
									R4=add(R4,R3);
								}
							else if(r2=="R4"){
									R4=add(R4,R4);
								}
							else if(r2=="R5"){
									R4=add(R4,R5);
								}
							else if (r2[0]=='#'){
									int n=memoryIndex(r2);
									R4=add(R4,myMemory.getMem(n));								
								}
							else{
								temp= intConverter(r2);
								R4=add(R4,temp);
								}

						}
					if(r1=="R5"){
							if(r2=="R1"){
									R5=add(R5,R1);
								}
							else if(r2=="R2"){
									R5=add(R5,R2);
								}
							else if(r2=="R3"){
									R5=add(R5,R3);
								}
							else if(r2=="R4"){
									R5=add(R5,R4);
								}
							else if(r2=="R5"){
									R5=add(R5,R5);
								}
                                                        else if (r2[0]=='#'){
									int n=memoryIndex(r2);
									R5=add(R5,myMemory.getMem(n));								
								}
							else{
								temp= intConverter(r2);
								R5=add(R5,temp);
								}
						}

					

					}


			else if(instrac == "SUB"){

					if(r1=="R1"){
							if(r2=="R1"){
									R1=sub(R1,R1);
								}
							else if(r2=="R2"){

									R1=sub(R1,R2);
								}
							else if(r2=="R3"){
									R1=sub(R1,R3);
								}
							else if(r2=="R4"){
									R1=sub(R1,R4);
								}
							else if(r2=="R5"){
									R1=sub(R1,R5);
								}
							else if (r2[0]=='#'){
									int n=memoryIndex(r2);
									R1=sub(R1,myMemory.getMem(n));								
								}
							else{
								temp= intConverter(r2);
								R1=sub(R1,temp);
								}

						}

					if(r1=="R2"){
							if(r2=="R1"){
									R2=sub(R2,R1);
								}
							if(r2=="R2"){
									R2=sub(R2,R2);
								}
							if(r2=="R3"){
									R2=sub(R2,R3);
								}
							if(r2=="R4"){
									R2=sub(R2,R4);
								}
							if(r2=="R5"){
									R2=sub(R2,R5);
								}
                                                        else if (r2[0]=='#'){
									int n=memoryIndex(r2);
									R2=sub(R2,myMemory.getMem(n));								
								}
							else{
								temp= intConverter(r2);
								R2=sub(R2,temp);
								}

						}



					if(r1=="R3"){
							if(r2=="R1"){
									R3=sub(R3,R1);
								}
							else if(r2=="R2"){
									R3=sub(R3,R2);
								}
							else if(r2=="R3"){
									R3=sub(R3,R3);
								}
							else if(r2=="R4"){
									R3=sub(R3,R4);
								}
							else if(r2=="R5"){
									R3=sub(R3,R5);
								}
                                                        else if (r2[0]=='#'){
									int n=memoryIndex(r2);
									R3=sub(R3,myMemory.getMem(n));								
								}
							else{
								temp= intConverter(r2);
								R3=sub(R3,temp);
								}

						}

					if(r1=="R4"){
							if(r2=="R1"){
									R4=sub(R4,R1);
								}
							else if(r2=="R2"){
									R4=sub(R4,R2);
								}
							else if(r2=="R3"){
									R4=sub(R4,R3);
								}
							else if(r2=="R4"){
									R4=sub(R4,R4);
								}
							else if(r2=="R5"){
									R4=sub(R4,R5);
								}
                                                        else if (r2[0]=='#'){
									int n=memoryIndex(r2);
									R4=sub(R4,myMemory.getMem(n));								
								}
							else{
								temp= intConverter(r2);
								R4=sub(R4,temp);
								}

						}
					if(r1=="R5"){
							if(r2=="R1"){
									R5=sub(R5,R1);
								}
							else if(r2=="R2"){
									R5=sub(R5,R2);
								}
							else if(r2=="R3"){
									R5=sub(R5,R3);
								}
							else if(r2=="R4"){
									R5=sub(R5,R4);
								}
							else if(r2=="R5"){
									R5=sub(R5,R5);
								}
                                                        else if (r2[0]=='#'){
									int n=memoryIndex(r2);
									R5=sub(R5,myMemory.getMem(n));								
								}
							else{
								temp= intConverter(r2);
								R5=sub(R5,temp);
								}
						}


					}


			else if(instrac == "PRN"){
					if(r1=="R1"){
						prn(R1);
					}
					else if(r1=="R2"){
						prn(R2);
					}
					else if(r1=="R3"){
						prn(R3);
					}
					else if(r1=="R4"){
						prn(R4);
					}
					else if(r1=="R5"){
						prn(R5);
					}
                                        else if (r1[0]=='#'){
						int n=memoryIndex(r1);
						prn(myMemory.getMem(n));
					}
					else{

					 prn(intConverter(r1));

					}
		
			}

			else if(instrac == "JMP"){
              /*THis determines the nature of instruction
               *If the length of refined is greater than 8 the instruction is of JMP R# # nature.*/
				if(size > 8){
					if(getReg(r1) == 0){

						setPC(intConverter(r2)-1);

					}
					else{
						/*do not change value of PC and program continues*/
					}
				}
                     /*this is a condition for a simple jump of nature JMP #*/
				if(size < 8){

					setPC(intConverter(r1)-1);

				}

			}
        
                        else if(instrac == "JPN"){
                            
                            if(getReg(r1) <= 0){

						setPC(intConverter(r2)-1);

					}
					else{
						/*do not change value of PC and program continues*/
					}
                        
                        }

			else if(instrac == "HLT"){
                                flag=1;
				print();
                                myMemory.printAll();
				
			}
                        else{
                            cerr<<"ERROR"<<endl
                                <<"The instruction "<<instrac<< " is not valid"<<endl;
                            exit(1);
                           
                        }
                                
PC++;

return 0;	
}
