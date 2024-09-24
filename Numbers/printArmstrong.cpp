#include<iostream>
using namespace std;
int main()
{
    int n,count=0,LastDigit ,sum=0 ;
    cout<<" Enetr the value of n";
    cin>>n;
     int Duplicate_of_N = n;

    while(n>0)
    {
        LastDigit=n% 10;
         n= n / 10;
         sum = (sum +(LastDigit*LastDigit*LastDigit));

         for ( int i=1; i <= 500; i++)
         {
            if( sum == i)
            {
                cout<< i;
            }
         }
       
        
    }

    
    cout<<" The sum of no is \n"<< sum;



}