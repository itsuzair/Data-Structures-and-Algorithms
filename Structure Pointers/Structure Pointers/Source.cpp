#include <iostream>
using namespace std;

//const int students = 10;
//const int subjects = 5;

struct Date
{
	int day, month, year;
};

struct Student
{
	//int marks[subjects];
	int marks;
	char name[30];
	//Date dob;
	Student * next;
};

int main() {
	/*

	//Basic usage
	Student s1 = { 25, "abc" };
	Student s2 = { 24, "xyz"};

	//Pointer for structure
	Student *ptr = &s1;
	cout << (*ptr).marks;
	delete ptr;

	//Initializing structures
	Student s1 = { 30, "xyz", 10, 12, 1984 };
	cout << s1.name[1] << endl;

	//Dynamic structure with pointer and initialization
	Student *ptr = new Student;
	*ptr = { 25, "abc" };
	cout << ptr->name;
	cout << endl;
	delete ptr;

	//Array of structures
	Student multipleStudents[students];
	for (int i = 0; i < students; i++) {
		cout << "Enter student " << i << "'s Name : ";
		cin >> multipleStudents[i].name;
		cout << "Enter student " << i << "'s Date of birth : ";
		cin >> multipleStudents[i].dob.day;
		cout << "Enter student " << i << "'s Month of birth : ";
		cin >> multipleStudents[i].dob.month;
		cout << "Enter student " << i << "'s Year of birth : ";
		cin >> multipleStudents[i].dob.year;
		for (int j = 0; j < subjects; j++) {
			cout << "Enter student " << i << "'s Marks for subject " << j << " : ";
			cin >> multipleStudents[i].marks[j];
		}
		cout << endl;
	}

	for (int i = 0; i < students; i++) {
		cout << multipleStudents[0].name << "'s Data : " << endl;
		cout << "DOB : " << multipleStudents[0].dob.day << "/" << multipleStudents[0].dob.month << "/" << multipleStudents[0].dob.year << endl <<
			"Obtained marks as follows :" << endl;
		for (int j = 0; j < subjects; j++) {
			cout << multipleStudents[i].marks[j] << endl;
		}
		cout << endl;
	}

	//Pointer to structure Basic
	Student s1 = { 25, "Uzair"};
	Student s2 = { 30, "Zia" };
	s1.next = &s2;
	cout << s1.next->name << s1.next->marks << endl;

	delete s1.next;
	delete s1.next;

	//Pointer to structure, Dynamic allocation.
	Student * first = new Student;
	*first = { 25, "Uzair" };
	first->next = new Student;
	*first->next = { 30, "Zia" };
	cout << first->name << endl << first->next->name << endl;
	delete first->next->next;
	delete first->next;

	*/
	//Pointer to structure, Dynamic allocation. List of structs
	//creating students
	Student *first = new Student; //first student
	Student *base = first; //creating a base case for student, setting first to base
	for (int i = 0; i < 3; i++) {
		//loop for no. of students to create
		base->next = new Student; //create a new student and make base's next point to this new student
		base = base->next; //change base to newly created student
	}
	//getting data for students
	base = first;
	for (int i = 0; i < 3; i++) {
		cout << "Enter data for student " << i << endl;
		cout << "Name of student " << i << " : ";
		cin >> base->name;
		cout << "Marks of student " << i << " : ";
		cin >> base->marks;
		base = base->next;
	}
	//printing all data
	base = first;
	for (int i = 0; i < 3; i++) {
		cout << base->name << " obtained " << base->marks << " marks." << endl;
		base = base->next;
	}
	return 0;
}