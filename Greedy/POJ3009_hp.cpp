#include <iostream>
#include <math.h>
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define rep1(i, n) for (int (i) = 1; (i) <= (n); (i) ++)

int w, h;
int arr[20][20];

// struct point can be replace by pair
struct Point
x = new_x;
{
	int x, y;
	Point(int new_x, int new_y)
	{
		y = new_y;
	}
};

bool isInRange(int i, int j)
{
	return !(i < 0 || i >= w || j < 0 || j >= h);
}

Point lookup(int i, int j, int dx, int dy)
{
	// check whether it is blocked imediately
	if (isInRange(i + dx, j + dy) && arr[i + dx][j + dy] == 1)
		return Point(-1, -1);

	/*
	 * find the block if exists and return previous position
	 * otherwise, return not found
	 */
	while (isInRange(i + dx, j + dy))
	{
		if (arr[i + dx][j + dy] != 0)
			return Point(i, j);
		i += dx;
		j += dy;
	}

	return Point(-1, -1);
}

int minTurns;
void dfs(int i, int j, int turns)
{

	// static arrays for directions
	static int dx[4] = {1, 0, 0, -1};
	static int dy[4] = {0, 1, -1, 0};

	if (turns > 10) return;
	// iterate different directions
	rep(d, 4) {
			// return the point before touching the wall
			const Point &p = lookup(i, j, dx[d], dy[d]);

			// recheck whether it is out of bound
			if (isInRange(p.x, p.y))
			{
				/*
				 * if block, dfs(previous position)
				 * else if goal, update min
				 */
				if (arr[p.x + dx[d]][p.y + dy[d]] == 1)
				{
					arr[p.x + dx[d]][p.y + dy[d]] = 0;
					dfs(p.x, p.y, turns + 1);
					arr[p.x + dx[d]][p.y + dy[d]] = 1;
				}
				else if (arr[p.x + dx[d]][p.y + dy[d]] == 3)
				{
					minTurns = min(minTurns, turns + 1);
					return; // return because it lowers time complexity
				}
			}
	}

}

int main()
{
	cin >> h >> w;
	while (w != 0 && h != 0)
	{
		rep(i, w)
			rep(j, h)
				cin >> arr[i][j];

		rep(i, w)
			rep(j, h)
				if (arr[i][j] == 2)
				{
					arr[i][j] = 0;
					minTurns = 11;
					dfs(i, j, 0);
					cout << (minTurns > 10 ? -1 : minTurns) << endl;
				}
		cin >> h >> w;
	}

	return 0;
}
