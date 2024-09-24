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
 void fun( int i,int n)//  CODE REVRSE CHA AHE PAN BECOZ OF LINE NO 20 IT IS PRINTING
 {  // IN 1 TO N MANNER.
    if ( i<1)
    {
        return;
    }
    else{
         
         fun(i-1,n);// BECOZ MI ADHI FUNCTION CALL KELA MM PRINT KELA SO THAT
         cout<<i<<" \n"; //JEVHA CODE TERMINATE HOIL TEVA REVRSE FASION MADHE
//      REVRSE CHA CODE HA STAIGHT BANEL
    }
 }