/**
The program must accept N integers as the input. The program must sort the N integers using bubble sort and print all the
iterations of the bubble sorting process as the output.
Boundary Condition(s):
2 <= N <= 20
1 <= Each integer value <= 10^8
Input Format:
The first line contains N.
The second line contains N integers separated by a space.
Output Format:
The lines containing all the iterations of bubble sorting process.
Example Input/Output 1:
Input:
5
4 1 2 5 3
Output:
1 4 2 5 3
1 2 4 5 3
1 2 4 5 3
1 2 4 3 5
1 2 4 3 5
1 2 4 3 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
Explanation:
In the 1 iteration, the integers 4 and 1 are swapped (where 4 is greater than 1).
After swapping, the integers become 1 4 2 5 3 and printed.
In the 2 iteration, the integers 4 and 2 are swapped (where 4 is greater than 2).
After swapping, the integers become 1 2 4 5 3 and printed.
In the 3 iteration, the integers 4 and 5 are not swapped (where 4 is lesser than 5).
So the same integers 1 2 4 5 3 are printed.
In the 4 iteration, the integers 5 and 3 are swapped (where 5 is greater than 3).
After swapping, the integers become 1 2 4 3 5 and printed.
Similarly, the remaining integers are printed.
Example Input/Output 2:
Input:
5
45 22 34 79 23
Output:
22 45 34 79 23
22 34 45 79 23
22 34 45 79 23
22 34 45 23 79
22 34 45 23 79
22 34 45 23 79
22 34 23 45 79
22 34 23 45 79
22 23 34 45 79
22 23 34 45 79
**/


#include<stdio.h>
#include <stdlib.h>
#define pp(arr,n) for(int i=0;i<n;i++)printf("%d ",arr[i]);
int main()
{
    int n,i=0;
    scanf("%d\n",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d ",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= temp;
            }
            pp(arr,n);
            printf("\n");
        }
    }
}