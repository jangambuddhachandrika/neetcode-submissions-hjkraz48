class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>freq;
        vector<int>res;
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]] = i;
        }
        int start = 0;
        int end = 0;
        for(int i=0;i<s.size();i++)
        {
            end = max(end,freq[s[i]]);
            if(end==i)
            {
                res.push_back(end-start+1);
                start = i+1;
            }
        }
        return res;
        
    }
};
