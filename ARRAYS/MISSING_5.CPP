
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
    
    int ans;
  int XOR1=0;
  
  int XOR2=0;
  for (int i =0 ;i<N-1;i++) // XOR OF 1 TO N-1 ARRYA ELEMNTS
  {
    
        XOR2 = XOR2 ^a[i] ;
        XOR1 =XOR1^(i+1);
       
  }
   XOR1 = XOR1^N;
   ans = XOR1 ^ XOR2;


  
    

     return ans;    
 }