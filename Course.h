#pragma once
#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;

struct Course {
	char ID[20];
	char name[100];
	Student students[1000];
	int current;
	int max_student;
	int min_student;
};
void courseinput(ifstream&in ,Course& b);
void courseoutput(ofstream&out,Course& b);
void add(Course& b,Student& a);
void del(Course& b,Student& a);
void samemonth(ofstream& fout, Course& b);
void samedate(ofstream& fout, Course& b);
void driving(ofstream& fout,Course& b);
void k19(ofstream& fout, Course& b);
void findByID(Course b,int targetID,ofstream& fin);
void givenname(char given[], ofstream& fout, Course& b);
void sort_id(ofstream& fout, Course& b);
void sort_first(ofstream& fout, Course& b);
void sort_gpa(ofstream& fout, Course& b);
void sort_dob(ofstream& fout, Course& b);
