class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!= t.size()) return false;

        unordered_map<char,int> count;
        for(auto c:s){
            count[c]++;
        }
        for(auto c:t){
            if(--count[c] <0) return false;
        }
        return true;
    }
};