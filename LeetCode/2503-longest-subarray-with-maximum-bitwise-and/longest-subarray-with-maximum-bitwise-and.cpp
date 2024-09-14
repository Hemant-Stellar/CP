class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max = -1;
        for(auto i : nums){
            if ((i)>max) max = i;
        }
        int maxLength =0,len=0;
        for(auto i : nums){
            if((i)==max){
                len++;
            }
            else{
                len=0;
            }
            if(len>maxLength) maxLength = len;
        }
        return maxLength;
    }
};