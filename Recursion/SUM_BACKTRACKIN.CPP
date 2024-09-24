#include<iostream>
using namespace std;
 int fun(int n ); //prototype
int main()
{
    int n;
    cout<<" enetr the value of n";
    cin>>n;

   cout<<" the sum is"<< fun( n);
    return 0;

}
int fun( int n) // YAHA PAI i KA MATLAB N KI VALUE KO PASS KIYA HAI 
{                       // CALL BY VALUE HAI TOH VARAIVLE SAI FARAK NAHI PADTA
    if (n == 1)
    {
        
        return(1);
    }
    else{
        return( n + fun (n-1));
    
    }
}
