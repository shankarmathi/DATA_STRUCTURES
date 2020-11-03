listnode* solve(listnode* A, int B) {
    int count = 0;
    listnode *prev = NULL,*curr = A,*next = NULL;
    while(count < B && curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count += 1;
    }
    if(A){
        A->next = curr;
    }
    count  = 0;
    while(curr && count < B-1){
        curr = curr -> next;
        count += 1;
    }
    if(curr){
        curr -> next = solve(curr->next,B);
    }
    return prev;
}