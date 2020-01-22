// QuickSort implementation
int partition(int left, int right, vector<int> &v){
	int start = left+1;
	int key = v[left];
	for(int i=left+1; i<=right; i++){
		if(v[i]<key){
			swap(v[i], v[start]);
			start++;
		}
	}
	swap(v[start-1], v[left]);
	return start-1;
}
void quicksort(int left, int right, vector<int> &v){
	if(right>left){
		int piv_pos = partition(left, right, v);
		quicksort(left, piv_pos-1, v);
		quicksort(piv_pos+1, right, v);
	}
}
