#include<iostream>
using namespace std;
 int fact(int n ); //prototype
int main()
{
    int n;
    cout<<" enetr the value of n";
    cin>>n;

   cout<<" the factorial is"<< fact( n);
    return 0;

}
int fact( int n) // YAHA PAI i KA MATLAB N KI VALUE KO PASS KIYA HAI 
{                       // CALL BY VALUE HAI TOH VARAIVLE SAI FARAK NAHI PADTA
    if (n == 0)
    {
        
        return(1);
    }
    else{
        return( n * fact (n-1));
    
    }
}
