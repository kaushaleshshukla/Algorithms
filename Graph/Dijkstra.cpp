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


