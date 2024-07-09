#include<bits/stdc++.h>
using namespace std;

/*
	n = 10, m = 8
	1 2
	2 3
	2 4
	3 6
	3 7
	6 7
	5 8
	8 9
*/

int n, m, first, last;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void dfs(int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			parent[v] = u; // Ghi nhan cha cua v
			dfs(v);
		}
	}
}

// Neu khong co trong so thi BFS la tim duong di ngan nhat
void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int x : adj[v]){
			if(!visited[x]){
				q.push(x);
				parent[x] = v;
				visited[x] = true;
			}
		}
	}
}

void Path(int first, int last){
	memset(parent, 0, sizeof(parent));
	memset(visited, false, sizeof(visited));
	int select;
	cout << "Nhap lua chon: "; cin >> select;
	if(select == 1){
		dfs(first);
	}
	else bfs(first);
	if(!visited[last]){
		cout << "Khong co duong di toi dinh " << last;
	}
	else{
		vector<int> path;
		// Truy vet
		while(last != first){
			path.push_back(last);
			last = parent[last];
		}
		path.push_back(first);
		reverse(path.begin(), path.end());
		for(int x : path){
			cout << x << " ";
		}
	}
}

int main(){
	system("cls");
	cout << "Nhap so dinh: "; cin >> n;
	cout << "Nhap so canh: "; cin >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout << "Nhap dinh dau: "; cin >> first;
	cout << "Nhap dinh cuoi: "; cin >> last;
	Path(first, last);
	return 0;
}
