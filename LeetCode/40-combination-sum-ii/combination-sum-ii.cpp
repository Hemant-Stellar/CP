class Solution {
private:
vector<vector<int>> ans;
void solve(int i,int sum,vector<int>& candidates,vector<int> curr,int& target){
    if(sum==target){
        ans.push_back(curr); 
        return;
        }
    if(i>=candidates.size() || sum+candidates[i]>target) return;
    curr.push_back(candidates[i]);
    solve(i+1,sum+candidates[i],candidates,curr,target);
    curr.pop_back();
    while((i+1)<candidates.size()&&candidates[i]==candidates[i+1]) i++;
    solve(i+1,sum,candidates,curr,target);

  }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        solve(0,0,candidates,curr,target);
        return ans;
    }
};