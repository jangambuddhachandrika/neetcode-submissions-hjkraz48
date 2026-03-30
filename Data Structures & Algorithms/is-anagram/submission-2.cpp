class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>freqs;
        unordered_map<char,int>freqt;
        for(auto i:s)
        {
            freqs[i]++;
        }
         for(auto i:t)
        {
            freqt[i]++;
        }
        return freqs==freqt;
        
    }
};
