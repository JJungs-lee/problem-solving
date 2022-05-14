class MyCircularQueue {
	vector<int> v;
	int max_size;
	int head;
	int tail;

public:
	MyCircularQueue(int k) {
		v.resize(k + 1);
		max_size = k + 1;
		head = 0;
		tail = 0;
	}

	bool enQueue(int value) {
		if (isFull())
			return false;

		tail = (tail + 1) % max_size;
		v[tail] = value;
		return true;
	}

	bool deQueue() {
		if (isEmpty())
			return false;

		head = (head + 1) % max_size;
		return true;
	}

	int Front() {
		if (isEmpty())
			return -1;
		return v[(head + 1) % max_size];
	}

	int Rear() {
		if (isEmpty())
			return -1;
		return v[tail];
	}

	bool isEmpty() {
		return head == tail;
	}

	bool isFull() {
		return head == (tail + 1) % max_size;
	}
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */