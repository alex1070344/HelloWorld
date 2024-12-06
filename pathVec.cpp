#include <iostream>
#include <functional>
#include <queue>

class Node {
public:
    int value;
    Node* next;
    Node(int data=0) {
         value=data;
         next=NULL;
    }
};

int main() {
    Node head[6];
    int data[14][2] = {
        {1, 2}, {1, 5}, {2, 1}, {2, 3}, {2, 4}, {3, 2},
        {3, 4}, {3, 5}, {4, 2}, {4, 3}, {4, 5}, {5, 1},
        {5, 3}, {5, 4}
    };
    Node* ptr ,* newnode;
    int i,j;
    for(i=1; i<6; i++) {
        head[i].value = i;
        ptr = &head[i];
        std::cout<<"第"<<i<<std::endl;
        for(j=0;j<14;j++) {
            if(data[j][0] == i) {
                newnode = new Node(data[j][1]);
                while(ptr->next != NULL) {
                    ptr = ptr->next;
                }
                ptr->next = newnode;
                std::cout<<"["<<newnode->value<<"]";
            }
        }
        std::cout<<std::endl;
    }
    
    // 深度優先搜尋 (DFS) 遍歷
    std::cout << "DFS Traversal:" << std::endl;
    std::function<void(Node*, bool[])> dfs = [&](Node* node, bool visited[]) {
        if (!node || visited[node->value]) return; // 如果節點為空或已訪問過，則返回
        visited[node->value] = true; // 標記節點為已訪問
        std::cout << node->value << " "; // 輸出節點值
        Node* neighbor = node->next; // 獲取鄰居節點
        while (neighbor) {
            dfs(&head[neighbor->value], visited); // 遞迴訪問鄰居節點
            neighbor = neighbor->next; // 獲取下一個鄰居節點
        }
    };

    // 初始化訪問標記陣列
    bool visited[6] = {false};
    // 遍歷每個節點，執行 DFS
    for (int i = 1; i < 6; ++i) {
        if (!visited[i]) {
            dfs(&head[i], visited);
            std::cout << std::endl;
        }
    }

    // 廣度優先搜尋 (BFS) 遍歷
    std::cout << "BFS Traversal:" << std::endl;
    std::queue<Node*> q;
    // 重置訪問標記陣列
    std::fill(std::begin(visited), std::end(visited), false);

    // 遍歷每個節點，執行 BFS
    for (int i = 1; i < 6; ++i) {
        if (!visited[i]) {
            q.push(&head[i]);
            visited[i] = true;

            while (!q.empty()) {
                Node* current = q.front();
                q.pop();
                std::cout << current->value << " ";

                Node* neighbor = current->next;
                // 遍歷鄰居節點
                while (neighbor) {
                    if (!visited[neighbor->value]) {
                        q.push(&head[neighbor->value]);
                        visited[neighbor->value] = true;
                    }
                    neighbor = neighbor->next;
                }
            }
            std::cout << std::endl;
        }
    }
}