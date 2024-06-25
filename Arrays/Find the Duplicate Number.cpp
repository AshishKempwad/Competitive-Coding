/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one duplicate number in nums, return this duplicate number.

Follow-ups:

How can we prove that at least one duplicate number must exist in nums? 
Can you solve the problem without modifying the array nums?
Can you solve the problem using only constant, O(1) extra space?
Can you solve the problem with runtime complexity less than O(n2)?
 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [1,1]
Output: 1
Example 4:

Input: nums = [1,1,2]
Output: 1

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
     int slow = nums[0];
        int fast = nums[nums[0]];

        while (fast != slow)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        //slow or fast doesn't matter here
        return slow;
      
    }
};

-----------------------------------------------------------

 // Approach 2 : TC = O(n) SC = O(1) - Same TC and SC as above just different approach
 class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        //Method : Using numbers as index - We use this method whenever we are given 
        //that for n size array numbers would be in range [1,n]
        
        int n = nums.size();
       //Iterate over the array
        for(int i=0;i<n;i++){

           //Consider absolete value from the given array
            int num = abs(nums[i]);

           //As it is 0 based index array, we find index by subtracting "-1" from the array value.
            int idx = num - 1;

           //If the number is negative that means we have lready visited this  number and made is negative
            if(nums[idx] < 0){
                //That means number is negative and we have already visited such number hence it is duplicate number
                return num;
            }else {
               //This means it is not visited number and we mark the value as negative by multipling it with "-1" to mark it as visited
                nums[idx] = nums[idx]*-1;
            }
        }

        return 0;
        
    }
};
