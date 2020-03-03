#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<unordered_map>
using namespace std;

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
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* head = new Node(node->val);
        deque<Node*> q(1, node);
        unordered_map<Node*, Node*> copies;
        copies[node] = head; 
        while(!q.empty()){
            Node *cur = q.back();
            q.pop_back();
            for(Node* neib: cur->neighbors){
                if(copies.find(neib) == copies.end()){
                    copies[neib] = new Node(neib->val);
                    q.push_front(neib);
                }
                copies[cur]->neighbors.push_back(copies[neib]);
            }
        }
        return head;
    }
};
