#include<iostream>
using namespace std;
 void fun( int i,int n); //prototype
int main()
{ int n;
cout<<" Enetr the value of n";
cin>>n;


fun(1, n);// call //we can also give value in call 

}
void fun( int i,int n)// define
{
    if ( i>n)
    {
        return;
    }
    else{
        
        fun ( i+1,n);
        cout<< i<<"\n"; //SAME LOGIC AS PREVOIUS CODE REVRSE IN I+1
    }

}