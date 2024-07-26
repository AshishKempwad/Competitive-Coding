class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        //PrefixSum row wise
        for(int i = 0;i<rows;i++){
            for(int j=1;j<cols;j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }

        //Now apply (cumSum-target) logic in download directions

        int count = 0;

        for(int sc=0;sc<cols;sc++){

            for(int j=sc;j<cols;j++){
                Map<Integer,Integer>mp = new HashMap<>();
                mp.put(0,1);
                int cumSum = 0;

                for(int row=0;row<rows;row++){
                    cumSum += matrix[row][j] - (sc > 0 ? matrix[row][sc-1] : 0);

                    if(mp.containsKey(cumSum-target)){
                        count += mp.get(cumSum-target);
                    }

                    mp.put(cumSum, mp.getOrDefault(cumSum,0)+1);
                }

            }
        }

        return count;
    }
}
