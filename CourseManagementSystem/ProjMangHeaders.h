#ifndef PROJMANGHEADERS_H_INCLUDED
#define PROJMANGHEADERS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <windows.h>

using namespace std;

struct student_struct{
    int id,nofc;
    float grade;
    char name[50],course_name[50];
};
struct course_struct{
  int id,Enrolled_students=0;
  char course_name[50],prof_name[50];
};

//The Courses
void course_add();
void course_display();
void all_stud_in_course(string course,string stud[],int grad[]);
void course_search();
void dlet_course_from_stud(string name,string want);
void course_delet();
void course_edit();

// The Final Table
void get_stud(int id[],string arr[],int &c);
void get_stud_grade(int id,string arr[],int grad[],int &c);
void get_course(string arr[],int &c);
void my_final_table();
void course_choose();
void student_choose();

//The students
void student_add();
void student_display();
void student_search();
void student_delete();
void display_one_stud(int n,bool &found);
void student_edit();
void course_display_in_student_add(string arr[],int &c);

//The GUI
void chang_color(int x);
void cler(int x);
void cord(int x,int y);
void load();
void thank_you();

#endif // PROJMANGHEADERS_H_INCLUDED
