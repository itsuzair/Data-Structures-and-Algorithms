#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Function prototypes
void displayMenu();
int validateId(int, int, struct Student []);
void insertStudent(int &, int, struct Student []);
void deleteStudent(int &, struct Student []);
void modifyStudent(int &, struct Student []);
void searchStudent(int, struct Student []);
void printStudents(int, struct Student[]);
bool endProgram(int, int, struct Student[]);
void readData(int &, int &, Student * &, ifstream &);

//Structures
struct Date
{
	int day, month, year;
};
struct Student
{
	int id;
	int marks[5];
	char name[50];
	Date dob;
};

//Main function
int main() {
	//initialization
	int maxStudents = 0;
	int enrolledStudents = 0;
	char option = '0';
	bool keepRunning = true;
	bool loadedFromFile = false;
	Student *students;

	//check if file exists and load if required else take user input
	ifstream file("students.dat", ios::in | ios::binary);
	if (file.is_open()) {
		char option;
		do {
			cout << "Student data file found." << endl << "Do you want to read data from file ? [Y/N] : ";
			cin >> option;
			switch (option)
			{
			case 'y': case 'Y':
				readData(enrolledStudents, maxStudents, students, file);
				loadedFromFile = true;
				break;
			case 'n': case 'N':
				break;
			default:
				cout << "Please enter Y or N" << endl;
				break;
			}
		} while (option != 'Y' && option != 'y' && option != 'N' && option != 'n');
		file.close();
	}
	if(!loadedFromFile){
		do {
			cout << "Please enter no of students : ";
			cin >> maxStudents;
		} while (maxStudents <= 0);
		students = new Student[maxStudents];
	}

	//Display menu and respond to option
	displayMenu();
	while (keepRunning)
	{
		cout << endl << "Enter operation : ";
		cin >> option;
		switch (option)
		{
		case 'i': case 'I':
			insertStudent(enrolledStudents, maxStudents, students);
			break;
		case 'd': case 'D':
			deleteStudent(enrolledStudents, students);
			break;
		case 'm': case 'M':
			modifyStudent(enrolledStudents, students);
			break;
		case 's': case 'S':
			searchStudent(enrolledStudents, students);
			break;
		case 'p': case 'P':
			printStudents(enrolledStudents, students);
			break;
		case 'q': case 'Q':
			keepRunning = endProgram(enrolledStudents, maxStudents, students);
			if (keepRunning) {
				cout << "There was an error writing to file" << endl;
				displayMenu();
			}
			break;
		default:
			cout << "Please enter a valid option" << endl;
			displayMenu();
			break;
		}
	}
}

//Menu display function
void displayMenu() {
	cout << endl;
	cout << "\t            Operations" << endl << endl;
	cout << "\tInsert           :              [I/i]" << endl;
	cout << "\tDelete           :              [D/d]" << endl;
	cout << "\tModify           :              [M/m]" << endl;
	cout << "\tSearch           :              [S/s]" << endl;
	cout << "\tPrint            :              [P/p]" << endl;
	cout << "\tQuit             :              [Q/q]" << endl;
}

//Function to check if user entered id exists in array
int validateId(int id, int enrolledStudents, Student students[]) {
	int first = 0;
	int last = enrolledStudents - 1;
	int mid = 0;
	while (first <= last) {
		mid = (first + last) / 2;
		if (students[mid].id < id) {
			first = mid + 1;
		} else if (students[mid].id > id) {
			last = mid - 1;
		} else {
			return mid;
		}
	}
	return -1;
}

//Function to sort students by id
void Sort(int enrolledStudents, Student students[]) {
	Student temp;
	int min_index = 0;
	for (int i = 0; i < enrolledStudents - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < enrolledStudents; j++) {
			if (students[min_index].id > students[j].id) {
				min_index = j;
			}
		}
		temp = students[i];
		students[i] = students[min_index];
		students[min_index] = temp;
	}
}

