class StockPrice {
	unordered_map<int, int> prices;
	map<int, int> price_order;
	int lastTime = -1;

public:
	StockPrice() {
	}

	void update(int timestamp, int price) {
		if (prices.find(timestamp) != prices.end()) {
			int prev_price = prices[timestamp];
			price_order[prev_price]--;
			if (price_order[prev_price] == 0)
				price_order.erase(prev_price);
		}
		prices[timestamp] = price;
		price_order[price]++;
		lastTime = max(lastTime, timestamp);
	}

	int current() {
		return prices[lastTime];
	}

	int maximum() {
		return price_order.rbegin()->first;
	}

	int minimum() {
		return price_order.begin()->first;
	}
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */