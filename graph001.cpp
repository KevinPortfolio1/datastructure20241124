/*

「圖」是一種用來記錄關聯、關係的東西。
 由點（Vertex，有時也稱 Node）和邊（Edge）構成
 
 圖的基本分類：

    無向圖（Undirected Graph）：邊是無方向的，即若 A 與 B 之間有邊連接，那麼 A 到 B 與 B 到 A 是等價的。
    有向圖（Directed Graph, 或稱 Digraph）：邊有方向性，即 A 到 B 與 B 到 A 不相等。
    加權圖（Weighted Graph）：每條邊都有一個權重（通常表示距離、成本等）。
    無加權圖（Unweighted Graph）：邊沒有權重。
	
 常見的圖的實現方式：

    鄰接矩陣（Adjacency Matrix）：
        使用一個二維矩陣表示圖的邊。若圖中有 N 個節點，則使用一個 N x N 的矩陣來表示。
		矩陣中的每個元素 matrix[i][j] 代表節點 i 與節點 j 之間是否有邊（或有多少邊）。

    鄰接表（Adjacency List）：
        使用鏈表或動態陣列來儲存每個節點的鄰接節點。這種方式比鄰接矩陣更節省空間，尤其是在圖中邊比較稀疏的情況下。
		
 

*/

//使用鄰接表表示無向圖

#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    // 以鄰接表來儲存圖
    vector<vector<int>> adjList;

    // 建構函數，初始化圖的節點數量
    Graph(int vertices) {
        adjList.resize(vertices);  // 初始化 adjList 以儲存每個節點的鄰接節點
    }

    // 添加邊
    void addEdge(int v, int w) {
        adjList[v].push_back(w);  // v 到 w 的邊
        adjList[w].push_back(v);  // w 到 v 的邊（因為是無向圖）
    }

    // 顯示圖
    void display() {
        for (int i = 0; i < adjList.size(); ++i) {
            cout << "節點 " << i << " 連接到: ";
            for (int j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // 建立一個有 5 個節點的圖
    Graph g(5);

    // 添加一些邊
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    // 顯示圖的鄰接表
    g.display();

    return 0;
}

//鄰接矩陣表示有向圖

#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    vector<vector<int>> adjMatrix;
    
    // 建構函數，初始化矩陣
    Graph(int vertices) {
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    // 添加有向邊
    void addEdge(int v, int w) {
        adjMatrix[v][w] = 1;  // 有向邊從 v 到 w
    }

    // 顯示鄰接矩陣
    void display() {
        for (int i = 0; i < adjMatrix.size(); ++i) {
            for (int j = 0; j < adjMatrix[i].size(); ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // 建立一個有 5 個節點的有向圖
    Graph g(5);

    // 添加一些有向邊
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    // 顯示鄰接矩陣
    g.display();

    return 0;
}
