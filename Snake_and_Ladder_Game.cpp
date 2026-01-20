// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int jump(int i);

struct game{
    int a,b;
};

class player{
    
public:
    int pos;
    player(){
        pos=0;
    }
    
};
game *p;
game *temp;
int N;
int x(int position)
{
    temp=p; int i;
    for(i=0; i<N; i++)
    {
        if(position== temp->a)
        {
          position = jump(i);
            
        }
        else
        {
            temp++;
        }
    }
    return position;
}

int jump(int i)
{
    int val,z;
    val=temp->b;
   z= x(val);
    return z;
}







int main() {
    // Write C++ code here
    
    cout<<"\nEnter the number of terms:";
    cin>>N;
    p=(game*)malloc(sizeof(game)*N);
    
    temp=p;
    int i=0;
    for(i;i<N;i++)
    {
        cout<<"\nEnter the Values: \n";
        cin>>temp->a;
        cin>>temp->b;
        temp++;
    }
    temp=p;
    // for(i=0;i<N;i++)
    // {
    //     cout<<"\nPrinting the values:\n";
    //     cout<<temp->a<<endl;
    //     cout<<temp->b;
    //     temp++;
    // }
    int d,c,*m;
    cout<<"\nEnter the number of moves: ";
    cin>>d;
    
    m=(int*)malloc(sizeof(int)*d);
    for(i=0; i<d; i++)
    {
        cout<<"enter value"<<endl;
        cin>>c;
        if(c>0 && c<7)
        {
            m[i]=c;
        }
        else
        {
            cout<<"invaild number"<<endl;
            i--;
        }
        
    }
         
    //int val1=0,val2=0; 
    player P1,P2;
    for(i=0; i<d; i++)
    {
        if(i%2==0)
        {
             P1.pos= P1.pos+m[i];
            if(P1.pos<=99)
            P1.pos= x(P1.pos);
            //cout<<val1;
        }
        
        else
        {
            P2.pos = P2.pos+m[i];
            if(P2.pos<=99)
            P2.pos=x(P2.pos);
            //cout<<val2;
        }
        
    }
        
    if(P1.pos>P2.pos)
    {
        cout<<"A "<<P1.pos<<endl;
    }
    else
    {
        cout<<"B "<<P2.pos;
    }
    
    
    
    
}