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

    void insert(int pos,node* t){
        if(pos == 0){
            t->prev = NULL;
            t->next = head;
            head->prev = t;
            head = t;
        }
        else{
            node* p = head;
            for(int i=0;p && i<pos-1;i++){
                p = p->next;
            }
            t->next = p->next;
            t->prev = p;
            if(p->next){
                p->next->prev = t;
            }
            p->next = t;
        }
    }

    void deletenode(int pos){
        node* p = head;
        if(pos == 0){
            head = head->next;
            delete p;
            if(head){
                head->prev = NULL;
            }
        }
        else{
            for(int i=0;i<pos-1;i++){
                p = p->next;
            }
            p->prev->next = p->next;
            if(p->next){
                p->next->prev = p->prev;
            }
            delete p;
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
            obj.insert(pos,n1);
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