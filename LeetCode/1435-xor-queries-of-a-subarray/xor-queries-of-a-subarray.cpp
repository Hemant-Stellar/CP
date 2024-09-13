class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> preXor(arr.size());
        int a = 0;
        for(int i = 0;i<arr.size();i++){
            a^=arr[i];
            preXor[i]= a;
        }
        for(auto &q : queries){
            int left = q[0];
            int right = q[1];
            if(left==0){
                ans.push_back(preXor[right]);
                continue;
            }
            ans.push_back(preXor[left-1]^preXor[right]); 
        }
        return ans;    
        }
};