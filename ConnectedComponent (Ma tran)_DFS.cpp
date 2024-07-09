// Dung DFS
#include<iostream>
#include<string.h>
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

void dfs(int i, int j){
	a[i][j] = 'o';
	for(int k = 0; k < 4; k++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == 'x'){
			dfs(i1, j1);
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
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << "So thanh phan lien thong: " << cnt;
	return 0;
}
