#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

/*
	n = 9, m = 10
	1 2
	1 3
	1 5
	2 4
	3 6
	6 7
	3 7
	5 8
	8 9
	9 3
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
	}
	memset(visited, false, sizeof(visited));
}

void dfs(int u){
	cout << u << " ";
	// Danh dau u da duoc tham
	visited[u] = true;
	for(int v : adj[u]){
		//Neu dinh v chua duoc tham
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

