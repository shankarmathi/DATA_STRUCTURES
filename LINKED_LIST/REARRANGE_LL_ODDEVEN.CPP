//ODD INDEX FOLLOWED BY EVEN INDEX
node *rearrange(node *head)
{
    if(head == NULL || head-> next == NULL){
        return head;
    }
    node* oddh = head;
    node* eveh = head -> next;
    node* oddt,*evet;
    oddt = oddh;
    evet = eveh;
    while(evet && evet->next){
        oddt->next = oddt->next->next;
        evet->next = evet->next->next;
        oddt = oddt->next;
        evet = evet->next;
    }
    oddt->next = eveh;
    return head;
}