/*
生成樹(Spanning Tree)

以最少的邊來連結圖形中所有的頂點(且須避免循環)。

------------------------------------------------

花費最少擴張樹(Minimum Spanning Tree)

擁有最小成本(權重)的擴張樹

-----------------------------------------------
找出一個加權圖形中花費最少擴張樹可以利用以下三種演算法(當然不止這三種)：

    Kruskal's Algorithm
	
	 這個演算法較容易實作，由Spanning tree中花費最少的邊出發，
	 每一次都選擇目前尚未被選擇的最少花費的邊，且避免形成循環，
	 直到邊的個數為n-1(頂點為n)即找出花費最少擴張樹。
	 
	--------------------------------------------------------------- 
	
    Prim's Algorithm
	
	  先從Spanning tree中找一個頂點V作為起始點，
	  找出與V相連且還沒有被選取的頂點裡面加權值最小的邊，
	  直到找到n-1個邊(頂點為n)。
	  
	--------------------------------------------------------------
	
    Sollin's Algorithm

	  每次選擇花費最少的子圖，並且再選取花費較少的邊將這些子圖相連(不能造成循環)，
	  直到邊數為n-1(頂點為n)停止。
	
--------------------------------------------------------------------------




*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定義邊結構
struct Edge {
    int u, v, weight;
    
    // 比較邊的權重
    bool operator<(const Edge &e) const {
        return weight < e.weight;
    }
};

// 定義並查集
class DisjointSet {
private:
    vector<int> parent, rank;
    
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;  // 每個節點的父節點初始化為自身
        }
    }
    
    // 找到節點的代表元素（根節點），並進行路徑壓縮
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    // 合併兩個集合
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            // 根據秩進行合併，秩小的節點合併到秩大的節點下面
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

// Kruskal’s Algorithm
vector<Edge> kruskal(int n, vector<Edge> &edges) {
    // 結果存儲生成樹的邊
    vector<Edge> mst;
    
    // 先按邊的權重排序
    sort(edges.begin(), edges.end());
    
    // 初始化並查集
    DisjointSet ds(n);
    
    // 遍歷所有邊
    for (const auto &edge : edges) {
        int u = edge.u;
        int v = edge.v;
        
        // 如果這兩個節點不在同一集合，則加入這條邊
        if (ds.find(u) != ds.find(v)) {
            ds.unionSets(u, v);
            mst.push_back(edge);
        }
    }
    
    return mst;
}

int main() {
    int n = 4;  // 節點數
    vector<Edge> edges = {
        {0, 1, 10},  // 邊 (0, 1) 權重 10
        {0, 2, 6},   // 邊 (0, 2) 權重 6
        {0, 3, 5},   // 邊 (0, 3) 權重 5
        {1, 3, 15},  // 邊 (1, 3) 權重 15
        {2, 3, 4}    // 邊 (2, 3) 權重 4
    };
    
    // 求解最小生成樹
    vector<Edge> mst = kruskal(n, edges);
    
    // 輸出生成樹的邊
    cout << "Edges in the Minimum Spanning Tree (MST):\n";
    for (const auto &edge : mst) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
    }
    
    return 0;
}



/*

    邊結構 Edge：
        這個結構包含了邊的兩個端點 u 和 v 以及邊的權重 weight，並且重載了 < 運算符來根據邊的權重對邊進行排序。

    並查集類 DisjointSet：
        find：查找節點的根節點並進行路徑壓縮。
        unionSets：合併兩個不同集合，並根據秩（rank）進行優化。

    Kruskal’s Algorithm：
        將所有邊按權重升序排序。
        使用並查集來檢查是否已經包含這條邊所連接的兩個節點（即是否會形成環路），若不會形成環路，則將這條邊加入生成樹。
        最終返回最小生成樹的邊。

輸出範例：

假設圖中的邊和權重如下：

    (0, 1) 權重 10
    (0, 2) 權重 6
    (0, 3) 權重 5
    (1, 3) 權重 15
    (2, 3) 權重 4

這段代碼將輸出最小生成樹的邊，結果可能如下：

Edges in the Minimum Spanning Tree (MST):
2 - 3 : 4
0 - 3 : 5
0 - 2 : 6

這意味著最小生成樹包含了邊 (2, 3), (0, 3), 和 (0, 2)，並且這三條邊沒有形成環路。

*/

