#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

/*
	Greedy
	오른쪽 위, 오른쪽, 오른쪽 아래 순서로 가능한지 판단
*/

bool visited[10005][505];
char pipe[10005][505];
int dr[3] = { -1, 0, 1 };
int dc[3] = { 1, 1, 1 };
int R, C, ans = 0;

bool dfs(int r, int c)
{
	visited[r][c] = true;

	if (c == C - 1) {
		ans++;
		return true;
	}

	for (int i = 0; i < 3; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr >= 0 && nr < R && nc >= 0 && nc < C && !visited[nr][nc] && pipe[nr][nc] == '.') {
			if (dfs(nr, nc))
				return true;
		}
	}

	return false;
}

int main()
{
	memset(visited, false, sizeof(visited));

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> pipe[i][j];
		}
	}

	for (int start = 0; start < R; start++) {
		dfs(start, 0);
	}

	cout << ans;
}
