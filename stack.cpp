/*

stack如果和類別的元素相等可比較，而且只有在 類別的元素小於可比較時，
而且只有在 類別的TypeType元素小於可比較時，物件才會相等。

類別 stack 支持最後一個先出 （LIFO） 資料結構。 
就好像盤子的堆疊一樣，這是一種較為貼切好記的類比。 
項目 (盤子) 可能會插入、檢查，或只從堆疊頂端移除，這是基底容器尾端的最後一個項目。 
只存取 top 元素的限制是使用 stack 類別的原因。

類別queue支援先進先出 （FIFO） 數據結構。 
就好像人們排隊等候銀行櫃員一樣，這是一種較為貼切好記的類比。 
項目 (人) 可能會加入隊伍的尾端，以及從隊伍的前面移除。 
隊伍的前端和後端都可能會進行檢查。 以這種方式只存取前端和後方元素的限制，是使用 queue 類別的 fur 的原因。

類別priority_queue會排序其元素，讓最大元素一律位於頂端位置。 
它支援插入項目，以及檢查和移除頂端項目。 就好像依照年齡、身高或某些其他條件來排列一群人一樣，
這是一種較為貼切好記的類比。


*/

/*

函式
名稱 	描述
empty 	測試 stack 是否為空白。
pop 	從 stack 頂端移除項目。
push 	將項目加入 stack 的頂端。
size 	傳回 stack 中項目的數目。
top 	傳回 stack 頂端項目的參考。

*/


/*
 value_type

一個類型，代表堆疊中儲存為項目的物件類型。
C++

typedef typename Container::value_type value_type;

備註

此類型與由堆疊所配接的基底容器 value_type 同義。


*/

// stack_value_type.cpp
// compile with: /EHsc
#include <stack>
#include <iostream>

int main( )
{
   using namespace std;
   // Declares stacks with default deque base container
   stack<int>::value_type AnInt;

   AnInt = 69;
   cout << "The value_type is AnInt = " << AnInt << endl;

   stack<int> s1;
   s1.push( AnInt );
   cout << "The element at the top of the stack is "
        << s1.top( ) << "." << endl;
}

/*
Output

The value_type is AnInt = 69
The element at the top of the stack is 69.

*/


/*

[後序式]

括號法，將運算子兩旁的運算元依先後順序(由左至右)全部括號起來，
然後將所有的右括號取代為左邊最接近的運算子（由最內層括號開始），
最後去掉所有的左括號就可以完成後序表示式，例如：

a+b*d+c/d   =>    ((a+(b*d))+(c/d)) -> abd*+cd/+

[演算法]

由左至右掃描中序運算式：

一、運算元：直接輸出至postfix。

二、運算子與左括號：堆疊中運算子優先順序>=讀入的運算子，
則輸出堆疊中的運算子、再將讀入的運算子置入堆疊，否則將讀入的運算子置入堆疊。

三、右括號：輸出堆疊中的運算子，直至遇見堆疊中的左括號。

輸出時也是由左至右。

[計算步驟]

1.由後序式的前方開始讀取。
2.遇「運算元」先存入『堆疊』。
3.遇「運算子」，則由堆疊取出兩個「運算元」進行運算，將結果存回『堆疊』。
4.運算式讀取完畢，『堆疊』頂端即為答案。


[前序式]

括號法，將運算子兩旁的運算元依先後順序(由右至左)全部括號起來，
然後將所有的左括號取代為右邊最接近的運算子（由最內層括號開始），
最後去掉所有的右括號就可以完成後序表示式，例如：

a+b*d+c/d   =>    ((a+(b*d))+(c/d)) -> ++a*bd/cd

[演算法]

由右至左掃描中序運算式：

一、運算元：直接輸出至prefix。

二、運算子與右括號：堆疊中運算子優先順序>=讀入的運算子，則輸出堆疊中的運算子、再將讀入的運算子置入堆疊，否則將讀入的運算子置入堆疊。

三、左括號：輸出堆疊中的運算子，直至遇見堆疊中的右括號。

輸出時也是由右至左。

[計算步驟]

1.一樣由前序式的前方開始讀取。

2.遇「運算元」先存入『堆疊』。

3.遇「運算子」，則由堆疊取出兩個「運算元」進行運算，將結果存回『堆疊』。

※傳入的運算元次序與後序式相反。※

4.運算式讀取完畢，『堆疊』頂端即為答案。

*/