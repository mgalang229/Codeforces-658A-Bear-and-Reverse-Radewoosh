#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, c;
	cin >> n >> c;
	vector<int> p(n), t(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	// create a 'limak_score' variable to store the total score of Limak
	int limak_score = 0;
	// create a 'current_time' variable to store the current time of the contest
	int current_time = 0;
	// for Limak, start the iteration in left to right manner
	for (int i = 0; i < n; i++) {
		// update the current time of the contest
		current_time += t[i];
		// calculate the maximum points available using the formula given in the problem statement
		// which is: max(0, p[i] - c * x), where:
		// p[i] = the initial number of points of the current problem
		// c = constant provided
		// x = current time of the contest
		limak_score += max(0, p[i] - c * current_time);
	}
	// reset the 'current_time' variable to 0
	current_time = 0;
	// use the same logic to calculate the score of Radewoosh but this time 
	// start from right to left (opposite of what Limak did)
	int radewoosh_score = 0;
	for (int i = n - 1; i >= 0; i--) {
		current_time += t[i];
		radewoosh_score += max(0, p[i] - c * current_time);
	}
	// finally, check whethere which one of them wins or if they a tie (possibly)
	if (limak_score == radewoosh_score) {
		cout << "Tie";
	} else if (limak_score > radewoosh_score) {
		cout << "Limak";
	} else {
		cout << "Radewoosh";
	}
	cout << '\n';
	return 0;
}
