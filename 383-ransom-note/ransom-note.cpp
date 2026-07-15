class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=ransomNote.size();
        int m=magazine.size();
        unordered_map<char,int> map;
        for(int i=0;i<m;i++){
            map[magazine[i]]++;
        }
        for(int i=0;i<n;i++){
            if(map[ransomNote[i]]>0){
                map[ransomNote[i]]--;
            }else{
                return false;
            }
        }
        return true;
    }
};