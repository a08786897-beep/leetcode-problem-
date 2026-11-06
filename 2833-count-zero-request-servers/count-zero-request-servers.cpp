class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=logs.size();

        auto lambda=[](vector<int>& vec1,vector<int>& vec2){
            return vec1[1]<vec2[1];
        };

        sort(logs.begin(),logs.end(),lambda);

        int q=queries.size();
        vector<int> res(q);

        vector<pair<int,int>> timeIdx(q);
        for(int i=0;i<q;i++){
            timeIdx[i]={queries[i],i};
        }

        sort(timeIdx.begin(),timeIdx.end());
        unordered_map<int,int> mp;
        int i=0,j=0;

        for(auto [time,idx]:timeIdx){
            int start=time-x;
            int end=time;

            while(j<m && logs[j][1]<=end){
                mp[logs[j][0]]++;
                j++;
            }
            while(i<m && logs[i][1]<start){
                mp[logs[i][0]]--;
                if(mp[logs[i][0]]==0){
                    mp.erase(logs[i][0]);
                }
                i++;
            }
            res[idx]=n-mp.size();
        }
        return res;
    }
};