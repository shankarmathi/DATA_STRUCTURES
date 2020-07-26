node* rev(node* head){
    node* prev = NULL;
    node* curr = head;
    node* next = NULL;
    while(curr){
        next = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

node* add(node* first, node* second)
{
    node* head,*tail;
    head = tail = NULL;
    node* t1 = rev(first);
    node* t2 = rev(second);
    int carry = 0;
    while(t1 || t2){
        int num1 = t1?t1->data:0;
        int num2 = t2?t2->data:0;
        if(head == NULL){
            head = tail = new node((num1+num2+carry)%10);
            carry = (num1+num2+carry)/10;
        }
        else{
            node* temp = new node((num1+num2+carry)%10);
            carry = (num1+num2+carry)/10;
            temp -> next = head;
            head = temp;
        }
        if(t1){
            t1 = t1 -> next;
        }
        if(t2){
            t2 = t2 -> next;
        }
    }
    if(carry){
        node* temp = new node(carry);
        temp -> next = head;
        head = temp;
    }
    return head;
}
