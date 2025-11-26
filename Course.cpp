#include <iostream>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
using namespace std;

#include "Course.h"
#include "Student.h"

Date currentdate = { 18,11,2025 };

void courseinput(ifstream& fin, Course& b) {
	fin >> b.ID;
	fin >> b.name;
	fin >> b.max_student >> b.min_student;
	fin >> b.current;
	for (int i = 0; i < b.current; i++) {
		inputstudent(b.students[i]);
	}
}
void courseoutput(ofstream& fout, Course& b) {
	fout << "ID: " << b.ID << endl;
	fout << "Ten khoa hoc: " << b.name << endl;
	fout << "So luong SV toi da: " << b.max_student << endl;
	fout << "So luong SV toi thieu: " << b.min_student << endl;
	fout << "So luong SV hien tai: " << b.current << endl;
		for (int i = 0; i < b.current; ++i) {
			fout << "Sinh vien thu " << i << ":" << endl;
			outputstudent(fout, b.students[i]);
		}
    fout.close();
}
void add(Course& b,Student& a) {
	if (b.current < b.max_student) {
		b.students[b.current] = a;
		b.current++;
	}
	else {
		cout << "Khong the them hoc sinh" << endl;
	}
}
void del(Course& b,Student& a) {
	int index = -1;
	for (int i = 0; i < b.current; i++) {
		if (b.students[i].id == a.id) {
			index = i;
			break;
		}
	}
	if (index!=-1){
		for (int i = index; i < b.current; i++) {
			b.students[i] = b.students[i + 1];
		}
		b.current--;
		cout << "Da xoa sinh vien co id " << a.id << endl;
	}
	else {
		cout << "Khong the tim thay thong tin sinh vien de xoa.";
	}
}
void samemonth (ofstream& fout, Course& b) {
	cout << "Sinh vien co thang sinh trung voi thang nay :" << endl;
	for (int i = 0; i < b.current; i++) {
		if (b.students[i].dob.month == currentdate.month) {
			outputstudent(fout, b.students[i]);
		}
	}
}
void samedate(ofstream& fout, Course& b) {
	cout << "Sinh vien co thang sinh trung voi ngay nay :" << endl;
	for (int i = 0; i < b.current; i++) {
		if (b.students[i].dob.day == currentdate.day && b.students[i].dob.month == currentdate.month) {
			outputstudent(fout, b.students[i]);
		}
	}
}
bool license(Date dob) {
	if (2025 - dob.year > currentdate.year) {
		return true;
	}
	if (2025 - dob.year < currentdate.year) {
		return false;
	}
	else {
		if (currentdate.month - dob.month > 0) {
			return true;
		}
		if (dob.month < currentdate.month) {
			return false;
		}
		else {
			if (dob.day >= currentdate.day) {
				return false;
			}
			else return true;
		}
	}
}
void driving(ofstream& fout, Course& b) {
	fout << "Danh sach sinh vien du tuoi co GPLX:" << endl;
	for (int i = 0; i < b.current; i++) {
		if (license(b.students[i].dob)) {
			outputstudent(fout, b.students[i]);
		}
	}
}
void k19(ofstream& fout, Course& b) {
	fout << "Danh sach sinh vien trong lop K19:" << endl;
	for (int i = 0; i < b.current; i++) {
		if (b.students[i].id % 1000000 == 19) {
			outputstudent(fout, b.students[i]);
		}
    }
}
void findByID(Course b, int targetID, ofstream& fout) {
	int a = 0;
	for (int i = 0; i < b.current; i++) {
		if (targetID == b.students[i].id) {
			outputstudent(fout, b.students[i]);
			a++;
		}
	}
	if (a == 0) fout << "Khong tim thay sinh vien.";
}
void givenname(char given[], ofstream& fout, Course& b) {
	bool found = false;
	for (int i = 0; i < b.current; i++) {
		for (int j = 0; j < strlen(b.students[i].fullname); j++) {
			b.students[i].fullname[j] = tolower(b.students[i].fullname[j]);
		}
		if (strstr(given, b.students[i].fullname)) {
			bool found = true;
			outputstudent(fout, b.students[i]);
		}
	}
	if (!found) {
		fout << "Khong tim thay sinh vien.";
	}
}
void sort_id(ofstream& fout, Course& b) {
	for (int i = 0; i < b.current; i++) {
		for (int j = i + 1; j < b.current; j++) {
			if (b.students[i].id > b.students[j].id) {
				Student temp = b.students[i];
				b.students[i] = b.students[j];
				b.students[j] = temp;
			}
		}
	}
	fout << "Danh sach sap xep theo ID:" << endl;
	for (int i = 0; i < b.current; i++) {
		outputstudent(fout, b.students[i]);
	}
}

void getFirstName(const char full[], char first[]) {
	int i = strlen(full) - 1;
	while (i >= 0 && full[i] != ' ') i--;
	strcpy(first, full + i + 1);
}

void sort_first(ofstream& fout, Course& b) {
	char f1[50], f2[50];

	for (int i = 0; i < b.current - 1; i++) {
		for (int j = i + 1; j < b.current; j++) {
			getFirstName(b.students[i].fullname, f1);
			getFirstName(b.students[j].fullname, f2);
			if (strcmp(f1, f2) > 0){
				Student temp = b.students[i];
		     	b.students[i] = b.students[j];
			    b.students[j] = temp;
		     }
		}
	}
	for (int i = 0; i < b.current; i++) {
		outputstudent(fout, b.students[i]);
	}
}
void sort_gpa(ofstream& fout, Course& b){
	for (int i = 0; i < b.current - 1; i++) {
		for (int j = i + 1; j < b.current; j++) {
			if (b.students[i].gpa < b.students[j].gpa) {
				Student temp = b.students[i];
				b.students[i] = b.students[j];
				b.students[j] = temp;
			}
		}
	}
	for (int i = 0; i < b.current; i++) {
		outputstudent(fout, b.students[i]);
	}
}
int compare2dates(Date a, Date b) {   //a nho tuoi hon b thi return 1
	if (a.year > b.year) return 1;
	else if (a.year < b.year) return -1;
	else {
		if (a.month > b.month) return 1;
		else if (a.month < b.month) return -1;

		else {
			if (a.day >= b.day) return 1;
			else return -1;
		}
	}
}
void sort_dob(ofstream& fout, Course& b) {
	for (int i = 0; i < b.current - 1; i++) {
		for (int j = i + 1; j < b.current; j++) {
			if (compare2dates(b.students[i].dob, b.students[j].dob) == 1) {
				Student temp = b.students[i];
				b.students[i] = b.students[j];
				b.students[j] = temp;
			}
		}
	}
	for (int i = 0; i < b.current; i++) {
		outputstudent(fout, b.students[i]);
	}
}