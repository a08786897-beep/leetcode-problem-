class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
         // Make the Augmented string
        string t = "1" + s + "1";

        // Store alternate block lengths
        vector<int> blocks;

        int count = 0;
        int i = 0;
        int j = 0;

        while (j < t.length()) {

            // Continue same block
            if (t[i] == t[j]) {
                count++;
                j++;
                continue;
            }

            // New block starts
            blocks.push_back(count);
            count = 0;
            i = j;
        }

        // Add last block
        blocks.push_back(count);

        // Find maximum gain
        int maxGain = 0;

        for (int i = 2; i < blocks.size() - 1; i += 2) {
            maxGain = max(maxGain, blocks[i - 1] + blocks[i + 1]);
        }

        // Count original active sections
        int oneCount = 0;

        for (char ch : s) {
            if (ch == '1')
                oneCount++;
        }

        // Return answer
        return oneCount + maxGain;
    }
};