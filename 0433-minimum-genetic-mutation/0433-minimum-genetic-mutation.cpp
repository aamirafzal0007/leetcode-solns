class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int m=bank.size();
        int i=0;
        unordered_map<string,int>mp;
        for(int i=0;i<m;i++)
        {
            mp[bank[i]]=i;
        }
        if(mp.find(end)==mp.end())
             return -1;
        int count=0;
        queue<pair<string,int>>q;
        q.push(make_pair(start,0));
        unordered_map<string,bool>visited;
        visited[start]=true;
        while(!q.empty())
        {//cout<<q.front().first<<endl;
            pair<string,int>res=q.front();
            q.pop();
            if(res.first==end)
                return res.second;
            for(int i=0;i<8;i++)
            {
                string dna="ACGT";
                for(int j=0;j<4;j++)
                {
                    string temp="";
                    temp.append(res.first,0,i);
                    temp+=dna[j];
                   // temp.append(to_string(c));
                    temp.append(res.first,i+1,8-i-1);
                  
                    if(mp.find(temp)!=mp.end()&&visited.find(temp)==visited.end())
                    {  //cout<<"QUEUEE  "<<temp<<endl;
                        q.push(make_pair(temp,res.second+1));
                        visited[temp]=true;
                    }
                }
               // cout<<"next char"<<endl;
            }
          //  cout<<"queue"<<endl;
        }
        return -1;
//         "AGCTGGGG"
// "GGGGGGGG"
// ["CGCTGGGG","CGGTGGGG","CGGGGGGG","GGGGGGGG"]
    }
};