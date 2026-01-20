#include<iostream>
#include<vector>
#include<iterator>
#include<map>
#include<string>
#include<bits/stdc++.h>

using namespace std;

  //global data we are going to use in allocation


map<int,string> final1;//map for storing allocated result
int i;
  int n,m;//n(number of college ) m(number of student )




class student
{

 private:

 //    string name;
     int id,marks,nu_of_choice;
     vector<string> preference;
     int i= 0;
     int allocated =0;
 public:
   void get_details()
    {
     //   cout<<"enter the name of student "<<endl;
       // cin>>name;
        //cout<<"enter the id of student"<<endl;
        cin>>id;
        //cout<<"enter marks "<<endl;
        cin>>marks;
        //cout<<"\nEnter number of preferences: ";
        cin>>nu_of_choice;
        for(i=1; i<=nu_of_choice; i++)
        {
            //cout<<"\nEnter your "<<i<<" preference: ";
            string pref;
            cin>>pref;

            preference.push_back(pref);


        }
    }
    int getmarks()
    {
        return marks;
    }
  friend void allocation();
  friend void sorting();

};

vector<student> total_student;

 void sorting()
 {
     int max,index,i,j;
       index = 0;
       int Flag;
     for(i=0; i<m; i++)
     {
        Flag=0;
         max = total_student[i].marks;
         for(j=i; j<m; j++)
         {
             if(total_student[j].marks> max)
             {
                max =total_student[j].marks;
                index=j;
                Flag=1;
             }

         }
         if(Flag==0 || (i==m-1 && j==m-1))
            continue;

                student x =total_student[index];
               total_student[index] = total_student[i];
               total_student[i]=x;



     }



 }



  class college
  {
      private:
      string name;
      int seat;

      public:
       void get_details()
        {
            //cout<<"enter the name of college"<<endl;
            cin>>name;
            //cout<<"enter the number of seat"<<endl;
            cin>>seat;
        }


      void set_seat_allocation(student x)
      {
          //cout<<student<<name;
           seat--;

      }

 friend void allocation();

  };
vector<college> total_college;

void allocation()//this will do allocation of seats to student
{    //make friend of both student and college class
      //sort student in descending order of marks
      //take that student who has maxmum marks
      //allocate collage to that student
      //and do seat --

      int p,q,r;
     // cout<<"\nCalled allocation";
     //this code will take student with heighest marks and allocate seats one by one
     //here 'm' is number of student object(global)
     //her n is number of college object(global)
          for(p=0; p<m; p++)
      {
            for(r=0; r< total_student[p].nu_of_choice; r++)
          {

            for(q=0; q<n; q++)
              {



              if(!(total_student[p].preference[r].compare(total_college[q].name))&&total_college[q].seat!=0)//storing in map with student id and college name

              {
                  final1.insert(pair<int,string>(total_student[p].id,total_college[q].name));//store in map
                  //cout<<"\nStored the Pair in Map.";
                  total_college[q].seat--;
                  total_student[p].allocated =1;
                  r= total_student[p].nu_of_choice;
                  break;
              }
              else if(!(total_student [p].preference[r].compare(total_college[q].name)))

                break;


              }
          }

          if(total_student[p].allocated==0)
          {

            final1.insert(pair<int,string>(total_student[p].id,"null"));
              //store null in the map with this student id
          }


      }

  };











   int main()
   {

       //cout<<"enter the number of college"<<endl;
       cin>>n;
       for(i=1; i<=n; i++ )
       {
           college temp;
           temp.get_details();
       total_college.push_back(temp);
       }

      // cout<<"enter the number of candidate"<<endl;
       cin>>m;
       for(i=1; i<=m; i++ )
       {
           student temp;
           temp.get_details();
       total_student.push_back(temp);

       }

       //cout<<"\nBefore sorting";
       //for(int i=0; i<total_student.size();i++)
        //cout<<"\n"<<total_student[i].getmarks();


       sorting();
       //code for checking whether objects are sorted according to marks or not
       //cout<<"\nAfter sorting";
       //for(int i=0; i<total_student.size();i++)
        //cout<<"\n"<<total_student[i].getmarks();

       allocation();

     //printing map of student and there respective college
     //defining a iterator on map
     map<int,string>::iterator itr;
     for(itr=final1.begin(); itr!=final1.end();itr++)
     {

         cout<<itr->first<<" "<<itr->second<<"\n";
     }



   }



