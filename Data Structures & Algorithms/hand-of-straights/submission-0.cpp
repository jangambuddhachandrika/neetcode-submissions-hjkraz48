class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)
        {
            return false;
        }
        map<int,int>freq;
        for(auto i:hand)
        {
            freq[i]++;
        }
        while(!freq.empty())
        {
            int start = freq.begin()->first;
            for(int i=0;i<groupSize;i++)
            {
                int num = start+i;
                if(freq.find(num)==freq.end())
                {
                    return false;
                }
                freq[num]--;
                if(freq[num]==0)
                {
                    freq.erase(num);
                }
            }
        }
        return true;

        
    }
};
