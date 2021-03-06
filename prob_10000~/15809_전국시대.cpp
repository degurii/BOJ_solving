/*
문제
전국시대엔 N개의 국가가 존재한다. 각 국가는 1부터 N까지의 번호를 가지고 있다.
또한, 모든 국가는 각자 자신의 국가의 힘을 상징하는 병력을 가지고 있다. 이때 M개의 기록이 주어진다. 각각의 기록은 다음과 같다.
동맹 - 두 나라가 서로 동맹을 맺는다. 두 나라의 병력이 하나로 합쳐진다.
전쟁 - 두 나라가 서로 전쟁을 벌인다. 병력이 더 많은 나라가 승리하며 패배한 나라는 속국이 된다. 이때 남은 병력은 승리한 나라의 병력에서 패배한 나라의 병력을 뺀 수치가 된다. 두 나라의 병력이 같을 경우 두 나라 모두 멸망한다.
모든 나라는 정직하기 때문에 내 동맹의 동맹도 나의 동맹이고, 내 동맹이 적과 전쟁을 시작하면 같이 참전한다. 속국인 경우도 동맹의 경우와 마찬가지이다.
따라서, 전쟁에서 진 국가와 동맹인 다른 국가 또한 전쟁에서 이긴 국가의 속국이 된다.
모든 기록이 끝났을 때 남아있는 국가의 수를 출력하고, 그 국가들의 남은 병력의 수를 오름차순으로 출력하는 프로그램을 작성하시오.
단, 여러 국가가 서로 동맹이거나 속국 관계인 경우는 한 국가로 취급한다.

입력
첫 번째 줄에 국가의 수를 나타내는 N과 기록의 수 M이 주어진다. (1 ≤ N, M ≤ 100,000)
두 번째 줄 부터 N개의 줄에 걸쳐 i번째 국가의 병력 Ai (1 ≤ i ≤ N)가 자연수로 주어진다. (1 ≤ Ai ≤ 10,000)
다음 M개의 줄에는 기록이 3개의 정수 O, P, Q로 주어진다.
O가 1인 경우 P, Q가 서로 동맹을 맺었음을 의미하고,
O가 2인 경우 P, Q가 서로 전쟁을 벌였음을 의미한다.
동맹끼리 다시 동맹을 맺거나 전쟁하는 입력은 주어지지 않는다.

출력
첫째 줄에 남아있는 국가의 수를 출력한다.
다음 줄에 각 국가의 남은 병력의 수를 띄어쓰기를 간격으로 오름차순으로 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int cost[100001], par[100001];
int find(int now) {
	if (par[now] == now) return now;
	return par[now] = find(par[now]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (cost[u] >= cost[v]) {
		cost[u] += cost[v];
		cost[v] = 0;
		par[v] = u;
	}
	else {
		cost[v] += cost[u];
		cost[u] = 0;
		par[u] = v;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		cin >> cost[i];
		par[i] = i;
	}
	while (m--) {
		int o, p, q;
		cin >> o >> p >> q;
		if (o == 1) {
			merge(p, q);
		}
		else {
			p = find(p);
			q = find(q);
			if (cost[p] > cost[q]) {
				cost[p] -= cost[q];
				cost[q] = 0;
				merge(p, q);
			}
			else if (cost[p] < cost[q]) {
				cost[q] -= cost[p];
				cost[p] = 0;
				merge(p, q);
			}
			else {
				cost[p] = cost[q] = 0;
			}
		}
	}
	vector<int> ans;
	for (int i = 1; i < n + 1; i++) {
		if (cost[i])ans.push_back(cost[i]);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i : ans) cout << i << ' ';
	
}