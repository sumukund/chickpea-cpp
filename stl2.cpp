//--------------------------------------------------------------------
//
// Week 6 Homework
// CET 2200
// Sudarsna Mukund
//--------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

struct DataType 
{
	string lastname;	// Student's Last Name
	string firstname;	// Student's First Name

	string getKey () const
	{ return lastname; }  // Returns the key field
    
};

//---------Need to add code to overload operator <<

void operator << (ostream& out, struct DataType student){
	out << "\n" << student.firstname << " " << student.lastname;
}

//------- Need to add code to fix error C2784: 'bool __cdecl std::operator <

bool operator < (DataType lhs, DataType rhs)
{
return lhs.getKey() < rhs.getKey();
}


int main(void) 
{
	ifstream studentFile ("input.txt");  // Student file
	list <DataType> students;            // Students
	DataType currStudent;             // One Student (has firstname,lastname)

	// Read each line from input.txt:
    //Store the firstname and the lastname into 
    //the temporary student structure "currStudent".
	while(studentFile >> currStudent.firstname >> currStudent.lastname)

	// Push the current student into the list ("students") 
students.push_back(currStudent);

	// Use an iterator to print the unsorted list of students.
cout << "\n\nOriginal List:";

list<DataType>::iterator p = students.begin();
while(p != students.end()){
		cout << *p;
		p++;
	}

	// Sort the list of students.

students.sort();

	// Use an iterator to print the sorted list of students.
cout <<"\n\nsorting...........\n";
p = students.begin();
while(p != students.end()){
		cout << *p;
		p++;
	}
cout << "\n\nPress any key to continue \n";
return 0;
}
