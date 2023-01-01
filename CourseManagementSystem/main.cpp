#include "ProjMangHeaders.h"

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
