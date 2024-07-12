#include <iostream>
#include<vector>
using namespace std;

int count = 0,m,n;
const int MOD=1e9+7;



int solve(vector<vector<char>>& A,int i,int j,vector<vector<int>>& dp){

        if(i==n-1 && j==m-1) return 1;
        
        if(A[i][j] =='#') return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int ans =0;
        
        if((i)<n-1)  ans= solve(A,i+1,j,dp)%(MOD);
        
        if((j)<m-1)  ans+= solve(A,i,j+1,dp)%(MOD);

        return dp[i][j] = ans%(MOD);
}

int grid1(vector<vector<char>>& A){

    vector<vector<int>> dp(n,vector<int>(m,-1));
    return solve(A,0,0,dp);
}

int main(){
    cin>>n>>m;
    vector<vector<char>> A(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>A[i][j];
    }
    cout<<grid1(A);
    return 0;
}
