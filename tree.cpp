/*

排序資料結構 binary search tree 、極值資料結構 heap 、資料壓縮 Huffman tree 、 3D 繪圖 BSP tree 

binary tree 資料結構
 第一種方式：建立節點，以指標串接節點。
 第二種方式：二進位數字一一對應到二元樹的節點。

二元樹的遍歷順序，理論上總共四種 ── 但是事實上只有 DFS 與 BFS 兩種，只不過更動了節點的輸出順序。

preorder traversal 前序遍歷
理論上的遍歷順序是：根、左子樹、右子樹。根排在前面。
即是depth-first search。

inorder traversal 中序遍歷
理論上的遍歷順序是：左子樹、根、右子樹。根排在中間。
實際上是採用depth-first search，只不過更動了節點的輸出順序。

postorder traversal 後序遍歷
理論上的遍歷順序是：左子樹、右子樹、根。根排在後面。
實際上是採用depth-first search，只不過更動了節點的輸出順序。

level-order traversal 層序遍歷
即是breadth-first search。


*/

#include <iostream>
using namespace std;

struct TreeNode {
    int value;      // 節點值
    TreeNode* left; // 左子樹
    TreeNode* right;// 右子樹

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};


// 插入操作

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    // 插入操作
    void insert(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        } else {
            insertRecursive(root, value);
        }
    }

    // 插入的遞迴實現
    void insertRecursive(TreeNode* node, int value) {
        if (value < node->value) {
            if (node->left == nullptr) {
                node->left = new TreeNode(value);
            } else {
                insertRecursive(node->left, value);
            }
        } else {
            if (node->right == nullptr) {
                node->right = new TreeNode(value);
            } else {
                insertRecursive(node->right, value);
            }
        }
    }
};

// 刪除操作	
class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    // 插入操作
    void insert(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        } else {
            insertRecursive(root, value);
        }
    }

    // 插入的遞迴實現
    void insertRecursive(TreeNode* node, int value) {
        if (value < node->value) {
            if (node->left == nullptr) {
                node->left = new TreeNode(value);
            } else {
                insertRecursive(node->left, value);
            }
        } else {
            if (node->right == nullptr) {
                node->right = new TreeNode(value);
            } else {
                insertRecursive(node->right, value);
            }
        }
    }

    // 刪除操作
    void deleteValue(int value) {
        root = deleteRecursive(root, value);
    }

    // 刪除的遞迴實現
    TreeNode* deleteRecursive(TreeNode* node, int value) {
        if (node == nullptr) return node;

        // 依照大小找到需要刪除的節點
        if (value < node->value) {
            node->left = deleteRecursive(node->left, value);
        } else if (value > node->value) {
            node->right = deleteRecursive(node->right, value);
        } else {
            // 情況 1: 節點沒有子節點
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // 情況 2: 節點只有一個子節點
            else if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            // 情況 3: 節點有兩個子節點
            else {
                TreeNode* temp = findMin(node->right); // 找右子樹的最小節點
                node->value = temp->value;
                node->right = deleteRecursive(node->right, temp->value);
            }
        }
        return node;
    }

    // 找到樹中最小的節點
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};


// 查詢操作
    bool search(int value) {
        return searchRecursive(root, value);
    }

    // 查詢的遞迴實現
    bool searchRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == value) {
            return true;
        } else if (value < node->value) {
            return searchRecursive(node->left, value);
        } else {
            return searchRecursive(node->right, value);
        }
    }
	
	
//Heap Tree - 堆積樹
//特徵一：Binary Heap之結構可以視作Complete Binary Tree。
//特徵二：若將位於index(i)之node視為subtree之root，那麼，可將此Binary Heap分為兩類：
//        Max Heap：在每一個subtree中，root之「數值」要比兩個child之「數值」還要大
//        Min Heap：在每一個subtree中，root之「數值」要比兩個child之「數值」還要小


#include <iostream>
#include <queue>
#include <vector>

