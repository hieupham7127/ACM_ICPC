#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define rep1(i, n) for (int (i) = 1; (i) <= (n); (i) ++)

struct Point {
	double x, y;
	Point(){}
	Point(double new_x, double new_y) {
		x = new_x;
		y = new_y;
	}
	
	bool operator< (const Point p) const {
		return x < p.x;
	}
};


int main() {
	Point p[1000];
	int t = 0, n, res;
	double x, y, d;
	bool isFar;
	
	cin >> n >> d;
	while (n != 0) {
		t++;
		isFar = false;
		
		// inputing
		rep(i, n) {
			cin >> x >> y;
			// convert from point to interval on x-axis
			if (abs(y) <= d) {
				p[i].x = x - sqrt(d*d - y*y);
				p[i].y = x + sqrt(d*d - y*y);
			}
			// point is further than d
			else isFar = true;			
		}
		
		if (!isFar) {
			// sort by starting points in ascending order
		    sort(p, p + n);
			
		    res = 1;
		    d = p[0].y;
			rep1(i, n - 1)
				// if current.finish < selected, replace selected
				if (p[i].y < d) {
					d = p[i].y;
				} else if (p[i].x > d) {
					// if current.start > selected, add new selected. increases result
					res++;
					d = p[i].y;
				}
		}
		// point is too far, res = -1
		else res = -1;
		
		cout << "Case " << t << ": " << res << endl;
		cin >> n >> d;
	}
	return 0;
}
