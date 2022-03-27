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
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#define IOS std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
const long long eps = 0.00000000001;

namespace Geometry
{

    struct Point
    {
        long long x, y;

        int ind = -1;

        Point(long long x = 0, long long y = 0) : x(x), y(y) {}

        Point operator+(const Point &p) { return Point(x + p.x, y + p.y); }

        Point operator-(const Point &p) { return Point(x - p.x, y - p.y); }

        Point operator-(void) { return Point(-x, -y); }

        bool operator==(const Point &other) { return other.x == x && other.y == y; }

        friend std::ostream &operator<<(std::ostream &out, const Point &value)
        {
            out << value.x << ' ' << value.y;
            return out;
        }
    };

    struct Vector
    {
        long long x, y;

        Vector(Point a, Point b) : x((b - a).x), y((b - a).y) {}

        long long length()
        {
            return sqrt(x * x + y * y);
        }

        Vector operator+(const Vector &v)
        {
            return Vector(Point(), Point(v.x + x, v.y + y));
        }

        long long operator*(const Vector &v)
        {
            return (long long)(v.x * x + v.y * y);
        }

        static long long pseudovector(const Vector &v1, const Vector &v2)
        {
            return (long long)(v2.y * v1.x - v2.x * v1.y);
        }

        friend std::ostream &operator<<(std::ostream &out, const Vector &value)
        {
            out << value.x << ' ' << value.y;
            return out;
        }
    };

    int ind_segments = 0;

    struct Segment
    {
        Point first_point, second_point;

        Segment()
        {
            ++ind_segments;
            first_point.ind = ind_segments;
            second_point.ind = ind_segments;
        }

        Segment(Point first_point2, Point second_point2) : first_point(first_point2), second_point(second_point2)
        {
            ++ind_segments;
            first_point.ind = ind_segments;
            second_point.ind = ind_segments;
        }
    };

    struct Line
    {
        long long A, B, C;

        long long calculate_y(long long x) { return (A * x + C) / (-B); }

        long long calculate_x(long long y) { return (B * y + C) / (-A); }

        Line(long long A, long long B, long long C) : A(A), B(B), C(C) {}

        Vector get_vector() const { return Vector(Point(0, 0), Point(-B, A)); }

        long long get_distance(Point p) const
        {
            if (A == 0)
                return abs(-C / B - p.y);
            else if (B == 0)
                return abs(-C / A - p.x);
            else
                return abs(A * p.x + B * p.y + C) / sqrt(A * A + B * B);
        }

        long long get_rdistance(Point p) const
        {
            if (A == 0)
                return (-C / B - p.y);
            else if (B == 0)
                return (-C / A - p.x);
            else
                return (A * p.x + B * p.y + C) / sqrt(A * A + B * B);
        }

        Point get_intersection(Line l) const
        {
            return Point(
                -((C * l.B - l.C * B) / (A * l.B - l.A * B)),
                -((A * l.C - l.A * C) / (A * l.B - l.A * B)));
        }
    };

    bool comp_x(Point p1, Point p2)
    {
        return p1.x < p2.x;
    }

    bool comp_y(Point p1, Point p2)
    {
        return p1.y < p2.y;
    }

    bool comp_xy(Point p1, Point p2)
    {
        return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
    }

    bool comp_yx(Point p1, Point p2)
    {
        return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
    }

    bool comp_angle(Point p1, Point p2)
    {
        Vector AB = Vector(Point(), p1);
        Vector BC = Vector(Point(), p2);
        long long pv = Vector::pseudovector(AB, BC);
        return pv == 0 ? AB * AB < BC * BC : pv > 0;
    }

    bool is_intersected_x(Segment s1, Segment s2)
    {
        std::vector<Point> points;
        points.push_back(s1.first_point);
        points.push_back(s1.second_point);
        points.push_back(s2.first_point);
        points.push_back(s2.second_point);
        std::stable_sort(points.begin(), points.end(), comp_x);
        if (points[0].ind == points[1].ind && points[1].x != points[2].x)
            return 0;
        return 1;
    }

    bool is_intersected_y(Segment s1, Segment s2)
    {
        std::vector<Point> points;
        points.push_back(s1.first_point);
        points.push_back(s1.second_point);
        points.push_back(s2.first_point);
        points.push_back(s2.second_point);
        std::stable_sort(points.begin(), points.end(), comp_y);
        if (points[0].ind == points[1].ind && points[1].y != points[2].y)
            return 0;
        return 1;
    }

