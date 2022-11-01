class Solution {
public:
   int dfs(int i,int j,vector<vector<int>>& grid){
     if(i>=grid.size())return j;
    
    if(grid[i][j]==1&&j+1<grid[0].size()&&grid[i][j+1]==1)
        return dfs(i+1,j+1,grid);
    
    if(grid[i][j]==-1&&j-1>=0&&grid[i][j-1]==-1)
        return dfs(i+1,j-1,grid);
    
    return -1;
    
}
vector<int> findBall(vector<vector<int>>& grid) {
    int j=grid[0].size();
    vector<int>ans(j);
    for(int k=0;k<j;k++){
       ans[k]= dfs(0,k,grid);
    }
    return ans;
}
};