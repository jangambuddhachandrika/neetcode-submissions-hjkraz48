class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi = INT_MIN;
        int left = 0;
        int right = heights.size()-1;
        while(left<right)
        {
            int area = (right-left)*min(heights[left],heights[right]);
            maxi = max(maxi,area);
            if(heights[left]>heights[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return maxi;
        
    }
};
