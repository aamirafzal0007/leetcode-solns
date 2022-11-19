class Solution {
public:
    int findslope(pair<int,int>&p1,pair<int,int>&p2,pair<int,int>p3)
    {
        int x1=p1.first;
        int x2=p2.first;
        int x3=p3.first;
        int y1=p1.second;
        int y2=p2.second;
        int y3=p3.second;
        return (y3-y2)*(x2-x1)-(y2-y1)*(x3-x2);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(),trees.end());  //to start with left most tree in xy plane
        vector<vector<int>>res;
        deque<pair<int,int>> upper,lower;  //pairs of x and y
        
        for(auto point:trees)
        {
            int lsize=lower.size();
            int usize=upper.size();
            
            while(lsize>1&&findslope(lower[lsize-1],lower[lsize-2],{point[0],point[1]})<0)
            {
                lsize--;
                lower.pop_back();
            }
            
             while(usize>1&&findslope(upper[usize-1],upper[usize-2],{point[0],point[1]})>0)
            {
                usize--;
                upper.pop_back();
            }
            upper.push_back({point[0],point[1]});
             lower.push_back({point[0],point[1]});
         }
        
        set<pair<int,int>> points;
        for(auto point:upper)
            points.insert(point);
        for(auto point:lower)
            points.insert(point);
        
        for(auto point:points)
        {
            res.push_back({point.first,point.second});
        }
        return res;
        
    
    }
};