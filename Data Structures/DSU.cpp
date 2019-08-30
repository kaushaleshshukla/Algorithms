// DSU template with path compression


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
        void merge(int u,int v){
            int p1 = getpar(u), p2 = getpar(v);
            if(p1==p2)
                return;
            comp--;
            if(sz[p1]>sz[p2]){
                par[p2] = p1;
                sz[p1] += sz[p2];
            }
            else{
                par[p1] = p2;
                sz[p2] += sz[p1];
            }
        }
        int getcomp(){
            return comp;
        }
        int getsize(int node){
            return sz[node];
        }
};
