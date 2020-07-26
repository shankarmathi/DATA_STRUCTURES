//BRUTE FORCE
struct node* find_merge_point(struct node* temp1,struct node* temp2){
    struct node* a = temp1;
    struct node* b = temp2;
    int len1 = 0,len2 = 0;
    while(a){
        len1++;
        a = a->next;
    }
    a = temp1;
    while(b){
        len2++;
        b = b->next;
    }
    b = temp2;
    for(int i=0;i<len1;i++){
        b = temp2;
        for (int j=0;j<len2;j++)
        {
            if(a == b){
                return a;
            }
            b = b -> next;
        }
        a = a ->next;
    }
    return NULL;
}

//USING SET
struct node* find_merge_point(struct node* temp1,struct node* temp2){
    struct node* a = temp1;
    struct node* b = temp2;
    int len1 = 0,len2 = 0;
    while(a){
        len1++;
        a = a->next;
    }
    a = temp1;
    while(b){
        len2++;
        b = b->next;
    }
    b = temp2;
    set<node*> s;
    for(int i=0;i<len1;i++){
        s.insert(a);
        a = a -> next;
    }
    for(int i=0;i<len2;i++){
        if(s.find(b) != s.end()){
            return b;
        }
        b = b->next;
    }
    return NULL;
}

//efficient way
struct node* find_merge_point(struct node* A,struct node* B){
    if(A == NULL || B == NULL){
        return NULL;
    }
    struct node* temp1 = A;
    struct node* temp2 = B;
    int l1 = 0,l2 = 0;
    while(A){
        l1++;
        A = A->next;
    }
    while(B){
        l2++;
        B = B->next;
    }
    int diff;
    if(l1 > l2){
        diff = l1-l2;
        for(int i=0;i<diff;i++){
            temp1 = temp1->next;
        }
    }
    else{
        diff = l2-l1;
        for(int i=0;i<diff;i++){
            temp2 = temp2 -> next;
        }
    }
    while(temp1 && temp2){
        if(temp1 == temp2){
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return  NULL;
}