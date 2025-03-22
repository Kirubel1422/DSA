#include <iostream>
using namespace std;

const int MAX=5;

class Queue{
    public:
        Queue();
        ~Queue();
        void enQueue(char item);
        void deQueue();
        char get_rear();
        char get_front();
        bool is_empty();
        bool is_full();
    
    private:
        int front;
        int back;
        char items[MAX];
};

Queue::Queue(){
    front = 0;
    back = -1;
}

Queue::~Queue(){
    front = 0;
    back = -1;
    delete [] items;
}

bool Queue::is_full(){
    return bool(back == MAX - 1);
}

bool Queue::is_empty(){
    return bool(front > back);
}

char Queue::get_front(){
    return items[front];
}

char Queue::get_rear(){
    return items[back];
}

void Queue::enQueue(char item){
    if (is_full()){
        cout << "Can not add! Queue is already full" << endl;
    }else{
        back++;
        items[back] = item;
    }
}

void Queue::deQueue(){
    if(is_empty()){
        cout << "Can not remove! Queue is empty" << endl;
    }else{
        cout << "Removed item: " << items[front] << endl;
        front++;
    }
}

int main(){
    Queue my_queue = Queue();

    cout << "Enqueue A and B" << endl; 
    my_queue.enQueue('A');
    my_queue.enQueue('B');

    cout << "Front: " << my_queue.get_front() << endl; // A
    cout << "Back: " << my_queue.get_rear() << endl; // B

    cout << "Dequeue" << endl;
    my_queue.deQueue();

    cout << "Front: " << my_queue.get_front() << endl; // B
    cout << "Back: " << my_queue.get_rear() << endl; // B

    return 0;
}