class Solution {
public:
    int getLucky(string s, int k) {
        string temp="";
        for(auto &t:s){
            int a=t-'a'+1;
            temp+=to_string(a);
        }
        while(k--){
            int sum=0;
            for(auto &t:temp){
                sum+=(t-'0');
            }
            temp=to_string(sum);
        }
        return stoi(temp);
    }
};