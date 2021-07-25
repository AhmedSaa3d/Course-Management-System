#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <windows.h>

using namespace std;

/////GUI///
void chang_color(int x){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}
void cler(int x){
system ("cls");
chang_color(7);
cout<<"\t***************************************************\n";
cout<<"\t***\t\tWrite What is you want\t\t***\n";
cout<<"\t***************************************************\n";
chang_color(x);
}
void cord(int x,int y){
COORD mycord;
mycord.X=x;
mycord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),mycord);

}

struct student_struct{
    int id,nofc;
    float grade;
    char name[50],course_name[50];
};
struct course_struct{
  int id,Enrolled_students=0;
  char course_name[50],prof_name[50];
};

//////The students////////////
// write the students
void course_display_in_student_add(string arr[],int &c){
 course_struct course_data;
 ifstream course_file;
 course_file.open("courses_file.txt");
 cout<<"\t**************** Courses Data **********************\n";
 cout<<"\t\tCourse Name\tProf_Name\n";
 while(!course_file.eof()){
    char x; //for $
    course_file>>course_data.id;
    course_file>>x; //for $
    course_file.get(course_data.course_name,50,'$');
    course_file>>x; //for $
    course_file.get(course_data.prof_name,50,'$');
    course_file>>x; //for $
    course_file>>course_data.Enrolled_students;
    cout<<"\t\t"<<course_data.course_name<<"\t\t"<<course_data.prof_name<<endl;
    arr[c]=course_data.course_name;
    c++;
 }
cout<<"\t*************** Choose From Up *********************\n";
 course_file.close();
}
void student_add(){
cler(10);
string arr[20];int c=0;//34an nsearch el courses s7 wla l2

student_struct stud_data;//get data from the user
ofstream stud_file; //to write in the fill
stud_file.open("students_file.txt",ios::app);
cout<<"\n\t*************** Student Add ************************\n";
cout<<"\tEnter the sudent ID : ";
cin>>stud_data.id;
cin.ignore();
cout<<"\tEnter the sudent Name : ";
cin.getline(stud_data.name,50);
cout<<"\tEnter the N.O.C : ";
cin>>stud_data.nofc;
stud_file<<endl<<stud_data.id<<"$"<<stud_data.name<<"$"<<stud_data.nofc;
course_display_in_student_add(arr,c);
for(int i=0;i<stud_data.nofc;i++)//check for the course
{  bool ok=false;
    cin.ignore();
   do{
       cout<<"\tEnter the course name N "<<i+1<<" : ";
       cin.getline(stud_data.course_name,50);

       for(int j=0;j<c;j++){
        if(stud_data.course_name==arr[j]){
        cout<<"\tEnter the student grade in the course N "<<i+1<<" : ";
        cin>>stud_data.grade;
        stud_file<<"$"<<stud_data.course_name<<"$"<<stud_data.grade;
        ok=true;break;
            }
        }
     if(!ok)
        cout<<"\t***** please choose correct Course. *****\n";
     }while(!ok);
   }
stud_file.close();
cout<<"\t********************* Done!!! **********************\n";
 }
