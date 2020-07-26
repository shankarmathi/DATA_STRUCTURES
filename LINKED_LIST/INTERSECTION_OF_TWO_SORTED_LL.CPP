node* findIntersection(node* head1, node* head2)
{
    int f = 0;
    node* head = NULL,*tail = NULL;
    while(head1 && head2){
        if(head1 -> data == head2 -> data){
            if(f == 0){
                head = tail = new node(head1 -> data);
                f++;
            }
            else{
                Node* temp = new node(head1->data);
                tail -> next = temp;
                tail = temp;
            }
            head1 = head1->next;
            head2 = head2 ->next;
        }
        else if(head1->data > head2 -> data){
            head2 = head2 -> next;
        }
        else{
            head1 = head1 -> next;
        }
    }
    return head;
}