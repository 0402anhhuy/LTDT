#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

/*
	n = 10, m = 8
	1 2	
	2 3
	2 4
	3 6					
	6 7			
	3 7					
	5 8				
	8 9	
				
	n = 10, m = 10
	1 2							
	2 3
	2 4
	3 6
	3 7
	3 8
	6 7
	5 8
	5 10
	8 9				
*/

int n, m;
vector<int> adj[1001];
bool visited[1001];

void dfs(int u){
	cout << u << " ";
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

void ConnectedComponent(){
	int ans = 0;
	for(int i = 1; i <= n; i++){
		// Kiem tra xet cac dinh da duoc tham chua
		if(!visited[i]){
			++ans;
			cout << "Thanh phan lien thong cua dinh thu " << ans << ": ";
			dfs(i);
			cout << "\n";
		}
	}
	cout << "So thanh phan lien thong: " << ans << endl;
	if(ans == 1){
		cout << "Do thi lien thong\n";
	}
	else cout << "Do thi khong lien thong\n";
}

int main(){
	cout << "Nhap so dinh: "; cin >> n;
	cout << "Nhap so canh: "; cin >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
	ConnectedComponent();
	return 0;
}
