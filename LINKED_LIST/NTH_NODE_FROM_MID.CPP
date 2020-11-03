/*
Given a linked list A of length N and an integer B.

You need to find the value of the Bth node from the middle towards the beginning of the Linked List A.

If no such element exists, then return -1.

NOTE:

Position of middle node is: (N/2)+1, where N is the total number of nodes in the list.


Problem Constraints
1 <= N <= 105
1<= Value in Each Link List Node <= 103
1 <= B <= 105


Input Format
First argument is the head pointer of the linkedlist A.

Second argument is an integer B.



Output Format
Return an integer denoting the value of the Bth from the middle towards the head of the linked list A. If no such element exists, then return -1.
*/

int solve(listnode* A, int B) {
    if(A == NULL || A -> next == NULL){
        return -1;
    }
    listnode* temp = A;
    int len = 0;
    while(temp){
        len++;
        temp = temp->next;
    }
    int mid = len/2+1-B;
    if(mid < 0){
        return -1;
    }
    temp = A;
    while(--mid && temp){
        temp = temp -> next;
    }
    return temp->val;
}