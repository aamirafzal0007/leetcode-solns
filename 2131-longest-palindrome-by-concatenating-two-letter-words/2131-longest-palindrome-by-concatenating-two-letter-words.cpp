class Solution {
public:
//     int longestPalindrome(vector<string>& words) {
//         int  n=words.size();
//         unordered_map<string,int>mp;
//         for(int i=0;i<n;i++)
//         {
//             mp[words[i]]++;
//         }
//         int count=0,res=0;
//         bool flag=false;
//         for(auto x:mp)
//         {
//             if(x.first[0]==x.first[1])
//             {
//                 if(x.second%2)
//                 {
//                     flag=true;
//                     count+=(x.second-1);
//                 }
//                 else
//                 {
//                     count+=x.second;
//                 }
//                 mp.erase(x.first);
//             }
//             else
//             {
//                 string str=x.first;
//                     reverse(str.begin(),str.end());
//                 if(mp.find(str)!=mp.end())
//                 {
//                     res+=min(x.second,mp[str])*4;
//                 }
//                 mp.erase(x.first);
//                 mp.erase(str);
                
                
//             }
//         }
//         if(flag)
//             return res+count*2+2;   //odd
//         return res+count*2;
//     }
     int longestPalindrome(vector<string>& words) {
        
       int count[26][26] = {}; 
       int ans =0;
        
			for(auto w : words){
				int a = w[0] - 'a';
				int b = w[1] - 'a'; 

				if(count[b][a]){
					ans+= 4;          
					count[b][a]--;   // decrement the count as we found mirror word
				}
                else
					count[a][b]++;  //increment the current word count if we not find any mirror //word
			}
        
			for(int i=0;i<26;i++){
				if(count[i][i]){
					ans+=2;
					break;
				}
			 }
      
	return ans;
     }
};