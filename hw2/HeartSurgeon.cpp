/*
 * =====================================================================================
 *
 *       Filename:  HeartSurgeon.cpp
 *
 *    Description:  This class allows for a Heart Surgeon object to be created with
 *                  patients and surgeries
 *
 *        Version:  1.0
 *        Created:  11/14/2016 10:59:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tyler Jewell
 *         E-Mail:  tjj0013@auburn.edu
 *
 * =====================================================================================
 */

#include "HeartSurgeon.h"

// Functions: input
// Description:	adds all input from the user. adds the patients 
//              in the parameter to the list of patients, and changes 
//              the number of patients, and adds everything for surgeries scheduled

void HeartSurgeon::input(int numIn, string * patientsIn, int numSurgIn, SurgerySchedule * scheduleIn)
{
	int i = 0, num = numIn, j = 0;
   	// creates a list for the patientInfo
    string * patientInfo = new string[numPatients + numIn];

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

    patientList = patientInfo;
    patientInfo = NULL;
    numPatients += numIn;
      
   	//copy of list fo surgeries scheduled
	SurgerySchedule * temp = new SurgerySchedule[numSurgeriesScheduled + numSurgIn];

	i = 0, j = 0;

	while(i < numSurgeriesScheduled)
	{
		temp[i] = schedule[i];
	}

	while(j < num)
	{
		temp[numSurgeriesScheduled + i] = scheduleIn[i];
	}

    schedule = temp;
    temp = NULL;
    numSurgeriesScheduled += numSurgIn;
}
	
// Functions: patientOutput
// Description:	returns the doctors patients and scheduled surgeries

string HeartSurgeon::patientOutput()
{
	string patient = "";

	//checks to see if doctor has patients
    if (numPatients > 0)
    {
		//prints the list of patients
		patient += "";

		int i = 0;
		while (i < numPatients)
		{
			//adds the patients to the list to be returned
			patient += "\n";
            patient += patientList[i];
			i++;
		}
     }
     //checks to see if the number of surgeries scheduled is greater than zero
     if (numSurgeriesScheduled > 0)
     {
		 patient += "\n\nSurgeries Scheduled:\n";

		 int i = 0;
		 while(i < numSurgeriesScheduled)
		 {
			 //adds the surgeries scheduled to the list to be returned
			 patient += "\n";
             patient += schedule[i].getDate();
             patient += "\t";
             patient += schedule[i].getName();
			 i++;
		 }
      }
   	
	 //returns the patients of the doctor and the surgeries scheduled for the doctor
	 return patient;
}

// Functions: resetSurgery
// Description:	resets the list of the doctors surgery

void HeartSurgeon::resetSurgery()
{
	schedule = NULL;
    numSurgeriesScheduled = 0;
}

// Functions: operator =
// Description:	Assignment operator that correctly 
//              makes a copy of a HeartSurgeon object with 
//              the list of patients

HeartSurgeon& HeartSurgeon::operator=(const HeartSurgeon & doc)
{
	//If it is the current doctor return the info associated with the doctor
	if (this == &doc)
    {
		return *this;
    }

	// copies the doctor object
    numPatients = doc.numPatients;
    delete patientList;
    patientList = doc.patientList;
    numSurgeriesScheduled = doc.numSurgeriesScheduled;
    delete schedule;

	//copies the schedule object
    schedule = doc.schedule;
    name = doc.name;
    return * this;
}

//Function: getSurgerySchedule
//Description: retruns surgeries scheduled

SurgerySchedule * HeartSurgeon::getSurgerySchedule() 
{
	return schedule;
}

// Functions: ~HeartSurgeon
// Description:	Destructor for the HeartSurgeon class - deletes patientList and schedule

HeartSurgeon::~HeartSurgeon() 
{
	delete schedule, patientList;
}
