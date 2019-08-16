#include<iostream>
#include<conio.h>
#include<malloc.h>
using namespace std;

struct node {
	int data;
	struct node* next;
};

class LinkedList {
private:
	struct node *head, *tail;
	
	struct node* createNode(int data) {
		struct node* newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = data;
		newnode->next = NULL;
		return newnode;
	}
public:
	LinkedList() {
		head = tail = NULL;
	}


	void insertAtEnd(int data) {
		struct node* newnode = createNode(data);
		if (head == NULL) {
			head = newnode;
			tail = newnode;
		}
		else {
			tail->next = newnode;
			tail = newnode;
		}
		cout << data << " inserted at the end sucessfully." << endl;
		print();
	}

	void insertAtStart(int data) {
		struct node* newnode = createNode(data);
		if (head == NULL) {
			head = newnode;
			tail = newnode;
		}
		else {
			newnode->next = head;
			head = newnode;
		}
		cout << data << " inserted at the beginning sucessfully." << endl;
		print();
	}

	void insertAtPos(int data, int pos) {
		if (size() < pos) {
			cout << "The entered position exceeds the size of the current list. Try a position less than " << size() << "." << endl;
		}
		else {
			if (size() == pos) {

				cout << "The entered position is the end of the list. InsertAtEnd performed." << endl;
				insertAtEnd(data);
			}
			else if (pos == 0) {
				cout << "The entered position is the beginning of the list. InsertAtStart performed." << endl;
				insertAtStart(data);
			}
			else {
				int count = 1;
				struct node* temp = head;
				while (count != pos) {
					count++;
					temp = temp->next;
				}
				struct node* newnode = createNode(data);
				newnode->next = temp->next;
				temp->next = newnode;
				cout << data << " inserted at position " << pos << " sucessfully." << endl;
				print();
			}
		}
	}

	void deleteFromStart() {
		if (head == NULL) {
			cout << "The list is empty." << endl;
		}
		else {
			if (head == tail) {
			cout << head->data << " was deleted sucessfully." << endl;
			free(head);
			head = tail = NULL;
			}
			else {
			struct node* deleted = head;
			cout << deleted->data << " was deleted sucessfully." << endl;
			head = head->next;
			free(deleted);
			}
			print();
		}
	}

	void deleteFromEnd() {
		if (head == NULL) {
			cout << "The list is empty." << endl;
		}
		else {
			if (head == tail) {
				cout << head->data << " was deleted sucessfully." << endl;
				free(head);
				head = tail = NULL;
			}
			else {
				struct node* temp = head;
				while (temp->next != tail) {
					temp = temp->next;
				}
				struct node* deleted = temp->next;
				cout << deleted->data << " was deleted sucessfully." << endl;
				temp->next = NULL;
				tail = temp;
			}
			print();
		}
	}

	void deleteFromPos(int pos) {
		if (pos > size()) {
			cout << "The entered position is greater than the linked list. Try a position less than " << size() << "." << endl;
		}
		else if (pos == 0) {
			cout << "The entered position is the beginning. DeleteFromStart performed." << endl;
			deleteFromStart();
		}
		else if (pos == size()) {
			cout << "The entered position is the end. DeleteFromEnd performed." << endl;
			deleteFromEnd();
		}
		else {
			struct node* temp = head;
			int count = 1;
			while (count != pos) {
				count++;
				temp = temp->next;
			}
			struct node* deleted = temp->next;
			cout << deleted->data << " deleted from the position " << pos << " sucessfully." << endl;
			temp->next = temp->next->next;
			free(deleted);
			print();
		}
	}

	void print() {
		if (head == NULL) {
			cout << "The linked list is empty."<<endl;
		}
		else {
			cout << "The list items are: ";
			struct node* temp = head;
			while (temp != NULL) {
				cout << temp->data << "->";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	int size() {
		int count = 0;
		struct node* temp = head;
		while (temp != NULL) {
			count++;
			temp = temp->next;
		}

		return count;
	}
};