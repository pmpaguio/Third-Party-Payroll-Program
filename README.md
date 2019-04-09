# Third-Party-Payroll-Program

This program is for a third-party payroll clearinghouse which contains an employee pay feature and a company total pay feature.  This program deals with a text file called "input.txt." which stores data of each record in the company.  Each record contains a a first name, last name, employee ID, company name, hours worked, and pay rate per hour.

Each record is stored inside a class called Person.  This class is declared in a header file called person.h.  Then we make a seperate file called person.cpp.  This file contains proper definitions for all function declarations in the header file. 

Another file called pay.cpp contains the main function.  A vector called employees used to store the employee data when reading from the file (employees will be of the Person class).

A function called printHighestPaid must find and output (cout) the full name, employee ID, company name, and total pay of the person who was paid the highest amount this statement. 

Lastly, a function called separateAndSave must write the payroll information to multiple text files - one for each company.
