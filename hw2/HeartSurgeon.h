/*
 * =====================================================================================
 *
 *       Filename:  HeartSurgeon.h
 *
 *    Description:  Header file for the HeartSurgeon class.
 *
 *        Version:  1.0
 *        Created:  11/14/2016 10:54:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tyler Jewell
 *         E-Mail:  tjj0013@auburn.edu
 *
 * =====================================================================================
 */

#include <string>
#include "SurgerySchedule.h"
#include "Doctor.h"
   
class HeartSurgeon : public Doctor
{
public:
	HeartSurgeon(string nameIn, int numPatientsIn, string * patientsIn)
		: Doctor(nameIn, numPatientsIn, patientsIn){};
    HeartSurgeon(string nameIn, int numPatientsIn, string * patientsIn, int numSurgIn, SurgerySchedule *scheduleIn)
      	: Doctor(nameIn, numPatientsIn, patientsIn) {schedule = scheduleIn; numSurgeriesScheduled = numSurgIn;};

    void input(int, string*, int, SurgerySchedule*);
    string patientOutput();
	SurgerySchedule * getSurgerySchedule();
    void resetSurgery();
    HeartSurgeon& operator=(const HeartSurgeon & doc);
    ~HeartSurgeon();

private:
	int numSurgeriesScheduled; 
    SurgerySchedule * schedule;
};
