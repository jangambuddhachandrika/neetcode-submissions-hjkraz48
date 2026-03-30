class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>freq;
        for(auto i: nums)
        {
            if(freq.count(i))
            {
                return true;
            }
            freq.insert(i);
        }
        return false;

    }
};
