// Segment Tree template

template<typename T, typename U>
class SegmentTree{
    public:
        vector<T> seg;
        vector<U> inp;  // Initialize this 'inp' vector in main function
        SegmentTree(int n){
            seg.resize(4*n);
            inp.resize(n+1);
        }
        T merge(T data1, T data2){
            // Edit here
            
        }
        void build(int ind, int start, int end){
            if(start==end){
                // Edit here
                
            }
            else{
                int mid = (start+end)/2;
                build(2*ind, start, mid);
                build(2*ind+1, mid+1, end);
                seg[ind] = merge(seg[2*ind],seg[2*ind+1]);
            }
        }
        void update(int ind, int start, int end, int index, ll val){
            if(start==end){
                // Edit here
                
            }
            else{
                int mid = (start+end)/2;
                if(index<=mid)
                    update(2*ind, start, mid, index, val);
                else
                    update(2*ind+1, mid+1, end, index, val);
                seg[ind] = merge(seg[2*ind], seg[2*ind+1]);
            }
        }
        T query(int ind, int start, int end, int left, int right){
            if(left>right){
                // Edit here
                
            }
            if(start==left && end==right)
                return seg[ind];
            int mid = (start+end)/2;
            T q1 = query(2*ind, start, mid, left, min(mid, right));
            T q2 =  query(2*ind+1, mid+1, end, max(mid+1, left), right);
            return merge(q1,q2);
        }
};


//-------------------------------------------------------------------------------------------------------------//


// Segment Tree with lazy Update template 

template<typename T, typename U>
class SegmentTree{
    public:
        vector<T> seg,lazy;
        vector<U> inp;
        SegmentTree(int n){
            seg.resize(4*n);
            lazy.resize(4*n);
            inp.resize(n+1);
        }
        T merge(T &data1, T &data2){
            // Edit here
            return data1+data2;
        }
        void push(int ind,int start, int mid, int end){
            // Edit here
            lazy[2*ind] += lazy[ind];
            lazy[2*ind+1] += lazy[ind];
            seg[2*ind] += lazy[ind]*(ll)(mid-start+1);
            seg[2*ind+1] += lazy[ind]*(ll)(end-mid);
            lazy[ind] = 0;
        }
        void build(int ind, int start, int end){
            if(start==end){
                // Edit here
                seg[ind] = inp[start];
            }
            else{
                int mid = (start+end)/2;
                build(2*ind, start, mid);
                build(2*ind+1, mid+1, end);
                seg[ind] = merge(seg[2*ind], seg[2*ind+1]);
            }
        }
        void lazyUpdate(int ind, int start, int end, int left, int right, ll val){
            if(left>right){
                return ;
            }
            if(start==left && end==right){
                // Edit here
                seg[ind] += (ll)(right-left+1)*val;
                lazy[ind] += val;
            }
            else{
                int mid = (start+end)/2;
                push(ind,start,mid,end);
                lazyUpdate(2*ind, start, mid, left, min(mid,right), val);
                lazyUpdate(2*ind+1, mid+1, end, max(left,mid+1), right, val);
                seg[ind] = merge(seg[2*ind], seg[2*ind+1]);
            }
        }

        T query(int ind, int start, int end, int left, int right){
            if(left>right){
                // Edit here
                return 0;
            }
            if(start==left && end==right)
                return seg[ind];
            int mid = (start+end)/2;
            push(ind,start,mid, end);
            T data1 = query(2*ind, start, mid, left, min(mid, right));
            T data2 = query(2*ind+1, mid+1, end, max(left,mid+1), right);
            return merge(data1,data2);
        }
};

// Problem : https://codeforces.com/contest/1208/problem/D
// Solution : https://codeforces.com/contest/1208/submission/60055831
