class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int>& visited, vector<int>& comp) {
        visited[node] = 1;
        comp.push_back(node);
        
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited, comp);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
        vector<int> visited(V, 0);
        vector<vector<int>> result;
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                vector<int> comp;
                dfs(i, adj, visited, comp);
                result.push_back(comp);
            }
        }
        return result;
    }
};
