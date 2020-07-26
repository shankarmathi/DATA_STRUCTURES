Node* find_mid(Node* head){
    Node* slw = head;
    Node* fast = head->next; //care
    while(slw && fast && fast -> next){
        slw = slw->next;
        fast = fast->next->next;
    }
    return slw;
}
Node* merge(Node* a,Node* b){
    Node* temp = NULL;
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    if(a->data <= b->data){
        temp = a;
        temp->next = merge(a->next,b);
    }
    else{
        temp = b;
        temp->next = merge(a,b->next);
    }
    return temp;
}
Node* mergeSort(Node* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* mid = find_mid(head);
    Node* temp = mid->next;
    mid->next = NULL;
    Node* first = mergeSort(head);
    Node* second = mergeSort(temp);
    Node* ans = merge(first,second);
    return ans;
}
