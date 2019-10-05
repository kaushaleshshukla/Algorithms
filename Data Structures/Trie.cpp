// Trie implementation

 
struct node{
    int cnt;
    node *child[2];
};
 
node *getnode(){
    node *new_node = new node;
    new_node->cnt = 0;
    new_node->child[0] = new_node->child[1] = NULL;
    return new_node;
}
 
node* start = getnode();
 
void insert(int n){
    node *iter = start;
    for(int i=30; i>=0; i--){
        int curbit = n&(1<<i)?1:0;
        if(!iter->child[curbit])
            iter->child[curbit] = getnode();
        iter = iter->child[curbit];
        iter->cnt++;
    }
} 
 
bool erase(int n){
    node *iter = start;
    for(int i=30;i>=0; i--){
        int curbit = n&(1<<i)?1:0;
        if(!iter->child[curbit])
            return false;
        iter = iter->child[curbit];
        iter->cnt--;
    }
    return true;
}
 
int maxXor(int n){
    node *iter = start;
    int res = 0;
    for(int i=30;i>=0;i--){
        int curbit = n&(1<<i)?1:0;
        if(iter->child[curbit^1] && iter->child[curbit^1]->cnt>0){
            res = res|(1<<i);
            iter = iter->child[curbit^1];
        }
        else
            iter = iter->child[curbit];
    }
    return res;
}

int minXor(int n){
    node *iter = start;
    int res = 0;
    for(int i=30;i>=0;i--){
        int curbit = n&(1<<i)?1:0;
        if(iter->child[curbit] && iter->child[curbit]->cnt>0)
            iter = iter->child[curbit];
        else{
            iter = iter->child[curbit^1];
            res = res|(1<<i);
        }
    }
    return res;
}
 
 // Source : https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/
 
 // Problem : http://codeforces.com/contest/706/problem/D
 // Solution : https://codeforces.com/contest/706/submission/61841997
 
 // Problem : http://codeforces.com/problemset/problem/948/D
 // Solution : https://codeforces.com/contest/948/submission/61858634
 
 
