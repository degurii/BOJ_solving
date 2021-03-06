/*
입력
The input consists of several data sets. Each set begins with a line containing the number n of stacks Bob has built.
The next line contains n numbers, the heights hi of the n stacks. You may assume 1 ≤ n ≤ 50 and 1 ≤ hi ≤ 100.
The total number of bricks will be divisible by the number of stacks.
Thus, it is always possible to rearrange the bricks such that all stacks have the same height.

The input is terminated by a set starting with n 0. This set should not be processed.

출력
For each set, first print the number of the set, as shown in the sample output.
Then print the line “The minimum number of moves is k.”,
where k is the minimum number of bricks that have to be moved in order to make all the stacks the same height.

Output a blank line after each set.
*/
#include <iostream>
using namespace std;

int n, p[51];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int test = 1; cin >> n, n; test++) {
		int h = 0;
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			h += p[i];
		}
		h /= n;
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += p[i] < h ? 0 : p[i] - h;
		cout << "Set #" << test << '\n';
		cout << "The minimum number of moves is " << ans << ".\n\n";
	}
}