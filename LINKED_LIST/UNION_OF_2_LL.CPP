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

Node* getunion(Node* head1,Node* head2) 
{ 
    Node* head = NULL,*tail = NULL; 
    Node *t1 = head1, *t2 = head2;  
    while (t1 != NULL && t2 != NULL) {  
        if (t1->data < t2->data) { 
            if(head == NULL){
                head = tail = t1;
            }
            else{
                tail->next = t1;
                tail = tail->next;
            }
            t1 = t1->next;
        } 
        else if (t1->data > t2->data)
        { 
            if(head == NULL){
                head = tail = t2;
            } 
            else{
                tail->next = t2;
                tail = tail->next;
            }
            t2 = t2->next;
        } 
        else
        { 
            tail->next = t1;
            tail = tail->next;
            t1 = t1->next; 
            t2 = t2->next; 
        } 
    } 
    while (t1 != NULL) { 
        tail->next = t1;
        tail = tail->next;
        t1 = t1->next; 
    } 
    while (t2 != NULL) { 
        tail->next = t2;
        tail = tail->next;
        t2 = t2->next; 
    } 
  
    return head; 
}