class Solution {
public:
    string breakPalindrome(string palindrome) {
        string alphas="abcdefghijklmnopqrstuvwxyz";
        int n=palindrome.length();
        if(n==1)
            return "";
        int count =0;
        for(int i=0;i<n;i++)
            if(palindrome[i]=='a')
                count++;
        if(count==n||count==n-1)
        {
            palindrome[n-1]='b';
            return palindrome;
        }
        for(int i=0;i<n;i++)
        {   int j=0;
            while(j<26)
            {
                if(palindrome[i]>alphas[j])
                {
                    palindrome[i]=alphas[j];
                    return palindrome;
                }
                j++;
            }
        }
        return "";
    }
};