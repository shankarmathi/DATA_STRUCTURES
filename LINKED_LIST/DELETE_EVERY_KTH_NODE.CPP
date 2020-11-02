/*
Given a singly linked list, Your task is to remove every K-th node of the linked list. Assume that K is always less than or equal to length of Linked List.

Examples :

Input : 1->2->3->4->5->6->7->8  
        k = 3
Output : 1->2->4->5->7->8
As 3 is the k-th node after its deletion list 
would be 1->2->4->5->6->7->8
And now 4 is the starting node then from it, 6 
would be the k-th node. So no other kth node 
could be there.So, final list is:
1->2->4->5->7->8.

Input: 1->2->3->4->5->6  
       k = 1
Output: Empty list 
All nodes need to be deleted
*/

//PRACTICE LINK: https://practice.geeksforgeeks.org/problems/remove-every-kth-node/1

node* del_k_node(node *head,int k)
{
    if(head == NULL || k == 0){
        return head;
    }
    if(k == 1){
        return NULL;
    }
    int c=1;
    node* h = head;
    while(h && h->next){
        if(c%(k-1) == 0){
            h -> next = h -> next ->next;
        }
        h = h->next;
        c++;
    }
    return head;
}