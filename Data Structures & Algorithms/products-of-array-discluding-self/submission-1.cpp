class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        vector<int> res_left(nums.size(), 1);
        vector<int> res_right(nums.size(), 1);
        int prod = 1;

        for (int i = 1; i < nums.size(); ++i) {
            prod = nums[i-1];
            res_left[i] = res_left[i-1]*prod;
        }

         for (int i =  nums.size()-2; i >= 0; --i) {
            prod = nums[i+1];
            res_right[i] = res_right[i+1]*prod;
        } 

        for ( int i = 0  ; i < nums.size() ; ++i){
            res[i] = res_left[i]*res_right[i];
        }

        return res;
    }
};
