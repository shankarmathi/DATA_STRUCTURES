//method 1
node* remove_node(node* head,int n){
    node* temp = head;
    int length = 0,position;
    while (temp)
    {
        length++;
        temp = temp -> next;
    }
    position = length-n;
    if(position == 1){
        return head->next;
    }
    temp = head,length = 0;
    while(temp){
        length++;
        if(position == len){
            temp -> next = temp->next->next;
            break;
        }
        temp = temp->next;
    }
    return head;
}
//method 2
node* remove_node(node* head,int n){
    node* slow = head;
    node* fast = head;
    for (int i = 1; i <= n && fast; i++)
    {
        fast = fast -> next;
    }
    if (fast == NULL)
    {
        head = head -> next;
        return head;
    }
    while(fast -> next){
        fast = fast->next;
        slow = slow -> next;
    }
    slow->next = slow->next->next;
    return head;   
}