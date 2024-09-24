#include<iostream>
using namespace std;
 int count =0;
int main()
{ void print(); //prototype
    print();// call
}
void print()// define
{
    if ( count ==3)
    return;
    else{
        cout<<count;
        count++;
        print();
    }
}
