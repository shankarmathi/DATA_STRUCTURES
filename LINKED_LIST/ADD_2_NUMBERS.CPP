/*
Given two numbers represented by two lists, write a function that returns the sum list. The sum list is list representation of the addition of two input numbers.
Example:

Input:
List1: 5->6->3 // represents number 365
List2: 8->4->2 // represents number 248
Output:
Resultant list: 3->1->6 // represents number 613
Explanation: 365 + 248 = 613

Input:
List1: 7->5->9->4->6 // represents number 64957
List2: 8->4 // represents number 48
Output:
Resultant list: 5->0->0->5->6 // represents number 65005
Explanation: 64957 + 48 = 65005
*/

//PRACTISE LINK: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

//if input is already reversed then dont need to reverse if not we have to reverse.

node* rev(node* head){
    node* prev = NULL;
    node* curr = head;
    node* next = NULL;
    while(curr){
        next = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

node* add(node* first, node* second)
{
    node* head,*tail; //to store the result
    head = tail = NULL;
    node* t1 = rev(first); // reversing first list
    node* t2 = rev(second); // reversing second list
    int carry = 0;
    while(t1 || t2){
        int num1 = t1?t1->data:0;
        int num2 = t2?t2->data:0;
        if(head == NULL){
            head = tail = new node((num1+num2+carry)%10);
            carry = (num1+num2+carry)/10;
        }
        else{
            node* temp = new node((num1+num2+carry)%10);
            carry = (num1+num2+carry)/10;
            temp -> next = head;
            head = temp;
        }
        if(t1){
            t1 = t1 -> next;
        }
        if(t2){
            t2 = t2 -> next;
        }
    }
    if(carry){
        node* temp = new node(carry);
        temp -> next = head;
        head = temp;
    }
    return head;
}
