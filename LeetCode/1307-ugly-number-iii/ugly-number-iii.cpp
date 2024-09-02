class Solution {
public:
    long long gcd(long long a,long long b){
        return b==0?a:gcd(b,a%b);
    }
    long long lcm(long long a,long long b){
        return a*b/gcd(a,b);
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long long l=1,right=1e18;
        long long ab=lcm(a,b);
        long long bc=lcm(b,c);
        long long ac=lcm(a,c);
        long long abc=lcm(a,bc);
        while(l < right){
            long long mid=l+(right-l)/2;
            if(mid/a+mid/b+mid/c-mid/ab-mid/bc-mid/ac+mid/abc>=n){
                right=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};