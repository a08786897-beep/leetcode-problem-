class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        // Step 1: Find two possible candidates
        for (int i = 0; i < nums.size(); i++) {

            if (count1 == 0 && el2 != nums[i]) {
                count1 = 1;
                el1 = nums[i];
            }
            else if (count2 == 0 && el1 != nums[i]) {
                count2 = 1;
                el2 = nums[i];
            }
            else if (el1 == nums[i]) {
                count1++;
            }
            else if (el2 == nums[i]) {
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verify the candidates
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el1)
                cnt1++;

            if (nums[i] == el2)
                cnt2++;
        }

        // Step 3: Check if frequency > n/3
        vector<int> ls;
        int mini = nums.size() / 3 + 1;

        if (cnt1 >= mini)
            ls.push_back(el1);

        if (cnt2 >= mini)
            ls.push_back(el2);

        return ls;
    }
};