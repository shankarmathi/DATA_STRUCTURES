/**
 The program must accept N integers as the input. The program must sort the N integers using insertion sort and print all the
iterations of the insertion sorting process as the output.
Boundary Condition(s):
2 <= N <= 100
-10^8 <= Each integer value <= 10^8
Input Format:
The first line contains N.
The second line contains N integers separated by a space.
Output Format:
The lines containing all the iterations of insertion sorting process.
Example Input/Output 1:
Input:
5
7 2 3 1 -5
Output:
7 2 3 1 -5
2 7 3 1 -5
2 3 7 1 -5
1 2 3 7 -5
-5 1 2 3 7
Explanation:
In the first iteration, the integers become 7, 2, 3, 1 and -5.
In the second iteration, the integers 7 and 2 are sorted. Here the integers become 2, 7, 3, 1 and -5.
In the third iteration, the integers 2, 7 and 3 are sorted. Here the integers become 2, 3, 7, 1 and -5.
Similarly, the remaining integers are sorted.
Hence the output is
7 2 3 1 -5
2 7 3 1 -5
2 3 7 1 -5
1 2 3 7 -5
-5 1 2 3 7
Example Input/Output 2:
Input:
7
-9 12 -18 10 11 13 -20
Output:
-9 12 -18 10 11 13 -20
-9 12 -18 10 11 13 -20
-18 -9 12 10 11 13 -20
-18 -9 10 12 11 13 -20
-18 -9 10 11 12 13 -20
-18 -9 10 11 12 13 -20
-20 -18 -9 10 11 12 13
**/

#include<stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d ",&arr[i]);
    }
    for(int i=0;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        for(int k=0;k<n;k++){
            printf("%d ",arr[k]);
        }
        printf("\n");
    }
}