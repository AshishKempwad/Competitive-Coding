class Solution {
public:
    //THIS IS FAMOUS Josephus problem
    int findTheWinner(int n, int k) {
        
        // //Approach 1 : Simulation on Array TC = O(n^2)
        // vector<int>arr;
        // for(int i=1;i<=n;i++){
        //     arr.push_back(i);
        // }

        // int i = 0;        //We start the game from first player who is at at index 0 in array.
        // while(arr.size() > 1){  //Keep playing this game until there are more than 1 player left
           
        //    //Find the index to remove(i+k) and do subtract -1 becuase it is 0 based array.
        //    //And we mod with size of array so that if it goes out of bound, we rotate back to start.
        //    int idx = (i+k-1)%arr.size();  

        //    arr.erase(arr.begin()+idx); //Delete the element at position (and erase operation shifts all the elements left by one place)

        //    i = idx;   //We start counting/playing game from next index
        // } 

        // return arr[0];





        //Approach 2 : Simulation on Queue.   TC = O(n*k)

        // queue<int>q;

        // for(int i=1;i<=n;i++){
        //     q.push(i);
        // }
      
        // //We play this game until more than 1 player are remaining
        // while(q.size() > 1){

        //     for(int count=1;count<k;count++){  //Move by "k" steps
        //         q.push(q.front());            //Push the first k elements to back and pop it from front
        //         q.pop();
        //     }

        //     q.pop();                          //remove the player to be deleted
        // }

        // return q.front();      //The only remaning player finally

        //Approach 3: Using Recursion TC = O(n)

        int idx = findIdxOfWinner(n,k);
        return idx+1;   //As datastructure is 0 based index
   
    }

    int findIdxOfWinner(int n, int k){
        if(n == 1){
            return 0;
        }

        int idx = findIdxOfWinner(n-1,k);
        idx = (idx+k)%n;   //To find the original index in original array

        return idx;

    }
};
