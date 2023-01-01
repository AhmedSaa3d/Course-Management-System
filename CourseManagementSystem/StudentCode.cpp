#include "ProjMangHeaders.h"

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
void load(){
SetConsoleTitle("My_Mangment_Course");
int mycolor;
for(int i=1;i<=100;i+=3)
{
 for(int j=0;j<100000;j++);
  system("cls");
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
 cout<<"\n\n\n\n\n\t\tWelcome To My Simple Programe.\n";
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
 cout<<"\t\t\tLoading...\n";
 mycolor=i;
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


