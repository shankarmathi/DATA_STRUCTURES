int find_middle(node *head)  
{  
    node *slow_ptr = head;  
    node *fast_ptr = head;  
  
    if (head)  
    {  
        while (fast_ptr && fast_ptr->next)  
        {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
        }  
        return slow_ptr->data;  
    }  
}