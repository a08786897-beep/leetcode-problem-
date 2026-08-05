class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start>destination){
            swap(start,destination);
        }
        int clock_distance=0;
        int total_distance=0;

        for(int i=0;i<distance.size();i++){
            if(i>=start && i<destination){
                clock_distance += distance[i];
            }
            total_distance+=distance[i];
        }
        int curr_clock_wise_ditance=total_distance-clock_distance;
        return min(curr_clock_wise_ditance,clock_distance);
    }
};