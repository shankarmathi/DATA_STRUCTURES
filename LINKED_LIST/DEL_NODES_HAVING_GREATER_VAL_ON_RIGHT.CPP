node* del(node *head)
{
    vector<int> s;
    node* temp = head;
    while(temp){
        if(s.size() == 0){
            s.push_back(temp->data);
            temp = temp -> next;
        }
        else{
            int num = temp->data;
            while(s.size() != 0 && s.back() < num){
                s.pop_back();
            }
            s.push_back(num);
            temp = temp->next;
        }
    }
    node* h,*t;
    h = t = new node(s[0]);
    for(int i=1;i<s.size();i++){
        t->next = new node(s[i]);
        t = t->next;
    }
    t->next = NULL;
    return h;
}