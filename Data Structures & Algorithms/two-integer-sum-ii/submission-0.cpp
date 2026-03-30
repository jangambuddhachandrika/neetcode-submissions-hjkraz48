class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>freq;
        for(int i=0;i<numbers.size();i++)
        {
            if(freq.find(target-numbers[i])!=freq.end())
            {
                return {freq[target-numbers[i]]+1,i+1};
            }
            else
            {
                freq[numbers[i]]=i;
            }
        }
        return {};
        
    }
};
