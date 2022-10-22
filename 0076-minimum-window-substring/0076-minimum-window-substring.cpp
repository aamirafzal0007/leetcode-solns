class Solution {
public:
    string minWindow(string s, string t) {
        int freq[128]={0};
        for(auto c:t)
                 freq[c]++;
        int start=0,end=0,minstart=0,minlen=INT_MAX,count=t.length();
        while(end<s.length())
        {
            char s_end=s[end];
            if(freq[s_end]>0)
                count--;
            freq[s_end]--;
            end++;
            
            while(count==0)
            {
                minlen=min(minlen,end-start);
                if(minlen==end-start)
                    minstart=start;
                char s_start=s[start];
                freq[s_start]++;
                if(freq[s_start]>0)
                    count++;
                start++;
            }
        }
        return minlen==INT_MAX?"":s.substr(minstart,minlen);
    }
};