class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,pair<int,int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                int diff=abs(mp[nums[i]].first-i);
             //   cout<<diff<<"   "<<mp[nums[i]].second<<endl;
                if(diff<mp[nums[i]].second)
                    mp[nums[i]].second=diff;
                mp[nums[i]].first=i;
            //    cout<<mp[nums[i]].first<<endl;
            }
            else
            {
                mp[nums[i]]=make_pair(i,INT_MAX);
            }
        }
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
           // cout<<mp[i]<<"  "<<mp[i].second<<endl;
            if(it->second.second<=k)
                return true;
        }
        return false;
        
    }
};