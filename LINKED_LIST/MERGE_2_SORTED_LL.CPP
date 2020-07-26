node* merge(node* temp1, node* temp2) {
    node *head = NULL,*tail=NULL;
    while (temp1 && temp2){
        if(temp1 && temp1->val <= temp2->val){
            if(head == NULL){
                head = tail = temp1;
            }
            else{
                tail->next = temp1;
                tail = temp1;
            }
            temp1 = temp1 -> next;
        }
        else if(temp2 && temp2 -> val < temp2->val){
            if(head == NULL){
                head = tail = temp2;
            }
            else{
                tail->next = temp2;
                tail = temp2;
            }
            temp2 = temp2 -> next;
        }
    }
    if(A != NULL){
        tail->next = temp1;
    }
    if(B != NULL){
        tail-> next = temp2;
    }
    return head;
}