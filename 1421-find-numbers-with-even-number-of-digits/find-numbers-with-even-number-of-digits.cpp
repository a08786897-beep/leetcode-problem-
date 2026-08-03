class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            int count=nums[i];
            int sum=0;
            while(count>0){
                sum++;
                count/=10;
            }
            if(sum%2==0){
                total++;
            }
        }
        return total;
    }
};