#include <iostream>
#include <queue>

using namespace std;

class stack{
    public:
    queue<int> q1,q2;
    int size;

    stack(){
        size = 0;
    }

    void push(int x){
        size++;
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int pop(){
        if(q2.empty()){
           return -1; 
        }
        int y = q2.front();
        q2.pop();
        size--;
        return y;
    }
};

int main(){
    stack obj;
    obj.push(1);
    obj.push(5);
    obj.push(3);
    cout<<obj.pop()<<" ";
    obj.push(2);
    cout<<obj.pop();
}