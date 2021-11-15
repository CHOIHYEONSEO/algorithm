#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#define MAXN 10000

using namespace std;
vector<int> v[500];
stack<pair<int, int>> s;
int N, M;
int number = 0;
int direction[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };



int search() {

	int max_area = 0;
	int area = 0;

	for(int c = 0; c<N; c++) 	// column
		for (int r = 0; r < M; r++) { 		//row
			if (v[c][r] == 1) {
				number++;
				area = 1;
				s.push(make_pair(c, r));
				v[c][r] = -1;
			}

			while (!s.empty()) {
				pair<int, int> cur = s.top();
				s.pop();

				pair<int, int> next;
				for (int i = 0; i < 4; i++) {
					next = make_pair(cur.first + direction[i][0], cur.second + direction[i][1]);
					if ((next.first >= 0 && next.first < N) && (next.second >= 0 && next.second < M) && v[next.first][next.second] == 1) {
						s.push(next);
						v[next.first][next.second] = -1;
						area++;
					}

				}
			}

			if (area > max_area)
				max_area = area;
		}

	return max_area;

}





int main(void) {
	int val;
	cin >> N >> M;

	for(int i =0; i<N; i++)
		for (int j = 0; j < M; j++) {
			cin >> val;
			v[i].push_back(val);
		}

	int max = search();

	std::cout << number << '\n' << max << endl;

	return 0;
}
