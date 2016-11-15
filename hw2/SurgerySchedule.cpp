/*
 * =====================================================================================
 *
 *       Filename:  SurgerySchedule.cpp
 *
 *    Description:  This class keeps track of the surgeries scheduled.
 *
 *        Version:  1.0
 *        Created:  11/14/2016 10:57:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tyler Jewell
 *   Organization:  tjj0013@auburn.edu
 *
 * =====================================================================================
 */

#include "SurgerySchedule.h"

//Function: SurgerySchedule (default constructor)
//Description: Sets patient name and surgerydate to empty strings

SurgerySchedule::SurgerySchedule()
{
	patient == "";
	surgeryDate == "";
}

//Function: SurgerySchedule (constructor)
//Description: sets the patient name and surgeryDate equal to the parameters

SurgerySchedule::SurgerySchedule(string nameIn, string dateIn) 
{
	patient = nameIn;
	surgeryDate = dateIn; 
}

//Function: setName
//Description: sets the name of the patient to the parameter

void SurgerySchedule::setName(string nameIn) 
{
	patient = nameIn;
}

//Function: getName
//Description: returns the name of the patient

string SurgerySchedule::getName() 
{
	return patient;
}

//Function: setDate
//Description: sets the date of the surgery to the parameter

void SurgerySchedule::setDate(string dateIn) 
{
	surgeryDate = dateIn;
}

//Function: getDate
//Description: returns the date of the surgery

string SurgerySchedule::getDate() 
{
	return surgeryDate;
}

// Functions: operator =
// Description:	The assignment operator for the SurgerySchedule 
//              class that copies over the appropriate data for 
//              the surgery

SurgerySchedule & SurgerySchedule::operator= (const SurgerySchedule & doc)
{
	//checks to see if it is the current doctor
	if (this == &doc)
    {
		return *this;
    }

	//copies patient name and surgery date
    patient = doc.patient;
    surgeryDate = doc.surgeryDate;
    return *this;
}