    bool is_intersected_segments(Segment s1, Segment s2)
    {
        if (is_intersected_y(s1, s2) && is_intersected_x(s1, s2))
        {
            long long x1 = s2.first_point.x;
            long long y1 = s2.first_point.y;
            long long x2 = s2.second_point.x;
            long long y2 = s2.second_point.y;
            long long a = y1 - y2;
            long long b = x2 - x1;
            long long c = y2 * x1 - x2 * y1;
            Line l1(a, b, c);
            x1 = s1.first_point.x;
            y1 = s1.first_point.y;
            x2 = s1.second_point.x;
            y2 = s1.second_point.y;
            b = x2 - x1;
            a = y1 - y2;
            c = y2 * x1 - x2 * y1;
            Line l2(a, b, c);
            //        std::cout << l1.get_rdistance(s1.first_point) << ' ' << l1.get_rdistance(s1.second_point) << std::endl;
            //        std::cout << l2.get_rdistance(s2.first_point) << ' ' << l2.get_rdistance(s2.second_point) << std::endl;
            if ((l1.get_rdistance(s1.first_point) >= 0 && l1.get_rdistance(s1.second_point) >= 0) ||
                (l1.get_rdistance(s1.first_point) <= 0 && l1.get_rdistance(s1.second_point) <= 0))
            {
                return 0;
            }
            else
            {
                if ((l2.get_rdistance(s2.first_point) >= 0 && l2.get_rdistance(s2.second_point) >= 0) ||
                    (l2.get_rdistance(s2.first_point) <= 0 && l2.get_rdistance(s2.second_point) <= 0))
                {
                    return 0;
                }
                else if (l2.get_rdistance(s2.second_point) != 0)
                    return 1;
            }
        }
        return 0;
    }

    template <typename T>
    bool compare_sign(T a, T b)
    {
        if (a == 0 && b == 0)
            return 1;
        else if (a == 0 || b == 0)
            return true;
        return a / abs(a) == b / abs(b);
    }

    int find_sign(std::vector<Point> &points)
    {
        for (int i = 0; i < points.size() - 2; ++i)
        {
            Vector AB(points[i], points[i + 1]);
            Vector BC(points[i + 1], points[i + 2]);
            if (AB.x * BC.y - AB.y * BC.x < 0)
                return -1;
            if (AB.x * BC.y - AB.y * BC.x > 0)
                return 1;
        }
        return 0;
    }

    bool is_convex(std::vector<Point> points)
    {
        points.push_back(points[0]);
        points.push_back(points[1]);
        long long sign = find_sign(points);
        for (int i = 0; i < points.size() - 2; ++i)
        {
            Vector AB(points[i], points[i + 1]);
            Vector BC(points[i + 1], points[i + 2]);
            if (!compare_sign(AB.x * BC.y - AB.y * BC.x, sign))
            {
                return 0;
            }
        }
        return 1;
    }

    bool belongs_to(Point point, std::vector<Point> points)
    {
        Segment beam(point, Point(1e5, 1e5 + 1) + point);
        bool is_on_vertex = 0;
        for (auto &a : points)
        {
            if (a == point)
                is_on_vertex = 1;
        }

        if (is_on_vertex)
            return 1;

        points.push_back(points[0]);

        int number_of_intersections = 0;
        for (int i = 0; i < points.size() - 1; ++i)
            if (is_intersected_segments(beam, Segment(points[i], points[i + 1])))
                ++number_of_intersections;
        if (number_of_intersections % 2)
            return 1;
        return 0;
    }
};

using namespace Geometry;

int main()
{
    int n;
    IOS;
    Point a;
    std::vector<Point> points;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a.x >> a.y;
        points.push_back(a);
    }

    std::sort(points.begin(), points.end(), comp_xy);
    Point p = points[0];
    std::vector<Point> hull = {p};

    for (auto &point : points)
    {
        point = point - p;
    }
    std::sort(points.begin() + 1, points.end(), comp_angle);
    for (auto &point : points)
    {
        point = point + p;
    }

    for (int i = 1; i < points.size(); ++i)
    {
        while (hull.size() >= 2 &&
               Vector::pseudovector(
                   Vector(*(hull.end() - 2), *(hull.end() - 1)),
                   Vector(*(hull.end() - 1), points[i])) <= 0)
        {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    std::cout << hull.size() << std::endl;
    for (auto &a : hull)
        std::cout << a << std::endl;
}