class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if(nums.size()<=2){
        return nums.size();
       }
       int wId=2;

       for(int i=2;i<nums.size();i++){
        if(nums[i] != nums[wId-2]){
            nums[wId]=nums[i];
            wId++;
        }
       }
       return wId;
    }
};