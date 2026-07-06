class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        vector<vector<int>>bucket(nums.size()+1);
        for (auto i : nums){
            um[i]++;
        }
        for (auto p : um){
            bucket[p.second].push_back(p.first);
        }

        vector<int> res;
        for (int i = bucket.size() - 1; i >= 0 && res.size() < k; --i) {
            for (auto num : bucket[i]) {
                res.push_back(num);

                if (res.size() == k) {
                    break;
                }
            }
        }

        return res;
    }
};
