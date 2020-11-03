Node* merge(Node* first,Node* second){
    Node* temp;
    if(first->data < second->data){
        temp = first;
        first = first->bottom;
    }
    else{
        temp = second;
        second = second->bottom;
    }
    Node* ans = temp;
    while(first && second){
        if(first->data < second-> data){
            ans->bottom = first;
            first = first->bottom;
        }
        else{
            ans->bottom = second;
            second = second->bottom;
        }
        ans = ans->bottom;
    }
    ans->bottom = (first != NULL)?first:second;
    ans -> next = NULL;
    return temp;
}
Node *flatten(Node *root)
{
  if(root == NULL || root->next == NULL){
      return root;
  }
  return merge(root,flatten(root->next));
}

