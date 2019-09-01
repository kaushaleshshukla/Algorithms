// Sqrt Decompostion for range sum query


vector<int> blocks;
int b_size;


void build(vector<int> &inp){
	int n = inp.size();
	b_size = (int)sqrt(n)+1;
	blocks.resize(b_size);
	for(int i=0;i<n;i++){
		blocks[i/b_size] += inp[i];
	}
}

int query(int l, int r, vector<int> &inp){
	int res = 0;
	for(int i=l;i<=r;){
		if(i%b_size==0 && i+b_size-1<=r){
			res += blocks[i/b_size];
			i+=b_size;
		}
		else{
			res += inp[i];
			i++;
		}
	}
	return res;
}


// Source : https://cp-algorithms.com/data_structures/sqrt_decomposition.html

