class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        auto it = um.begin();
        for (auto s : strs){
            vector<int> count(26, 0);
            string key = "";
            for (auto ch : s){
                count[ch - 'a']++;
            }
            for (int x : count){
                key += "#" + to_string(x);
            }
            um[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto par : um){
            res.push_back(par.second);
        }
        return res;
    }
};
