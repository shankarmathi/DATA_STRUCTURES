node* sort(node* head){
    int count[3] = {0},index = 0;
    node* temp1 = head;
    while(temp){
        count[temp->data] += 1;
        temp = temp->next;
    }
    node* temp2 = head;
    while(temp2){
        if(count[index]){
            temp2-> data = index;
            count[index]--;
        }
        else{
            index++;
        }
        temp2 = temp2->next;
    }
}