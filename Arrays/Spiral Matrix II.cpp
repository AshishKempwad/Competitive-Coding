class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n));

        int top = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;

        int dir = 0;
        int element = 1;

        while(top <= down && left <= right){
              if(dir == 0){
                  for(int i=left;i<=right;i++){
                    matrix[top][i] = element;
                    element++;
                  }
                  top++;
              }else if(dir == 1){
                for(int i=top;i<=down;i++){
                    matrix[i][right] = element;
                    element++;
                }
                right--;
              }else if(dir == 2){
                for(int i=right;i>=left;i--){
                    matrix[down][i] = element;
                    element++;
                }
                down--;
              }else if(dir == 3){
                for(int i=down;i>=top;i--){
                    matrix[i][left] = element;
                    element++;
                }
                left++;
              }

              dir = (dir+1)%4;
        }

        return matrix;
    }
};

/*            left      right
top              [[1,2,3]
                  [8,9,4]
down              [7,6,5]]


*/
