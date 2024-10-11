class Solution {

    //TC = O(N)

  /* LOGIC :
First, we give each soldier at least 1 medal, as per the problem's requirement.
Then, we traverse the soldiers from left to right, ensuring that each soldier has more medals than the soldier to their left if they have a higher rank.
After that, we traverse the soldiers from right to left to ensure the same rule holds true for the neighbors to the right.

  */
    
    public int candy(int[] ratings) {
        int n = ratings.length;
        int[] medals = new int[n];

        Arrays.fill(medals,1);

       //left to right - compare with left
        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1]){
                medals[i] = medals[i-1]+1;
            }
        }
        //right to left - compare with right
        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                medals[i] = Math.max(medals[i], medals[i+1]+1);
            }
        }

        int totalMedals = 0;

        for(int medal : medals){
            totalMedals += medal;
        }

        return totalMedals;
    }
}
