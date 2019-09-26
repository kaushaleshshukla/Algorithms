// Function to compute prefix function of string

vector<int> compPref(string s){
	int n = s.size();
	vector<int> pi(n,0);
	int j;
	for(int i=1;i<n;i++){
		j = pi[i-1];
		while(j>0 && s[i]!=s[j])
			j = pi[j-1];
		if(s[i]==s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

