#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int entry[32005];

int main()
{
	int N, M;
	vector <int> pre[32005];
	priority_queue <int> pq;
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		pre[A].push_back(B);
		entry[B] += 1;
	}
	
	for (int i = 1; i <= N; i++) {
		if (entry[i] == 0) {
			pq.push(-i);
		}
	}
	
	while (!pq.empty()) {
		int problem = -pq.top();
		pq.pop();

		cout << problem << " ";
		for (auto e : pre[problem]) {
			entry[e] -= 1;
			if (entry[e] == 0) {
				pq.push(-e);
			}
		}
	}
}