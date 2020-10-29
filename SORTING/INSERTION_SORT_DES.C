/**
 The program must accept N integers as the input. The program must sort the N integers in descending order using insertion
sort and print all the iterations of the insertion sorting process as the output.
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
7 -3 9 5 10
Output:
7 -3 9 5 10
7 -3 9 5 10
9 7 -3 5 10
9 7 5 -3 10
10 9 7 5 -3
Explanation:
In the first iteration, the integers become 7, -3, 9, 5 and 10.
In the second iteration, the integers 7 and -3 are sorted in descending order. Here the integers become 7, -3, 9, 5 and 10.
In the third iteration, the integers 7, -3 and 9 are sorted in descending order. Here the integers become 9, 7, -3, 5 and 10.
Similarly, the remaining integers are sorted in descending order.
Hence the output is
7 -3 9 5 10
7 -3 9 5 10
9 7 -3 5 10
9 7 5 -3 10
10 9 7 5 -3
Example Input/Output 2:
Input:
7
14 -80 60 51 -86 49 12
Output:
14 -80 60 51 -86 49 12
14 -80 60 51 -86 49 12
60 14 -80 51 -86 49 12
60 51 14 -80 -86 49 12
60 51 14 -80 -86 49 12
60 51 49 14 -80 -86 12
60 51 49 14 12 -80 -86

*/

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
        int j = i-1;
        int key = arr[i];
        while(j >=0 && arr[j] < key){
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
