// Lowest common ancestor using binary lifting


int n,l;
vector< vector<int> > adj;

int timer;
vector<int> tin;
vector<int> tout;
vector< vector<int> > up;

void dfs(int node, int par){
    tin[node] = timer++;
    up[node][0] = par;
    for(int i=1;i<=l;i++)
        up[node][i] = up[up[node][i-1]][i-1];
    for(int x:adj[node])
        if(x!=par)
            dfs(x,node);
    tout[node] = timer++;
}

bool isAncestor(int u, int v){
    return tin[u]<=tin[v] && tout[u]>=tout[v];
}

int lca(int u, int v){
    if(isAncestor(u,v))
        return u;
    if(isAncestor(v,u))
        return v;
    for(int i=l;i>=0;i--)
        if(!isAncestor(up[u][i],v))
            u = up[u][i];
    return up[u][0];
}

void preprocess(int root){
    tin.resize(n);
    tout.resize(n);
    timer =0;
    l = ceil(log2(n));
    up.resize(n, vector<int>(l+1));
    dfs(root,root);
}


