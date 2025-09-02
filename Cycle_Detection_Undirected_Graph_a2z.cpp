


class Solution {
    private:
    bool detect(int src, vector<int> adj[], int vis[]){
        vis[src] = 1;
        queue <pair<int, int>> q;
        q.push ({src, -1});
        while (!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto adjacentNode : adj[node]){
                if (!vis[adjacentNode]){
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                else if (parent != adjacentNode){
                    return true;
                }
            }
        }
        return false;
    }
    public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int visited[V] = {0};
        for(int i = 0; i < V ; i++){
            if(!visited[i]){
                if(detect(i, adj, visited)) return true;
            }
        }
        return false;;
    }
};