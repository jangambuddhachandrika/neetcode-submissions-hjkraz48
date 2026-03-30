class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> result;
        
        // queue stores: {current combination, current sum, start index}
        queue<tuple<vector<int>, int, int>> q;
        
        q.push({{}, 0, 0});
        
        while(!q.empty()) {
            
            auto [comb, sum, start] = q.front();
            q.pop();
            
            if(sum == target) {
                result.push_back(comb);
                continue;
            }
            
            for(int i = start; i < candidates.size(); i++) {
                
                int newSum = sum + candidates[i];
                
                if(newSum > target) continue;
                
                vector<int> newComb = comb;
                newComb.push_back(candidates[i]);
                
                // push back to queue
                q.push({newComb, newSum, i}); // i (not i+1) because reuse allowed
            }
        }
        
        return result;
    }
};

