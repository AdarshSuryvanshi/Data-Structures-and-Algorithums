#include <iostream>
using  namespace std;
int main()
{
    int arr[1000000];//  IF HERE I DECLARE AN ARRAY OF 10 TO THE POWER 5
}                   // IT WILL BE OKAY BUT IF I TRIED TO DECLARE BEYOND THAT IT 
                // WILL BE THE ""SEGMENTATION FALULT"""
                // CODE WILL NOT RUN

                //SOLUTION.
                // IF YOU HAVE TO DECLARE AN ARRAY BEYOND 10 TO THE POWER 5
                // SO DECALRE IT GLOBALLY ( ABOVE THE MAIN FUNCTION )
                // NEVER SHOW SEGMENTATION FAULT.