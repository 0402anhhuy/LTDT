#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

/*
	n = 9, m = 9
	1 2
	1 3
	1 5
	2 4
	3 6
	3 7
	3 9
	5 8
	8 9
*/

int n, m;
vector<int> adj[1001];
bool visited[1001];

void input(){
	cout << "Nhap so dinh: "; cin >> n;
	cout << "Nhap so canh: "; cin >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void dfs(int u){
	cout << u << " ";
	// Danh dau u da duoc tham
	visited[u] = true;
	for(int v : adj[u]){
		// Xet cac dinh v ke voi u, neu dinh v chua duoc tham
		if(!visited[v]){
			dfs(v);
		}
	}
}

int main(){
	input();
	int x;
	cout << "Nhap dinh muon tim kiem: "; cin >> x; 
	dfs(x);
	return 0;
}
