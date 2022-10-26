class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0)
        {
            for(int i=1;i<n;i++)
                if(nums[i]==0&&nums[i-1]==0)
                    return true;
            return false;
        }
        unordered_map<int,int>mp;
        mp[0]=-1;//edge case
        int prefix=0;
        for(int i=0;i<n;i++)
        {
            prefix+=nums[i];
            if(mp.find(prefix%k)!=mp.end()&&(i-mp[prefix%k])>1)
                return true;
            if(mp.find(prefix%k)==mp.end())
                    mp[prefix%k]=i;
        }
        return false;
    }
};