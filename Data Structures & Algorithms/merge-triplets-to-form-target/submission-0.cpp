class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool foundx = false;
        bool foundy = false;
        bool foundz = false;
        for(auto i:triplets)
        {
            bool notvalid = false;
            for(int j=0;j<target.size();j++)
            {
                if(i[j]>target[j])
                {
                    notvalid = true;
                    break;
                }
            }
            if(!notvalid)
            {
             for(int j=0;j<target.size();j++)
            {
                if(i[j]==target[j])
                {
                   if(j==0)
                   {
                    foundx = true;
                   }
                   else if(j==1)
                   {
                    foundy = true;
                   }
                   else
                   {
                    foundz = true;
                   }
                }
            }

            }
        }
        return foundx && foundy && foundz;
        
    }
};
