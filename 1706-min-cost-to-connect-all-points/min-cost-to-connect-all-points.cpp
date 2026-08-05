class Solution {
public:
    int manD(vector<vector<int>>& points,int p1,int p2){
        return abs(points[p1][0]-points[p2][0])+abs(points[p1][1]-points[p2][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>> > pq;
        vector<bool> mstset(n,false);
        int mstCount=0;
        pq.push({0,0});
        while(pq.size()>0){
            auto p=pq.top();
            int wt=p.first;
            int node=p.second;
            pq.pop();

            if(mstset[node]) continue;

            mstset[node]=true;
            mstCount += wt;

            for(int i=0;i<n;i++){
                if(!mstset[i]){
                    int dis=manD(points,node,i);
                    pq.push({dis,i});
                }
            }
        }
        return mstCount;
    }
};