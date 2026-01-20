#include<iostream>
#include<ctime>
using namespace std;

int xleap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int nonleap[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int leap(int year)
{

    if(year%4==0)
    {
        if((year%100)%2==0&&((year%400)%2==0))
         {
           return 1;
         }

        else if((year%100)%2!=0)
               return 1;
    }
     else
            return 0;
    return 0;
}

class Date
{
  private:
    int currentyear , currentmonth , currentdate, year, month, date;
    char *name;
    int index, remaining_day, passed_day, c_remaining_day, c_passed_day, c_index;
    signed int no_day;
    int count;

  public:
      //get and set funtion of variable

        int getindex()
        {
            return index;
        }

        int getpassed_day()
        {
            return passed_day;
        }

        int getremaining_day()
        {
         // cout<<"\nRemaining day="<<remaining_day<<endl;
         return remaining_day;
        }


        int getc_passed_day()
        {
           return  c_passed_day;
        }

        int getc_remaining_day()
        {

          return c_remaining_day;
        }


        int getdate()
        {
          return date;
        }

        int getmonth()
        {
          return month;
        }

        int getyear()
        {

          return year;

        }

        int getcurrentdate()
        {

          return currentdate;

        }
        int getcurrentmonth()
        {

          return currentmonth;
        }

        int getcurrentyear()
        {
          return currentyear;
        }
        void setcurrentdate(int d,int m,int y)
        {
          currentdate =d;
          currentmonth = m;
          currentyear = y;
        }

        int getcurrentindex()
        {
          return c_index;
        }

        void setDate(int x, int y, int z)
        {
          date=x;
          month=y;
          year=z;
        }

        void getsetdate()
        {

          cout<<"\n"<<date<<"  "<<month<<" "<<year<<endl;
        }

        //get set funtion over


        //constructor

        Date()
        {

            year = 0;
            month = 0;
            date = 0;
            currentyear = 0;
            currentmonth = 0;
            currentdate =0;
            name =(char*)"null";
            index =0;
            c_index =0;
            remaining_day = 0;
            passed_day = 0;
            c_passed_day = 0;
            c_remaining_day =0;

            time_t now = time(0);
            tm *ltm = localtime(&now);
            setcurrentdate(ltm->tm_mday, ltm->tm_mon+1, ltm->tm_year+1900);
            int xx=getcurrentdate();
            int yy=getcurrentmonth();
            int zz=getcurrentyear();
            }


        Date(int d,int m,int y)
          {
              date = d;
              month = m;
              year = y;
          }



         Date(int x,char *m ,int z)
          {
            date = x;
            name = m;
            year = z;
          }


         //copy constructor


            Date(Date &t)
            {
               year =t.year;
              month = t.month;
              date = t.date;
              passed_day =t.passed_day;
              remaining_day =t.remaining_day;
              c_passed_day = t.c_passed_day;
              c_remaining_day = c_remaining_day;
              currentyear =t.currentyear;
              currentmonth =t.currentmonth;
              currentdate = t.currentdate;
            }




             //destructor


            ~Date()
            {

                cout<<"\nObject destroyed."<<" "<<endl;
            }

//operator overloading

        void operator[](int idx)
        {
            cout<<"\n'[]' operator overloaded.";
            if(idx==0)
                cout<<"\nDay: "<<date;
            else if(idx==1)
            {
                cout<<"\nMonth: "<<month;
            }

            else if(idx==2)
                cout<<"\nYear: "<<year;
            else
                cout<<"\nInvalid Index.";
        }




        void operator()(Date& y)
        {
            cout<<"\n'()' operator overloaded.";
            cout<<"\nDate 1 from current day: "<<this->count<<endl;
            cout<<"\nDate 2 from current day: "<<y.count<<endl;
            if(this->count > y.count)
                cout<<"\nDate 1 is having more distance from today as compared to Date 2"<<" "<<endl;
            else if (this->count == y.count)
            {

                cout<<"\nBoth dates have same distance from today. "<<" "<<endl;
            }
            else
                cout<<"\nDate 2 is having more distance from today as compared to Date 1"<<" "<<endl;

        }



        Date& operator=(Date & t)
        {
            year =t.year;
            month = t.month;
            date = t.date;
            passed_day =t.passed_day;
            remaining_day =t.remaining_day;
            c_passed_day = t.c_passed_day;
            c_remaining_day = c_remaining_day;
            currentyear =t.currentyear;
            currentmonth =t.currentmonth;
            currentdate = t.currentdate;
           // cout<<"\n'=' Operator overloaded"<<" "<<endl;
            return *this;
        }



      int operator+(Date&y)
      {
            int n;
            cout<<"\nNumber of days between Date 1 and Today + Number of days between Date 2 and Today"<<" "<<endl;
            n = count + y.count;
            cout<<n<<" "<<endl;
            return n;
        }

    int operator-(Date &y)
    {
        int diff;
        if (no_day>0 && y.no_day >0)
        {
          cout<<"\nBoth date are more than current date."<<endl;
          if( no_day > y.no_day)
            diff = no_day - y.no_day;
            else if(y.no_day > no_day)
             {
                diff = y.no_day - no_day;
             }
         else
            diff = 0;
        }
        else if(no_day >0 && y.no_day <0)
        {
            diff = no_day - y.no_day;
        }
        else if(no_day <0 && y.no_day >0)
        {
            diff =  y.no_day - no_day;
        }
        else
        {
         if(no_day < y.no_day)
           diff =  y.no_day - no_day;
          else if(no_day > y.no_day)
            diff = no_day -y.no_day ;
        else
          diff = 0;
        }
        return diff;

    }// -overload

    //overloading of operator ended

    // funtion (num_day,currentsetday(),void setday()

    void setday() //It finds the remaining days and passed days in a year
    {
        int i,a;
        int daypassed =0;
        //cout<<"\nsetDay() called.";
        if(leap(year))
        {

            for (i=0;i<= month-1; i++)
                daypassed = daypassed +xleap[i];
            a= xleap[i-1]- date;
            daypassed = daypassed -a;
            passed_day =daypassed;
            remaining_day = 366-daypassed;
        }
        else
        {
              for (i=0;i<= month-1; i++)
                daypassed = daypassed +nonleap[i];
            a= nonleap[i-1]- date;
            daypassed = daypassed -a;
            passed_day =daypassed;
            remaining_day = 365-daypassed;
        }
    }

    void currentsetday() //Finds the remaining days and the passed days of today.
    {
        int i,a;
        int daypassed =0;
        if(leap(currentyear))
        {

            for (i=0;i<= currentmonth-1; i++)
                daypassed = daypassed +xleap[i];
            a= xleap[i-1]- currentdate;
            daypassed = daypassed -a;
            c_passed_day =daypassed;
            c_remaining_day = 366-daypassed;
        }
        else
            {
              for (i=0;i<= currentmonth-1; i++)
                daypassed = daypassed +nonleap[i];
            a= nonleap[i-1]- currentdate;
            daypassed = daypassed -a;
            c_passed_day =daypassed;
            c_remaining_day = 365-daypassed;
        }
    }

    int num_day() //returns the number of days of the passed date from today.
    {
        int p,q,r,d;
        d=currentyear;
        if(year>currentyear)
        {
            p = c_remaining_day;
            d++;
            while(d<year)
            {
                if(leap(d))
                    p = p + 366;
                else
                    p = p +365;
                d++;
            }
            int temp;
            temp=c_passed_day;
            p = p + passed_day;
            cout<<"\nNumber of Days between Today and date: ";
            cout<<p;
            count = p;
            no_day = p;
          return p;
    }

    else if(d>year)
        {
            p = c_passed_day;
            d--;
            while(d>year)
            {
                if(leap(d))
                    p = p+366;
                else
                    p = p+365;
                d--;
            }
            p = p +remaining_day;
            cout<<"Number of days between Today and  date: ";
            cout<<-p<<endl;
            count = p;
            no_day = -p;
            return no_day;
    }
    else if(d==year)
    {
        int m;
        m = passed_day - c_passed_day;
        cout<<m;
        count = m;
        no_day = m;
        return m;
    }

    return 1;
    }
    //function over

  };//class over

int main()
{

    int date,month,year,a,b;
    cout<<"\nThis program will give number of days between current year and given year."<<endl;
    cout<<"\nEnter Date in Date Month Year format in integer value."<<endl;
    cout<<"\nEnter date: "<<endl;
    cin>>date;
    cout<<"\nEnter month: "<<endl;
    cin>>month;
    cout<<"\nEnter year: "<<endl;
    cin>>year;

    Date x;
    int dd,mm,yy;
    dd=x.getcurrentdate();
    mm=x.getcurrentmonth();
    yy=x.getcurrentyear();
    cout<<"\nToday: ";
    cout<<dd<<"/"<<mm<<"/"<<yy<<endl;
    x.setDate(date, month, year);
    int date1,month1,year1;
    cout<<"\nEnter Date in Date Month Year format in integer value."<<endl;
    cout<<"\nEnter date: "<<endl;
    cin>>date1;
    cout<<"\nEnter month: "<<endl;
    cin>>month1;
    cout<<"\nEnter year: "<<endl;
    cin>>year1;
    x.setday();
    cout<<"\nSpecifications of Date 1: ";
    x.getsetdate();
    x.currentsetday();
    Date d;
    d.setDate(date1, month1, year1);
    d.setday();
    d.currentsetday();
    cout<<"Specifications of Date 2: ";
    d.getsetdate();
    Date z;
    z =x; //"="operator overloaded.
    Date y(x);//copy contructor called
    cout<<"\n"<<endl;
    a = x.num_day(); //a= number of days of x from today
    b = d.num_day();//b= number of days of d from today
    cout<<"\nNumber of days of Date 1 from today: "<<a<<" "<<endl;
    cout<<"\nNumber of days of Date 2 from today: "<<b<<" "<<endl;

    a = x-d; //a will now store the number of days between the provided dates
    cout<< "\nDifference between two given dates: ";
    cout<<a<<" days."<<endl;
    cout<<"\nValue of Object 1 (i.e. X): ";
    x.getsetdate();
    cout<<"\nValue of Object 2 (i.e. D): ";
    d.getsetdate();
    x(d); //this will print which day is farther from today

    //cout<<"sum of difference of dates from current year"<<" "<<endl;
    cout<<"\nBefore using the + operator, Value of Date 1: ";
    x.getsetdate();
    cout<<"\nBefore using the + operator, the value of Date 2: ";
    d.getsetdate();
    cout<<"\nNow using the + operator, X+D.";
    b = x + d;
    cout<<"\nSelect one of the following: ";
    cout<<"\nPress 0 for getting the Day value.\nPress 1 for getting the Month value.\nPress 2 for getting the year value.\n";
    int idx;
    cin>>idx;
    x[idx];

return 0;

}

