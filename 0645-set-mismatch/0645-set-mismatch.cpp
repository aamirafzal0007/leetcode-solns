class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>mp;
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++)
        { mp[nums[i]]++;
        sum+=nums[i];
        }
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]==2)
            {
                res.push_back(nums[i]);
                break;
            }
        }
        int miss=(n*(n+1)/2)-(sum-res[0]);
        res.push_back(miss);
     return res;   
    }
};