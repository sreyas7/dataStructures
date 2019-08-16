#include<iostream>
#include<conio.h>
using namespace std;

struct item {
	int data;
	int priority;
	struct item *previous, *next;
};

class PriorityQueue {
private:
	struct item  *head, *tail, *temp;
	
	struct item* create_item(int data, int priority) {
		struct item* newitem = (struct item*)malloc(sizeof(struct item));
		newitem->data = data;
		newitem->priority = priority;
		newitem->previous = NULL;
		newitem->next = NULL;
		return newitem;
	}
public:
	PriorityQueue() {
		head = tail = temp = NULL;
	}

	void insert_item(int data, int priority) {
		struct item* newitem = create_item(data, priority);
		if (head == NULL) {
			head = tail = newitem;
		}
		else {
			temp = head;
			while (newitem->priority > temp->priority && temp->next != NULL) {
				temp = temp->next;
			}
			if (newitem->priority < temp->priority) {
				if (temp == head) {
					newitem->next = temp;
					temp->previous = newitem;
					head = newitem;
				}
				else {
					newitem->previous = temp->previous;
					newitem->next = temp->previous->next;
					temp->previous->next = newitem;
					temp->previous = newitem;
				}
			}
			else if (temp->next == NULL) {
				temp->next = newitem;
				newitem->previous = temp;
				tail = newitem;
			}
		}
		cout << data << " with priority "<< priority <<", inserted sucessfully." << endl;
	}

	int return_max() {
		if (head == NULL) {
			cout << "There are no elements in the queue currently." << endl;
			return INT_MAX;
		}
		return tail->data;
	}

	int pop_max() {
		if (head == NULL) {
			cout << "There are no elements in the queue currently." << endl;
			return INT_MAX;
		}
		else if (head == tail) {
			temp = tail;
			free(tail);
			head = tail = NULL;
		}
		else {
			temp = tail;
			tail = tail->previous;
			free(tail->next);
			tail->next = NULL;
		}
		return temp->data;
	}

	int return_min() {
		if (head == NULL) {
			cout << "There are no elements in the queue currently." << endl;
			return INT_MIN;
		}
		return head->data;
	}

	int pop_min() {
		if (head == NULL) {
			cout << "There are no elements in the queue currently." << endl;
			return INT_MIN;
		}
		else if (head == tail) {
			temp = head;
			free(head);
			head = tail = NULL;
		}
		else {
			temp = head;
			head = head->next;
			free(head->previous);
			head->previous = NULL;
		}
		return temp->data;
	}

	void update_priority(int data, int new_priority) {
		if (head == NULL) {
			cout << "There are no elements in the queue currently." << endl;
		}
		else {
			temp = head;
			while (temp->data != data && temp->next != NULL) {
				temp = temp->next;
			}
			if (temp->data == data) {
				temp->priority = new_priority;
				cout << "Priority updated for the given data." << endl;
			}
			else if (temp->next == NULL) {
				cout << "Data with the given value does not exist." << endl;
			}
		}
	}

	void pop_item(int data) {
		if (head == NULL) {
			cout << "There are no elements in the queue currently." << endl;
		}
		else {
			temp = head;
			while (temp->data != data && temp->next != NULL) {
				temp = temp->next;
			}
			if (temp->data == data) {
				if (temp->next != NULL) {
					temp->next->previous = temp->previous;
					temp->previous->next = temp->next;
					free(temp);
				}
				else {
					tail = temp->previous;
					tail->next = NULL;
					free(temp);
				}
				cout << "The data was sucessfully removed." << endl;
			}
			else if (temp->next == NULL) {
				cout << "Data with the given value does not exist." << endl;
			}
		}
	}

	void print_queue() {
		if (head == NULL) {
			cout << "There are no elements in the queue currently." << endl;
		}
		else {
			temp = head;
			while (temp != NULL) {
				cout << "(data=" << temp->data << ", priority=" << temp->priority << ")->";
				temp = temp->next;
			}
			cout << endl;
		}
	}
};