#include <bits/stdc++.h> 
using namespace std; 

struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
	if(node == NULL) return;
	Node *temp = node;
	while (temp != NULL) { 
        cout << temp->data <<" ";
        temp = temp->next;
    }
  cout<<"\n";
} 

//Function to insert a node at the beginning of the linked list.
Node *insertAtBegining(Node *head, int x) {
    Node *new_node = new Node(x);
    new_node->next = head;
    return new_node;
}
    
    
//Function to insert a node at the end of the linked list.
Node *insertAtEnd(Node *head, int x) {
    Node *temp = head;
    while(temp->next != NULL){
    	temp = temp->next;
    }
	Node *new_node = new Node(x);
	temp->next = new_node;
    return head;
}

Node* deleteNode(Node *head,int x)
{
    // x is the position of that node
    // e.g. in 1->2->3
    // 2 is at position 2
    if(x==1) {
    	// corner condition
    	Node *to_delete = head;
    	head = head->next;
    	delete to_delete;
    	return head;
    }
    Node *temp = head;
    for (int i = 1; i < x-1; ++i){
    	temp = temp->next;
    }

    Node *to_delete = temp->next;

    if(temp->next->next == NULL){
    	// corner condition
    	temp->next = NULL;
    } else {
    	Node *next_node = temp->next->next;
    	temp->next = next_node;
    }
    delete to_delete;
    return head;
    
}

Node *deleteList(Node *head){
	Node *current = head;
	Node *next_node = NULL;
	while(current != NULL){
		next_node = current->next;
		delete current;
		current = next_node;
	}
	head = NULL;
	return head;
}

int main() { 
    Node *head = new Node(1);

    Node *last = head;
    for (int i = 2; i < 7; ++i){
    	Node *temp = new Node(i);
    	temp->next = NULL;
    	last->next = temp;
    	last = temp;
    }

    printList(head);    
    head = deleteList(head);
    printList(head);

    return 0; 
} 