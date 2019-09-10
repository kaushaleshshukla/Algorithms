// Articulation point in O(n+m)

int n; // number of nodes
vector< vector<int> > adj; // adjency list
vector<int> tin,low;
vector<bool> vis;
int timer;

void isArticulation(int node){
    cout<<node<<" is articulation point"<<endl;
}

void dfs(int v, int par=-1){
    vis[v] = true;
    tin[v] = low[v] = timer++;
    int child = 0;
    for(int to:adj[v]){
        if(to==par)
            continue;
        if(vis[to])
            low[v] = min(low[v], tin[to]);
        else{
            dfs(to,v);
            low[v] = min(low[to], low[v]);
            if(low[to]>=tin[v] && par!=-1)
                isArticulation(v);
            child++;
        }
    }
    if(child>1 && par==-1)
        isArticulation(v);
}

void articulationPoint(){
    timer = 0;
    vis.resize(n+1, false);
    tin.resize(n+1);
    low.resize(n+1);
    for(int i=0;i<n;i++)
        if(!vis[i])
            dfs(i);
}

// Source : https://cp-algorithms.com/graph/cutpoints.html
