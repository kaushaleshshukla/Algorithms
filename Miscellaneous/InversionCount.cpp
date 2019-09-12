// Inversion count of given array

ll merge(vector<int> &a, int start, int end){
    int mid = (start+end)/2;
    vector<int> sorted(end-start+1);
    ll i=start, j=mid+1, inversion=0,ind=0;
    while(i<=mid && j<=end){
        if(a[i]<=a[j])
            sorted[ind++] = a[i++];
        else{
            inversion += (ll)mid-i+1;
            sorted[ind++] = a[j++];
        }
    }
    while(i<=mid)
        sorted[ind++] = a[i++];
    while(j<=end)
        sorted[ind++] = a[j++];
    for(int i=start;i<=end;i++)
        a[i] = sorted[i-start];
    return inversion;
}

ll merge_sort(vector<int> &a, int start, int end){
    if(start>=end)
        return 0;
    ll inversion = 0,mid = (start+end)/2;
    inversion += merge_sort(a,start,mid);
    inversion += merge_sort(a,mid+1, end);
    inversion += merge(a,start, end);
    return inversion;
}

// Problem : https://www.codechef.com/LTIME73A/problems/DPERM
// Solution : https://www.codechef.com/viewsolution/26504945
