#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N;
	int sum = 0;
	priority_queue <int> pq;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		pq.push(-x);
	}

	while (pq.size() > 1) {
		int a = -pq.top();
		pq.pop();
		int b = -pq.top();
		pq.pop();
		sum += (a + b);
		pq.push(-(a + b));
	}

	cout << sum;
}