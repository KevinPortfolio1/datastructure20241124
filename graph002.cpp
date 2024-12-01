/*

1. BFS (廣度優先搜尋)

BFS 是一種以層級（Level）為基準進行的搜尋演算法，從起始節點開始，先遍歷所有相鄰節點，再遍歷這些節點的相鄰節點，依此類推。BFS 通常用來找最短路徑，尤其是在無權重圖中。
BFS 遍歷的步驟：

    初始化：
        用一個隊列（Queue）來存放待處理的節點。
        使用一個 visited 陣列來標記已經訪問過的節點，避免重複訪問。
    遍歷：
        將起始節點放入隊列，並標記為已訪問。
        從隊列中取出節點，將所有未訪問的鄰居節點加入隊列並標記為已訪問。
        重複此步驟直到隊列為空。

BFS 範例：

假設有如下圖結構：

   A
  / \
 B   C
 |   |
 D   E

BFS 從節點 A 開始，步驟如下：

    初始化：隊列 = [A]，visited = [A]
    取出 A，將 B 和 C 加入隊列：隊列 = [B, C]，visited = [A, B, C]
    取出 B，將 D 加入隊列：隊列 = [C, D]，visited = [A, B, C, D]
    取出 C，將 E 加入隊列：隊列 = [D, E]，visited = [A, B, C, D, E]
    取出 D，無鄰居可加入。
    取出 E，無鄰居可加入。
    結束。

最終遍歷順序為：A -> B -> C -> D -> E
BFS 特點：

    時間複雜度：O(V + E)，其中 V 是節點數，E 是邊數。
    空間複雜度：O(V)，因為需要存儲節點的訪問狀態。

2. DFS (深度優先搜尋)

DFS 是一種從起始節點開始，沿著每條邊盡可能深地搜尋下去，直到達到無法繼續的節點，然後回溯到最近的未完全遍歷的節點。DFS 可以用遞歸或使用堆疊（Stack）來實現。
DFS 遍歷的步驟：

    初始化：
        使用一個堆疊（Stack）來存放待處理的節點，或使用遞歸來模擬堆疊。
        使用 visited 陣列來標記已經訪問過的節點。
    遍歷：
        將起始節點加入堆疊，並標記為已訪問。
        取出堆疊頂部的節點，然後將其所有未訪問的鄰居節點加入堆疊。
        重複此步驟直到堆疊為空。

DFS 範例：

假設有如下圖結構：

   A
  / \
 B   C
 |   |
 D   E

DFS 從節點 A 開始，步驟如下：

    初始化：堆疊 = [A]，visited = [A]
    取出 A，將 B 和 C 加入堆疊：堆疊 = [C, B]，visited = [A, B, C]
    取出 C，將 E 加入堆疊：堆疊 = [E, B]，visited = [A, B, C, E]
    取出 E，無鄰居可加入：堆疊 = [B]，visited = [A, B, C, E]
    取出 B，將 D 加入堆疊：堆疊 = [D]，visited = [A, B, C, E, D]
    取出 D，無鄰居可加入：堆疊 = []，visited = [A, B, C, E, D]
    結束。

最終遍歷順序為：A -> C -> E -> B -> D
DFS 特點：

    時間複雜度：O(V + E)，其中 V 是節點數，E 是邊數。
    空間複雜度：O(V)，在最壞情況下，堆疊或遞歸深度可能會達到 V。

BFS 和 DFS 的比較：
特點		BFS							DFS
遍歷順序	層級順序（從上到下）		深度順序（先進入一條路徑，再回溯）
結構		使用隊列（Queue）			使用堆疊（Stack）或遞歸
最短路徑	能夠找到無權圖的最短路徑	不保證找到最短路徑
空間需求	相對較高，尤其在廣泛的圖中	較低，但可能會有較深的遞歸栈
應用場景	最短路徑、廣泛搜索			搜索深層結構、連通性檢查


*/

//bfs

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 定義圖的結構
class Graph {
public:
    int V; // 節點數量
    vector<vector<int>> adj; // 鄰接表

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // 添加邊
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // 若為無向圖
    }

    // BFS 遍歷
    void BFS(int start) {
        vector<bool> visited(V, false); // 記錄是否訪問過
        queue<int> q;  // 使用隊列來實現 BFS

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";  // 輸出節點

            // 訪問所有未被訪問過的鄰居
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g(6); // 創建一個有 6 個節點的圖

    // 添加邊
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "BFS traversal starting from node 0: ";
    g.BFS(0);  // 從節點 0 開始 BFS 遍歷

    return 0;
}


//dfs

#include <iostream>
#include <vector>

using namespace std;

// 定義圖的結構
class Graph {
public:
    int V; // 節點數量
    vector<vector<int>> adj; // 鄰接表

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // 添加邊
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // 若為無向圖
    }

    // DFS 遍歷
    void DFS(int start) {
        vector<bool> visited(V, false); // 記錄是否訪問過
        DFSUtil(start, visited);
    }

    // 內部的遞歸 DFS 函數
    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";  // 輸出節點

        // 訪問所有未被訪問過的鄰居
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }
};

int main() {
    Graph g(6); // 創建一個有 6 個節點的圖

    // 添加邊
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "DFS traversal starting from node 0: ";
    g.DFS(0);  // 從節點 0 開始 DFS 遍歷

    return 0;
}
