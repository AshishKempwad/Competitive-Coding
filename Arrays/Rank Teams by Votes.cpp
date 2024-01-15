class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int m = votes[0].size();
        vector<vector<int>> mp(26, vector<int>(m,0)); // 2d vector to calc total votes for each
        //ranking for each char
        for(string& voter : votes){
            for(int i = 0 ; i < voter.length() ; i++){
                mp[voter[i]-'A'][i]++;
            }
        }

        vector<pair<vector<int>, char>> table(26); //to store the rank chart against each char 

        for(int i = 0 ; i < 26 ; i++){
            table[i] = {mp[i],(i+'A')};
        }

        sort(table.begin(),table.end(),[](pair<vector<int>,char>& a,pair<vector<int>,char>& b){
            //making the cmp according to the intruction in question
            return (a.first > b.first) || (a.first == b.first && a.second < b.second);
        });

        string ans = "";

        for(int i = 0 ; i < m ; i++){ //just to reduce a little bit tc
            ans += table[i].second;
        }

        return ans;
    }
};
