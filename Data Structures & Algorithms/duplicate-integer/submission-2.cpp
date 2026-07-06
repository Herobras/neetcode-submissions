class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> vistos;
        for (auto i : nums){
            auto it = vistos.find(i);
            if (it != vistos.end()){
                return true;
            }
            else {
                vistos.insert(i);
            }
        }
        return false;
    }
};