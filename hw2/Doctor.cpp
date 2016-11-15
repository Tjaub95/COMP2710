/*
 * =====================================================================================
 *
 *       Filename:  Doctor.cpp
 *
 *    Description:  This class represents a doctor has a list of patients.
 *
 *        Version:  1.0
 *        Created:  11/10/2016 11:46:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tyler Jewell
 *         E-Mail:  tjj0013@auburn.edu
 *
 * =====================================================================================
 */

#include "Doctor.h"

// Functions: Doctor
// Description:	Sets all of the variables in Doctor

Doctor::Doctor(string nameIn, int numPatientsIn, string * patientListIn)
{
	name = nameIn;
    numPatients = numPatientsIn;
    patientList = patientListIn;
}

// Functions: input
// Description: adds all input from the user. adds the patients 
//              in the parameter to the list of patients, and changes 
//              the number of patients

void Doctor::input(int numIn, string * patientsIn)
{
	int i = 0, num = numIn, j = 0;

	// creates a list for the patientInfo the size of the number of patients
	string * patientInfo = new string[numPatients + num];
	
	// Continues loop until i equals the numPatients
	while(i < numPatients)
	{
		// Sets the index i in patientInfo to what is at the same index in patientList
		patientInfo[i] = patientList[i];
		i++;
	}
	
	while(j < num)
	{
		//Adds the patient to the list
		patientInfo[numPatients + j] = patientsIn[j];
		j++;
	}

	//sets the numPatients and patientList
	numPatients += numIn;
	patientList = patientInfo;
}

// Functions: patientOutput
// Description:	Returns a list of all patients for the current doctor

const string Doctor::patientOutput()
{
	string patients = "";
	// checks to see if there are any patients
	
	if (numPatients > 0)
	{
		// add the patients in the list to the patients list to be returned	
		patients += patientList[0];
		int i = 1;
		// continues the loop until i equals the number of patients
		while(i < numPatients)
		{
			// add a new line in between the patients names that are going to be printed
			patients += "\n";
			// add the patients in the list to the patients list to be returned	
			patients += patientList[i];
			i++;
		}
	}
	//returns the list of patients
	return patients;
   }

// Functions: resetPatients
// Description:	Deletes the patientList and resets the numPatients

void Doctor::resetPatients()
{
	// Resets the list of patients.
    patientList = NULL;
    numPatients = 0;
}

// Function: setName
// Description: sets the name of the doctor

void Doctor::setName(string nameIn) 
{
	name = nameIn;
}

// Function: getName
// Description: returns the doctor name

string Doctor::getName() 
{
	return name;
}

// Function: getNumPatients
// Description: retrurns the number of patients for current doctor

int Doctor::getNumPatients() 
{
	return numPatients;
}

// Function: getPatientList
// Description: returns the list of patients for current doctor

string * Doctor::getPatientList() 
{
	return patientList;
}
   
// Functions: ~Doctor
// Description:	Destructor for the Doctor class - deletes patientList

Doctor::~Doctor()
{
	delete patientList;
}

// Functions: operator =
// Description:	Assignment operator that correctly 
//              makes a copy of a Doctor object with 
//              the list of patients

Doctor & Doctor::operator=(const Doctor & doc)
{
	//If it is the current doctor return the info associated with the doctor
	if (this == &doc)
    {
		return * this;
	}

	// copies the doctor object
    numPatients = doc.numPatients;
    patientList = doc.patientList;
    name = doc.name;
    return * this;
}