//Function to add new student data
void insertStudent(int &enrolledStudents, int maxStudents, Student students[]) {
	if (enrolledStudents < maxStudents) {
		int studentId = 0;
		cout << endl << "Enter data for student" << endl;
		do {
			cout << "Enter students's id : ";
			cin >> studentId;
		} while (studentId <= 0);
		int idExists = validateId(studentId, enrolledStudents, students);
		if (idExists == -1) {
			Student s;
			s.id = studentId;
			cout << "Enter student's name : ";
			cin.ignore();
			cin.getline(s.name, 50);
			do {
				cout << "Enter student's date of birth : ";
				cin >> s.dob.day;
			} while (s.dob.day < 0 || s.dob.day > 31);
			do {
				cout << "Enter student's month of birth : ";
				cin >> s.dob.month;
			} while (s.dob.month < 0 || s.dob.month > 12);
			do {
				cout << "Enter student's year of birth : ";
				cin >> s.dob.year;
			} while (s.dob.year < 1990 || s.dob.year > 2000);
			cout << "Enter student's marks" << endl;
			for (int j = 0; j < 5; j++) {
				do {
					cout << "Enter marks of student in subject " << j + 1 << " : ";
					cin >> s.marks[j];
				} while (s.marks[j] < 0 || s.marks[j]>100);
			}
			students[enrolledStudents] = s;
			enrolledStudents++;
			cout << "Student record inserted successfully" << endl;
			Sort(enrolledStudents, students);
		} else {
			cout << "This id is already in use" << endl;
		}
	}
	else {
		cout << "Max students enrolled. No new entries can be inserted" << endl;
	}
}

//Function to delete student data
void deleteStudent(int &enrolledStudents, Student students[]) {
	int id;
	cout << endl << "Enter id of student to delete : ";
	cin >> id;
	int foundAt = validateId(id, enrolledStudents, students);
	if (foundAt != -1) {
		for (int i = foundAt; i < enrolledStudents; i++) {
			students[i] = students[i+1];
		}
		enrolledStudents--;
		cout << "Student record deleted successfully" << endl;
	} else {
		cout << "No such student with provided id found" << endl;
	}
}

//Function to modify a student's name
void modifyName(Student &s) {
	cout << "Enter new name for student : ";
	cin.ignore();
	cin.getline(s.name, 50);
	cout << "Student record modified successfully" << endl;
}

//Function to modify a student's marks
void modifyMarks(Student &s) {
	int subjectId = 0;
	do {
		cout << "Enter subject id to modify marks of (1-5) : ";
		cin >> subjectId;
	} while (subjectId < 1 || subjectId > 5);
	do {
		cout << "Enter marks of student in subject " << subjectId << " : ";
		cin >> s.marks[subjectId - 1];
	} while (s.marks[subjectId - 1] < 0 || s.marks[subjectId - 1]>100);
	cout << "Student record modified successfully" << endl;
}

//Function to modify a student's Date of birth
void modifyDob(Student &s) {
	char option;
	cout << endl;
	cout << "\tDate    :   [D/d]" << endl;
	cout << "\tMonth   :   [M/m]" << endl;
	cout << "\tYear    :   [Y/y]" << endl;
	cout << "Select attribute you want to modify : ";
	cin >> option;
	switch (option)
	{
	case 'D' : case 'd':
		do {
			cout << "Enter new date of birth : ";
			cin >> s.dob.day;
		} while (s.dob.day < 0 || s.dob.day > 31);
		break;
	case 'M' : case 'm':
		do {
			cout << "Enter new month of birth : ";
			cin >> s.dob.month;
		} while (s.dob.month < 0 || s.dob.month > 12);
		break;
	case 'Y' : case 'y':
		do {
			cout << "Enter new year of birth : ";
			cin >> s.dob.year;
		} while (s.dob.year < 1990 || s.dob.year > 2000);
		break;
	default:
		cout << "Invalid option selected" << endl;
		displayMenu();
		break;
	}
}

//Handler function for modification of student data
void modifyStudent(int &enrolledStudents, Student students[]) {
	int id;
	cout << endl << "Enter id of student to modify : ";
	cin >> id;
	int foundAt = validateId(id, enrolledStudents, students);
	if (foundAt != -1) {
		cout << endl;
		cout << "\tName            :   [N/n]" << endl;
		cout << "\tMarks           :   [M/m]" << endl;
		cout << "\tDate of Birth   :   [D/d]" << endl;
		char option;
		cout << endl << "Select field you want to modify : ";
		cin >> option;
		switch (option)
		{
		case 'N' : case 'n':
			modifyName(students[foundAt]);
			break;
		case 'M' : case 'm':
			modifyMarks(students[foundAt]);
			break;
		case 'D': case 'd' :
			modifyDob(students[foundAt]);
			break;
		default:
			cout << "Invalid option selected" << endl;
			displayMenu();
			break;
		}

	} else {
		cout << "No such student with provided id found" << endl;
	}
}

