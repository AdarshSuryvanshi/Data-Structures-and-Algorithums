#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cout<<" enetr the n";
    cin>>n;
    int arr1[n];
    

    for (int i =0;i<n ;i++)
    {
        cin>>arr1[i];
    }

    int arr2[n];
       for (int i =0;i<n ;i++)
    {
        cin>>arr2[i];
    }
    int ans = Find_union(arr1,arr2,n);
}

    int Find_union(int arr1[],int arr2[],int n){

    set<int>st;

       for (int i =0;i<n ;i++) // INSERTION OF ARRAY1 UNIQUE ELEMENTS IN SET 
    {
        st.insert(arr1[i]); // ST IS THE VARAIBLE NAME .. SET MAI UNIQUE ELEMENTS ENTRE HO RAHE 
       
     }                               //HAI OF ARRY 1

       for (int i =0;i<n ;i++)//INSERTION OF ARRAY2 UNIQUE ELEMENTS IN SET
    {
        st.insert(arr2[i]);
         
    }

    vector<int> Union[ st.size()];
    int i=0;

    for (int i= 0;i<st.size();i++)
    {
        //Union->push_back(st);
    }
   

    cout<<" The elemets in the union array are as follows";

          for (int i =0;i<st.size() ;i++)
    {
        Union->push_back(i);
    }
   
    


}

