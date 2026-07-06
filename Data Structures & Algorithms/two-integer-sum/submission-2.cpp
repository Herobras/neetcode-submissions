class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;
        int y;
        for (int i = 0; i<nums.size();++i){
            y = target - nums[i];
            auto it = um.find(y);
            if (it!=um.end()){
                return {it->second,i};                
            }
            else{
            um.insert({nums[i],i});
            }        
        }
        return {0,0};
    }
};
