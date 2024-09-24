
#include <bits/stdc++.h>
using namespace std;

int missingNumber(int a[], int N) {
    int Hasharray[N+1] = {0};

    // Outer loop that runs from 1 to n-1:
    for (int i=0; i<N-1; i++) {
         Hasharray[a[i]] = 1;
    }

     for (int i=1;i<=N ;i++)   {
        
        if(Hasharray[i]==0)
        {
            return i;
        }
     } 
     return 0;    
 }

    

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