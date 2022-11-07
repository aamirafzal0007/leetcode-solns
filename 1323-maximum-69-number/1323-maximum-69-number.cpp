class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digits;
        while(num>0)
        {
            int rem=num%10;
            digits.push_back(rem);
            num=num/10;
            
        }
        num=0;
        bool flag=true;
        int n=digits.size();
        for(int i=n-1;i>=0;i--)
        {
            //cout<<digits[i]<<endl;
            if(digits[i]==6&&flag)
            {  digits[i]=9;
            flag=false;
            }
            num=(digits[i]*10)+num*10;
           // cout<<num<<endl;
        }
        return num/10;
        
        
    }
};