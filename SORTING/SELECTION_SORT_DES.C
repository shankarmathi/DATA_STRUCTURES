/**
 The program must accept N integers as the input. The program must sort the N integers in descending order using selection
sort and print all the iterations of the selection sorting process as the output.
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
8 6 3 90 4
Output:
90 6 3 8 4
90 8 3 6 4
90 8 6 3 4
90 8 6 4 3
Explanation:
In the 1 iteration, the first largest integer 90 is swapped with the first integer 8. Now the integers become 90 6 3 8 4 and
printed.
In the 2 iteration, the second largest integer 8 is swapped with the second integer 6. Now the integers become 90 8 3 6 4 and
printed.
In the 3 iteration, the third largest integer 6 is swapped with the third integer 3. Now the integers become 90 8 6 3 4 and
printed.
In the 4 iteration, the fourth largest integer 4 is swapped with the fourth integer 3. Now the integers become 90 8 6 4 3
and printed.
Example Input/Output 2:
Input:
6
82 12 67 4 5 78
Output:
82 12 67 4 5 78
82 78 67 4 5 12
82 78 67 4 5 12
82 78 67 12 5 4
82 78 67 12 5 4
**/

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
        int max_ind = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] > arr[max_ind]){
                max_ind = j;
            }
        }
        int t = arr[i];
        arr[i] = arr[max_ind];
        arr[max_ind] = t;
        for(int k=0;k<n;k++){
            printf("%d ",arr[k]);
        }
        printf("\n");
    }
}