/*
 * =====================================================================================
 *
 *       Filename:  Doctor.h
 *
 *    Description: Header file for the Doctor class.
 *
 *        Version:  1.0
 *        Created:  11/10/2016 11:41:20 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tyler Jewell
 *         E-Mail:  tjj0013@auburn.edu
 *
 * =====================================================================================
 */

#include <string>
#include <cstdarg>

using namespace std;

class Doctor
{
public: 
	Doctor(string, int, string*);
    void input(int, string*);
    const string patientOutput();
	void setName(string);
    string getName();
	int getNumPatients();
	string * getPatientList();
    void resetPatients();
    Doctor& operator=(const Doctor &doc);
    ~Doctor();
	       
protected:
	string name;
    int numPatients; 
    string * patientList; 
};
