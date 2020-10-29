/*
The program must accept N integers as the input. The program must sort the N integers using selection sort and print all the
iterations of the selection sorting process as the output.
Boundary Condition(s):
2 <= N <= 100
1 <= Each integer value <= 1000
Input Format:
The first line contains N.
The second line contains N integers separated by a space.
Output Format:
The lines containing all the stages of the selection sort.
Example Input/Output 1:
Input:
5
12 6 15 9 10
Output:
6 12 15 9 10
6 9 15 12 10
6 9 10 12 15
6 9 10 12 15
Explanation:
In the 1 iteration, the first smallest integer 6 is swapped with the first integer 12. Now the integers become 6 12 15 9 10 and
printed.
In the 2 iteration, the second smallest integer 9 is swapped with the second integer 12. Now the integers become 6 9 15 12
10 and printed.
In the 3 iteration, the third smallest integer 10 is swapped with the third integer 15. Now the integers become 6 9 10 12 15 and
printed.
In the 4 iteration, the remaining 2 integers 12 and 15 are already in sorted order. So 6 9 10 12 15 are printed.
Example Input/Output 2:
Input:
6
26 43 49 30 3 63
Output:
3 43 49 30 26 63
3 26 49 30 43 63
3 26 30 49 43 63
3 26 30 43 49 63
3 26 30 43 49 63

*/

#include<stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d ",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d ",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        int min_ind = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min_ind]){
                min_ind = j;
            }
        }
        int t = arr[i];
        arr[i] = arr[min_ind];
        arr[min_ind] = t;
        for(int k=0;k<n;k++){
            printf("%d ",arr[k]);
        }
        printf("\n");
    }
}