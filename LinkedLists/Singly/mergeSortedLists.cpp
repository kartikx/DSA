#include <iostream>

class Node{
    public:
        Node* next;
        int data;
};

void pushNode(Node*& head, Node*& tail, Node* h) {
    if (!head) {
        head = h;
        tail = h;
        return;
    }
    
    tail->next = h;
    tail = tail->next;
    return;
}

Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    Node* head = NULL;
    Node* tail = NULL;
    while (1) {
        if (!head_A) {
            pushNode(head, tail, head_B);
            break;
        }
        else if (!head_B){
            pushNode(head, tail, head_A);
            break;
        }
        
        if (head_A->data < head_B->data) {
            pushNode(head, tail, head_A);
            head_A = head_A->next;
        }
        else {
            pushNode(head, tail, head_B);
            head_B = head_B->next;
        }
    }
    return head;
}  