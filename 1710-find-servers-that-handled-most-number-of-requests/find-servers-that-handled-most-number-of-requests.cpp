class Solution {
public:
    typedef pair<int,int> p;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> freeServer;

        for(int i=0;i<k;i++){
            freeServer.insert(i);
        }

        priority_queue<p,vector<p>, greater<p>> busyServer;

        vector<int> countRequest(k,0);

        for(int i=0;i<arrival.size();i++){
            int time=arrival[i];

            while(!busyServer.empty() && busyServer.top().first<=time){
                int server=busyServer.top().second;

                busyServer.pop();

                freeServer.insert(server);
            }
            int target=i%k;

            auto it=freeServer.lower_bound(target);

            if(it==freeServer.end()){
                it=freeServer.begin();
            }

            if(freeServer.empty()){
                continue;
            }

            int targetServer=*it;

            freeServer.erase(it);

            busyServer.push({time+load[i],targetServer});

            countRequest[targetServer]++;

        }
        int maxNumber=*max_element(countRequest.begin(),countRequest.end());

        vector<int> res;

        for(int i=0;i<k;i++){
            if(countRequest[i]==maxNumber){
                res.push_back(i);
            }
        }
        return res;

    }
};