#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int N, M;
int cnt = 0;
vector<int> v[101];
int visited[101] = { 0 };
stack<int> q;

int main(void) {

	cin >> N >> M;

	pair<int, int> edge;
	for (int i = 0; i < M; i++) {
		cin >> edge.first >> edge.second;
		v[edge.first].push_back(edge.second);
		v[edge.second].push_back(edge.first);
	}

	q.push(1);

	while (!q.empty()) {
		int cur = q.top();
		visited[cur] = 1;
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visited[next] == 0) {
				q.push(next);
				visited[next] = 1;
				cnt++;
			}
		}

	}

	cout << cnt;

	return 0;
}