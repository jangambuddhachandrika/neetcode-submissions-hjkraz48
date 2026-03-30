class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        for(int i=0;i<nums.size()-k+1;i++)
        {
            int maxi = INT_MIN;
            for(int j=i;j<i+k;j++)
            {
                maxi = max(maxi,nums[j]);
            }
            res.push_back(maxi);
        }
        return res;
        
    }
};
