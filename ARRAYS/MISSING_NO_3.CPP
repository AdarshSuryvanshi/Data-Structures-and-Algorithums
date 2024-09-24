
#include <bits/stdc++.h>
using namespace std;

int missingNumber(int a[], int N);

int main()
{
    int N;
    cout<<"Entre the no of elemts of array";cin>>N;
        
    int a[N];
     cout << "Enter elements of the  array: ";

    for (int i = 0; i < N-1; i++) {
        cin >> a[i];
    }

    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}

int missingNumber(int a[], int N) {
    
    int sum1 = N*(N+1)/2; //STORE SUMMATAION OF 1ST ARRAY
    int sum2 =0; // STORES THE SUMMATION OF 2ND ARRAY 
    int ans; // THE DIFFRENCE BETWEEN THEM
  
    for (int i =0; i<N-1;i++){
        sum2 =sum2+ a[i]; 
    }
    ans = sum1-sum2;
    

     return ans;    
 }