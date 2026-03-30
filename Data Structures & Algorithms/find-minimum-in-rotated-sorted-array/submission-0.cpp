class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
      
        while(left<right)
        {
            if (nums[left]<nums[right])
            {
                return nums[left];
            }
            int mid = (left+right)/2;
            if (nums[0] <= nums[mid]) {
                left = mid + 1;
            } else { // Otherwise, it is to the left of mid
                right = mid;
            }
        }
        return nums[left];
        
    }
};
