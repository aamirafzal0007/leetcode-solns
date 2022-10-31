class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int i=matrix[0].size();
        int n=matrix.size(),m=i;
      //  cout<<n<<m;
        for(;i>0;)
        {
            
            int k=i;
            for(int j=1;j<m&&j<n&&i<m;j++)
            {
                if(matrix[j][i]!=matrix[j-1][i-1])
                    return false;
                i++;
            }
            i=k;
            i--;
            
        }
        //[[1,2],[2,1],[1,2],[2,1]]
        //[[11,74,0,93],[40,11,74,7]]
     //   [[1,2,1,2],[2,1,2,1]]
        
         for(int i=2;i<n;i++)
        {
            int k=i;
            for(int j=1;j<m&&i<n;j++)
            {
                
                if(matrix[i][j]!=matrix[i-1][j-1])
                    return false;
                i++;
            }
            i=k;
            
            
        }
        return true;
        
    }
};