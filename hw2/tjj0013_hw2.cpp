/*
 * =====================================================================================
 *
 *       Filename:  tjj0013_hw3.cpp
 *
 *    Description:  Driver program
 *
 *        Version:  1.0
 *        Created:  11/14/2016 11:07:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *    Compilation:  make hw2
 *
 *         Author:  Tyler Jewell
 *         E-Mail:  tjj0013@auburn.edu
 *
 * =====================================================================================
 */

#define UNIT_TESTING
#include "HeartSurgeon.h"
#include <iostream>
#include <string>

#ifdef UNIT_TESTING

using namespace std;

int main()
{
	Doctor * doc = new Doctor("Tyler Jewell", 0, NULL);
   
   // test adding doctor
      cout << "Doctor's name: " << doc->getName() << endl;
      cout << "Number of patients: " << doc->getNumPatients() << endl;
      doc->setName("Craig Shanks");
      cout << "Doctor's name: " << doc->getName() << endl;
      cout << endl;
   
   // test patient output
      cout << "Patient information:" << endl;
      cout << doc->patientOutput();
      cout << endl;
   
   //test adding patients to current doctor
      cout << "Please enter patients names:\n";
      string * patients = new string[2];
      patients[0] = "Joshua Carter";
      patients[1] = "Robert Beaty";
      doc->input(2, patients);
      cout << doc->patientOutput() << endl;
      cout << endl;
	  cout << "Patient information:" << endl;
      cout << doc->patientOutput();
      cout << endl << endl;

	  //tests deleting patients
	  doc->resetPatients();
	  cout << "Patient information:" << endl;
      cout << doc->patientOutput();
      cout << endl;
   
   //test adding patients to a new doctor
      string * morepatients = new string[4];
      morepatients[0] = "Kele Okereke";
      morepatients[1] = "Russal Lissack";
	  morepatients[2] = "Matt Tong";
	  morepatients[3] = "Damon Albarn";
      Doctor * newDoc = new Doctor("Kayla Edmondson", 4, morepatients);
      newDoc = doc;
      newDoc->input(4, morepatients);
      cout << newDoc->patientOutput();
      cout << endl;
  
   	// test creating heart surgeon and surgeries
      SurgerySchedule * schedule = new SurgerySchedule[2];
      schedule[0] = SurgerySchedule("Max Bemis", "11/16/16");
      schedule[1] = SurgerySchedule("Jesse Lacey", "11/18/16");
      HeartSurgeon * surgeon = new HeartSurgeon("Brian Sella", 2, morepatients, 2, schedule);
	  
	  // test patient output
      cout << surgeon->patientOutput();
      cout << endl;

	  //test deleting patients
      surgeon->resetPatients();
      
   	// test the assignment operator
      HeartSurgeon * surg;
      surg = surgeon;
      cout << surg->patientOutput();
	  cout << endl;
      
   	// test deleting everything from surgeon
      surg->resetSurgery();
      cout << surg->patientOutput();
      return 0;
   }

#else

int main()
{
	string docName, patientName;
	string * patientList = new string[1];
	
	cout << "Please enter doctor name: ";
	getline(cin, docName);

	Doctor * doc = new Doctor(docName, 0, NULL);

	cout << "Current Doctor " << doc->getName() << endl << endl;

	cout << "Please enter patients names: ";
	cin >> patientName;
	patientList[0] = patientName;
	doc->input(1, patientList);
	cout << doc->patientOutput() << endl << endl;
	doc->resetPatients();

	string docName2, patientname2;
	cout << "Please enter doctor name: ";
	cin >> docName2;

	Doctor * doc2 = new Doctor(docName2, 0, NULL);


	int i = 0;
	string * patientList2 = new string[5];
	while(i < 4)
	{
		cout << "Please enter patients names: ";
		cin >> patientname2;
		patientList2[i] = patientname2;
		i++;
	}

	doc->input(i + 1, patientList2);
	cout << doc->patientOutput();

	SurgerySchedule * schedule = new SurgerySchedule[3];
	i = 0;
	string patient, date;
	cout << "Schedule Surgeries:" << endl;
	while(i < 3)
	{
		cout << "Enter patient's name: ";
		cin >> patient;
		cout << "Enter date of surgery (M/DD/YY): ";
		cin >> date;
		schedule[i] = SurgerySchedule(patient, date);
		i++;
	}

	HeartSurgeon * surgeon = new HeartSurgeon("Dr. Bob", 5, patientList2, 2, schedule);
	cout << surgeon->patientOutput();
    cout << endl;

	return 1;
}
#endif
