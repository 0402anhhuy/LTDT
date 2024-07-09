// Tim duong di ngan nhat (khong co trong so)
#include<bits/stdc++.h>
using namespace std;

/*
	n = 10, m = 11
	1 2
	1 3
	1 5
	1 10
	2 4
	3 6
	6 7
	3 7
	3 9
	5 8
	8 9
*/

int n, m, x;
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

void bfs(int u){
	// Khoi tao
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front();   // Lay dinh o dau hang doi
		q.pop();
		cout << v << " ";
		for(int x : adj[v]){
			// Xet cac dinh x ke voi v, neu dinh u chua duoc tham
			if(!visited[x]){
				q.push(x);
				visited[x] = true; // Danh dau da tham roi
			}
		}
	}
}

int main(){
	system("cls");
	input();
	cout << "Nhap dinh muon tim kiem: "; cin >> x;
	bfs(x);
	return 0;
}
