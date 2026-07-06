class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s_nums(nums.begin(), nums.end());
        if (nums.size()==s_nums.size()){
            return false;
        }
        else{
            return true;
        }
    }
};