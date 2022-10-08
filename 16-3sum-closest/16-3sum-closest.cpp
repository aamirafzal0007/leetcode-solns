class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        //sorting te array
        sort(nums.begin(),nums.end());
        int res=0;
        int n=nums.size();
        if(n<3)
            return accumulate(nums.begin(),nums.end(),res);
        res=nums[0]+nums[1]+nums[2];
       // cout<<res<<endl;
        for(int i=0;i<n-2;i++)
        {
           
            int curr=nums[i];
            int j=i+1,k=n-1;
            while(j<k)
            {
                if(curr+nums[j]+nums[k]==target)
                    return target;
                int sum=curr+nums[j]+nums[k];
          //       cout<<"sumlinbe"<<i<<"  "<<j<<" "<<k<<" "<<sum<<endl; 
                if(abs(sum-target)<abs(res-target))
                {  res=sum;
             //   cout<<i<<"  "<<j<<" "<<k<<" "<<res<<endl; 
                }
                if(sum>target)
                    k--;
                else if(target>sum)
                    j++;
                else
                {
                    k--;
                    j++;
                }
            }
        }
        
        
        return res;
        
    }
};