int main() {
    // 使用 vector 作為底層容器，默認為最大堆積
    std::priority_queue<int> maxHeap;

    // 向堆積中插入元素
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(15);
    maxHeap.push(30);

    // 輸出最大堆積中的元素（最大元素會先被彈出）
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " "; // top() 會返回堆積頂端的最大元素
        maxHeap.pop(); // 彈出最大元素
    }

    return 0;
}


#include <iostream>
#include <queue>
#include <vector>

int main() {
    // 使用 vector 作為底層容器，並通過比較器來實現最小堆積
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // 向堆積中插入元素
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(15);
    minHeap.push(5);

    // 輸出最小堆積中的元素（最小元素會先被彈出）
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " "; // top() 會返回堆積頂端的最小元素
        minHeap.pop(); // 彈出最小元素
    }

    return 0;
}


/*

高度平衡樹的類型

有很多種類的高度平衡樹，其中最著名的幾種包括：

    AVL 樹（Adelson-Velsky and Landis Tree）：
	這是最早提出的平衡二叉搜尋樹之一。
	它對每個節點的左右子樹高度差（稱為平衡因子）要求不超過 1。

    紅黑樹（Red-Black Tree）：
	這是一種自平衡的二叉搜尋樹，它通過將節點標記為紅色或黑色來維護平衡。
	它的平衡條件比 AVL 樹更寬鬆，但仍然能夠保證對數時間的操作。

    Splay 樹：這是一種自調整的二叉搜尋樹，每當查詢一個元素時，會將其移動到樹的根部，從而加速頻繁訪問的元素的查詢。

    Treap（樹堆）：這是一種結合了二叉搜尋樹和最大堆積樹特性的樹結構。

AVL 樹

AVL 樹是一種自平衡的二叉搜尋樹，其中每個節點都有一個平衡因子（左右子樹的高度差）。如果某個節點的平衡因子的絕對值超過 1，則需要進行旋轉操作來維持平衡。
AVL 樹的平衡因子

    平衡因子：平衡因子 = 左子樹的高度 - 右子樹的高度
    AVL 樹的平衡因子只能是 -1, 0, 1 之一。若平衡因子的絕對值大於 1，則樹失去平衡，需要進行旋轉。

AVL 樹的旋轉操作

    左旋轉（Left Rotation）：當某個節點的右子樹過高時，進行左旋轉。
    右旋轉（Right Rotation）：當某個節點的左子樹過高時，進行右旋轉。
    左右旋轉（Right-Left Rotation）：當右子樹的左子樹過高時，進行右旋轉再左旋轉。
    左右旋轉（Left-Right Rotation）：當左子樹的右子樹過高時，進行左旋轉再右旋轉。

*/

#include <iostream>
#include <algorithm> // 用於 std::max

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    
    Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

// 計算節點的高度
int height(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

// 計算平衡因子
int getBalanceFactor(Node* node) {
    return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

// 右旋轉
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // 執行旋轉
    x->right = y;
    y->left = T2;

    // 更新高度
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x; // 返回新的根節點
}

// 左旋轉
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // 執行旋轉
    y->left = x;
    x->right = T2;

    // 更新高度
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y; // 返回新的根節點
}

// 插入節點
Node* insert(Node* node, int key) {
    if (node == nullptr) {
        return new Node(key);
    }

    if (key < node->data) {
        node->left = insert(node->left, key);
    } else if (key > node->data) {
        node->right = insert(node->right, key);
    } else { // 不允許插入重複元素
        return node;
    }

    // 更新節點高度
    node->height = 1 + std::max(height(node->left), height(node->right));

    // 計算平衡因子，並執行相應的旋轉操作
    int balance = getBalanceFactor(node);

    // 左左情況
    if (balance > 1 && key < node->left->data) {
        return rightRotate(node);
    }

    // 右右情況
    if (balance < -1 && key > node->right->data) {
        return leftRotate(node);
    }

    // 左右情況
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // 右左情況
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // 返回根節點
}

// 中序遍歷
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 15);

    // 中序遍歷輸出
    inOrder(root); // 10 15 20 30
    return 0;
}
