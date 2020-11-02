#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(){
        data = 0;
        next = NULL;
        prev = NULL;
    }

    node(int num){
        data = num;
        next = NULL;
        prev = NULL;
    }
};

class dll{
    public:
    node* head;
    dll(){
        head = NULL;
    }
    dll(node* n){
        head = n;
    }

    void append_node(node* n)
    {
        if(head == NULL){
            head = n;
        }
        else{
            node* ptr = head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = n;
            n -> prev = ptr;

        }
    }

    void prepend_node(node *n)
    {
        if(head == NULL){
            head = n;
        }
        else{
            head->prev = n;
            n->next = head;
            head = n;
        }
    }

    void insert_node_after(int pos,node* n){
        node* ptr = head;
        for(int i=1;ptr && i<pos-1;i++){
            ptr = ptr->next;
        }
        if(n){
            node* nextnode = ptr->next;
            if(nextnode == NULL){
                ptr -> next = n;
                n->prev = ptr;
            } 
            else{
                n->next = nextnode;
                nextnode->prev = n;
                n->prev = ptr;
                ptr->next = n;
            }
        }
    }

    void deletenode(int pos){
        node* ptr = head;
        for(int i=1;ptr && i < pos;i++){
            ptr = ptr->next;
        }
        if(ptr){
            if(ptr == head){
                head = head->next;
            }
            else{
                node* nextnode = ptr->next;
                node* prevnode = ptr->prev;
                if(nextnode == NULL){
                    prevnode -> next = NULL;
                }
                else{
                    prevnode->next = nextnode;
                    nextnode->prev = prevnode;
                }
            }
        }
    }

    void printlist(){
        if(head){
            node* temp = head;
            while(temp){
                cout<<temp->data;
                temp = temp -> next;
            }
        }
    }

};

int main()
{
    dll obj;
    int choose,num,pos;
    do{
        cout<<"choose from the option\n";
        cout<<"0. EXIT\n 1.APPEND\n 2.PREPEND\n 3.INSERT_BTWN\n 4.DELETE\n 5.PRINT\n";
        cin>>choose;
        node* n1 = new node();
        switch(choose){
            case 0:
            break;
            case 1:
            cin>>num;
            n1->data = num;
            obj.append_node(n1);
            break;
            case 2:
            cin>>num;
            n1->data = num;
            obj.prepend_node(n1);
            break;
            case 3:
            cin>>num>>pos;
            n1->data = num;
            obj.insert_node_after(pos,n1);
            break;
            case 4:
            cin>>pos;
            obj.deletenode(pos);
            break;
            case 5:
            obj.printlist();
            default:
            cout<<"choose crt option";
        }
        cout<<'\n';
    }
    while(choose != 0);

    return 0;     
}