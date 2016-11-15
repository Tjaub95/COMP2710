/*
 * =====================================================================================
 *
 *       Filename:  SurgerySchedule.h
 *
 *    Description:  Header file for the SurgerySchedule class.
 *
 *        Version:  1.0
 *        Created:  11/14/2016 10:56:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tyler Jewell
 *         E-Mail:  tjj0013@auburn.edu
 *
 * =====================================================================================
 */

#include <string>

using namespace std;

class SurgerySchedule
{
public:
	SurgerySchedule();
	SurgerySchedule(string, string);
	string getName();
    string getDate();
    void setName(string);
    void setDate(string);
    SurgerySchedule & operator=(const SurgerySchedule & doc);

private:
	string patient;
    string surgeryDate;
};
