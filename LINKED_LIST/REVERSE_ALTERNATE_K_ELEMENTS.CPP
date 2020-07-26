node *reverse(node *head,int k)  
{  
    node* curr = head;  
    node* next;  
    node* prev = NULL;  
    int c = 0;  
    while (curr && count < k)  
    {  
        next = curr -> next;  
        curr -> next = prev;  
        prev = curr;  
        curr = next;  
        c++;  
    }
    if(head != NULL){
        head->next = curr;
    }  
    c = 0;  
    while(c < k-1 && curr != NULL )  
    {  
    curr = curr -> next;  
    count++;  
    }  
    if(current != NULL){  
        curr -> next = reverse(curr -> next, k);  
    }
    return prev;  
}