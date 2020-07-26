node *reverse (node *head, int k)
{
    int i=0;
    node* prev = NULL,*curr = head,*next = NULL;
    if(curr){
        next = curr->next;
    }
    while(curr && i < k){
        i++;
        curr->next = prev;
        prev = curr;
        curr = next;
        if(curr){
            next = curr->next;
        }
    }
    if(next){
        head -> next = reverse(next,k);
    }
    return prev;
}

//USING STACK
node* reverse(node* head, int k) 
{ 
    stack<node*> s; 
    node* curr = head; 
    node* prev = NULL; 
    while (curr != NULL) {  
        int c = 0; 
        while (curr != NULL && c < k) { 
            s.push(curr); 
            curr = curr -> next; 
            c++; 
        }  
        while (s.size()) {  
            if (prev == NULL) { 
                prev = s.top(); 
                head = prev; 
                s.pop(); 
            }
            else { 
                prev->next = s.top(); 
                prev = prev->next; 
                s.pop(); 
            } 
        } 
    }  
    prev->next = NULL; 
    return head; 
} 