/*
類別 queue 支援先進先出 （FIFO） 數據結構。 
記住的一個很好的模擬是人們排隊為銀行出納員。 
項目 (人) 可能會加入隊伍的尾端，以及從隊伍的前面移除。 
隊伍的前端和後端都可能會進行檢查。 
以這種方式只 front 存取 和 back 元素的限制是使用 queue 類別的原因。

函式
名稱 	描述
back 	傳回 queue 後端最後且最近新增的項目。
empty 	測試 queue 是否為空白。
front 	傳回 queue 前端第一個項目的參考。
pop 	從 queue 前端移除項目。
push 	將項目加入 queue 的後端。
size 	傳回 queue 中項目的數目。


*/



/*
deque 類別
以線性排列方式排列指定類型的項目，並且像向量一樣允許快速隨機存取任何項目，可有效率地在容器背面插入和刪除。 
不過，與向量不同的是，deque 類別也支援在此容器前面有效率的插入和刪除。

函式
名稱 						描述
assign 						清除 deque 中的項目，並複製新的項目序列至目標 deque。
at 							傳回 deque 中指定位置的項目參考。
back 						傳回 deque 的最後一個項目的參考。
begin 						傳回 deque 中對第一個項目定址的隨機存取迭代器。
cbegin 						將 const 反覆運算器傳回 至中的 deque第一個專案。
cend 						傳回指向 deque 結尾之外的 const 隨機存取迭代器。
clear 						清除 deque 的所有項目。
crbegin 					將隨機存取 const 反覆運算器傳回以反向順序檢視的第 deque 一個專案。
crend 						將隨機存取 const 反覆運算器傳回以反向順序檢視的第 deque 一個專案。
emplace 					將就地建構的項目插入 deque 的指定位置。
emplace_back 				將就地建構的項目加入 deque 的結尾。
emplace_front 				將就地建構的項目加入 deque 的開頭。
empty 						如果 deque 包含零個項目，則傳回 true，而如果它包含一或多個項目，則傳回 false。
end 						傳回指向 deque 結尾之外的隨機存取迭代器。
erase 						從指定位置移除在 deque 中的項目或某個項目範圍。
front 						傳回 deque 中第一個項目的參考。
get_allocator 				傳回用來建構 allocator 的 deque 物件複本。
insert 						將一個項目、多個項目或一定範圍的項目在指定位置插入 deque。
max_size 					傳回 deque 的最大可能長度。
pop_back 					清除 deque 結尾的項目。
pop_front 					清除 deque 開頭的項目。
push_back 					將項目加入 deque 的結尾。
push_front 					將項目加入 deque 的開頭。
rbegin 						傳回反轉的 deque 中第一個項目的隨機存取迭代器。
rend 						傳回在反轉的 deque 中恰好指向最後一個項目之外的隨機存取迭代器。
resize 						指定 deque 的新大小。
shrink_to_fit 				捨棄多餘的容量。
size 						傳回 deque 中項目的數目。
swap 						交換兩個 deque 的項目。


*/


// C++ program to implement the circular queue using array
#include <bits/stdc++.h>

// defining the max size of the queue
#define MAX_SIZE 5

using namespace std;

// class that represents queue
class Queue {
public:
    // index pointers and data array
    int front, rear;
    int arr[MAX_SIZE];

    // constructor to initialize the index pointers
    Queue() { front = rear = 0; }

    // checking if queue is empty
    bool isEmpty()
    {
        if (front == rear)
            return true;
        return false;
    }

    // checking if the queue is full
    bool isFull()
    {
        if ((rear + 1) % MAX_SIZE == front)
            return true;
        return false;
    }

    // enqueue operation
    void enqueue(int val)
    {
        if (this->isFull()) {
            printf("Queue Overflow!\n");
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = val;
    }

    // dequeue operation
    void dequeue()
    {
        if (this->isEmpty()) {
            printf("Queue Underflow!\n");
            return;
        }
        front = (front + 1) % MAX_SIZE;
    }

    // peek function
    int peek()
    {
        if (this->isEmpty()) {
            printf("Queue is Empty!\n");
            return -1;
        }
        return arr[(front + 1) % MAX_SIZE];
    }

    // utility to print queue
    void print()
    {
        if (this->isEmpty())
            return;
        for (int i = (front + 1) % MAX_SIZE; i < rear;
             i = (i + 1) % MAX_SIZE) {

            printf("%d ", arr[i]);
        }
        cout << arr[rear];
    }
};

// driver code
int main()
{
    Queue q;

    q.enqueue(11);
    q.enqueue(11);
    q.enqueue(11);
    q.enqueue(11);
    q.enqueue(11);
    q.enqueue(11);

    q.dequeue();

    q.dequeue();
    q.enqueue(123);

    q.print();

    return 0;
}