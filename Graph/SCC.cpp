// Strongly connected component in directed graph

vector< vector<int> > adj, radj; 
vector< bool > vis;
vector< int > order, component;

void dfs(int node){
    vis[node] = true;
    for(int x: adj[node])
        if(!vis[x])
            dfs(x);
    order.push_back(node);
}

void dfs2(int node){
    vis[node] = true;
    component.push_back(node);
    for(int x:radj[node])
        if(!vis[x])
            dfs2(x);
}
int main()
{
    optimizeIO();
    int tt=1;
    //cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        adj.resize(n);
        radj.resize(n);
        vis.resize(n, false);
        while(m--){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            radj[y].push_back(x);
        }
        for(int i=0;i<n;i++)
            if(!vis[i])
                dfs(i);
        vis.assign(n,false);

        for(int i=n-1;i>=0;i--){
            if(!vis[order[i]]){
                dfs2(order[i]);
                // process component
                component.clear();
            }
        }
    }
    return 0;
}


// Source : https://cp-algorithms.com/graph/strongly-connected-components.html
// Problem : https://www.codechef.com/AUG16/problems/CHEFRRUN
// Solution : https://www.codechef.com/viewsolution/26469703
