class Solution {
public:
     bool checkIfPangram(string sentence) {
        
            int visited[26]={0};
        int n=sentence.length() ;
        for(int i=0;i<n;i++) 
            {
            visited[sentence[i]-'a']++;
            
        }
        for(int i=0;i<26;i++) 
            {
            if(visited[i]==0) 
                return false;
        }
        return true;
        
    }
};