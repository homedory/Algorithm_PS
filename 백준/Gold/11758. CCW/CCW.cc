#include <iostream>
using namespace std;

int main()
{
	int x1, x2, x3, y1, y2, y3;

	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	if (x1 == x3) {
		if (y1 > y3) {
			if (x2 > x1) {
				cout << -1;
			}
			else if (x2 < x1) {
				cout << 1;
			}
			else {
				cout << 0;
			}
		}
		else {
			if (x2 > x1) {
				cout << 1;
			}
			else if (x2 < x1) {
				cout << -1;
			}
			else {
				cout << 0;
			}
		}
	}
	else if (x1 > x3) {
		if ((y1 - y3) * (x2 - x3) + y3 * (x1 - x3) > y2 * (x1 - x3)) {
			cout << -1;
		}
		else if ((y1 - y3) * (x2 - x3) + y3 * (x1 - x3) < y2 * (x1 - x3)) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	else {
		if ((y1 - y3) * (x2 - x3) + y3 * (x1 - x3) > y2 * (x1 - x3)) {
			cout << -1;
		}
		else if ((y1 - y3) * (x2 - x3) + y3 * (x1 - x3) < y2 * (x1 - x3)) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
}