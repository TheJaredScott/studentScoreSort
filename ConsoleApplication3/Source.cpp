#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
	public:
	int grade;
	string name;
	Student(int, string);
	Student();
	void printvalues();
	string getname();
	int getgrade();
	void setname(string);
	void setgrade(int);



};

struct compare
{
	bool operator()(const Student& s1, const Student& s2)
	{
		return s1.grade < s2.grade;
	}
};

Student::Student() {

	grade = 0;
	name = "none";

}

Student::Student(int tempgrade, string tempname) {

	grade = tempgrade;
	name = tempname;
}

void Student::printvalues() {

	cout << getname() << ": " << getgrade() << endl;

}

string Student::getname() {

	return name;

}

int Student::getgrade() {

	return grade;

}

void Student::setname(string tempname) {

	name = tempname;

}

void Student::setgrade(int tempgrade) {

	grade = tempgrade;

}


vector<Student> students;
Student tempstudent;
string studentname;
int studentgrade;
int length;
int main() {


	int switcher = 0;
	cout << "Enter amount of students to enter" << endl;
	cin >> length;
	//create vector of students by promping user
	while (switcher < length) {
		cout << "Enter a student name, then grade. Enter 'exit' to exit" << endl;
		cin >> studentname;
		cin >> studentgrade;
		students.emplace_back(studentgrade, studentname);
		switcher++;
	}

	//make vector into heap using makeheap

	make_heap(students.begin(), students.end(), compare());
	sort_heap(students.begin(), students.end(), compare());

	//display students.back grade

	cout << "Highest grade: " << students.back().grade << endl;

	//display students[0]

	cout << "Lowest grade: " << students[0].grade << endl;

	//display students.range

	cout << "Range of grades: {";

	for (vector<Student>::iterator it = students.begin(); it != students.end(); it++) {

		cout << it->grade << ", ";

	}
	cout << "}" << endl;

	//use printvalues on students.back

	cout << "Student with highest grade: "; students.back().printvalues();
	cout << endl;

	//use printvalues on each member of vector
	cout << "All students and grades: " << endl;
	for (vector<Student>::iterator it = students.begin(); it != students.end(); it++) {
		it->printvalues();
	}

	system("PAUSE");

}

