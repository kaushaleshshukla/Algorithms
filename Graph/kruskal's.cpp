// Kruskal's algorithm for finding minimum spanning tree

class DSU{
    public:
        int comp;
        vector< int > par, sz;
        DSU(int n){
            par.resize(n);
            sz.resize(n);
            for(int i=0;i<n;i++){
                par[i] = i;
                sz[i] = 1;
            }
            comp = n;
        }
        int getpar(int node){
            if(par[node]==node)
                return node;
            return par[node] = getpar(par[node]);
        }
        bool merge(int u,int v){
            int p1 = getpar(u), p2 = getpar(v);
            if(p1==p2)
                return false;
            comp--;
            if(sz[p1]>sz[p2]){
                par[p2] = p1;
                sz[p1] += sz[p2];
            }
            else{
                par[p1] = p2;
                sz[p2] += sz[p1];
            }
            return true;
        }
        int getcomp(){
            return comp;
        }
        int getsize(int node){
            return sz[node];
        }
};

struct edge{
    int w,u,v;
};
vector< edge > edges;
int n; // number of nodes

bool comp(edge x, edge y){
    return x.w<y.w;
}

int kruskal(){
    sort(edges.begin(), edges.end(), comp);
    int res = 0;
    DSU o(n+1);
    for(auto x: edges){
        if(o.merge(x.u,x.v))
            res += x.w;
    }
    return res;
}


// Source : https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html
