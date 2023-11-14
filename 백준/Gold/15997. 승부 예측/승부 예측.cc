#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct match
{
	int team1;
	int team2;
	double prob[3];
};


string teams[4];
match matches[6];
int point_table[4];
double probs[4];


int get_team_idx(string name)
{
	for (int i = 0; i < 4; i++) {
		if (teams[i] == name) {
			return i;
		}
	}
}

void select_advanced_teams(double p)
{
	vector <pair<int, int>> v;
	for (int i = 0; i < 4; i++) {
		v.push_back({ point_table[i], i });
	}
	sort(v.begin(), v.end(), greater<pair<int, int>>());

	if (v[1].first == v[2].first) {
		//4 teams point same
		if (v[0].first == v[3].first) {
			probs[v[0].second] += p / 2;
			probs[v[1].second] += p / 2;
			probs[v[2].second] += p / 2;
			probs[v[3].second] += p / 2;
		}
		//2md, 3rd, 4th same
		else if (v[1].first == v[3].first) {
			probs[v[0].second] += p;
			probs[v[1].second] += p / 3;
			probs[v[2].second] += p / 3;
			probs[v[3].second] += p / 3;
		}
		//1st, 2nd, 3rd same 
		else if (v[0].first == v[2].first) {
			probs[v[0].second] += p / 3 * 2;
			probs[v[1].second] += p / 3 * 2;
			probs[v[2].second] += p / 3 * 2;
		}
		//2nd, 3rd same
		else {
			probs[v[0].second] += p;
			probs[v[1].second] += p * 0.5;
			probs[v[2].second] += p * 0.5;
		}
	}
	else {
		probs[v[0].second] += p;
		probs[v[1].second] += p;
	}
}

void proceed_match(int match_num, int wdl, double p)
{
	int t1 = matches[match_num].team1;
	int t2 = matches[match_num].team2;
	int t1_point, t2_point;

	p *= matches[match_num].prob[wdl];

	//team1 win
	if (wdl == 0) {
		t1_point = 3;
		t2_point = 0;
	}
	//draw
	else if (wdl == 1) {
		t1_point = 1;
		t2_point = 1;
	}
	//team2 win
	else if (wdl == 2) {
		t1_point = 0;
		t2_point = 3;
	}

	// reflect points
	point_table[t1] += t1_point;
	point_table[t2] += t2_point;

	if (match_num == 5) {
		select_advanced_teams(p);
	}
	else {
		for (int i = 0; i < 3; i++) {
			proceed_match(match_num + 1, i, p);
		}
	}

	//restore points for next case
	point_table[t1] -= t1_point;
	point_table[t2] -= t2_point;
}

int main() 
{
	//input
	for (int i = 0; i < 4; i++) {
		cin >> teams[i];
	}
	for (int i = 0; i < 6; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		matches[i].team1 = get_team_idx(s1);
		matches[i].team2 = get_team_idx(s2);
		cin >> matches[i].prob[0] >> matches[i].prob[1] >> matches[i].prob[2];
	}

	//solution
	for (int i = 0; i < 3; i++) {
		proceed_match(0, i, 1);
	}
	
	//print result
	for (int i = 0; i < 4; i++) {
		cout << probs[i] << "\n";
	}
}