/**
 Fill in the blanks with code so that the program sorts the integers in ascending order using merge sortalgorithm.
Example Input/Output 1:
Input:
8
70 20 10 50 80 90 30 40
Output:
10 20 30 40 50 70 80 90
**/

#include<stdio.h>
#include <stdlib.h>
void sort(int arr[], int N)
{
    mergeSort(arr, 0, N-1);
}
void mergeSort(int arr[], int left, int right)
{
    if( left < right)
    {
    int mid = (left + right) / 2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr, left, mid, right);
    }
}
void merge(int arr[], int left, int mid, int right)
{
    int start1 = left;
    int start2 = mid+1;
    int temp[(mid - left +1) + (right - mid)], tempIndex = 0;
    while( start1 <= mid && start2  <= right)
    {
    if(arr[start1] < arr[start2])
    {
        temp[tempIndex++] = arr[start1++];
    }
    else
    {
        temp[tempIndex++] = arr[start2++];
    }
}
    while(start1 <= mid)
    {
        temp[tempIndex++] = arr[start1++];
    }
    while(start2 <= right)
    {
    temp[tempIndex++] = arr[start2++];
    }
    tempIndex = 0;
    for(int index = left;index <= right; index++){}
    arr[index] = temp[tempIndex++];
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    int arr[N];
    for(int index = 0; index < N; index++)
    {
        scanf("%d", &arr[index]);
    }
    sort(arr, N);
    for(int index = 0; index < N; index++)
    {
    printf("%d ", arr[index]);
    }
    return 0;
}