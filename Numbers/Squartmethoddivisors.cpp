#include<iostream>
using namespace std;
int main()
{ int n;
    cout<<" Eneter the value of n";
    cin>>n;

    for ( int i=1 ; i*i<=n; i++)
    {
        if ( n % i== 0)// BY BIG O(SQRT (N))
        {
             cout<< " divisor = \n "<< i;
            if ( (n/i)!=i)
            {
            
                cout<< " divisor = \n "<< n/i; // PRINT IN NOT A SORTED ORDER
            }   
            
        }
         
    }
    
}

/*#include<bits/stdc++.h>
using namespace std;
int main()
{ int n;
    cout<<" Eneter the value of n";
    cin>>n;

    vector<int> ls;

    for ( int i=1 ; i*i<=n; i++)
    {
        if ( n % i== 0)
        {
            ls.push_back(i);
             
            if ( (n/i)!=i)
            {
            
                ls.push_back(n/i); // PRINT IN NOT A SORTED ORDER
            }   
            
        }
         
    }
    sort(ls.begin(),ls.end());
    for ( auto it = ls;)  {
    cout<<it<<" ";
    }
    
}*/