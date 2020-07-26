node* swap_nodes(node* head,int x,int y){
    if(head == nullptr || x == y){
        return;
    }
    node *prevx = NULL,*currx = head;
    while(currx && currx->data != x){
        currx = currx->next;
    }
    node *prevy = NULL,*curry = head;
    while(curry && curry -> data != y){
        curry = curry -> next;
    }
    if(currx == NULL || curry == NULL){
        return;
    }
    if(prevx == NULL){
        head = curry;
    }
    else
    {
        prevx -> next = curry;
    }
    if(prevy == NULL){
        head = currx;
    }
    else{
        prevy -> next = currx;
    }

    node* swap = curry -> next;
    curry -> next = currx -> next;
    currx -> next = swap;
    
}