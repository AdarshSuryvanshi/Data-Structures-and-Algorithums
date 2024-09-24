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
       
        count++;
    }

    
    cout<<" The sum of no is \n"<< sum;

    cout<<" The no of digit is\n "<< count;

    if ( sum ==Duplicate_of_N )// n chi value last la 0 hote last loop madhe so thats why we
    {               // cannot compare smu with n but with duplicate of n              
        cout<<" The no is armestrong";
    }

    else{
        cout<< "The no is not Aremstrong" ;
    }

}