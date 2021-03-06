#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

struct Query {
	int s, e, idx;
	Query(int s, int e, int idx) :s(s), e(e), idx(idx) {}
};

int n, m, p[100001], cnt[100001], ans[100001], an;
vector<Query> query;

void add(int num) {
	if (++cnt[num] == 1)
		an++;
}

void erase(int num) {
	if (--cnt[num] == 0)
		an--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> p[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		query.emplace_back(a, b, i);
	}
	int nsqrt = sqrt(n);
	sort(query.begin(), query.end(), [&](const Query &a, const Query &b) {
		int aidx = a.e / nsqrt;
		int bidx = b.e / nsqrt;
		return (aidx == bidx) ? a.s < b.s : aidx < bidx;
	});
	
	int s = 0, e = 0;
	add(p[0]);
	for (auto cur : query) {
		int ns = cur.s, ne = cur.e;
		for (int i = s; i < ns; i++)
			erase(p[i]);
		for (int i = s - 1; i >= ns; i--)
			add(p[i]);
		for (int i = e + 1; i <= ne; i++)
			add(p[i]);
		for (int i = e; i > ne; i--) {
			erase(p[i]);
		}
		s = ns;
		e = ne;
		ans[cur.idx] = an;
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << '\n';
	}
	
}