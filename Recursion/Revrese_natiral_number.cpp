#include<iostream>
using namespace std; 
void fun( int n ,int N);
int main()
{
    int n;
    cout<<" The value of n";
    cin>>n;
    fun(n,n);
}
 void fun( int i,int n)
 {
    if ( i<1)
    {
        return;
    }
    else{
         cout<<i<<"\n";
         fun(i-1,n);

    }
 }