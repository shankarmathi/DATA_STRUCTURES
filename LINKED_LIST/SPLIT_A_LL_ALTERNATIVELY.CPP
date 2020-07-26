node* a,*b;
void alternate(node* head) 
{
    if(head == NULL ){
        a = NULL;
        b = NULL;
    }
    else if(head -> next == NULL){
        a = head;
        b =  NULL;
        return;
    }
    else{
        node* tempa,*tempb;
        a = tempa = head;
        b = tempb = head->next;
        head = head->next->next;
        while(head && head->next){
            tempa->next = head;
            tempb->next = head->next;
            tempa = tempa -> next;
            tempb = tempb -> next;
            head = head -> next -> next;
        }
        if(head){
            tempa -> next = head;
            tempa = tempa->next;
            head = head->next;
        }
        tempa->next = NULL;
        tempb-> next = NULL;
    }
}