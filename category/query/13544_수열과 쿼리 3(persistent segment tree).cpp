/*
문제
길이가 N인 수열 A1, A2, ..., AN이 주어진다. 이 때, 다음 쿼리를 수행하는 프로그램을 작성하시오.
i j k: Ai, Ai+1, ..., Aj로 이루어진 부분 수열 중에서 k보다 큰 원소의 개수를 출력한다.

입력
첫째 줄에 수열의 크기 N (1 ≤ N ≤ 100,000)이 주어진다.
둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 10^9)
셋째 줄에는 쿼리의 개수 M (1 ≤ M ≤ 100,000)이 주어진다.
넷째 줄부터 M개의 줄에는 a, b, c가 주어진다. a, b, c를 이용해 쿼리를 만들어야 한다.

i = a xor last_ans
j = b xor last_ans
k = c xor last_ans
last_ans는 이전 쿼리의 정답이며, 가장 처음에는 0이다. xor한 결과는 1 ≤ i ≤ j ≤ n, 1 ≤ k ≤ 10^9 을 만족한다.

출력
각각의 쿼리마다 정답을 한 줄에 하나씩 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int v = 0;
	Node *left = 0, *right = 0;
} *tree[100001];

Node* init(Node *prev, int s, int e, int v) {
	if (v < s || e < v) return prev;
	Node *now = new Node;
	if (s == e) {
		now->v = prev->v + 1;
		return now;
	}
	if (!prev->left) prev->left = new Node;
	if (!prev->right) prev->right = new Node;
	int m = (s + e) / 2;
	now->left = init(prev->left, s, m, v);
	now->right = init(prev->right, m + 1, e, v);
	now->v = now->left->v + now->right->v;

	return now;
}

int query(Node *now, int s, int e, int v) {
	if (e <= v || !now) return 0;
	if (v < s) return now->v;
	int m = (s + e) / 2;
	return query(now->left, s, m, v) + query(now->right, m + 1, e, v);
}
int last, n, m, x;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	tree[0] = new Node;
	for (int i = 1; i < n + 1; i++) {
		cin >> x;
		tree[i] = init(tree[i - 1], 1, 1e9, x);
	}
	cin >> m;
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		a ^= last;
		b ^= last;
		c ^= last;
		last = query(tree[b], 1, 1e9, c) - query(tree[a - 1], 1, 1e9, c);
		cout << last << '\n';
	}
}