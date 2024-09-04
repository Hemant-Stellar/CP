class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        if(n==1) return 10;
        if(n==2) return 91;
        int mul =9*9;
        int res=91;
        int s = 8;
        for(int i=2;i<n;i++){
            mul*=s;
            res+=mul;
            s--;
        }
        return res;
    }
};