class StockSpanner {
public:
   stack<pair<int,int>>s;
	StockSpanner() {

	}

	int next(int price) {
		if(s.empty())
		{
			s.push({price,1});
			return 1;
		}
		int sum=0;
		while(!s.empty() and s.top().first<=price)
		{
			int x=s.top().second;
			s.pop();
			sum+=x;
		}
		s.push({price,sum+1});
		return sum+1;
	}
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */