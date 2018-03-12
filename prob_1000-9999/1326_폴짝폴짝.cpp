/*
문제
개구리가 일렬로 놓여 있는 징검다리 사이를 폴짝폴짝 뛰어다니고 있다.
징검다리에는 숫자가 각각 쓰여 있는데,
이 개구리는 매우 특이한 개구리여서 어떤 징검다리에서 점프를 할 때는 그 징검다리에 쓰여 있는 수의 배수만큼 떨어져 있는 곳으로만 갈 수 있다.

이 개구리는 a번째 징검다리에서 b번째 징검다리까지 가려고 한다.
이 개구리가 a번째 징검다리에서 시작하여 최소 몇 번 점프를 하여 b번째 징검다리까지 갈 수 있는지를 알아보는 프로그램을 작성하시오.

입력
첫째 줄에 징검다리의 개수 N(1≤N≤10,000)이 주어지고, 이어서 각 징검다리에 쓰여 있는 N개의 정수가 주어진다.
그 다음 줄에는 N보다 작거나 같은 자연수 a, b가 주어지는 데, 이는 개구리가 a번 징검다리에서 시작하여 b번 징검다리에 가고 싶다는 뜻이다.
징검다리에 쓰여있는 정수는 10,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 개구리가 a번 징검다리에서 b번 징검다리로 최소 몇 번 점프하여 갈 수 있는 지를 출력하시오.
a에서 b로 갈 수 없는 경우에는 -1을 출력한다.
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, p[10001], dist[10001];
bool check[10001];
int a, b;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> p[i];
	}
	memset(dist, -1, sizeof(dist));
	cin >> a >> b;
	dist[a] = 0;
	check[a] = true;
	queue<int> q;
	q.push(a);
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == b)
			break;
		for (int next = now + p[now]; next <= n; next += p[now]) {
			if (!check[next]) {
				check[next] = true;
				q.push(next); 
				dist[next] = dist[now] + 1;
			}
		}

		for (int next = now - p[now]; next > 0; next -= p[now]) {
			if (!check[next]) {
				check[next] = true;
				q.push(next);
				dist[next] = dist[now] + 1;
			}
		}
	}
	cout << dist[b];
}