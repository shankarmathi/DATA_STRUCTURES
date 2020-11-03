int isCircular(node *head) 
{ 
    // An empty linked list is circular 
    if (head == NULL) 
       return 1;  
    node *node = head->next; 

    while (node != NULL && node != head) 
       node = node->next; 
  
    return (node == head); 
}