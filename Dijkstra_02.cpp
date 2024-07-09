//Tim duong di ngan nhat giua 2 dinh (co trong so - weight)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
	8 9
	6 8 1
	1 2 7
	1 3 12
	2 3 2
	2 4 9
	3 5 10
	4 6 1
	5 4 4
	5 6 5
*/

const int INF = 1e9;
int n, m, first, last;
vector<pair<int, int>> adj[1001];
int pre[1001];
bool mark[1001];

void dijkstra(int first, int last){
    vector<long long> d(n + 1, INF);
    vector<bool> mark(n + 1, false);
    d[first] = 0;
    for(int i = 1; i <= n; i++){
        int u = -1;
        for(int j = 1; j <= n; j++){
        	// Neu dinh j chua duoc tham
            if(!mark[j] && (u == -1 || d[j] < d[u])){
                u = j;
            }
        }
        if(d[u] == INF) break; 
        mark[u] = true;
        for(auto x : adj[u]){
            int v = x.first;
            int w = x.second;
            if(!mark[v] && d[v] > d[u] + w){
                d[v] = d[u] + w;
                pre[v] = u;
            }
        }
    }
    cout << "\nTrong so: " << d[last] << endl;
    vector<int> path;
    while(1){
    	path.push_back(last);
    	if(last == first) break;
    	last = pre[last];
	}
	reverse(path.begin(), path.end());
	cout << "Duong di: ";
	for(int x : path){
		cout << x << " ";
	}
}

int main(){
    cout << "Nhap so dinh: "; cin >> n;
    cout << "Nhap so canh: "; cin >> m;
    cout << "Nhap dinh dau: "; cin >> first;
	cout << "Nhap dinh cuoi: "; cin >> last;
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
    dijkstra(first, last);
    return 0;
}

