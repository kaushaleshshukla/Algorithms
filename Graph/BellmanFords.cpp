// Bellman Ford's implementation

struct edge{
    int u,v,cost;
};

vector<edge> edges;
vector<int> dist;
int n,m;

void BellmanFords(int source){
    dist.clear();
    dist.resize(n+1,INF);
    dist[source] = 0;
    while(true){      
        bool update = false;
        for(auto e:edges){
            if(dist[e.u]<INF){
                if(dist[e.v]>dist[e.u]+e.cost){
                    dist[e.v] = dist[e.u] + e.cost;
                    update = true;
                }
            }
        }
        if(!update)
            break;
    }
}


// Bellman Fords with path

struct edge{
    int u,v,cost;
};

vector<edge> edges;
vector<int> dist;
vector<int> par;
int n,m;

void BellmanFords(int source){
    dist.clear();
    dist.resize(n+1,INF);
    par.clear();
    par.resize(n+1,-1);
    dist[source] = 0;
    while(true){      
        bool update = false;
        for(auto e:edges){
            if(dist[e.u]<INF){
                if(dist[e.v]>dist[e.u]+e.cost){
                    dist[e.v] = dist[e.u] + e.cost;
                    par[e.v] = e.u;
                    update = true;
                }
            }
        }
        if(!update)
            break;
    }
}

// Finding negative cycle 

struct edge{
    int u,v,cost;
};

vector<edge> edges;
vector<int> dist;
vector<int> par;
int n,m;

vector<int> BellmanFords(int source){
    dist.clear();
    dist.resize(n+1,INF);
    par.clear();
    par.resize(n+1,-1);
    dist[source] = 0;
    int update;
    for(int i=0;i<n;i++){      
        update = -1;
        for(auto e:edges){
            if(dist[e.u]<INF){
                if(dist[e.v]>dist[e.u]+e.cost){
                    dist[e.v] = max(-INF, dist[e.u] + e.cost);
                    par[e.v] = e.u;
                    update = e.v;
                }
            }
        }
        if(update==-1)
            break;
    }
    vector<int> cycle;
    if(update==-1)
        return cycle;

    int y = update;
    trace1(update);
    for(int i=0;i<n;i++)
        y = par[y];
    int cur = y;
    while(true){
        cycle.push_back(cur);
        if(cur==y && cycle.size()>1)
            return cycle;
         cur = par[cur];
    }
}

