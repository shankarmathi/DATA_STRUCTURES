node* remove_dup(node* head) {
    node* temp = head;
    while(temp){
        int currdata = temp->data;
        node* prev = temp;
        while(temp && temp->data == currdata){
            temp = temp -> next;
        }
        prev->next = temp;
    }
    return head;
}