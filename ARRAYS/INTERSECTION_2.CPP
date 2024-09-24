#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> sorted_arrays(int arr1[],int arr2[] ,int n, int m);
int main()
{
    int n;
    cout<<"Entre the no of elemts of array1";cin>>n;
        
    int arr1[n];
     cout << "Enter elements of the first array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    int m;
    cout<<"Entre the no of elemts array2";cin>>m;

      int arr2[m];

    cout << "Enter elements of the second array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

     vector<int> Ans =     sorted_arrays(arr1,arr2 ,n,m);
   
     cout << " Intersection of arr1 and arr2 is  " << endl;
    for (auto & val: Ans)
    cout << val << " ";
     

}
vector<int> sorted_arrays(int arr1[],int arr2[] ,int n, int m){

    int i =0;
    int j =0;
    vector<int> Ans; // KADHI PAN VECTOR MADHE SIZE MENTIONED KELI KI ERROR DAKHVNAR 
    // KADHI PAN SIZE MENTIONED KARYACHI GARAJ NAHI ONLY PUSHBACK ADD HOTIL
    while(i<n && j<m)
    {
       if ( arr1[i]<arr2[j])
       {
            i++;
       }
      else if ( arr1[j] < arr2[i]) // IF I TAKE VISITED TO CHECK UNIQUENESS THEN 
       {// SPACE COMPLEXITY IS O(M) , BUT I CANT TAKE THEN FOR NOT USING EXTRA VARAIBLE IT IS O(1)
            j++;
       }
       else {
        
        Ans.push_back(arr1[i]); // IF THEY ARE EQAUAL THEN 
        i++; // WHEN THEY ARE EQUAL
        j++;
                // TIME COMPLEXITY IS 
       }
         
    
    }  
    
  return Ans;
       
    }