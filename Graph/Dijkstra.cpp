// Dijkstra implementation
// Time complexity -> O( mlog(n) )

vector<int> dist;
vector< vector< pair<int,int> > > adj;

void dijkstra(int source){
    int n = adj.size();
    dist.clear();
    dist.resize(n,INF);
    priority_queue< pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > > q;
    dist[source] = 0;
    q.push(make_pair(dist[source], source));
    while(q.size()){
        auto cur = q.top();
        q.pop();
        if(dist[cur.second]!=cur.first)
            continue;
        for(auto x: adj[cur.second]){
            if(dist[x.first] > dist[cur.second] + x.second){
                dist[x.first] = dist[cur.second] + x.second;
                q.push(make_pair(dist[x.first], x.first));
            }
        }
    }
}

// Dijkstra with path

vector<int> dist,path;
vector< vector< pair<int,int> > > adj;

void dijkstra(int source){
    priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > > q;
    q.push({0,source});
    dist[source]=0;
    path[source]=-1;
    while(!q.empty()){
        auto cur = q.top();
        q.pop();
        if(cur.first!=dist[cur.second])
            continue;
        for(auto next : adj[cur.second]){
            if(dist[next.first] > cur.first + next.second){
                dist[next.first] = cur.first + next.second;
                path[next.first] = cur.second;
                q.push(make_pair(dist[next.first], next.first));
            }
        }
    }
}
