#include<iostream>
using namespace std;
int main()
{
    int n,count=0,LastDigit , revnum =0;
    cout<<" Enetr the value of n";
    cin>>n;

    while(n>0)
    {
        LastDigit=n% 10;
         n= n / 10;

         revnum = ( revnum*10)+LastDigit;
        count++;
    }
    cout<<" The reverse no is "<< revnum;

    cout<<" The no of digit is "<< count;

}
