#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

class Queue {
private:
	int *queue;
	int queueCapacity;
	int start;
	int end;
public:
	Queue(int queue_capacity) {
		queueCapacity = queue_capacity;
		queue = (int*)malloc(sizeof(int) * queue_capacity);
		start = -1;
		end = -1;
	}

	void enqueue(int data) {
		if (end < start || (end == queueCapacity - 1 && start == 0)) {
			cout << "the queue is full." << endl;
			return;
		}
		else if (end == -1 && start == -1) {
			end = 0;
			start = 0;
		}
		else if (end == queueCapacity - 1) {
			end = 0;
		}
		else {
			end++;
		}
		queue[end] = data;
	}

	int dequeue() {
		if (start == end == -1) {
			cout << "the queue is empty." << endl;
			return -1;
		}
		int removed = queue[start];
		if (start == end) {
			start = end = -1;
		}
		else if (start == queueCapacity - 1) {
			start = 0;
		}
		else {
			start++;
		}
		return removed;
	}

	int front() {
		if (isEmpty())
			return -1;
		return queue[start];
	}

	bool isEmpty() {
		if (start == -1 && end == -1)
			return true;
		return false;
	}

	void printQueue() {
		if (isEmpty())
			cout << "the queue is empty." << endl;
		else {
			if (start <= end) {
				for (int i = start; i <= end; i++) {
					cout << queue[i] << "<-";
				}
			}
			else {
				for (int i = start; i < queueCapacity; i++) {
					cout << queue[i] << "<-";
				}
				for (int i = 0; i <= end; i++) {
					cout << queue[i] << "<-";
				}
			}
		}
	}
};