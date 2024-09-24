#include<iostream>
using namespace std;
 void fun( int n,int fact); //prototype fact=1;
int main()
{
    int n;
    cout<<" enetr the value of n";
    cin>>n;

    fun( n,1);

}
void fun( int i,int fact) // YAHA PAI i KA MATLAB N KI VALUE KO PASS KIYA HAI 
{                       // CALL BY VALUE HAI TOH VARAIVLE SAI FARAK NAHI PADTA
    if (i<1)
    {
        cout<<" The factorial is ="<<fact;
        return;
    }
    else{
        fun( i -1,fact*i);
    
    }
}