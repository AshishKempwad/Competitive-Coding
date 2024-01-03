class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();

        int laserBeams = 0;
        vector<int>temp;
        
        for(auto &row : bank){
            int devices=0;
            for(auto &ch : row){
                if(ch == '1'){
                    devices++;
                }
            }
            if(devices > 0){
                temp.push_back(devices);
            }
        }

        if(temp.size() == 0){
            return 0;
        }

        for(int i=0;i<temp.size()-1;i++){
          laserBeams += temp[i]*temp[i+1];  
        }
        return laserBeams;
    }
};
