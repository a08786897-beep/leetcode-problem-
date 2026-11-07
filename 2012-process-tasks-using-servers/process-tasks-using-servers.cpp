class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // Min-heap for free servers: {weight, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeserver;
        
        // Min-heap for busy servers: {free_time, weight, index}
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> busyserver;

        for (int i = 0; i < n; i++) {
            freeserver.push({servers[i], i});
        }

        vector<int> res(m);
        long long curr_time = 0;

        for (int i = 0; i < m; i++) {
            curr_time = max(curr_time, (long long)i);

            // Release all servers that have finished their tasks by curr_time
            while (!busyserver.empty() && get<0>(busyserver.top()) <= curr_time) {
                auto [fintime, wt, idx] = busyserver.top();
                busyserver.pop();
                freeserver.push({wt, idx});
            }

            // If no servers are free, jump time to when the earliest server becomes free
            if (freeserver.empty()) {
                auto [fintime, wt, idx] = busyserver.top();
                busyserver.pop();
                curr_time = fintime;
                freeserver.push({wt, idx});

                // Release any other servers that become free at this new curr_time
                while (!busyserver.empty() && get<0>(busyserver.top()) <= curr_time) {
                    auto [ft, wt_val, id] = busyserver.top();
                    busyserver.pop();
                    freeserver.push({wt_val, id});
                }
            }

            // Assign the task to the best available server
            auto [wt, idx] = freeserver.top();
            freeserver.pop();
            res[i] = idx;
            busyserver.push({curr_time + tasks[i], wt, idx});
        }

        return res;
    }
};