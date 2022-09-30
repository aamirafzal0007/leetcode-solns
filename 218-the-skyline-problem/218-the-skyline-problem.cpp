class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
         vector<vector< int>> res;
        int cur=0, cur_X, cur_H =-1,  len = buildings.size();
        priority_queue< pair<int, int>> liveBlg; 
        while(cur<len || !liveBlg.empty())
        { 
            cur_X = liveBlg.empty()? buildings[cur][0]:liveBlg.top().second; // next timing point to process

            if(cur>=len || buildings[cur][0] > cur_X)
            { 
                while(!liveBlg.empty() && ( liveBlg.top().second <= cur_X) ) liveBlg.pop();
            }
            else
            {
                cur_X = buildings[cur][0];
                while(cur<len && buildings[cur][0]== cur_X)  
                {  // just push them in the queue
                    liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }
            cur_H = liveBlg.empty()?0:liveBlg.top().first; 
            if(res.empty() || (res.back()[1] != cur_H) )                    {   vector<int>temp;
                                                                                temp.push_back(cur_X);
             temp.push_back(cur_H);                                                                
                res.push_back(temp);
                                                                            }
        }
        return res;
    }
};