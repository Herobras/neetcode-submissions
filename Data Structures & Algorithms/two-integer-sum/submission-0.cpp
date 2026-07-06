class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;
        int y;
        for (int i = 0; i<nums.size();++i){
            y = target - nums[i];
            if (um.find(y)!=um.end()){
                if (i<um[y]){
                    return {i,um[y]};
                }
                else {
                    return {um[y],i};
                }
            }
            else{
            um.insert({nums[i],i});
            }        
        }
        return {0,0};
    }
};
