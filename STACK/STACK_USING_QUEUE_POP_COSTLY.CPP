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
    }

    int pop(){
        if(q1.empty()){
            return -1;
        }
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int y = q1.front();
        q1.pop();
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
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