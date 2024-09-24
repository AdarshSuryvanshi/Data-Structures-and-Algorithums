#include<iostream>
using namespace std;
 void fun( int i,int n); //prototype
int main()
{ int n;
cout<<" Enetr the value of n";
cin>>n;


fun(1, n);// call

}
void fun( int i,int n)// define
{
    if ( i>n)
    {
        return;
    }
    else{
        cout<<" Adarsh \n";
        fun ( i+1,n);
    }

}