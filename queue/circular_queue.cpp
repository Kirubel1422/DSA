#include <iostream>
using namespace std;

const int SIZE = 2;

class Queue{
    public:
        Queue();
        ~Queue();
        char get_front();
        char get_rear();
        void enQueue(char item);
        void deQueue();
        bool is_full();
        bool is_empty();
    
    private:
        char items[SIZE];
        int front, back, count;
};

Queue::Queue(){
    front = 0;
    back = -1;
    count = 0;
}

Queue::~Queue(){};

char Queue::get_front(){
    return items[front];
}

char Queue::get_rear(){
    return items[back];
}

bool Queue::is_empty(){
    return bool(count == 0);
}

bool Queue::is_full(){
    return bool(count == SIZE);
}

void Queue::enQueue(char item){
    if(is_full()){
        cout << "Sorry, Queue is already full!" << endl;
    }else{
        back = (back + 1) % SIZE;
        items[back] = item;
        count ++;
    }
}

void Queue::deQueue(){
    if(is_empty()){
        cout << "Sorry, Queue is empty!" << endl;
    }else{
        front = (front + 1) % SIZE;
        count --;
    }
}

int main(){
    Queue my_queue = Queue();
    
    cout << "Enqueue: B" << endl;
    my_queue.enQueue('B');

    cout << "DeQueue" << endl;
    my_queue.deQueue();

    cout << "Enqueue: Z" << endl;
    my_queue.enQueue('Z');

    cout << "Enqueue: S" << endl;
    my_queue.enQueue('S');

    cout << "Enqueue: A" << endl;
    my_queue.enQueue('A');

    cout << "Front: " << my_queue.get_front() << endl << "Back: " << my_queue.get_rear();
    return 0;
}