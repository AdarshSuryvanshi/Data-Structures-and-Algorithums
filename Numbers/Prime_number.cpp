#include<iostream>
using namespace std;
int main()
{ int n , count=0;
    cout<<" Eneter the value of n";
    cin>>n;

    for ( int i=1 ; i*i<=n; i++)
    {
        if ( n % i== 0)
        {
            count++;
            if ( (n/i)!=i) // BY BIG O(SQRT (N))
            {
                count++;
            }   
            
        }
         
    }
    if ( count ==2)
    {
        cout<<" The no is prime number";
    }
    else {
        cout<< " the no is not prime number";
    }
    
}


#include<iostream>
using namespace std;
int main()
{ int n , count=0;
    cout<<" Eneter the value of n";
    cin>>n;

    for ( int i=1 ; i<=n; i++)
    {
        if ( n % i== 0) // BY BIG O ( N)
        {
            count++;
            
        }
         
    }
    if ( count ==2)
    {
        cout<<" The no is prime number";
    }
    else {
        cout<< " the no is not prime number";
    }
    
}

