#include<iostream>

using namespace std;

class Stack{
    private:
    int arr[10];
    int top;

    public:
    Stack(){
        top =-1;
    }
    void push(int num);
    int pop();
    bool isEmpty();
    bool isFull();
    void peek(int pos);
    void display();
};

bool Stack::isEmpty(){
    if(top == -1)
    return true;
    return false;
};

bool Stack::isFull(){
    if(top == 9)
    return true;
    return false;
};

void Stack::push(int num){
    if(isFull())
    cout<<"Stack is full.!!\n";
    else{
        top++;
        arr[top]=num;
        cout<<"Element pushed"<<endl;
    }
};

int Stack::pop(){
    if(isEmpty()){
    cout<<"Stack is Empty, nothing to pop\n";
    return 0;
    }
    else{
        int num = arr[top];
        top--;
        return num;
    }
};

void Stack::peek(int pos){
    cout<<"Element at pos "<<pos<<" is "<<arr[pos-1]<<endl;
};

void Stack::display(){
    if(isEmpty())
    cout<<"Nothing to display,Stack empty\n";
    else{
        cout<<"Elements are: \n";
        for(int i = top; i >=0 ;i--)
        cout<<arr[i]<<endl;
    }
};

int main(){
    Stack s;
    int choice;
    do
    {
        cout<<"Enter choice from given below\n";
        cout<<"1. push()\n";
        cout<<"2. pop()\n";
        cout<<"3. peek()\n";
        cout<<"4. display()\n";
        cout<<"5. exit()\n";
        cin>>choice;

        switch (choice)
        {
        case 1: int num;
                cout<<"Enter number to be pushed to stack\n";
                cin>>num;
                s.push(num);
            break;
        
        case 2: cout<<"Element popped is "<<s.pop()<<endl;
            break;

        case 3: int pos;
                cout<<"Enter position to peek element\n";
                cin>>pos;
                s.peek(pos);
                break;

        case 4: s.display();
        break;

        case 5: exit(0);
        break;
        
        default: cout<<"Invalid option. Try again.!\n";
            break;
        }
    } while (choice!=5);
    
return 0;
}