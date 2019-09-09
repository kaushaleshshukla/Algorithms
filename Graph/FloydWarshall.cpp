// Floyd-Warshall algorithm for all pair shortest path

vector< vector<int> > dist;
int n;
void floyd(){
    for(int k=0;k<n;k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][k]!=INF && dist[k][j]!=INF)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}

// Source : https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html
// Problem : https://codeforces.com/problemset/problem/295/B
// Solution : https://codeforces.com/contest/295/submission/60305624
