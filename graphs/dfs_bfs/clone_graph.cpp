#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    vector<Node*> nodeReg;

    void dfs(Node* clone, Node* actual) {
        for(auto neighbor : actual->neighbors) {
            if(!nodeReg[neighbor->val]) {
                Node* newNode = new Node(neighbor->val);
                nodeReg[newNode->val] = newNode;
                clone->neighbors.push_back(newNode);
                dfs(newNode, neighbor);
            } else {
                clone->neighbors.push_back(nodeReg[neighbor->val]);
            }
        }
    }

    Node* bfs(Node* node) {
        if(node == NULL) return NULL;
        Node* clone = new Node(node->val);
        nodeReg.resize(105,NULL);
        nodeReg[clone->val] = clone;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            for(auto neighbor : curr->neighbors) {
                if(!nodeReg[neighbor->val]) {
                    Node* newNode = new Node(neighbor->val);
                    nodeReg[newNode->val] = newNode;
                    nodeReg[curr->val]->neighbors.push_back(newNode);
                    q.push(neighbor);
                } else {
                    nodeReg[curr->val]->neighbors.push_back(nodeReg[neighbor->val]);
                }
            }
        }
        return clone;
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node* clone = new Node(node->val);
        nodeReg.resize(105,NULL);
        nodeReg[clone->val] = clone;
        // dfs(clone, node);
        // return clone;

        return bfs(node);
    }
};

int main() {
    

    return 0;
}