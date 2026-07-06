class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }

        unordered_map<char, int> chars_s;
        unordered_map<char, int> chars_t;

        for (auto c : s){
            chars_s[c]++;
        }
        for (auto c : t){
            chars_t[c]++;
        }
        for (auto [key,value] : chars_s){
            if (chars_t[key] == value){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
