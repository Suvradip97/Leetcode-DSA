


// 547. Number of Provinces



class Solution {
private:
    void dfs(int start, vector<vector<int>>& isConnected,
             unordered_set<int>& visited) {
        visited.insert(start);
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[start][i] and visited.find(i) == visited.end()) {
                dfs(i, isConnected, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        unordered_set<int> visited;
        for (int i = 0; i < isConnected.size(); i++) {
            if (visited.find(i) == visited.end()) {
                dfs(i, isConnected, visited);
                provinces++;
            }
        }
        return provinces;
    }
};