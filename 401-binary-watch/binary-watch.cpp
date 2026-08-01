class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    string timeStr = to_string(h) + ":" +
                                     (m < 10 ? "0" : "") +
                                     to_string(m);
                    result.push_back(timeStr);
                }
            }
        }

        return result;
    }
};