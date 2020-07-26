int last_n_node(node* head, int n)
{
    node* t1,*t2;
    t1 = t2 = head;
    int sum1 = 0,sum2 = 0;
    while(t1 && n--){
        sum1 += t1->data;
        t1 = t1->next;
    }
    while(t1){
        sum1 += t1->data;
        sum2 += t2->data;
        t1 = t1->next;
        t2 = t2->next;
    }
    return sum1 - sum2;
}