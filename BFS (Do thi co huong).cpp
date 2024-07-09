#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

/*
	n = 10, m = 11
	1 2
	1 3
	1 10
	2 4
	3 5
	3 6
	5 8
	5 10
	8 9
	6 7	
	7 3
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
	//visit = false
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
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

int main(){
	input();
	int x;
	cout << "Nhap dinh muon tim kiem: "; cin >> x;
	bfs(x);
	return 0;
}
