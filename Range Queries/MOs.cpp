// MOs implementation for range query... 
// Time Complexity -> O( (N+Q)Fsqrt(N) ), 'F' is compexity of add and remove function


int b_size;

bool comp( pair< pair<int,int>, int> p1, pair< pair<int,int>, int> p2){
	if( p1.first.first/b_size != p2.first.first/b_size )
		return p1.first.first/b_size < p2.first.first/b_size;
	return ( ((p1.first.first/b_size)&1) ? p1.first.second>p2.first.second : p1.first.second<p2.first.second);
}

class MO{
	public:
		vector<int> cur_range; // define data structure acc to problem

		vector<int> inp;
		
		int cur_ans;
		MO(int n){
			inp.resize(n);
			b_size = sqrt(n);
			cur_ans = 0;
			cur_range.resize(1e6+10,0);
		}
		
		void add(int ind){
			cur_range[inp[ind]]++;
			if(cur_range[inp[ind]]==2)
				cur_ans--;
			else if(cur_range[inp[ind]]==1)
				cur_ans++;
		}

		void remove(int ind){
			cur_range[inp[ind]]--;
			if(cur_range[inp[ind]]==0)
				cur_ans--;
			else if(cur_range[inp[ind]]==1)
				cur_ans++;
		}

		vector<int> getresult(vector< pair< pair<int,int>, int > > &queries){

			int q = queries.size();
			sort(queries.begin(), queries.end(), comp);
			vector<int> res(q);
			int cur_l=0, cur_r=-1;
			for(int i=0;i<q;i++){
				int left = queries[i].first.first;
				int right = queries[i].first.second;
				// trace3(left,right,cur_ans);
				while(cur_l>left){
					cur_l--;
					add(cur_l);
				}
				while(cur_r<right){
					cur_r++;
					add(cur_r);
				}
				while(cur_l<left){
					remove(cur_l);
					cur_l++;
				}
				while(cur_r>right){
					remove(cur_r);
					cur_r--;
				}
				// trace1(cur_ans);
				res[queries[i].second] = cur_ans;
			}
			return res;
		}
};

// Source : https://cp-algorithms.com/data_structures/sqrt_decomposition.html
// Problems : https://www.hackerrank.com/contests/university-codesprint-4/challenges/unique-art

