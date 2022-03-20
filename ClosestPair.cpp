#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;

class Point {
    public:
    int x, y;

    Point(int a, int b) {
        x = a;
        y = b;
    }
};

bool sort_x(Point &a, Point &b) { return a.x < b.x; }
bool sort_y(Point &a, Point &b) { return a.y < b.y; }

double d(Point first, Point second) {
    return pow(pow(first.x - second.x, 2) + pow(first.y - second.y, 2), 0.5);
}

vector<Point> closestPairBase(vector<Point> points) {
    if (points.size() == 2) return points;
    double d01 = d(points[0], points[1]);
    double d02 = d(points[0], points[2]);
    double d12 = d(points[2], points[1]);

    double dmin = std::min(d01, d02, d12);
    if (d01 == dmin) return {points[0], points[1]};
    if (d02 == dmin) return {points[0], points[2]};
    if (d12 == dmin) return {points[1], points[2]};
}

vector<Point> closestPoint(const vector<Point> &Px, const vector<Point> &Py) {
    if (Px.size() <= 3) return closestPairBase(Px);

    vector<Point> Qx(Px.begin(), Px.begin() + Px.size()/2);
    vector<Point> Qy(Py.begin(), Py.begin() + Py.size()/2);
    vector<Point> Rx(Px.begin() + Px.size()/2, Px.end());
    vector<Point> Ry(Py.begin() + Py.size()/2, Py.end());

    vector<Point> left = closestPoint(Qx, Qy);
    vector<Point> right = closestPoint(Rx, Ry);

    double dl = d(left[0], left[1]);
    double dr = d(right[0], right[1]);
    double d = std::min(dl, dr);

    
}

int main(int argc, char const *argv[]) {

    vector<Point> points = {
        Point(1, 2),
        Point(2, 4),
        Point(1, 3),
        Point(2, 3),
        Point(3, 4),
    };

    vector<Point> Px = points;
    vector<Point> Py = points;

    std::sort(Px.begin(), Px.end(), sort_x);
    std::sort(Py.begin(), Py.end(), sort_y);

    vector<Point> closest = closestPoint(Px, Py);

    return 0;
}

