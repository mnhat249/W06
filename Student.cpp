#include <iostream>
#include <fstream>
using namespace std;
#include "Student.h"


void inputstudent(Student& a) {
	cout << "Nhap cac thong tin can thiet cua sinh vien(ID,fullname,gpa,addres,dob): " << endl;
	cin >> a.id;
	cin >> a.fullname;
	cin >> a.gpa;
	cin >> a.address;
	cin >> a.dob.day >> a.dob.month >> a.dob.year;
}
void outputstudent(ofstream& fout,const Student& a) {
	fout << "Thong tin cua sinh vien yeu cau:" << endl;
	fout << "ID: " << a.id << endl;
	fout << "fullname: " << a.fullname << endl;
	fout << "address: " << a.address << endl;
	fout << "DateOfBirth " << a.dob.day << "/" << a.dob.month << "/" << a.dob.year << endl;
}


