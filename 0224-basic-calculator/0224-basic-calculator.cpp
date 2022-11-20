class Solution {
public:
    int calculate(string s) {
        int num=0;
        int res=0;
        int sign=1;
        int n=s.length();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                num=num*10+(s[i]-'0');
            }
            else if(s[i]=='+')
            {
                res+=(num*sign);
                num=0;
                sign=1;
            }
            else if(s[i]=='-')
            {
                res+=(num*sign);
                num=0;
                sign=-1;
            }
            else if(s[i]=='(')
            {
                st.push(res);
                st.push(sign);
                sign=1;
                res=0;
                num=0;
            }
            else if(s[i]==')')
            {
                res+=(sign*num);
                sign=1;
                num=0;
                int prev_sign=st.top();
                st.pop();
                int prev_res=st.top();
                st.pop();
                res*=prev_sign;
                res+=prev_res;
            }
            
        }
        res+=(num*sign);
        return res;
    }
};