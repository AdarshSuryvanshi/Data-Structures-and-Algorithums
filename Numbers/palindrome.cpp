#include<iostream>
using namespace std;
int main()
{
    int n,count=0,LastDigit , revnum =0;
    cout<<" Enetr the value of n";
    cin>>n;
     int Duplicate_of_N = n;

    while(n>0)
    {
        LastDigit=n% 10;
         n= n / 10;

         revnum = ( revnum*10)+LastDigit;
        count++;
    }

    
    cout<<" The reverse no is \n"<< revnum;

    cout<<" The no of digit is\n "<< count;

    if ( revnum ==Duplicate_of_N )// n chi value last la 0 hote last loop madhe so thats why we
    {               // cannot compare revnum with n but with duplicate of n              
        cout<<" The no is palindrome";
    }

    else{
        cout<< "The no is not pailndrome" ;
    }

}