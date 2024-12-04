/*

search 

1. 循序搜尋 (Sequential Search)

循序搜尋，也稱為線性搜尋，是最簡單的搜尋演算法。
它會逐一檢查資料結構中的每一個元素，直到找到目標元素或遍歷完整個結構。
這種方法對資料結構沒有特別要求，可以應用於任何順序排列的資料。

    時間複雜度: 最壞情況是O(n)，其中n是資料結構中的元素數量。
    優點: 實現簡單，無需排序。
    缺點: 效率低，對大資料集性能較差。

2. 二分搜尋 (Binary Search)

二分搜尋是對已排序陣列進行搜尋的高效方法。它通過將資料結構一分為二，
每次與中間元素比較，根據比較結果決定是繼續搜尋左邊還是右邊的部分。
這樣每次搜尋範圍都減少一半，直到找到目標元素。

    時間複雜度: O(log n)，其中n是資料結構中的元素數量。
    條件: 需要資料是已經排序的。
    優點: 高效，特別適用於大資料集。
    缺點: 必須保持資料有序，不能直接應用於無序資料。

3. 二元樹 (Binary Tree)

二元樹是一種樹狀資料結構，每個節點最多有兩個子節點，通常稱為左子樹和右子樹。
二元樹可用於實現搜尋演算法，特別是二元搜尋樹（Binary Search Tree，BST）。
在BST中，對每個節點，左子樹的所有值都小於該節點，右子樹的所有值都大於該節點。

    時間複雜度: 在平衡的二元樹中，搜尋、插入和刪除操作的時間複雜度為O(log n)，
	但在最壞情況（如樹退化成鏈表）中，複雜度為O(n)。
    優點: 動態結構，適合插入和刪除操作。
    缺點: 如果不平衡，效率會下降。

4. 內插搜尋 (Interpolation Search)

內插搜尋是一種基於二分搜尋的演算法，適用於資料按數值順序排列且分佈相對均勻的情況。
與二分搜尋不同，內插搜尋會根據目標元素與資料範圍的相對位置來計算預測的中間位置，
而不僅僅是選擇中間元素。這樣可以更精確地定位搜尋範圍。

    時間複雜度: 平均情況是O(log log n)，但最壞情況是O(n)，通常適用於數值範圍較均勻的情況。
    優點: 比二分搜尋更有效率，當資料均勻分佈時。
    缺點: 需要資料按數值順序且分佈均勻。

5. 雜湊 (Hashing)

雜湊是一種將資料映射到一個固定大小的陣列或表中的技術，通過雜湊函數（hash function）來進行映射。
這使得資料能夠在常數時間內被查找、插入或刪除。雜湊表中的每個元素對應一個唯一的索引值，並利用該索引直接存取資料。

    時間複雜度: 平均情況是O(1)，但最壞情況是O(n)（當發生碰撞時）。
    優點: 查詢、插入和刪除操作非常高效，尤其是對於大量資料。
    缺點: 需要一個好的雜湊函數來減少碰撞，並且可能會有空間浪費。

總結:

    循序搜尋: 簡單，但效率低。
    二分搜尋: 高效，但需要資料已排序。
    二元樹: 動態結構，適用於搜尋和修改操作，但可能會退化。
    內插搜尋: 對均勻分佈的數據有效，效率高。
    雜湊: 高效查詢，但需要適當的雜湊函數和處理碰撞。
*/

//1.

int sequentialSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;  // 找到元素，返回索引
        }
    }
    return -1;  // 沒有找到元素，返回-1
}


//2.

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;  // 避免溢位
        
        if (arr[mid] == target) {
            return mid;  // 找到元素，返回索引
        }
        if (arr[mid] < target) {
            left = mid + 1;  // 搜尋右半邊
        } else {
            right = mid - 1;  // 搜尋左半邊
        }
    }
    return -1;  // 沒有找到元素，返回-1
}


//3.

// 中序遍歷（遞迴）
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}


//4.

int interpolationSearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right && target >= arr[left] && target <= arr[right]) {
        if (left == right) {
            if (arr[left] == target) return left;
            return -1;
        }
        
        // 根據目標和範圍計算預測位置
        int pos = left + ((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]);
        
        // 確保位置在範圍內
        if (pos < left || pos > right) {
            return -1;
        }

        if (arr[pos] == target) {
            return pos;  // 找到目標
        }
        if (arr[pos] < target) {
            left = pos + 1;  // 目標在右邊
        } else {
            right = pos - 1;  // 目標在左邊
        }
    }
    return -1;  // 沒有找到目標
}


//5.

class HashTable {
private:
    vector<list<int>> table;
    int size;
    
    int hashFunction(int key) {
        return key % size;  // 取餘數作為索引
    }
    
public:
    HashTable(int size) : size(size) {
        table.resize(size);
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int x : table[index]) {
            if (x == key) return true;
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }
};