/*

最短路徑

最短路徑問題是圖論中的一個重要問題，目的是找出圖中兩個節點之間的最短路徑。
通常，最短路徑是根據邊的權重來計算的，權重可以表示距離、時間或其他代價。

常見的最短路徑算法有：

    Dijkstra 算法：
	適用於所有邊的權重均為非負數的圖。它的基本思想是每次選擇當前節點到起點的最短路徑，
	然後更新鄰接節點的最短路徑。
    Bellman-Ford 算法：適用於邊的權重可以為負數的情況，且可以檢測是否存在負環。
    Floyd-Warshall 算法：一種動態規劃算法，適用於計算圖中所有節點對之間的最短路徑。

*/

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

typedef pair<int, int> pii; // pair <距離, 節點>

class Graph {
public:
    int V; // 節點數
    vector<vector<pii>> adj; // 邊的列表：每個節點對應一個邊的列表，邊是 pair <相鄰節點, 邊權重>

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // 添加邊
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
    }

    // Dijkstra 算法，從源節點 source 開始計算最短路徑
    void dijkstra(int source) {
        vector<int> dist(V, INT_MAX); // 用來存儲每個節點到源節點的最短距離
        dist[source] = 0; // 源節點到自身的距離為 0

        // 優先隊列，儲存 (距離, 節點) ，根據距離進行排序，最小距離的節點優先取出
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, source}); // 將源節點加入優先隊列

        while (!pq.empty()) {
            int u = pq.top().second; // 當前節點
            int d = pq.top().first;  // 當前節點的距離
            pq.pop();

            // 如果當前節點的距離已經大於當前最短距離，跳過
            if (d > dist[u]) continue;

            // 更新鄰接節點的距離
            for (auto edge : adj[u]) {
                int v = edge.first;  // 相鄰節點
                int weight = edge.second;  // 邊的權重

                // 若找到更短的路徑，則更新距離並加入優先隊列
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // 輸出最短距離
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INT_MAX)
                cout << "Node " << i << " is unreachable from source." << endl;
            else
                cout << "Shortest distance from source to node " << i << " is " << dist[i] << endl;
        }
    }
};

int main() {
    // 範例：5個節點的圖
    Graph g(5);

    // 添加邊：addEdge(起點, 終點, 邊的權重)
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 4, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 0, 7);
    g.addEdge(3, 2, 6);
    g.addEdge(4, 1, 3);
    g.addEdge(4, 2, 9);

    // 從節點 0 開始計算最短路徑
    g.dijkstra(0);

    return 0;
}



/*

拓撲排序

拓撲排序是有向無環圖（DAG）中的一種排序方法，它將圖中的節點排成一個線性序列，
並且對於圖中的每一條邊 u→vu→v，節點 uu 必須排在 vv 之前。

拓撲排序的應用場景通常涉及依賴關係，例如：

    任務調度問題（確保任務按照依賴關係的順序執行）。
    編譯器中的依賴分析。
    設計工作流程。

拓撲排序的常用算法有：

    Kahn 算法：基於入度的算法，從圖中選擇沒有前驅的節點（入度為 0），然後逐步更新其鄰接節點的入度。
    深度優先搜索（DFS）法：通過深度優先遍歷，將節點加入拓撲排序結果中。

*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    int V;  // 節點數量
    vector<vector<int>> adj;  // 邊的鄰接表

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // 添加邊
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // 拓撲排序（Kahn算法）
    void topologicalSort() {
        vector<int> inDegree(V, 0);  // 記錄每個節點的入度
        // 計算每個節點的入度
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        // 使用優先隊列，從入度為0的節點開始
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);  // 把入度為0的節點加入隊列
            }
        }

        vector<int> topoOrder;  // 用來存儲拓撲排序的結果

        while (!q.empty()) {
            int u = q.front();  // 取出隊列中的節點
            q.pop();
            topoOrder.push_back(u);  // 加入到拓撲排序結果中

            // 更新所有相鄰節點的入度
            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);  // 如果相鄰節點的入度為0，則加入隊列
                }
            }
        }

        // 如果拓撲排序中的節點數等於總節點數，則成功
        if (topoOrder.size() == V) {
            cout << "Topological Sort: ";
            for (int node : topoOrder) {
                cout << node << " ";
            }
            cout << endl;
        } else {
            cout << "Graph has a cycle, topological sort is not possible!" << endl;
        }
    }
};

int main() {
    // 範例：5個節點的有向無環圖（DAG）
    Graph g(6);

    // 添加邊：addEdge(起點, 終點)
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    // 執行拓撲排序
    g.topologicalSort();

    return 0;
}
