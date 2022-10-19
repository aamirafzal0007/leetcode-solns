class Solution {
public:
    string countAndSay(int n) {
        if(n==1) 
            return "1";
        if(n==2) 
            return "11";
        string res="11";
        
        int count=1;
        for(int i=3;i<=n;i++){
           res+='&';
            int j=1;
            string temp="";
            while(j<res.length()) 
            {
                if(res[j]==res[j-1]) 
                    count++;
                else
                    {
                    temp+=to_string(count) ;
                    temp+=res[j-1];
                    
                    count=1;
                }
                j++;
            }
            res=temp;
        }
        return res;
    }
};