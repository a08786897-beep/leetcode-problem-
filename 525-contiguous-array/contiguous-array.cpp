class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> sumMap;

        sumMap[0]=-1;

        int maxLen=0;
        int count=0;

        for(int i=0;i<nums.size();i++){
            count+=(nums[i]==1)?1:-1;

            if(sumMap.find(count) != sumMap.end()){
                maxLen=max(maxLen,i-sumMap[count]);
            }else{
                sumMap[count]=i;
            }
        }
        return maxLen;
    }
};