//Function to print a student's data
void searchStudent(int enrolledStudents, Student students[]) {
	int id;
	cout << endl << "Enter id of student to search : ";
	cin >> id;
	int foundAt = validateId(id, enrolledStudents, students);
	if (foundAt != -1) {
		cout << endl << endl;
		Student student = students[foundAt];
		cout << setw(10) << left << "ID" <<
			setw(50) << left << "Name" <<
			setw(15) << left << "Date of Birth\t" <<
			setw(15) << "Marks" << endl;
		cout << right << setfill('_') << setw(110) << '\0' << setfill(' ') << endl << endl;
		cout << setw(10) << left << student.id <<
			setw(50) << left << student.name <<
			setfill('0') << setw(2) << right << student.dob.day << "/" <<
			setw(2) << right << student.dob.month << setfill('\0') << "/" <<
			setw(15) << left << student.dob.year;
			for (int i = 0; i < 5; i++) {
				if (i < 4) {
					cout << setfill('0') << setw(2) << right << student.marks[i] << ", ";
				} else {
					cout << setw(2) << right << student.marks[i] << setfill('\0');
				}
			}
			cout << endl;
	} else {
		cout << "No such student with provided id found" << endl;
	}
}

//Function to print all students' data
void printStudents(int enrolledStudents, Student students[]) {
	cout << endl << endl <<
		setw(10) << left << "ID" <<
		setw(50) << left << "Name" <<
		setw(15) << left << "Date of Birth\t" <<
		setw(15) << "Marks" << endl;
	cout << right << setfill('_') << setw(110) << '\0' << setfill(' ') << endl << endl;
	for (int i = 0; i < enrolledStudents ; i++)
	{
		cout << setw(10) << left << students[i].id <<
			setw(50) << left << students[i].name <<
			setfill('0') << setw(2) << right << students[i].dob.day << "/" <<
			setw(2) << right << students[i].dob.month << setfill('\0') << "/" <<
			setw(15) << left << students[i].dob.year;
		for (int j = 0; j < 5; j++) {
			if (j < 4) {
				cout << setfill('0') << setw(2) << right << students[i].marks[j] << ", ";
			}
			else {
				cout << setw(2) << right << students[i].marks[j] << setfill('\0');
			}
		}
		cout << endl << endl;
	}
}

//Function called before exiting program to store data on file
bool endProgram(int enrolledStudents, int maxStudents, Student students[]) {
	bool status = true;
	ofstream file("students.dat", ios::out | ios::binary);
	if (file.is_open()) {
		file.write((char *) &enrolledStudents, sizeof(enrolledStudents));
		file.write((char *) &maxStudents, sizeof(maxStudents));
		for (int i = 0; i < enrolledStudents; i++) {
			file.write((char *) &students[i].name, sizeof(students[i].name));
			file.write((char *) &students[i].id, sizeof(students[i].id));
			for (int j = 0; j < 5; j++) {
				file.write((char *) &students[i].marks[j], sizeof(students[i].marks[j]));
			}
			file.write((char *) &students[i].dob.day, sizeof(students[i].dob.day));
			file.write((char *) &students[i].dob.month, sizeof(students[i].dob.month));
			file.write((char *) &students[i].dob.year, sizeof(students[i].dob.year));
		}
		status = false;
		file.close();
		delete [] students;
	}
	return status;
}

//Function used to read data from file
void readData(int &enrolledStudents, int &maxStudents, Student * &students, ifstream &file) {
	file.read((char *) &enrolledStudents, sizeof(enrolledStudents));
	file.read((char *) &maxStudents, sizeof(maxStudents));
	cout << "Data read from file." << endl;
	cout << "There are " << enrolledStudents << " Students enrolled" << endl;
	cout << "Maximum capacity of class is " << maxStudents << " Students" << endl;
	students = new Student[maxStudents];
	for (int i = 0; i < enrolledStudents; i++) {
		file.read((char *) &students[i].name, sizeof(students[i].name));
		file.read((char *) &students[i].id, sizeof(students[i].id));
		for (int j = 0; j < 5; j++) {
			file.read((char *) &students[i].marks[j], sizeof(students[i].marks[j]));
		}
		file.read((char *) &students[i].dob.day, sizeof(students[i].dob.day));
		file.read((char *) &students[i].dob.month, sizeof(students[i].dob.month));
		file.read((char *) &students[i].dob.year, sizeof(students[i].dob.year));
	}
}