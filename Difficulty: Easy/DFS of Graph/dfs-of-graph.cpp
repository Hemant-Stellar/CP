//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    vector<int> ans;
    void dfs(map<int,vector<int>> &mp,vector<bool> &visited,int s){
        visited[s]= true;
        ans.push_back(s);
        for(auto &d: mp[s]){
            if(!visited[d]){
                dfs(mp,visited,d);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        if(v==0) return {};
        map<int,vector<int>> mp;
        vector<bool> visited(v,false);
        for (int i =0 ; i<v ; i++){
            for(auto &d : adj[i]){
                mp[i].push_back(d);
                mp[d].push_back(i);
            }
        }
        
        dfs(mp,visited,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends