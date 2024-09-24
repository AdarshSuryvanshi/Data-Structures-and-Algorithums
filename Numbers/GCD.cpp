/*#include<iostream>
using namespace std;
int main()
{ int num1 , num2; 
    cout<<" Eneter the value of n";
    cin>>num1 >>num2;

    for( int i= 1 ; i<=min(num1,num2);i++) //GCD TYPE 1
    {                                      // BIG O( MIN(NUM1, NUM2))
        if ( num1 % i==0 && num2 % i==0)
        {
            cout<< i;
        }
    }
}*/

/*#include<iostream>
using namespace std;
int main()
{ int num1 , num2; 
    cout<<" Eneter the value of n";
    cin>>num1 >>num2;

    for( int i= min(num1,num2) ; i>=1 ;i --) //GCD TYPE 1
    {                                      // BIG O( MIN(NUM1, NUM2))
        if ( num1 % i==0 && num2 % i==0)
        {
            cout<< i;
            break;
        }
    }
}*/

//TYPE 3 :- WORST CASE

#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cout<< " The no are a and b is";
    cin>> a>> b;

    while(a>0 && b>0)
    {
       if (a>b)
       {
         a= a % b;
       } 
       else{
        b = b% a;
       }

       if ( a == 0)
       {
        cout << " The gcd is "<<b;
       }

       else{
         cout<< " The gcd is "<< a;
       }

    }
}
