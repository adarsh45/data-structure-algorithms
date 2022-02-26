#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *prev, *next;
	Node(int x){
		data = x;
		prev = NULL;
		next = NULL;
	}
};

void printList(Node *node){
	if(node == NULL) return;
	Node *temp = node;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}

Node *insertAtBegining(Node *head, int x){
	Node *new_node = new Node(x);
	if(head != NULL){
		head->prev = new_node;
	}
	new_node->next = head;
	return new_node;
}

Node *insertAtEnd(Node *head, int x){
	Node *new_node = new Node(x);
	Node *temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->prev = temp;
	return head;
}

void addNode(Node *head, int pos, int data)
{
   // Your code here
   
   Node *new_node = new Node(data);
   Node *temp = head;
   while(pos--){
       temp = temp->next;
   }
   Node *next_node = temp->next;
   temp->next = new_node;
   next_node->prev = new_node;
   
   new_node->prev = temp;
   new_node->next = next_node;
}

struct Node* reverseDLL(struct Node * head)
{
	struct Node *curr = head;
    while(curr != NULL){
        struct Node *temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = curr->next;
    }
    return head;
}

int main(){
	Node *head = new Node(1);
	Node *last = head;
	for (int i = 2; i < 6; ++i)
	{
		Node *new_node = new Node(i);
		last->next = new_node;
		new_node->prev = last;
		last = new_node;

	}
	// head = insertAtBegining(head, 0);
	head = insertAtEnd(head, 6);
	head = insertAtEnd(head, 7);

	head = reverseDLL(head);

	printList(head);
	return 0;
}