#include <iostream>
#include <time.h>

using namespace std;

class Stack{
public:
    int capacity;
    struct Node{
        int value;
        Node *next;
    };
    Node *tos;
    Stack();
    ~Stack();
    int size() const;
    bool empty() const;
    void clear();
    void pop();
    void push(const int &pushed_value);
    int &top() const;
    void printStack();
};



int& Stack::top() const{
    return tos->value;
}

void Stack::clear(){
    while(!empty())
        pop();
}

bool Stack::empty() const {
    return capacity==0;
}


int Stack::size() const{
    return capacity;
}

Stack::~Stack(){
    clear();
}


Stack::Stack() {
    tos=nullptr;
    capacity=0;
}

void Stack::push(const int& pushed_value) {
    Node * temp = new Node();
    temp->next=tos;//Поставили указатель на старую вершину, новой будет temp.
    temp->value=pushed_value;
    tos=temp;//Переназначили вершину стека
    capacity++;
}

void Stack::pop() {
    if(!empty()){
        Node * temp=tos;//Берем текущую вершину стека
        tos=temp->next;//Смещаем вершину стека
        delete temp;//Удаляем старую вершину
        capacity--;
    }
}

void Stack::printStack()
{
    if(!empty()){
        Node * temp=tos;
        for (int i = 0; i < capacity; i++){
                cout << "| " << temp->value << endl;
                temp=temp->next;
        }
    }
}

void addElement(Stack &a, int pushed_value){
    Stack::Node * temp = new Stack::Node();
    temp->next=a.tos;//Поставили указатель на старую вершину (след. элемент), новой будет temp
    temp->value=pushed_value;
    a.tos=temp;//Переназначили вершину стека
    a.capacity++;
}

void getElement(Stack &a){
    if(!a.empty()){
        Stack::Node * temp=a.tos;//Берем текущую вершину стека
        a.tos=temp->next;//Смещаем вершину стека
        delete temp;//Удаляем старую вершину
        a.capacity--;
    }
}


int main(){
    Stack qwerty;

    addElement(qwerty, 148);
    addElement(qwerty, 1488);
    addElement(qwerty, 14888);
    addElement(qwerty, 148888);

    qwerty.printStack();

    int cycles = 1000000;
    double t0 = clock();
    for(int i=0; i < cycles; i++)
    {
    qwerty.push(1200);
    }
    double t1 = clock();
    double time_seconds = (t1-t0)*CLOCKS_PER_SEC/cycles;


    double y0 = clock();
    for(int i=0; i < cycles; i++)
    {
    addElement(qwerty, 1430);
    }
    double y1 = clock();
    double time_seconds1 = (y1-y0)*CLOCKS_PER_SEC/cycles;

    if(time_seconds > time_seconds1) {
        cout << "Function 'addElement' works faster then encapsulated method" << endl;
    }else if (time_seconds < time_seconds1) {
        cout << "Encapsulated method works faster then function 'addElement'" << endl;
    }

    cout << "1) push: " << time_seconds << endl;
    cout << "2) addElement: " << time_seconds1 << endl;

    return 0;
}
