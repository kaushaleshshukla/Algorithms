// Manacher's algorithm for finding all palindromic substring in O(n)

// odd length palindromes
vector<int> oddPal(string s){
    int n = s.size();
    vector<int> len(n);
    for(int i=0, l=0,r=-1; i<n; i++){
        int k = (i>r)?1:min(len[l+r-i], r-i+1);
        while(i-k>=0 && i+k<n && s[i-k]==s[i+k])
            k++;
        len[i] = k--;
        if(i+k>r){
            r = i+k;
            l = i-k;
        }
    }
    return len;
}

// even length palindromes
vector<int> evenPal(string s){
    int n = s.size();
    vector<int> len(n);
    for(int i=0, l=0, r=-1;i<n;i++){
        int k = (i>r)?0:min(len[l+r-i+1], r-i+1);
        while(i-k-1>=0 && i+k<n && s[i-k-1]==s[i+k])
            k++;
        len[i] = k--;
        if(i+k>r){
            r = i+k;
            l = i-k-1;
        }
    }
    return len;
}


// Source : https://cp-algorithms.com/string/manacher.html
