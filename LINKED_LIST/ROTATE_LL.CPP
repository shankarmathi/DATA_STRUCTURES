node* rotate(node* head, int k)
{
    node* slow = NULL;
    node* fast = head;
    while(fast && k){
        slow = fast;
        fast = fast->next;
        k--;
    }
    if(fast == NULL){
        return head;
    }
    while(fast->next){
        fast = fast->next;
    }
    if(fast){
    fast -> next = head;
    head = slow->next;
    slow->next = NULL;;
    }
    return head;
}