//display the students name,id,nofc
void student_display(){
 cler(14);

 student_struct stud_data;
 ifstream stud_file;
 stud_file.open("students_file.txt");
 cout<<"\n\t*************** Students Display ******************\n";
 cout<<"\t\tId\tName\t\tN.of.C\tT.G\n";
 while(!stud_file.eof())
 {
  float total_grade=0.0;
  char x; //for $
  stud_file>>stud_data.id;
  stud_file>>x;// for $
  stud_file.getline(stud_data.name,50,'$');
  stud_file>>stud_data.nofc;
  for(int i=0;i<stud_data.nofc;i++)
  {
   stud_file>>x;
   stud_file.getline(stud_data.course_name,50,'$');
   stud_file>>stud_data.grade;
   total_grade+=stud_data.grade;
  }
  cout<<"\t\t"<<stud_data.id<<"\t"<<stud_data.name<<"\t"<<stud_data.nofc<<"\t"<<total_grade<<endl;
 }
cout<<"\t********************* Done!!! **********************\n";
 stud_file.close();
}
//Search the students
void student_search(){
cler(11);
string get_want;bool found=false;int n;
cout<<"\n\t*************** Students Search ********************\n";
cout<<"\tEnter the Id for the Student to Search about : ";cin>>n;
student_struct stud_data;
ifstream stud_file;
stud_file.open("students_file.txt");
while(!stud_file.eof())
 {
  char x; //for $
  stud_file>>stud_data.id;
  stud_file>>x;// for $
  stud_file.getline(stud_data.name,50,'$');
  stud_file>>stud_data.nofc;
   ////if found
   if(stud_data.id==n)
  {  found=true;
   cout<<"\tWe Found the Student ";
   cout<<"1-Display\t2-Not : ";
   cin>>get_want;
   if(get_want=="Not"){
    cout<<"\t********************* Done!!! **********************\n";
    }
   if(get_want=="Display")
    {
      cout<<"\t*************** Student Details ********************\n";
      cout<<"\tId : "<<stud_data.id<<"\t";
      cout<<"Name : "<<stud_data.name<<"\t\t";
      cout<<"N.Of.C : "<<stud_data.nofc<<endl;
      cout<<"\t\tC.N\tCoure_Name\tGrade\n";
     }
  }
  float total_grades=0.0;
  for(int i=0;i<stud_data.nofc;i++)
  {
   stud_file>>x;
   stud_file.getline(stud_data.course_name,50,'$');
   stud_file>>stud_data.grade;
   if(found&&get_want=="Display")
    cout<<"\t\t"<<i+1<<"\t"<<stud_data.course_name<<"\t\t"<<stud_data.grade<<endl;
  total_grades+=stud_data.grade;
  }
  if(found&&get_want=="Display"){
     cout<<"\t\t\tTotal_Grades :  "<<total_grades<<endl;
     cout<<"\t********************* Done!!! **********************\n";
       break;
  }
 }
if(!found){
cout<<"\t****************************************************\n";
cout<<"\t\tSorry!!! We Can't find the student.\n";
}stud_file.close();
}
//Delete onede stident
void student_delete(){
cler(13);
int n;//for cin id
student_struct stud_data;
fstream stud_file;
fstream temp;
stud_file.open("students_file.txt",ios::in);
temp.open("temp.txt",ios::out);
cout<<"\n\t*************** Students Delete ********************\n";
cout<<"\tEnter the Id for the Student to Delete it : ";
cin>>n;
bool found=false,newstr=true;
//write from stud_file to temp
while(!stud_file.eof()){
  char x;
  stud_file>>stud_data.id>>x;
  stud_file.getline(stud_data.name,50,'$');
  stud_file>>stud_data.nofc;
  if(stud_data.id==n){found=true;}
  else if(newstr)
     temp<<stud_data.id<<'$'<<stud_data.name<<'$'<<stud_data.nofc;
  else
      temp<<endl<<stud_data.id<<'$'<<stud_data.name<<'$'<<stud_data.nofc;
  for(int i=0;i<stud_data.nofc;i++)
  {
   stud_file>>x;
   stud_file.get(stud_data.course_name,50,'$');
   stud_file>>x>>stud_data.grade;
   if(!found)
    temp<<'$'<<stud_data.course_name<<'$'<<stud_data.grade;
  }
  newstr=false;
 }
stud_file.close();
temp.close();

if(found){
fstream stud_file;
fstream temp;
stud_file.open("students_file.txt",ios::out);
temp.open("temp.txt",ios::in);
newstr=true;
while(!temp.eof()){
  char x;
  temp>>stud_data.id>>x;
  temp.getline(stud_data.name,50,'$');
  temp>>stud_data.nofc;
   if(newstr)
     stud_file<<stud_data.id<<'$'<<stud_data.name<<'$'<<stud_data.nofc;
  else
      stud_file<<endl<<stud_data.id<<'$'<<stud_data.name<<'$'<<stud_data.nofc;
  for(int i=0;i<stud_data.nofc;i++)
  {
   temp>>x;
   temp.get(stud_data.course_name,50,'$');
   temp>>x>>stud_data.grade;
   stud_file<<'$'<<stud_data.course_name<<'$'<<stud_data.grade;
  }
  newstr=false;
 }
stud_file.close();
temp.close();
 cout<<"\t********************* Done!!! **********************\n";
    }
else
 cout<<"\t********************* Sorry!!! *********************\n";
    remove("temp.txt");
}
//display one stud
void display_one_stud(int n,bool &found){
student_struct stud_data;
ifstream stud_file;
stud_file.open("students_file.txt");
while(!stud_file.eof())
 {
  char x; //for $
  stud_file>>stud_data.id;
  stud_file>>x;// for $
  stud_file.getline(stud_data.name,50,'$');
  stud_file>>stud_data.nofc;
  if(stud_data.id==n)
  {  found=true;
      cout<<"\t*************** Student Display ********************\n";
      cout<<"\tId : "<<stud_data.id<<"\t\t";
      cout<<"Name : "<<stud_data.name<<"\t\t";
      cout<<"N.Of.C : "<<stud_data.nofc<<endl;
      cout<<"\t\tC.N\tCoure_Name\tGrade\n";
  }
  float total_grades=0.0;
  for(int i=0;i<stud_data.nofc;i++)
  {
   stud_file>>x;
   stud_file.getline(stud_data.course_name,50,'$');
   stud_file>>stud_data.grade;
   if(stud_data.id==n)
      cout<<"\t\t"<<i+1<<"\t"<<stud_data.course_name<<"\t\t"<<stud_data.grade<<endl;
  total_grades+=stud_data.grade;

  }
 if(stud_data.id==n){
      cout<<"\t\t\tTotal_Grades :  "<<total_grades<<endl;
      cout<<"\t********************* Done!!! **********************\n";
      break;}
  }
stud_file.close();
}
//student edit
void student_edit(){
cler(14);
student_struct stud_data;
fstream stud_file;
fstream temp;
stud_file.open("students_file.txt",ios::in);
temp.open("temp.txt",ios::out);
int n;//to get the id
cout<<"\n\t***************** Students Edit ********************\n";
cout<<"\tEnter the Id for the Student to Edit it : ";
cin>>n;
bool found=false;
display_one_stud(n,found);

if(found){
string get_want;
cout<<"\tEnter What is you want to Edit.\n";
cout<<"\t1-Id\t2-Name\t3-Delete_course\t4-Course_grade\t5-Add_courses\n";
cout<<"\t\t\t";
cin>>get_want;
bool newstr=true;
int Enofc,nw=0;
//write from stud_file to temp
while(!stud_file.eof()){
  char x;
  stud_file>>stud_data.id>>x;
  stud_file.getline(stud_data.name,50,'$');
  stud_file>>stud_data.nofc;
  string cours_name,stud_name;//for delete course
  int new_grade;
  Enofc=stud_data.nofc;
  if(stud_data.id==n)
  {  if(get_want=="Id")
      {cout<<"\tEnter the new Id : ";cin>>stud_data.id;}
      else if(get_want=="Name")
      {cout<<"\tEnter the new Name : ";cin.ignore();cin.get(stud_data.name,50);}
      else if(get_want=="Delete_course")
      {cout<<"\tEnter the course_name to Delete : ";cin.ignore();getline(cin,cours_name);Enofc--;}
      else if(get_want=="Course_grade")
      { cout<<"\tEnter the course_name : ";cin.ignore();getline(cin,cours_name);
        cout<<"\tEnter the New Grade : ";cin>>new_grade;
      }
      else if(get_want=="Add_courses")
      {
      cout<<"\tEnter the N.of.C : ";cin>>nw;Enofc+=nw;
      }
   }
  if(newstr)
     temp<<stud_data.id<<'$'<<stud_data.name<<'$'<<Enofc;
  else
      temp<<endl<<stud_data.id<<'$'<<stud_data.name<<'$'<<Enofc;
  for(int i=0;i<stud_data.nofc;i++)
  {
   stud_file>>x;
   stud_file.get(stud_data.course_name,50,'$');
   stud_file>>x>>stud_data.grade;
   if(stud_data.id==n)
       {
        if(get_want=="Delete_course")
        {
           if(stud_data.course_name!=cours_name)
                temp<<'$'<<stud_data.course_name<<'$'<<stud_data.grade;
        }
        else if(get_want=="Course_grade")
        {
            if(stud_data.course_name==cours_name)
                temp<<'$'<<stud_data.course_name<<'$'<<new_grade;
            else
                temp<<'$'<<stud_data.course_name<<'$'<<stud_data.grade;
        }
        else
         temp<<'$'<<stud_data.course_name<<'$'<<stud_data.grade;
      }
  else
    temp<<'$'<<stud_data.course_name<<'$'<<stud_data.grade;
 }//add new courses
  string cors,arr[20];int grd,cc=0;
  if(get_want=="Add_courses"&&stud_data.id==n)
   {   course_display_in_student_add(arr,cc);
     for(int i=0;i<nw;i++)//check for the course
    {  bool ok=false;
    cin.ignore();
   do{
       cout<<"\tEnter the course name N "<<i+1<<" : ";
       getline(cin,cors);

       for(int j=0;j<cc;j++){
        if(cors==arr[j]){
        cout<<"\tEnter the student grade in the course N "<<i+1<<" : ";
        cin>>grd;
        temp<<'$'<<cors<<'$'<<grd;
        ok=true;break;
            }
        }
     if(!ok)
        cout<<"\t***** please choose correct Course. *****\n";
     }while(!ok);
   }
  }
  newstr=false;
 }
stud_file.close();
temp.close();

fstream stud_file;
fstream temp;
//write from temp to stud
stud_file.open("students_file.txt",ios::out);
temp.open("temp.txt",ios::in);
newstr=true;
while(!temp.eof()){
  char x;
  temp>>stud_data.id>>x;
  temp.getline(stud_data.name,50,'$');
  temp>>stud_data.nofc;
   if(newstr)
     stud_file<<stud_data.id<<'$'<<stud_data.name<<'$'<<stud_data.nofc;
  else
      stud_file<<endl<<stud_data.id<<'$'<<stud_data.name<<'$'<<stud_data.nofc;
  for(int i=0;i<stud_data.nofc;i++)
  {
   temp>>x;
   temp.get(stud_data.course_name,50,'$');
   temp>>x>>stud_data.grade;
   stud_file<<'$'<<stud_data.course_name<<'$'<<stud_data.grade;
  }
 newstr=false;
 }
stud_file.close();
temp.close();
cout<<"\t********************* Done!!! **********************\n";

remove("temp.txt");
}
else
    cout<<"\t********************* Sorry!!! *********************\n";
}
////////////////////the Courses/////////////////////////////////
// write the course
void course_add(){
cler(10);
course_struct course_data;//get data from the user
cout<<"\n\t*************** Courses Add ***********************\n";
cout<<"\tEnter the course ID : ";
cin>>course_data.id;
cin.ignore();
cout<<"\tEnter the course Name : ";
cin.getline(course_data.course_name,50);
cout<<"\tEnter the course Prof_name : ";
cin.getline(course_data.prof_name,50);
ofstream course_file; //to write in the fill
course_file.open("courses_file.txt",ios::app);
course_file<<endl<<course_data.id<<"$"<<course_data.course_name<<"$"<<course_data.prof_name<<"$"<<course_data.Enrolled_students;
course_file.close();
cout<<"\t***************************************************\n";
cout<<"\t\tDone!!!We Saved The New Data.\n";
}
//display the course
int nofs_in_course(string course_name){
 int c=0;
 student_struct stud_data;
 ifstream stud_file;
 stud_file.open("students_file.txt");
 while(!stud_file.eof())
 {
  char x; //for $
  stud_file>>stud_data.id;
  stud_file>>x;// for $
  stud_file.getline(stud_data.name,50,'$');
  stud_file>>stud_data.nofc;
  for(int i=0;i<stud_data.nofc;i++)
  {
   stud_file>>x;
   stud_file.getline(stud_data.course_name,50,'$');
   stud_file>>stud_data.grade;
   if(stud_data.course_name==course_name)
        c++;
  }
 }
stud_file.close();
return c;
}
void course_display(){
cler(14);
course_struct course_data;
ifstream course_file;
course_file.open("courses_file.txt");
cout<<"\n\t*************** Courses Display *******************\n";
cout<<"\tID\tCourse Name\tProf_Name\tNof_students\n";
while(!course_file.eof()){
    char x; //for $
    course_file>>course_data.id;
    course_file>>x; //for $
    course_file.get(course_data.course_name,50,'$');
    course_file>>x; //for $
    course_file.get(course_data.prof_name,50,'$');
    course_file>>x; //for $
    course_file>>course_data.Enrolled_students;
    course_data.Enrolled_students=nofs_in_course(course_data.course_name);
    cout<<"\t"<<course_data.id<<"\t"<<course_data.course_name<<"\t\t"<<course_data.prof_name<<"\t"<<course_data.Enrolled_students<<endl;
 }
cout<<"\t****************************************************\n";
cout<<"\t\tDone!!! We displayed all Courses.\n";

 course_file.close();
}
//search 3n course
void all_stud_in_course(string course,string stud[],int grad[]){
student_struct stud_data;
ifstream stud_file;
stud_file.open("students_file.txt");
int c=0;
 while(!stud_file.eof())
 {
  char x; //for $
  stud_file>>stud_data.id;
  stud_file>>x;// for $
  stud_file.getline(stud_data.name,50,'$');
  stud_file>>stud_data.nofc;
  for(int i=0;i<stud_data.nofc;i++)
  {
   stud_file>>x;
   stud_file.getline(stud_data.course_name,50,'$');
   stud_file>>stud_data.grade;
   if(stud_data.course_name==course)
      {
       stud[c]=stud_data.name;grad[c]=stud_data.grade;
       c++;
      }
   }
}
stud_file.close();
}
void course_search(){
cler(11);
int n;
bool found=false;
cout<<"\n\t*************** Courses Search ********************\n";
cout<<"\tEnter the Id for the course to Search about : ";
cin>>n;
course_struct course_data;
ifstream course_file;
course_file.open("courses_file.txt");
while(!course_file.eof()){
    char x; //for $
    course_file>>course_data.id;
    course_file>>x; //for $
    course_file.getline(course_data.course_name,50,'$');
    course_file.getline(course_data.prof_name,50,'$');
    course_file>>course_data.Enrolled_students;
    if(course_data.id==n)
     {found=true;break;}
 }
 //lw la2 el course
 if(found){
    string get_want;
    cout<<"\tWe found the course ";
    cout<<"1-Display\t2-Not\t: ";
    cin>>get_want;
   if(get_want=="Display")//lw 3ayz ytl3 el_course
   {
     string stud[100];int grad[100];
     course_data.Enrolled_students=nofs_in_course(course_data.course_name);
     cout<<"\n\t*************** Course Details ********************\n";
     cout<<"\tID : "<<course_data.id<<"\t\t\t"<<"Course Name : "<<course_data.course_name<<endl;
     cout<<"\tProf_Name : "<<course_data.prof_name<<"\t"<<"Enrolled_students : "<<course_data.Enrolled_students<<endl;
     if(course_data.Enrolled_students==0)
        cout<<"\t\tOops!!!No student in this course\n";
     else
         {
         all_stud_in_course(course_data.course_name,stud,grad);
         cout<<"\t\tStudent_name\t\tGrade\n";
         for(int i=0;i<course_data.Enrolled_students;i++)
         cout<<"\t\t"<<stud[i]<<"\t\t"<<grad[i]<<endl;
         }
   cout<<"\t****************************************************\n";
   cout<<"\t\tDone!! We Displayed the course.\n";
   }
   else
   {cout<<"\n\t****************************************************\n";
    cout<<"\t\t\t DONE Sire!!\n";
   }
}
 else
 {cout<<"\n\t****************************************************\n";
  cout<<"\t\tSorry We don't Found The course\n";
  }
course_file.close();
}
//Delete one course
void dlet_course_from_stud(string name,string want){
student_struct stud_data;
fstream stud_file;
fstream temp;
stud_file.open("students_file.txt",ios::in);
temp.open("temp1.txt",ios::out);
bool newstr=true;
//write from stud_file to temp
int Enofc,grad[100];
string arr[100];
bool in_this=false;
int nn,g;
   if(want=="grade"){
   cout<<"Enter the Id for the Student :";cin>>nn;
   cout<<"Enter the new grade : ";cin>>g;
   }
  if(want=="Deletestud"){
   cout<<"Enter the Id for the Student :";cin>>nn;
   }
while(!stud_file.eof()){
  in_this=false;
  char x;
  stud_file>>stud_data.id>>x;
  stud_file.getline(stud_data.name,50,'$');
  stud_file>>stud_data.nofc;
  Enofc=stud_data.nofc;
  for(int i=0;i<stud_data.nofc;i++)
  {
   stud_file>>x;
   stud_file.get(stud_data.course_name,50,'$');
   stud_file>>x>>stud_data.grade;
   if(stud_data.course_name==name)in_this=true;
   arr[i]=stud_data.course_name;grad[i]=stud_data.grade;
  }
 if(in_this&&(want=="Delete"||want=="Deletestud"))Enofc--;

 if(newstr)
     temp<<stud_data.id<<'$'<<stud_data.name<<'$'<<Enofc;
  else if(!newstr)
     temp<<endl<<stud_data.id<<'$'<<stud_data.name<<'$'<<Enofc;
  if(want=="Delete"||(want=="Deletestud"&&stud_data.id==nn)){
  for(int i=0;i<stud_data.nofc;i++)
   if(arr[i]!=name)temp<<'$'<<arr[i]<<'$'<<grad[i];}
  else if(want=="grade"){
   for(int i=0;i<stud_data.nofc;i++)
     if(arr[i]==name&&nn==stud_data.id)
        temp<<'$'<<arr[i]<<'$'<<g;
     else
        temp<<'$'<<arr[i]<<'$'<<grad[i];
  }
  newstr=false;
}
stud_file.close();
temp.close();

//write from temp to stud
stud_file.open("students_file.txt",ios::out);
temp.open("temp1.txt",ios::in);
newstr=true;
while(!temp.eof()){
  char x;
  temp>>stud_data.id>>x;
  temp.getline(stud_data.name,50,'$');
  temp>>stud_data.nofc;
   if(newstr)
     stud_file<<stud_data.id<<'$'<<stud_data.name<<'$'<<stud_data.nofc;
  else
      stud_file<<endl<<stud_data.id<<'$'<<stud_data.name<<'$'<<stud_data.nofc;
  for(int i=0;i<stud_data.nofc;i++)
  {
   temp>>x;
   temp.get(stud_data.course_name,50,'$');
   temp>>x>>stud_data.grade;
   stud_file<<'$'<<stud_data.course_name<<'$'<<stud_data.grade;
  }
 newstr=false;
 }
stud_file.close();
temp.close();
remove("temp1.txt");
}
void course_delet(){
cler(13);
string name;
int n;//for id
bool found=false;
cout<<"\n\t*************** Courses Delete ********************\n";
cout<<"\tEnter the Id for the course to Delet It : ";
cin>>n;
course_struct course_data;
ifstream course_file;
course_file.open("courses_file.txt");
ofstream temp;
temp.open("temp.txt");
bool newstr=false;//34an tzbt endl
//read the data courses file to temp
while(!course_file.eof()){
    char x;//for $
    course_file>>course_data.id;
    course_file>>x; //for $
    course_file.getline(course_data.course_name,50,'$');
    course_file.getline(course_data.prof_name,50,'$');
    course_file>>course_data.Enrolled_students;
    course_data.Enrolled_students=nofs_in_course(course_data.course_name);
  if(course_data.id==n)
   {found=true;name=course_data.course_name;}
 else if(!newstr)
    temp<<course_data.id<<"$"<<course_data.course_name<<"$"<<course_data.prof_name<<"$"<<course_data.Enrolled_students;
 else
    temp<<endl<<course_data.id<<"$"<<course_data.course_name<<"$"<<course_data.prof_name<<"$"<<course_data.Enrolled_students;
 newstr=true;
 }

temp.close();
course_file.close();
cout<<"\n\t****************************************************\n";
if(found){
    dlet_course_from_stud(name,"Delete");
    //read the data from temp to courses file
    course_struct course_data2;
    ofstream course_file;//write
    course_file.open("courses_file.txt");
    ifstream temp;//read
    temp.open("temp.txt");
    newstr=false;//34an tzb endl
    while(!temp.eof()){
        char x; //for $
        temp>>course_data2.id;
        temp>>x; //for $
        temp.getline(course_data2.course_name,50,'$');
        temp.getline(course_data2.prof_name,50,'$');
        temp>>course_data2.Enrolled_students;
        if(!newstr)
            course_file<<course_data2.id<<"$"<<course_data2.course_name<<"$"<<course_data2.prof_name<<"$"<<course_data2.Enrolled_students;
        else
            course_file<<endl<<course_data2.id<<"$"<<course_data2.course_name<<"$"<<course_data2.prof_name<<"$"<<course_data2.Enrolled_students;
        newstr=true;
       }
course_file.close();
temp.close();
cout<<"\t\tDone!!! We delete the course. \n";
}
else
    cout<<"\t\tSorry We didn't find the course.\n";
remove("temp.txt");//to remove temp
}
//Edit one course
void course_edit(){
cler(14);
int n;//for id
bool found=false;
cout<<"\n\t*************** Courses Edit **********************\n";
cout<<"\tEnter the Id for the course to Edit It : ";
cin>>n;
string get_want;
cout<<"\tEnter What is you want to Edit.\n";
cout<<"\t1-Id\t2-Chang_prof : ";
cin>>get_want;
course_struct course_data;
ifstream course_file;
course_file.open("courses_file.txt");
ofstream temp;
temp.open("temp.txt");

bool newstr=false;//34an tzb endl
 while(!course_file.eof()){
     //read the data courses file to temp
    char x; //for $
    course_file>>course_data.id;
    course_file>>x; //for $
    course_file.get(course_data.course_name,50,'$');
    course_file>>x; //for $
    course_file.get(course_data.prof_name,50,'$');
    course_file>>x; //for $
    course_file>>course_data.Enrolled_students;
  if(course_data.id==n)
   {
    found=true;
    if(get_want=="Id")
    {cout<<"\tEnter the New Id : ";cin>>course_data.id;}
     else if(get_want=="Chang_prof")
    {cout<<"\tEnter the New Prof_name : ";cin.ignore();cin.getline(course_data.prof_name,50);}
   }
  if(!newstr)
    temp<<course_data.id<<"$"<<course_data.course_name<<"$"<<course_data.prof_name<<"$"<<course_data.Enrolled_students;
 else
    temp<<endl<<course_data.id<<"$"<<course_data.course_name<<"$"<<course_data.prof_name<<"$"<<course_data.Enrolled_students;
 newstr=true;
 }
temp.close();
course_file.close();
cout<<"\n\t****************************************************\n";
if(found){
//read the data from temp to courses file
    course_struct course_data2;
    ofstream course_file;//write
    course_file.open("courses_file.txt");
    ifstream temp;//read
    temp.open("temp.txt");
     newstr=false;//34an tzb endl
     while(!temp.eof()){
        char x; //for $
        temp>>course_data2.id;
        temp>>x; //for $
        temp.get(course_data2.course_name,50,'$');
        temp>>x; //for $
        temp.get(course_data2.prof_name,50,'$');
        temp>>x; //for $
        temp>>course_data2.Enrolled_students;
        course_data2.Enrolled_students=nofs_in_course(course_data2.course_name);
       if(!newstr)
        course_file<<course_data2.id<<"$"<<course_data2.course_name<<"$"<<course_data2.prof_name<<"$"<<course_data2.Enrolled_students;
     else
        course_file<<endl<<course_data2.id<<"$"<<course_data2.course_name<<"$"<<course_data2.prof_name<<"$"<<course_data2.Enrolled_students;
     newstr=true;
     }
 course_file.close();
 temp.close();
cout<<"\t\tDone!!! We Edit the course "<<get_want<<".\n";
}
else
    cout<<"\tSorry We don't found the course to Edit.\n";
remove("temp.txt");
}
////my final table//////
void get_stud(int id[],string arr[],int &c){
student_struct stud_data;
ifstream stud_file;
stud_file.open("students_file.txt");
while(!stud_file.eof())
 {
  char x; //for $
  stud_file>>stud_data.id;
  stud_file>>x;// for $
  stud_file.getline(stud_data.name,50,'$');
  stud_file>>stud_data.nofc;

  for(int i=0;i<stud_data.nofc;i++)
  {
   stud_file>>x;
   stud_file.getline(stud_data.course_name,50,'$');
   stud_file>>stud_data.grade;
   }
arr[c]=stud_data.name;id[c]=stud_data.id;
c++;
}
stud_file.close();
}
void get_stud_grade(int id,string arr[],int grad[],int &c){
student_struct stud_data;
ifstream stud_file;
stud_file.open("students_file.txt");
bool found=false; //to save time
while(!stud_file.eof())
 {
  char x; //for $
  stud_file>>stud_data.id;
  stud_file>>x;// for $
  stud_file.getline(stud_data.name,50,'$');
  stud_file>>stud_data.nofc;

  for(int i=0;i<stud_data.nofc;i++)
  {
   stud_file>>x;
   stud_file.getline(stud_data.course_name,50,'$');
   stud_file>>stud_data.grade;
   if(stud_data.id==id)
      {found=true;
       arr[c]=stud_data.course_name;grad[c]=stud_data.grade;
       c++;
      }
  }
 if(found)break;//to save time_limit
}
stud_file.close();

}
void get_course(string arr[],int &c){
 course_struct course_data;
 ifstream course_file;
 course_file.open("courses_file.txt");
 while(!course_file.eof()){
    char x; //for $
    course_file>>course_data.id;
    course_file>>x; //for $
    course_file.get(course_data.course_name,50,'$');
    course_file>>x; //for $
    course_file.get(course_data.prof_name,50,'$');
    course_file>>x; //for $
    course_file>>course_data.Enrolled_students;
    arr[c]=course_data.course_name;
    c++;
 }
 course_file.close();
}
void my_final_table(){
string course[20],stud[50];
int c_c=0,s_c=0,stud_id[50];
get_course(course,c_c);
cout<<"\n*********************** Final Table ********************************\n";
cout<<"Id\tNames\t\t";
for(int i=0;i<c_c;i++)
    cout<<course[i]<<"\t";
cout<<endl;

get_stud(stud_id,stud,s_c);
for(int i=0;i<s_c;i++){
  int nofc=0,g_c=0,grades[20];
  string arr_course[20];
  cout<<stud_id[i]<<"\t"<<stud[i]<<"\t";
  get_stud_grade(stud_id[i],arr_course,grades,g_c);

  bool ok=false;
  for(int k=0;k<c_c;k++)
  {
      ok=false;
      int j=0;
      for(j=0;j<g_c;j++)
      {
       if(course[k]==arr_course[j]){ok=true;break;}
      }
       if(ok)cout<<grades[j]<<"\t";
       else cout<<"0\t";

  }
  cout<<endl;
}
cout<<"********************************************************************\n";
}
/////Course call////
void course_choose(){
string get_course_want;
     cout<<"\t1-Display\t2-Add\t3-Search\t4-Edit\t5-Delete\n";
     cord(25,7);
     cin>>get_course_want;
     if(get_course_want=="Display")//if chose display
      course_display();

     else if(get_course_want=="Add")//if chose Add
     course_add();

     else if(get_course_want=="Search")//if search for cousre
      course_search();

     else if(get_course_want=="Edit")//if Edi the course
        course_edit();

    else if(get_course_want=="Delete")//if Delete the course
        course_delet();

}
void student_choose(){
    string get_student_want;
    cout<<"\t1-Display\t2-Add\t3-Search\t4-Edit\t5-Delete\n";
    cord(25,7);
    cin>>get_student_want;

    if(get_student_want=="Display")  //if chose display
        student_display();


    else if(get_student_want=="Add")//if chose Add
        student_add();


    else if(get_student_want=="Search")//if search for stud
        student_search();

    else if(get_student_want=="Edit")//if Edi the stud
       student_edit();

    else if(get_student_want=="Delete")//if Delete the stud
        student_delete();
}
//loading func
void load(){
SetConsoleTitle("My_Mangment_Course");
int mycolor;
for(int i=1;i<=100;i++)
{
 for(int j=0;j<10000000;j++);
  system("cls");
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
 cout<<"\n\n\n\n\n\t\tWelcome To My Simple Programe.\n";
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
 cout<<"\t\t\tLoading...\n";
 mycolor=i;
 if(mycolor>=10)
    mycolor%=10;
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),mycolor);
 cout<<"\t\t\t"<<i;
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
 cout<<" %"<<endl;

}
 system("cls");
}
void thank_you(){
system ("cls");
cout<<"\n\n\n\n";
chang_color(55);
cout<<"\t";
char x=259;
for(int i=0;i<26;i++)
    cout<<x<<" ";
//cout<<"\t***************************************************\t\n";
cout<<"\t"<<endl;
cout<<"\t***\t\tTHaNK YoU\t\t\t***\t\n";
cout<<"\t";
for(int i=0;i<26;i++)
    cout<<x<<" ";
cout<<"\t"<<endl;
//cout<<"\t***************************************************\t\n";

chang_color(7);
}

int main()
{
load();

string get_want,cont;
do{
   cler(7);
   cout<<"\n\t1-Course\t2-Student\t3-Final_table\n";
   cord(25,5);
   cin>>get_want;
   if(get_want=="Course")// if choose the course
     course_choose();
   else if(get_want=="Student")// if choose the course
     student_choose();
   else if(get_want=="Final_table")
     {cler(22);my_final_table();}

chang_color(7);
cout<<"\n\t***************************************************\n";
cout<<"\t***\t\tDo you want to continue.\t***\n";
cout<<"\t\t\t1-Yes\t2-No : ";
cin>>cont;

 }while(cont=="Yes");

thank_you();
   return 0;
}
