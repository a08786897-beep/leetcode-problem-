class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubles=s+s;

        string modified=doubles.substr(1,doubles.length()-2);

        return modified.find(s)!=string::npos;
    }
};