// Online C++ compiler to run C++ program online
#include <iostream>
#include<cstdlib>
using namespace std;
int custopermin[]={0,1,2,3,4};
    int n1 = sizeof custopermin/ sizeof custopermin[0];
    int custpermin,number;
    int range[]={15,35,60,70,100};
    int n2 = sizeof range / sizeof range[0];
    int waitingtime;int counters;int counterscount=0;
    
void waitingTime(int servicetime,int n3,int servicerange[],int serviceinsec[])
{

	for (int i = 1; i<=n3; i++ ){
		waitingtime=waitingtime+servicetime;
	}
    cout<<"waiting time is  "<< waitingtime<<"\n";
	
	
}
void countcounters(int waitingtime,int counters){
    
    int twomin=120;
    
    for(int i=0;i<=120;i++){
	    if(waitingtime>twomin){
	        counters=counters+1;
	        waitingtime=waitingtime-twomin;
	        counterscount=counterscount+counters;
	    }
	    
    }
	cout<<"No of counters "<<counters<<"\n\n";
}
void Totalwaiting( int customers[], int n3, int serviceinsec[],int servicerange[],int randomnum)
{
    waitingtime=0;
    int servicetime=0;
    for(int i=0;i<8;i++){
        if(randomnum<=servicerange[i]){
            servicetime=serviceinsec[i];
            cout<<"Sevice time for a customer "<<servicetime<<"\n";
            break;
        }
    }
    waitingTime(servicetime,n3,servicerange,serviceinsec);
}
void randomnumgenerate(int randomnum){
    for(int i=0;i<=4;i++){
	    if(randomnum<=range[i]){
	        number=i;
	        cout<<"Customer per minute  ";
	        cout<<custopermin[number]<<endl;
	        break;
	    }
	}
	int servicerange[]={10,15,25,35,50,75,85,100};
	int serviceinsec[]={30,40,50,60,80,90,100,110};
	//cout<<custopermin[number]<<endl;
	int customers[10];
	for(int i=0;i<custopermin[number];i++){
	    customers[i]=i+1;
	}
	int n3 = custopermin[number];
	//cout<<n3<<"\n";
    Totalwaiting(customers, n3, serviceinsec, servicerange,randomnum);
}
void railway(){
    counters=0;
    srand((unsigned) time(NULL));
    int rn;
    cout<<"Enter number of minutes\n";
    cin>>rn;
    for(int i=0;i<rn;i++){
        int randomnum = 1 + (rand() % 100);
        cout<<"random number generated at "<<i<<" minute\n"<<randomnum<<endl;
	    randomnumgenerate(randomnum);
	    countcounters(waitingtime,counters);
    }
    //cout<<"Total waiting time "<<waitingtime<<"\n";
    cout<<"Total number of  counters at the end of simulation "<<counterscount;
	
}
//Driver code
int main() {
    
    railway();
	return 1;
}