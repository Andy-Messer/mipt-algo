// __  __            _                           
//|  \/  | __ ___  _(_)_ __ ___  _   _ _ __ ___  
//| |\/| |/ _` \ \/ / | '_ ` _ \| | | | '_ ` _ \ 
//| |  | | (_| |>  <| | | | | | | |_| | | | | | |
//|_|  |_|\__,_/_/\_\_|_| |_| |_|\__,_|_| |_| |_|
//                                               
//  ____                                  
// / ___|__ _ _ __ _ __   __ _  __ _  ___ 
//| |   / _` | '__| '_ \ / _` |/ _` |/ _ \
//| |__| (_| | |  | | | | (_| | (_| |  __/
// \____\__,_|_|  |_| |_|\__,_|\__, |\___|
//                             |___/      
// __  __            _                           
//|  \/  | __ ___  _(_)_ __ ___  _   _ _ __ ___  
//| |\/| |/ _` \ \/ / | '_ ` _ \| | | | '_ ` _ \ 
//| |  | | (_| |>  <| | | | | | | |_| | | | | | |
//|_|  |_|\__,_/_/\_\_|_| |_| |_|\__,_|_| |_| |_|
//                                               
//  ____                           _              
// / ___| ___  ___  _ __ ___   ___| |_ _ __ _   _ 
//| |  _ / _ \/ _ \| '_ ` _ \ / _ \ __| '__| | | |
//| |_| |  __/ (_) | | | | | |  __/ |_| |  | |_| |
// \____|\___|\___/|_| |_| |_|\___|\__|_|   \__, |
//                                          |___/ 
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
const long double eps = 0.00000000001;
namespace Geometry {

    struct Point {
        long double x, y;
        int ind = -1;
        Point(long double x = 0, long double y = 0) : x(x), y(y) {}
        Point operator +(const Point& p) { return Point(x + p.x, y + p.y); }
        Point operator -(const Point& p) { return Point(x - p.x, y - p.y); }
        Point operator -(void) { return Point(-x, -y); }
        friend std::ostream& operator<<(std::ostream& out, const Point& value) {
            out << value.x << ' ' << value.y << ' ' << value.ind;
            return out;
        }
    };

    struct Vector {
        long double x, y;

        Vector(Point a, Point b) : x((b - a).x), y((b - a).y) {}
        long double length() {
            return sqrt(x * x + y * y);
        }

        Vector operator +(const Vector& v) {
            return Vector(Point(), Point(v.x + x, v.y + y));
        }

        long double operator *(const Vector& v) {
            return (long double)(v.x * x + v.y * y);
        }

        static long double pseudovector(const Vector& v1, const Vector& v2) {
            return (long double)(v2.y * v1.x - v2.x * v1.y);
        }

        friend std::ostream& operator<<(std::ostream& out, const Vector& value) {
            out << value.x << ' ' << value.y;
            return out;
        }
    };



    struct Segment {
        Point first_point, second_point;
        Segment() { static int ind_g = 0; ++ind_g; first_point.ind = ind_g; second_point.ind = ind_g; }
        Segment(Point first_point, Point second_point) : first_point(first_point), second_point(second_point) {}
    };

    struct Line {
        long double A, B, C;
        long double calculate_y(long double x) { return (A * x + C) / (-B); }
        long double calculate_x(long double y) { return (B * y + C) / (-A); }
        Line(long double A, long double B, long double C) : A(A), B(B), C(C) {}
        Vector get_vector() const { return Vector(Point(0, 0), Point(-B, A)); }
        long double get_distance(Point p) const {
            if (A == 0)
                return abs(-C / B - p.y);
            else if (B == 0)
                return abs(-C / A - p.x);
            else
                return abs(A * p.x + B * p.y + C) / sqrt(A * A + B * B);
        }
        long double get_rdistance(Point p) const {
            if (A == 0)
                return (-C / B - p.y);
            else if (B == 0)
                return (-C / A - p.x);
            else
                return (A * p.x + B * p.y + C) / sqrt(A * A + B * B);
        }
        Point get_intersection(Line l) const {
            return Point(
                -((C * l.B - l.C * B) / (A * l.B - l.A * B)),
                -((A * l.C - l.A * C) / (A * l.B - l.A * B))
            );
        }
    };

    bool comp_x(Point p1, Point p2) {
        return p1.x < p2.x;
    }

    bool comp_y(Point p1, Point p2) {
        return p1.y < p2.y;
    }

    bool is_intersected_x(Segment s1, Segment s2) {
        std::vector<Point> points;
        points.push_back(s1.first_point);
        points.push_back(s1.second_point);
        points.push_back(s2.first_point);
        points.push_back(s2.second_point);
        std::sort(points.begin(), points.end(), comp_x);
        if (points[0].ind == points[1].ind)
            return 0;
        return 1;
    }

    bool is_intersected_y(Segment s1, Segment s2) {
        std::vector<Point> points;
        points.push_back(s1.first_point);
        points.push_back(s1.second_point);
        points.push_back(s2.first_point);
        points.push_back(s2.second_point);
        std::sort(points.begin(), points.end(), comp_y);
        if (points[0].ind == points[1].ind)
            return 0;
        return 1;
    }

    bool is_intersected_segments(Segment s1, Segment s2) {
        if (is_intersected_y(s1, s2) && is_intersected_x(s1, s2)) {
            Vector v1(s2.first_point, s2.second_point);
            Vector v2(s1.first_point, s1.second_point);
            Line l1(-v1.y, v1.x, 0);
            Line l2(-v2.y, v2.x, 0);
            std::cout << l1.get_rdistance(s1.first_point) << ' ' << l1.get_rdistance(s1.second_point) << std::endl;
            std::cout << l2.get_rdistance(s2.first_point) << ' ' << l2.get_rdistance(s2.second_point) << std::endl;
            if ((l1.get_rdistance(s1.first_point) > 0 && l1.get_rdistance(s1.second_point) > 0) ||
                (l1.get_rdistance(s1.first_point) < 0 && l1.get_rdistance(s1.second_point) < 0)) {
                return 0;
            }
            else {
                if ((l2.get_rdistance(s2.first_point) > 0 && l2.get_rdistance(s2.second_point) > 0) ||
                    (l2.get_rdistance(s2.first_point) < 0 && l2.get_rdistance(s2.second_point) < 0)) {
                    return 0;
                }
                else
                    return 1;
            }
        }
        return 0;
    }
};

using namespace Geometry;

template <typename T>
bool compare_sign(T a, T b) {
    if (a == 0 && b == 0) return 1;
    else if (a == 0 || b == 0) return true;
    return a / abs(a) == b / abs(b);
}

int find_sign(std::vector<Point>& points) {
    for (int i = 0; i < points.size() - 2; ++i){
        Vector AB(points[i], points[i + 1]);
        Vector BC(points[i + 1], points[i + 2]);
        if (AB.x * BC.y - AB.y * BC.x < 0) return -1;
        if (AB.x * BC.y - AB.y * BC.x > 0) return 1;
    }
    return 0;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Point> points;

    Point a;
    for (int i = 0; i < n; ++i) {
        std::cin >> a.x >> a.y;
        points.push_back(a);
    }
    points.push_back(points[0]);
    points.push_back(points[1]);
    long double sign = find_sign(points);
    for (int i = 0; i < n; ++i) {
        Vector AB(points[i], points[i + 1]);
        Vector BC(points[i + 1], points[i + 2]);
        if (!compare_sign(AB.x * BC.y - AB.y * BC.x, sign)) {
            std::cout << "NO";
            return 0;
        }
    }
    std::cout << "YES";
    return 0;
}