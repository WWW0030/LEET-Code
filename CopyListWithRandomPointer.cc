#include "bits/stdc++.h"
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        vector<pair<Node*, Node*>> nodeMap;
        Node* curPointer = head;        
        Node* newHead = new Node (curPointer->val);        
        Node* lastPointer = newHead;
        curPointer = head->next;
        Node* lastNewList = newHead;
        pair<Node*, Node*> tempPair;
        tempPair.first = head;
        tempPair.second = newHead;
        nodeMap.push_back(tempPair);
        while (curPointer != NULL) {
            Node* tempNode = new Node(curPointer->val);
            lastNewList->next = tempNode;
            tempPair.first = curPointer;
            tempPair.second = tempNode;
            nodeMap.push_back(tempPair);
            curPointer = curPointer->next;
            lastNewList = tempNode;
        }
        curPointer = head;
        for(pair<Node*, Node*> curp : nodeMap) {
            for (pair<Node*, Node*> p : nodeMap) {
                if (curp.first->random == p.first) {
                    curp.second->random = p.second;
                    cout << "Here is reached" << endl;
                    break;
                }
            }
        }
        return newHead;
    }
};