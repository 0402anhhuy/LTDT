// Dung BFS
#include<iostream>
#include<queue>
using namespace std;

/*
	6 6
	xxxooo
	ooxooo
	oxxxxo
	ooooox
	xxoxox
	xoxxox
*/

int n, m;
char a[1001][1001];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void bfs(int i, int j){
	queue<pair<int, int>> q;
	q.push({i, j});
	a[i][j] = 'o';
	while(!q.empty()){
		pair<int, int> top = q.front();
		q.pop();
		for(int k = 0; k < n; k++){
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == 'x'){
				q.push({i1, j1});
				a[i1][j1] = 'o';
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == 'x'){
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << "So thanh phan lien thong: " << cnt;
	return 0;
}
