class Logger {
public:
	Logger() {
	}

	bool shouldPrintMessage(int timestamp, string message) {
		auto node = hash.find(message);
		if (node == hash.end()) {
			hash.insert({message, timestamp + next_times});
			return true;
		}

		if (timestamp < node->second)
			return false;
		else
			node->second = timestamp + next_times;
		return true;
	}

private:
	unordered_map<string, int> hash;
	const int next_times = 10;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */