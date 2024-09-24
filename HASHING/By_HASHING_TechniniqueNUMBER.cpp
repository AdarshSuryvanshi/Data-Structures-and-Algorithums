#include <iostream>
using  namespace std;
int main()
{
    int n;
    cout<<" Enetr the value of n for size ofa an array";
    cin>>n;
    int arr[n];
    for ( int i=0;i<n;i++)
    {
        cin>> arr[i]; // HERE I INPUT AN ARRAYOF SIZE N
    }
     // PRECOMPUTING OR PRECALCULATIONS.
     
    int hash[13] = {0}; // ISKA MATLAB PURE ARRAY KE SIZE MAI HAR EK INDEX MAI 0
    // INITIALIZE HO GAYA.IT MEANS HAR INDEX 0 INITIZALISE
     
     // HERE YOU CAN STORED MAX SIZE TILL 1000000
   
     for ( int i=0; i< n; i++)
     {
        hash[arr[i]] = hash[arr[i]]+ 1;
     }

     int Q;  //THIS IS FOR YOUR QUERIES HOW MANY TIMES YOU HAVE TO ASK Q YOU CAN ASK 
    cout<<" Enter how many times you want ask queries \n";
    cin>>Q;

        while ( Q--)  // JITNE Q UTNE BAAR LOOP CHALEGA 0 AYA LOOP FALSE 
     {   
        int number; // konas element cheked karna hai.
        cout<<"\n The number you want to cheked is"<<"\n";
        cin>>number;

        cout<<" The appered in array is "<<hash[number]<<" times \n";
    }
}   