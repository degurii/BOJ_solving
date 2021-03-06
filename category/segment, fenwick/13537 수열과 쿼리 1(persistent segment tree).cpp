/*
문제
길이가 N인 수열 A1, A2, ..., AN이 주어진다. 이 때, 다음 쿼리를 수행하는 프로그램을 작성하시오.
i j k: Ai, Ai+1, ..., Aj로 이루어진 부분 수열 중에서 k보다 큰 원소의 개수를 출력한다.

입력
첫째 줄에 수열의 크기 N (1 ≤ N ≤ 100,000)이 주어진다.
둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 109)
셋째 줄에는 쿼리의 개수 M (1 ≤ M ≤ 100,000)이 주어진다.
넷째 줄부터 M개의 줄에는 쿼리 i, j, k가 한 줄에 하나씩 주어진다. (1 ≤ i ≤ j ≤ n, 1 ≤ k ≤ 109)

출력
각각의 쿼리마다 정답을 한 줄에 하나씩 출력한다.
*/



/*
solution:
persistent segment tree를 이용
*/
#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int val;
	Node *left, *right;
	Node() :val(0), left(0), right(0) {}
} *tree[100001];

Node* init(Node *now, int s, int e, int c) {
	if (c < s || e < c) return now;
	Node *ret = new Node();
	if (s == e) {
		ret->val = now->val + 1;
		return ret;
	}
	int m = (s + e) / 2;
	if (!now->left) now->left = new Node();
	if (!now->right) now->right = new Node();
	ret->left = init(now->left, s, m, c);
	ret->right = init(now->right, m + 1, e, c);
	ret->val = ret->left->val + ret->right->val;
	return ret;
}

int query(Node *now, int s, int e, int c) {
	if (e <= c || !now) return 0;
	if (c < s) return now->val;

	int m = (s + e) / 2;
	return query(now->left, s, m, c) + query(now->right, m + 1, e, c);
}
int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	tree[0] = new Node();
	for (int i = 1; i < n + 1; i++) {
		int x;
		cin >> x;
		tree[i] = init(tree[i - 1], 1, 1e9, x);
	}
	cin >> m;
	int i, j, k;
	while (m--) {
		cin >> i >> j >> k;
		cout << query(tree[j], 1, 1e9, k) - query(tree[i - 1], 1, 1e9, k) << '\n';
	}
}