/*
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task.
Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), 
that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.


Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int> count(26, 0);
        int tasks_size = tasks.size();
        int max_freq = 0;
        for (auto &it : tasks) {
            count[it - 65]++;   // 65 is ascii value of 'A'
            max_freq = max(max_freq, count[it - 65]);
        }

        int result = (max_freq - 1) * (n+1);
        for (auto &it : count) {
            if (max_freq == it) {
                result++;
            }
        }

        return max(result, tasks_size);
        
    }
};
