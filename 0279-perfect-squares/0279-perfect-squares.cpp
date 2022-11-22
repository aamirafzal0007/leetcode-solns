class Solution {
public:
    
    //18=16+1+1(3 numbers) but 18=9+9(2 only)
     int t[10001];
    
    int minSquares(int n) {
        if(n == 0)
            return 0;
        
        if(t[n] != -1)
            return t[n];
        
        //we can select only those perfect squares which can contribute to sum up to n
        int minCount = INT_MAX;
        for(int i = 1; i*i<=n; i++) {
            minCount = min(minCount, 1 + minSquares(n-i*i)); //1 is for selectcing one quare number
        }
        
        return t[n] = minCount;
    }
    
    int numSquares(int n) {
        memset(t, -1, sizeof(t));
        
        return minSquares(n);
    }
};