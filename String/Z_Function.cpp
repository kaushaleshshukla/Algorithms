// function to compute z-array

vector<int> Zfunction(string s){
	int n = s.size();
	vector<int> z(n,0);
	int l,r;
	l=r=-1;
	for(int i=1;i<n;i++){
		if(i>r){
			l = r = i;
			while(r<n && s[r]==s[r-i])
				r++;
			z[i] = r-l;
			r--;
		}
		else{
			int k = z[i-l];
			if(i+k<r)
				z[i] = k;
			else{
				l = i;
				while(r<n && s[r]==s[r-i])
					r++;
				z[i] = r-l;
				r--;
			}
		}
	}
	return z;
}
