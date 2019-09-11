// Topological sort O(v+e)

int n; // number of nodes
vector< set<int> > adj;
vector<bool> vis;
vector<int> topological;

void dfs(int node){
    vis[node] = true;
    for(int x: adj[node]){
        x = -x;
        if(!vis[x])
            dfs(x);
    }
    topological.push_back(node);
}

void topologicalSort(){
    vis.clear();
    vis.resize(n+1,false);
    for(int i=n;i>0;i--)
        if(!vis[i])
            dfs(i);
    reverse(topological.begin(), topological.end());
}


/*---------------------------------------------------------------------------------------------------------------------------------------
 Another O(v+e) approach for topological sort (Kahn's Algorithm) */
 
 
int n; // number of nodes
vector< vector<int> > adj; // adjency list
vector<int> indegree;
vector< pair<int,int> > topological; // pair< level, index > 


void topologicalSort(){
    topological.clear();
    queue< pair<int,int> > q;
    rep(i,0,n)
        if(!indegree[i])
            q.push(make_pair(i,1)); // index, level
    while(q.size()){
        auto cur = q.front();
        q.pop();
        topological.push_back(make_pair(cur.second, cur.first)); // level, index
        for(int x:adj[cur.first]){
            indegree[x]--;
            if(indegree[x]==0)
                q.push(make_pair(x, cur.second+1));
        }
    }
}

