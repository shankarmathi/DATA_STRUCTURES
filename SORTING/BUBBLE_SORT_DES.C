/**
 The program must accept N integers as the input. The program must sort the N integers in descending order using bubble sort
and print all the iterations of the bubble sorting process as the output.
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
4
3 4 1 6
Output:
4 3 1 6
4 3 1 6
4 3 6 1
4 3 6 1
4 6 3 1
6 4 3 1
Explanation:
In the 1 iteration, the integers 3 and 4 are swapped (where 3 is lesser than 4).
After swapping, the integers become 4 3 1 6 and printed.
In the 2 iteration, the integers 3 and 1 are not swapped (where 3 is greater than 1).
So the same integers 4 3 1 6 are printed.
In the 3 iteration, the integers 1 and 6 are swapped (where 1 is lesser than 6).
After swapping, the integers become 4 3 6 1 and printed.
In the 4 iteration, the integers 4 and 3 are not swapped (where 4 is greater than 3).
So the same integers 4 3 6 1 are printed.
Similarly, the remaining integers are printed.
Example Input/Output 2:
Input:
5
34 67 21 55 10
Output:
67 34 21 55 10
67 34 21 55 10
67 34 55 21 10
67 34 55 21 10
67 34 55 21 10
67 55 34 21 10
67 55 34 21 10
67 55 34 21 10
67 55 34 21 10
67 55 34 21 10
**/

#include<stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d\n",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d ",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j] < arr[j+1]){
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
            for(int k=0;k<n;k++){
                printf("%d ",arr[k]);
            }
            printf("\n");
        }
    }
}
