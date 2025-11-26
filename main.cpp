
#include <iostream>
#include <fstream>
using namespace std;

#include "Course.h"
#include "Student.h"


int main()
{
    int choice;
    Course course;
    Student newStudent;
    int targetID;
    char targetName[100];


    ifstream course_in("kvy.txt");
    ofstream course_out("mnhhat.txt");
    do {
        cout << "\n========================================\n";
        cout << "      MENU QUAN LY KHOA HOC (" << course.ID << ")\n";
        cout << "========================================\n";
        cout << " 1. Nhap Course (File)         8. Loc SV K19 (File)\n";
        cout << " 2. Xuat Course (File)         9. Tim SV theo ID (File)\n";
        cout << " 3. Them SV (Add)              10. Tim SV theo Ten (File)\n";
        cout << " 4. Xoa SV (Remove)            11. Sort theo ID (File)\n";
        cout << " 5. Loc SV cung Thang Sinh     12. Sort theo First Name (File)\n";
        cout << " 6. Loc SV cung Ngay Sinh      13. Sort theo GPA (File)\n";
        cout << " 7. Loc SV Du tuoi Lai Xe      14. Sort theo DOB (File)\n";
        cout << " 0. Thoat chuong trinh\n";
        cout << "----------------------------------------\n";
        cout << "Nhap lua chon: ";

        if (!(cin >> choice)) break;

        if (!course_out.is_open()) {
            course_out.open("mnhhat.txt", ios::app);
        }

        switch (choice) {
        case 1:
            course_in.open("kvy.txt");
            courseinput(course_in, course);
            course_in.close();
            break;
        case 2: courseoutput(course_out, course); break;
        case 3:
            inputstudent(newStudent);
            add(course, newStudent);
            break;
        case 4:
            cout << "Nhap ID SV can xoa: "; cin >> targetID;
            del(course,  newStudent); break;
        case 5: samemonth(course_out, course); break;
        case 6: samedate(course_out, course); break;
        case 7: driving(course_out, course); break;
        case 8: k19(course_out, course); break;
        case 9:
            cout << "Nhap ID SV can tim: "; cin >> targetID;
            findByID(course, targetID, course_out); break;
        case 10:
            cout << "Nhap Ten SV can tim: ";
            cin.ignore(100, '\n');
            cin.getline (targetName,100);
            givenname(targetName, course_out, course); break;
        case 11: sort_id(course_out, course); break;
        case 12: sort_first(course_out, course); break;
        case 13: sort_gpa(course_out, course); break;
        case 14: sort_dob(course_out, course); break;
        case 0: break;
        default: cout << "Lua chon khong hop le.\n"; break;
        }
        cout.flush();
    } while (choice != 0);
    if (course_out.is_open()) course_out.close();
}