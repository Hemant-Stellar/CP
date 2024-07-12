//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++
#include <vector>
#include <random>
using namespace std;

#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsetSum(vector<int> arr, int sum) {
        int N = arr.size();
        // Create a 2D DP array
        vector<vector<bool>> dp(N + 1, vector<bool>(sum + 1, false));

        // If sum is 0, then answer is true (empty subset)
        for (int i = 0; i <= N; i++) {
            dp[i][0] = true;
        }

        // Fill the DP table
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        // The answer will be in dp[N][sum]
        return dp[N][sum];
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends