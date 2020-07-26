//BRUTE FORCE
node * mergeResult(node *node1,node *node2)
{
    node* head  = NULL,*tail = NULL;
    if(node1->data <= node2->data){
        head = tail = node1;
        node1 = node1 -> next;
    }
    else{
        head = tail = node2;
        node2 = node2 -> next;
    }
    while(node1 && node2){
        if(node1->data <= node2->data){
            tail->next = node1;
            tail = node1;
            node1 = node1->next;
        }
        else{
            tail->next = node2;
            tail = node2;
            node2 = node2->next;
        }
    }
    if(node1){
        tail->next = node1;
    }
    if(node2){
        tail->next = node2;
    }
    node* prev = NULL,*curr = head,*next = NULL;
    if(curr == NULL || curr->next == NULL){
        return head;
    }
    else{
        next = curr->next;
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = next;
            if(curr){
                next = curr->next;
            }
        }
    }
    return prev;
}

//insert @ begin

node * mergeResult(node *node1,node *node2)
{
    node* head = NULL;
    while(node1 && node2){
        if(node1->data <= node2->data){
            node* t = node1->next;
            node1->next = head;
            head = node1;
            node1 = t;
        }
        else{
            node* t = node2->next;
            node2->next = head;
            head = node2;
            node2 = t;
        }
    }
    while(node1){
        node* t = node1->next;
        node1->next = head;
        head = node1;
        node1 = t;
    }
    while(node2){
        node* t = node2->next;
        node2->next = head;
        head = node2;
        node2 = t;
    }
    return head;
}