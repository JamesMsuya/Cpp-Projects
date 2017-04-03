/* 
 * File:   CPUProgam.h
 * Author: James Joshua Msuya
 *
 * Created on November 1, 2016, 7:40 AM
 */


#ifndef CPUPROGAM_H
#define CPUPROGAM_H
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class CPUProgam{

public:

        CPUProgam();
    
	CPUProgam(const char *filename);
        
        CPUProgam(int option);

	int ReadFile(const char *filename);

	string getLine(int num);

	int size();
        
        void setFilename(const char *filename){inputfile=filename;}
        
        bool nullChecker();
	
private:
    
	vector<string> information;
        
	const char *inputfile;
        
        int optionNum;

};

#endif /* CPUPROGAM_H */

