/*
Linked List

1. Singly Linked List
2. Doubly Linked List
3. Circular Linked List
4. Doubly Circular Linked List


1. 特性：

能夠不使用連續的記憶體空間的情況下，能夠保有並使用一份連續的資料；
相對來看，陣列則需要使用連續的記憶體空間，實作出其他的資料結構，例如堆疊(Stack)和佇列(Queue)等。

優點：

1. 不需使用連續記憶體空間，不需事先指定串列大小。
2. 能夠容易的修改指標，插入或移除節點。

缺點：

1. 使用額外的記憶體空間紀錄節點指標。
2. 無法快速索引到某個節點，必須遞程搜索。



*/

#include <iostream>
using namespace std;


struct Node {
    int data;       
    Node* next;     

   
    Node(int val) : data(val), next(nullptr) {}
};


class LinkedList {
private:
    Node* head;  

public:
   
    LinkedList() : head(nullptr) {}

    
    void insertEnd(int val) {
        Node* newNode = new Node(val);  
        if (head == nullptr) {           
            head = newNode;             
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;  
            }
            temp->next = newNode;    
        }
    }

    
    void insertStart(int val) {
        Node* newNode = new Node(val); 
        newNode->next = head;          
        head = newNode;               
    }

    
    void deleteNode(int val) {
        if (head == nullptr) return;  

        
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp; 
            return;
        }

       
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }

        
        if (temp->next != nullptr) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertStart(5);

   
    cout << "Linked List: ";
    list.display();

    
    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.display();

    
    list.deleteNode(5);
    cout << "After deleting 5: ";
    list.display();

    return 0;
}
