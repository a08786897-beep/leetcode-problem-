class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();

        vector<int> sorted_num=nums;
        sort(sorted_num.begin(),sorted_num.end());

        vector<int> divisors;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                divisors.push_back(i);

                if(i*i!=n){
                    divisors.push_back(n/i);

                }
            }
        }

        int totalSum=0;
        for(int k:divisors){
            bool possible=true;

            for(int j=0;j<n;j+=k){

                int drop=0;

                for(int i=0;i<k;i++){
                    if(nums[j+i]>nums[j+(i+1)%k]){
                        drop++;
                    }
                }
                if(drop>1){
                    possible=false;
                    break;
                }

                vector<int> blocks(nums.begin()+j,nums.begin()+j+k);

                sort(blocks.begin(),blocks.end());

                for(int i=0;i<k;i++){
                    if(blocks[i] != sorted_num[j+i]){
                        possible=false;
                        break;
                    }
                }
                if(!possible) break;
            }

            if(possible){
                totalSum+=k;
            }
        }

        return totalSum;
    }
};