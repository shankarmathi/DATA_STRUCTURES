node* del_k_node(node *head,int k)
{
    if(head == NULL || k == 0){
        return head;
    }
    if(k == 1){
        return NULL;
    }
    int c=1;
    node* h = head;
    while(h && h->next){
        if(c%(k-1) == 0){
            h -> next = h -> next ->next;
        }
        h = h->next;
        c++;
    }
    return head;
}