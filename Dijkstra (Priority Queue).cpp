#include<iostream>
#include<vector>
#include<queue>
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
int n, m, first;
vector<pair<int, int>> adj[1001];
int pre[1001];
bool mark[1001];


void dijkstra(int first){
	vector<long long> d(n + 1, INF);
	d[first] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, first});
	while(!q.empty()){
		int u = q.top().second;
		int du = q.top().first;
		q.pop();
		if(du != d[u]){
			continue;
		}
		for(auto x : adj[u]){
			int v = x.first;
			int w = x.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				pre[v] = u;
				q.push({d[v], v});
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(d[i] != INF){
			cout << d[i] << " ";
		}
		else cout << -1 << " ";
	}
}

int main(){
	cout << "Nhap so dinh: "; cin >> n;
	cout << "Nhap so canh: "; cin >> m;
	cout << "Nhap dinh bat dau: "; cin >> first;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({y, w});
	}
	dijkstra(first);
	return 0;
}
