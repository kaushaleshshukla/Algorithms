// Prims for finding minimum spanning tree

vector< vector< pair<int,int> > > adj;
vector< bool > marked;

int prims(int start = 1){
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
    q.push(make_pair(0,start));
    int res = 0;
    while(q.size()){
        auto cur = q.top();
        q.pop();
        if(marked[cur.second])
            continue;
        marked[cur.second] = true;
        res += cur.first;
        for(auto x: adj[cur.second]){
            if(!marked[x.first])
                q.push(make_pair(x.second, x.first));
        }
    }
    return res;
}

// Source: https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
