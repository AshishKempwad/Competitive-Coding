class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,string>mp;

        int n = names.size();

        for(int i=0;i<n;i++){
            mp[heights[i]] = names[i];
        }

        sort(heights.rbegin(),heights.rend());

        for(int i=0;i<n;i++){
            names[i] = mp[heights[i]];
        }

        return names;


    }
};

///In java

class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        int n = heights.length;

        Map<Integer,String>mp = new HashMap<>();

        for(int i=0;i<n;i++){
            mp.put(heights[i],names[i]);
        }

        Arrays.sort(heights);
        for(int i=0;i<n/2;i++){
            int temp = heights[i];
            heights[i] = heights[n-i-1];
            heights[n-i-1]=temp;
        }

        for(int i=0;i<n;i++){
            names[i] = mp.get(heights[i]);
        }

        return names;
    }
}
