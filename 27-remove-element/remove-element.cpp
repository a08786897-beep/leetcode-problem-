class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> temp;
        for(int i : nums){
            if(i != val){
                temp.push_back(i);
            }
        }
        nums=temp;
        return nums.size();
    }
};