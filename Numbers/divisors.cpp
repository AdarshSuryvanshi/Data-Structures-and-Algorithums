#include<iostream>
using namespace std;
int main()
{
    int n , count=0 ; 
    cout<<" Eneter the value of n";
    cin>>n;

    for ( int i=1 ; i<=n; i++)
    {
        if ( n % i== 0)
        {
            cout<< " divisor = \n "<< i;
            count++;
        }
         
    }
    cout<<"Total no of divisors is ="<< count;
}