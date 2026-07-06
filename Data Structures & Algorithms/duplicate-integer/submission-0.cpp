class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for (auto i = nums.begin(); i != nums.end();++i){
            for (auto j = i+1; j != nums.end(); ++j){
                if (*i == *j){
                    return true;
                }
            }
        }
        return false;
    }
};