#include<iostream>
using namespace std;

class Queue{
    private:
    int arr[10];
    int front;
    int rear;

    public:
    Queue(){
        front = rear = -1;      
    }

    void enqueue(int num);
    int dequeue();
    void display();
    bool isFull();
    bool isEmpty();
};

bool Queue::isEmpty(){
    if(front == -1 && rear == -1)
    return true;
    return false;
}

bool Queue::isFull(){
    if(rear == 9)
    return true;
    return false;
}

void Queue::enqueue(int num){
    if(isFull()){
    cout<<"Queue is full\n";
    return;
    }
    else if(isEmpty()){
        front++;
        rear++; 
        arr[rear] = num;
        return;
    }
    else{
        rear++;
        arr[rear] = num;
        return;
    }
}

int Queue::dequeue(){
    if(isEmpty()){
        cout<<"Queue is empty.\n";
        return 0;
    }
    else if(front == rear){
        int num = arr[front];
        front == -1;
        rear == -1;
        return num;
    }
    else{
        int num = arr[front];
        front++;
        return num;
    }
}

void Queue::display(){
    if(isEmpty()){
        cout<<"Nothing to show, Queue is empty\n";
        return;
    }
    else{
        for(int i = front;i<=rear;i++){
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
        return;
    }
}


int main(){
    Queue q;
    int choice;
    do
    {
        cout<<"Enter choice from given below\n";
        cout<<"1. enqueue()\n";
        cout<<"2. dequeue()\n";
        cout<<"3. display()\n";
        cout<<"4. exit()\n";
        cin>>choice;

        switch (choice)
        {
        case 1: int num;
                cout<<"Enter number to be enqueue\n";
                cin>>num;
                q.enqueue(num);
            break;
        
        case 2: cout<<"Element dequeued is "<<q.dequeue()<<endl;
            break;

        case 3: q.display();
        break;

        case 4: exit(0);
        break;
        
        default: cout<<"Invalid option. Try again.!\n";
            break;
        }
    } while (choice!=4);
    
return 0;
}
