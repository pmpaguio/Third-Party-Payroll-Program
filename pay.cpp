// Paul Paguio
//Section 1
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <vector>
#include "person.cpp"
using namespace std;

void readData(vector<Person> &empVect)
{
	ifstream theFile;
	theFile.open("input.txt");
	string inLine;

	int empId;
	string fName, lName, compName;
	float pRate, wHours;
	while (theFile)
	{
		theFile >> fName >> lName >> empId >> compName >>wHours >> pRate;
    if (!theFile)
		  break;
		Person newPerson;
		newPerson.setFirstName(fName);
		newPerson.setLastName(lName);
		newPerson.setEmployeeId(empId);
		newPerson.setCompanyName(compName);
		newPerson.setPayRate(pRate);
		newPerson.setHoursWorked(wHours);
		empVect.push_back(newPerson);
	}

	theFile.close();
}

void getCompanies (vector<Person> &empVect, vector<string> &compVect)
{
	for (int i = 0; i < empVect.size(); i++)
	{
		bool recFound = false;
		for (int j = 0; j < compVect.size(); j++)
		{
			if (empVect.at(i).getCompanyName() == compVect.at(j))
			{
				recFound = true;
				break;
			}
		}
		if (!recFound)
			compVect.push_back(empVect.at(i).getCompanyName());
	}
}

void printHighestPaid (vector<Person> &empVect, vector<string> &compVect)
{
	int ix = 0;
	float total = empVect.at(0).totalPay();
	for (int i = 1; i < empVect.size(); i++)
	{
		if (empVect.at(i).totalPay() > total)
		{
				ix = i;
				total = empVect.at(i).totalPay();
		}
	}
	cout << "Highest paid: " << empVect.at(ix).fullName() << endl;
	cout << "Employee ID: " << empVect.at(ix).getEmployeeId() << endl;
	cout << "Employer: " << empVect.at(ix).getCompanyName() << endl;
	cout << "Total Pay: $" << empVect.at(ix).totalPay() << endl;
}

void seperateAndSave (vector<Person> &empVect, vector<string> &compVect)
{
	for (int i = 0; i < compVect.size(); i++)
	{
		ofstream theFile;
		string strFileName = compVect.at(i) + ".txt";
		char * fileName = new char[strFileName.size() + 1];
		strcpy(fileName,strFileName.c_str());
		theFile.open(fileName);
		cout << fixed << showpoint << setprecision(2);
		float total = 0;
		for (int j = 0; j < empVect.size(); j++)
		{
			if (empVect.at(j).getCompanyName() == compVect.at(i))
			{
				theFile << empVect.at(j).fullName() << " " << empVect.at(j).getEmployeeId() << " "
					<< empVect.at(j).getCompanyName() << " " << empVect.at(j).totalPay() << endl;
				total += empVect.at(j).totalPay();
			}
		}
		theFile << "Total $" << total << endl;
		theFile.close();
	}
}

int main()
{
	vector<Person> employees;
	vector<string> companyNames;

	readData(employees);
	getCompanies(employees, companyNames);
	printHighestPaid(employees, companyNames);
	seperateAndSave(employees, companyNames);

	return 0;
}
