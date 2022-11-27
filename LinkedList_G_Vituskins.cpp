#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Node {
public:
    T value;
    Node* pNext;

    Node(T value) {
        this->value = value;
        this->pNext = nullptr;
    }

};



template<typename T>
class List {
private:

    int size;
    Node<T>* first;
    Node<T>* last;

    bool isEmpty() {
        return first == nullptr;
    }

    void deleteAll() {
        Node<T>* temp = first;
        Node<T>* temp1 = nullptr;
        for (int i = 0; i < size; i++) {
            temp1 = temp;
            temp = temp->pNext;
            delete temp1;
        }
    }

public:
    List() {
        size = 0;
        first = nullptr;
        last = nullptr;
    }

    ~List() {
        deleteAll();
    }

    void push(T value) {
        Node<T>* temp = new Node<T>(value);

        if (isEmpty()) {
            first = temp;
            last = temp;
        }
        else {
            last->pNext = temp;
            last = temp;
        }
        size++;
    }

    void printList() {
        if (isEmpty()) {
            cout << "List is empty\n";
        }
        else {
            Node<T>* temp = first;
            while (temp != nullptr) {
                cout << temp->value << " ";
                temp = temp->pNext;
            }
            cout << "\n";
        }
    }

    void remove(int index) {
        if (isEmpty())
            return ;
        if (index == 0) {
            removeFirst();
        } else if (index == size - 1) {
            removeLast();
        } else {
            Node<T>* tempDel = first;
            Node<T>* temp = first->pNext;
            for (int i = 0; i < index - 1; i++) {
                tempDel = tempDel->pNext;
                temp = temp->pNext;
            }
            tempDel->pNext = temp->pNext;
            size--;
            delete temp;
        }
    }

    void removeLast() {
        if (isEmpty()) {
            return;
        }
        Node<T>* tempDel = first;
        for (int i = 0; i < size - 2; i++) {
            tempDel = tempDel->pNext;
        }
        delete last;
        last = tempDel;
        last->pNext = nullptr;
        size--;
    }

    void removeFirst() {
        if (isEmpty()) {
            return;
        }
        Node<T>* temp = first;
        first = temp->pNext;
        size--;
        delete temp;
    }

    T getFirst() {
        return first->value;
    }

    int getSize() {
        return size;
    }
};


void printConditions() {
    cout << "write \"e\" to stop programm\n";
    cout << "write \"+\" to add person to the queue\n";
    cout << "write \"-\" to remove person from the queue\n";
    cout << "write \"s\" to check queue length\n";
}


int main() {

    string value;
    bool programLoop = true;
    char click;
    printConditions();


    List<string> queue;


    while (programLoop) {
        cin >> click;
        switch (click) {
            case 'e':
                programLoop = false;
                break;
            case '+':
                cout << "Enter customer name: \n";
                cin >> value;
                queue.push(value);
                queue.printList();
                break;
            case '-':
                if (queue.getSize() != 0) {
                    cout << queue.getFirst() << " get out\n";
                    queue.removeFirst();
                }
                queue.printList();
                break;
            case 's':
                cout << queue.getSize() << endl;
                break;
        }
    }
    system("pause");
}