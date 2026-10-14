class Solution {
public:
    int sum_max(vector<int>& weights){
        int n=weights.size();
        int sum=0;
        for(int i =0;i<n;i++){
            sum+=weights[i];
        }
        return sum;
    }
    int findnoOfdays(vector<int>& weights, int cap){
        int n=weights.size();
        int day=1,load=0;
        for(int i=0;i<n;i++){
            if(load+weights[i]>cap){
                day++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return day;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end()),high=sum_max(weights);

        while(low<=high){
            int mid=low+(high-low)/2;
            int reqdays=findnoOfdays(weights,mid);
            if(reqdays<=days){

                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};