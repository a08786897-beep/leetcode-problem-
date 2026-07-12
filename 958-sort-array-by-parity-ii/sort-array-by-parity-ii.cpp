class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
       vector<int> even={};
       vector<int> odd={};
       for(int i :nums){
            if(i%2==0){
                even.push_back(i);
            }
            if(i%2 != 0){
                odd.push_back(i);
            }
       }
       vector<int> res(nums.size(),0);
       int l=0,r=0;
       for(int i=0;i<nums.size();i++){
            if(i%2==0){
                res[i]=even[l];
                l++;
            }else{
                res[i]=odd[r];
                r++;
            }
       }
        return res;
    }
};