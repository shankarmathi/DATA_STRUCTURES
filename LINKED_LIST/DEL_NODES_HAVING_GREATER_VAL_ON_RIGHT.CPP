/*
Given a singly linked list, remove all the nodes which have a greater value on its next adjacent element.

Example 1:

Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on their next node. So, after deleting
them, the linked list would like be 15,
11, 6, 3.
Example 2:

Input:
LinkedList = 10->20->30->40->50->60
Output: 60
*/


//PRACTICE LINK:https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1


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