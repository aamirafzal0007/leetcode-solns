class Solution {
public:
     private:
    int shiftRightDown(vector<vector<int>>& A, vector<vector<int>>& B, int xShift, int yShift, int N) {
//i represents row i.e towards y axis
//j represents column i.e towards x axis
        int count = 0;
        for (int i = yShift; i < N; i++) {

            for (int j = xShift; j < N; j++) {
                if (A[i][j] == 1 && B[i - yShift][j - xShift] == 1)
                    count++;
            }
        }
        return count;
    }

    private:
    int shiftRightUp(vector<vector<int>>& A, vector<vector<int>>& B, int xShift, int yShift, int N) {
        int count = 0;
        for (int i = yShift; i < N; i++) {
            for (int j = 0; j < N - xShift; j++) {
                if (A[i][j] == 1 && B[i - yShift][j + xShift] == 1)
                    count++;
            }
        }
        return count;
    }

   public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
      int maxCount = 0;
        int N = img1.size();
        //xShift & yShift will be equivalent to the starting row, col of the sliding matrix over fixed matrix
        //i.e (1,0) the overlap started between
        //1st Matrix moving, 2nd fixed
        for (int yShift = 0; yShift < N; yShift++) {
            for (int xShift = 0; xShift < N; xShift++) {
                maxCount = max(maxCount, shiftRightDown(img1, img2, xShift, yShift, N));
                maxCount = max(maxCount, shiftRightDown(img2, img1, xShift, yShift, N));
                maxCount = max(maxCount, shiftRightUp(img1, img2, xShift, yShift, N));
                maxCount = max(maxCount, shiftRightUp(img2, img1, xShift, yShift, N));
            }
        }

        return maxCount;
        
        
    }
};