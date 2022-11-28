class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,bool>winner,loser;
        for(auto i:matches)
        {
            if(loser.find(i[1])==loser.end())
            {
                loser[i[1]]=true;
            }
            else if(loser[i[1]]==true)
            {
                loser[i[1]]=false;
            }
            winner[i[0]]=true;
        }
        for(auto &x:loser)
        {
            if(loser.find(x.first)!=loser.end())
            {
                winner.erase(x.first);
            }
        }
        vector<vector<int>>res;
        vector<int>temp;
        for(auto x:winner)
        {
            
            temp.push_back(x.first);
        }
        sort(temp.begin(),temp.end());
        res.push_back(temp);
        vector<int>t;
        for(auto x:loser)
            if (x.second==true)
                t.push_back(x.first);
        sort(t.begin(),t.end());
        res.push_back(t);
        return res;
    }
};