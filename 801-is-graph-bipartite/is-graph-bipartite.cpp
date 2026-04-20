class Solution {
public:
    bool bfs(int i,vector<vector<int>>& graph,vector<int>& col){
        col[i]=0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &it:graph[node]){
                if(col[it]==-1){
                    col[it]=!col[node];
                    q.push(it);
                    }
                else if(col[it]==col[node])return true;
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,-1);
        for(int i =0;i<n;i++){
            if(col[i]==-1){
                if(bfs(i,graph,col)) return false;
                
            }
        }
        return true;
    }
};