/*
qeusiton :

There is a rectangular meadow in a forest, having been covered with a blanket of fresh snow in the
morning (left in the figure below).

Rabbits and foxes, who live in the forest, are crossing the meadow and leave their tracks in the snow.
They always enter in the upper left corner and leave the meadow from the lower right corner. In
between they can move back and forth, playing in the snow, even crossing their own tracks. At any
time there is at most one animal on the meadow. No animal enters the meadow more than once. The
movements of the animals can be described by dividing the meadow into quadratic cells. The animals
never move diagonally in a single step and they never jump over a cell. When an animal enters a cell
its tracks will cover all previous tracks left in this cell.

For example, first a rabbit crossed the meadow from top-left to bottom-right (middle in the figure).
After that, a fox crossed, and now his tracks are partially covering the rabbit’s (right in the figure).

........ RRR..... FFR.....
........ ..RRR... .FRRR...
........ ..R..... .FFFFF..
........ ..RRRR.R ..RRRFFR
........ .....RRR .....FFF
You are given a map of the meadow at some time after indicating for each cell if there are any visible
tracks and whether they were left by a rabbit or by a fox (right in the figure). You are interested in the
local wildlife population. Write a program to determine the minimal possible number N of animals
that must have crossed the meadow to leave the given pattern of tracks in the snow.
Input
The first line contains two integers H and W, the height and the width of the map of the meadow. H
lines follow with exactly W characters on each: the map, where ‘.’ marks untouched snow, ‘R’ a spot
where a rabbit’s track is the topmost one, and ‘F’ a spot where a fox’s track is the topmost one. There
is at least one track on the meadow.
Output
The output should consist of a single integer: the minimal number N ≥ 1 of animals that could have
left the tracks given in the input.
Constraints
1 ≤ H, W ≤ 4000
In test cases worth 30 points: N ≤ 200 and H, W ≤ 500



*/



#include <bits/stdc++.h>
using namespace std;

int dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};

int n, m, depth[4000][4000], ans = 1;
string snow[4000];

bool inside(int x, int y) {
	return (x > -1 && x < n && y > -1 && y < m && snow[x][y] != '.');
}

int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> snow[i];

	deque<pair<int, int>> q;
	q.push_back({0, 0});
	depth[0][0] = 1;

	while (q.size()) {
		pair<int, int> c = q.front();
		q.pop_front();
		ans = max(ans, depth[c.first][c.second]);

		for (int i = 0; i < 4; i++) {
			int x = c.first + dx[i], y = c.second + dy[i];
			if (inside(x, y) && depth[x][y] == 0) {
				if (snow[x][y] == snow[c.first][c.second]) {
					depth[x][y] = depth[c.first][c.second];
					q.push_front({x, y});
				} else {
					depth[x][y] = depth[c.first][c.second] + 1;
					q.push_back({x, y});
				}
			}
		}
	}

	cout << ans;
	return 0;
}