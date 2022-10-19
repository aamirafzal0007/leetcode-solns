class Solution {
public:
   vector<string> topKFrequent(vector<string>& words, int k) {
        auto compare = [](pair<int,string>&a, pair<int,string>&b) {
            if(a.first == b.first){
                return a.second >= b.second;
            }
            return a.first < b.first;
        };
        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(compare)>pq(compare);
        unordered_map<string,int>freq;
        vector<string>res;
        int cnt = 0;
        for(auto i : words){
            freq[i]++;
        }
        for(auto i : freq){
            pq.push({i.second,i.first});
        }
        while(!pq.empty() and cnt < k){
           // cout << pq.top().first << " : " << pq.top().second << endl;
            res.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        
        return res;
    }
};