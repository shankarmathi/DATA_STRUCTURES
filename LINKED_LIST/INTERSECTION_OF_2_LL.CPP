/*
Input:
   List1: 10->15->4->20
   lsit2:  8->4->2->10
Output:
   Intersection List: 4->10
   Union List: 2->8->20->4->15->10
*/

Node* find_mid(Node* head){
    Node* slw = head;
    Node* fast = head->next;
    while(slw && fast && fast->next){
        slw = slw->next;
        fast = fast->next->next;
    }
    return slw;
}
Node* merge(Node* first,Node* second){
    Node* temp = NULL;
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }
    if(first->data <= second->data){
        temp = first;
        temp->next = merge(first->next,second);
    }
    else{
        temp = second;
        temp->next = merge(first,second->next);
    }
    return temp;
}
Node* mergesort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* mid = find_mid(head);
    Node* temp = mid->next;
    mid->next = NULL;
    Node* first = mergesort(head);
    Node* second = mergesort(temp);
    return merge(first,second);
}
Node* findIntersection(Node* head1, Node* head2)
{
    head1 = mergesort(head1);
    head2 = mergesort(head2);
    Node* head,*tail;
    head = tail = NULL;
    while(head1 && head2){
        if(head1->data == head2->data){
            if(head == NULL){
                head = tail = head1;
            }
            else{
                tail -> next = head2;
                tail = tail->next;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        else if(head1 && head1->data < head2->data){
            head1 = head1->next;
        }
        else if(head2){
            head2 = head2->next;
        }
    }
    tail->next = NULL;
    return head;
}