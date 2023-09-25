#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int K, V, E;

	cin >> K;
	while (K--) {
		vector <int> edge[20005];
		bool ans = true;

		cin >> V >> E;

		for (int i = 0; i < E; i++) {
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);	
		}

		
		int arr[20005], visit[20005];

		//initialize
		for (int i = 0; i < 20005; i++) {
			arr[i] = -1;
		}

		//using bfs
		for (int i = 1; i <= V; i++) {
			queue <int> q;

			if (!ans) {
				break;
			}

			if (arr[i] < 0) {
				q.push(i);
				arr[i] = 0;

				while (!q.empty() && ans) {
					int now = q.front(), now_num = arr[now];
					q.pop();

					for (int i = 0; i < edge[now].size(); i++) {
						int next = edge[now][i];
						if (arr[next] < 0) {
							arr[next] = (now_num + 1) % 2;
							q.push(next);
						}
						else if (arr[next] == now_num) {
							ans = false;
							break;
						}
					}
				}
			}
		}


		if (ans) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}