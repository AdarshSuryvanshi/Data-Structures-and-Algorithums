// TYPE 1
#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    int fun( int n);

    
    cout<<fun(n);
}
int fun(int n)
{
    if ( n<=1)
    {
        return n;
    }
    else{
        return fun(n-1)+fun(n-2);
    }

}
 

 //TYPE 2

 /* #include<bits/stdc++.h>
int fun( int n);
using namespace std;
int main()
{
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    cout<<fun(n);
    return 0;
}
int fun(int n)
{
     int last=fun(n-1);
    int Second_last= fun(n-2);
    if ( n<=1)
    {
        return n;
    }

    else{
        return (last + Second_last);
    }

}*/