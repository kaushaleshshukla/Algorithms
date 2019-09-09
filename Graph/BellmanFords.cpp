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


