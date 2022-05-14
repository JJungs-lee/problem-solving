class MovingAverage {
	int max_size;
	double sum = 0;
	queue<int> q;

public:
	MovingAverage(int size) {
		max_size = size;
	}

	double next(int val) {
		if (max_size <= q.size()) {
			sum -= q.front();
			q.pop();
		}

		sum += val;
		q.push(val);
		return sum / static_cast<double>(q.size());
	}
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */