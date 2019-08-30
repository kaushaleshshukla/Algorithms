// Segment Tree template

template<typename T, typename U>
class SegmentTree{
    public:
        vector<T> seg;
        vector<U> inp;  // Initialize this 'inp' vector in main function
        SegmentTree(int n){
            seg.resize(4*n);
            v.resize(n+1);
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
