// Sparce Table for immutable arrays

template<typename T>
class ST{
    public:
        vector< vector<T> > st;
        vector<T> inp;
        int n,k;
        ST(int sz){
            k = ceil(log2(sz));
            n = sz;
            st.resize(k+1, vector<T>(n));
            inp.resize(n);
        }
        T merge(T a, T b){
            // Edit here
            return a+b;
        }
        void build(){
            for(int i=0;i<n;i++)
                st[0][i] = inp[i];
            for(int j=1;j<=k;j++){
                for(int i=0;(i+(1<<j))<=n;i++){
                    st[j][i] = merge(st[j-1][i], st[j-1][i+(1<<(j-1))]);
               }
            }
        }
        T query(int l, int r){

            T res = 0; 
            for(int j=k;j>=0;j--){
                if((1<<j)<=r-l+1){
                    res = merge(res, st[j][l]);
                    l += (1<<j);
                }
            }

            /* for range min or max query (Idempotent function) */
            // int j = log2(r-l+1);
            // return merge(st[j][l], st[j][r-(1<<j)+1]);
           
            return res;
        }
};

// Source : https://cp-algorithms.com/data_structures/sparse-table.html
