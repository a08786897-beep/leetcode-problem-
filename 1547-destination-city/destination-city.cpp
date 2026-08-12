class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> start_cities;

        for( auto& path: paths){
            start_cities.insert(path[0]);
        }

        for( auto& path: paths){
            if(start_cities.find(path[1])==start_cities.end()){
                return path[1];
            }
        }
        return "";
    }
};