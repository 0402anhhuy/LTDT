#include<iostream>
using namespace std;

/*
	6 6
	Aooxoo
	oxoooo
	oxoooo
	ooooxx
	Boooxo
	oooxxx
	
	6 6
	Aooxoo
	oxoooo
	oxoooo
	xoooxx
	Bxooxo
	oxoxxx
*/

int n, m, x1, y1, x2, y2;
char a[1001][1001];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool dfs(int i, int j){
	if(a[i][j] == 'B') return true;
	a[i][j] = 'x';
	for(int k = 0; k < 4; k++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != 'x'){
			if(dfs(i1, j1)) return true;
		}
	}
	return false;
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			if(a[i][j] == 'A'){
				x1 = i;
				y1 = j;
			}
			else if(a[i][j] == 'B'){
				x2 = i;
				y2 = j;
			}
		}
	}
	if(dfs(x1, y1)) cout << "Co duong di";
	else cout << "Khong co duong di";
	return 0;
}
