#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct Date {
	int day;
	int month;
	int year;
};
struct Student {
	int id;
	char fullname[100];
	float gpa;
	char address[100];
	Date dob;
};

void inputstudent(Student& a);
void outputstudent(ofstream& fout, const Student& a);


