class Solution {
private:
    bool isValid(const std::string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

public:
    std::vector<std::string> removeInvalidParentheses(std::string s) {
        std::vector<std::string> result;
        if (s.empty()) return {""};

        std::unordered_set<std::string> visited;
        std::queue<std::string> q;

        q.push(s);
        visited.insert(s);
        bool found = false;

        while (!q.empty()) {
            int levelSize = q.size();
            std::unordered_set<std::string> levelResults;

            for (int i = 0; i < levelSize; ++i) {
                std::string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    levelResults.insert(curr);
                    found = true;
                }

                if (found) continue; // If we found valid strings at this level, don't generate deeper levels

                // Generate next states by removing one parenthesis at a time
                for (int j = 0; j < curr.length(); ++j) {
                    if (curr[j] != '(' && curr[j] != ')') continue;

                    std::string next = curr.substr(0, j) + curr.substr(j + 1);
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            if (found) {
                result.assign(levelResults.begin(), levelResults.end());
                break;
            }
        }

        return result;
    }
};