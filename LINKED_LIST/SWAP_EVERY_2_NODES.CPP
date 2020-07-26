node* swap(node* head){
    if(head == NULL || head -> next == NULL){
        return;
    }
    node* ans = head->next;
    node* p = head,*q,*temp;
    while(1){
        q = p->next;
        temp = q->next;
        q->next = p;
        if(temp == NULL ||temp->next == NULL){
            p->next = temp;
            break;
        }
        p->next = temp->next;
        p = temp;
    }
    return ans;
}