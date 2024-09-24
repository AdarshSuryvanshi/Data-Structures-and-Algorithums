#include<iostream>
using namespace std;
int main()
{
    int n,count=0,LastDigit;
    cout<<" Enetr the value of n";
    cin>>n;

    while(n>0)
    {
        LastDigit=n% 10;
        cout<<"The digit is \n ="<<LastDigit<<endl;

        n= n / 10;
        count++;
    }
    cout<<" The no of digit is "<< count;

}