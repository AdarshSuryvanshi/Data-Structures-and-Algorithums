#include<iostream>
using namespace std;
 void fun( int n,int sum); //prototype
int main()
{
    int n;
    cout<<" enetr the value of n";
    cin>>n;

    fun( n,0);

}
void fun( int i,int sum) // YAHA PAI i KA MATLAB N KI VALUE KO PASS KIYA HAI 
{                       // CALL BY VALUE HAI TOH VARAIVLE SAI FARAK NAHI PADTA
    if (i<1)
    {
        cout<<" The sum is ="<<sum;
        return;
    }
    else{
        fun( i -1,sum+i);
    
    }
}
