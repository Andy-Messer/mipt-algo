#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Point {
  long double x, y;
  long double key;

  Point() : x(0), y(0), key(-1) {}

  Point(const long double &new_x, const long double &new_y)
      : x(new_x), y(new_y), key(-1) {}

  Point operator+(const Point &p) { return Point(x + p.x, y + p.y); }

  bool operator==(const Point &other) const {
    return other.x == x && other.y == y;
  }

  Point operator-(const Point &p) { return Point(x - p.x, y - p.y); }
  friend std::ostream &operator<<(std::ostream &out, Point &value) {
    out << value.x << ' ' << value.y;
    return out;
  }

  friend std::istream &operator>>(std::istream &in, Point &value) {
    in >> value.x >> value.y;
    return in;
  }
};

struct Vector {
  long double x, y;

  Vector(Point a, Point b) : x((b - a).x), y((b - a).y) {}

  long double length() { return sqrt(x * x + y * y); }

  Vector operator+(const Vector &v) {
    return Vector(Point(), Point(v.x + x, v.y + y));
  }

  long double operator*(const Vector &v) {
    return (long double)(v.x * x + v.y * y);
  }

  static long double pseudovector(const Vector &v1, const Vector &v2) {
    return (long double)(v2.y * v1.x - v2.x * v1.y);
  }

  friend std::ostream &operator<<(std::ostream &out, const Vector &value) {
    out << value.x << ' ' << value.y;
    return out;
  }
};

bool comp_angle(const Point &p1, const Point &p2) {
  Vector AB = Vector(Point(), p1);
  Vector BC = Vector(Point(), p2);
  long double pv = Vector::pseudovector(AB, BC);
  return pv == 0 ? AB * AB < BC * BC : pv > 0;
}

bool comp_xy(const Point &p1, const Point &p2) {
  return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

struct Shape {
  std::vector<Point> points;

  Shape() : points(0) {}

  Shape(const std::vector<Point> &new_points) : points(new_points) {}

  Point get_min_point() {
    Point result = points[0];
    size_t start_index = 0;
    for (size_t i = 0; i < points.size(); ++i) {
      if (!comp_xy(result, points[i])) {
        result = points[i];
        start_index = i;
      }
    }
    std::vector<Point> sorted_points;
    sorted_points.insert(sorted_points.end(),
                         std::make_move_iterator(points.begin() + start_index),
                         std::make_move_iterator(points.end()));
    sorted_points.insert(sorted_points.end(),
                         std::make_move_iterator(points.begin()),
                         std::make_move_iterator(points.begin() + start_index));
    points = sorted_points;
    return result;
  }

  friend Shape operator+(const Shape &first, const Shape &second) {
    Shape f_copy = first;
    Shape s_copy = second;
    Point s1 = f_copy.get_min_point();
    Point s2 = s_copy.get_min_point();

    f_copy.points.push_back(s1);
    s_copy.points.push_back(s2);

    Shape result;
    Point p = s1 + s2;

    result.points.push_back(p);

    int i = 1;
    int j = 1;
    while (i < f_copy.points.size() && j < s_copy.points.size())
      if (comp_angle(f_copy.points[i] - f_copy.points[i - 1],
                     s_copy.points[j] - s_copy.points[j - 1])) {
        result.points.push_back(result.points.back() - f_copy.points[i - 1] +
                                f_copy.points[i]);
        ++i;
      } else {
        result.points.push_back(result.points.back() - s_copy.points[j - 1] +
                                s_copy.points[j]);
        ++j;
      }
    while (i < f_copy.points.size() - 1)
      result.points.push_back(result.points.back() - f_copy.points[i - 1] +
                              f_copy.points[i]),
          ++i;
    while (j < s_copy.points.size() - 1)
      result.points.push_back(result.points.back() - s_copy.points[j - 1] +
                              s_copy.points[j]),
          ++j;
    return result;
  }

  friend std::istream &operator>>(std::istream &in, Shape &value) {
    int n;
    in >> n;
    value.points.clear();
    Point a;
    for (int i = 0; i < n; ++i) {
      std::cin >> a;
      value.points.push_back(a);
    }
    return in;
  }

  friend std::ostream &operator<<(std::ostream &out, Shape &value) {
    out << value.points.size() << std::endl;
    for (auto &point : value.points) {
      std::cout << point << std::endl;
    }
    return out;
  }
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
    return Point(-((C * l.B - l.C * B) / (A * l.B - l.A * B)),
                 -((A * l.C - l.A * C) / (A * l.B - l.A * B)));
  }
};

struct Segment {
  Point fp, sp;

  Segment() {
    static int key = 0;
    ++key;
    fp.key = key;
    sp.key = key;
  }

  Segment(Point fp2, Point sp2) : fp(fp2), sp(sp2) {
    static int key = 0;
    ++key;
    fp.key = key;
    sp.key = key;
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
        points.push_back(s1.fp);
        points.push_back(s1.sp);
        points.push_back(s2.fp);
        points.push_back(s2.sp);
        std::stable_sort(points.begin(), points.end(), comp_x);
        if (points[0].key == points[1].key && points[1].x != points[2].x)
            return 0;
        return 1;
    }
 
    bool is_intersected_y(Segment s1, Segment s2) {
        std::vector<Point> points;
        points.push_back(s1.fp);
        points.push_back(s1.sp);
        points.push_back(s2.fp);
        points.push_back(s2.sp);
        std::stable_sort(points.begin(), points.end(), comp_y);
        if (points[0].key == points[1].key && points[1].y != points[2].y)
            return 0;
        return 1;
    }
 
    bool is_intersected_segments(Segment s1, Segment s2) {
        if (is_intersected_y(s1, s2) && is_intersected_x(s1, s2)) {
            long double x1 = s2.fp.x;
            long double y1 = s2.fp.y;
            long double x2 = s2.sp.x;
            long double y2 = s2.sp.y;
            long double a = y1 - y2;
            long double b = x2 - x1;
            long double c = y2 * x1 - x2 * y1;
            Line l1(a, b, c);
            x1 = s1.fp.x;
            y1 = s1.fp.y;
            x2 = s1.sp.x;
            y2 = s1.sp.y;
            b = x2 - x1;
            a = y1 - y2;
            c = y2 * x1 - x2 * y1;
            Line l2(a, b, c);
//        std::cout << l1.get_rdistance(s1.fp) << ' ' << l1.get_rdistance(s1.sp) << std::endl;
//        std::cout << l2.get_rdistance(s2.fp) << ' ' << l2.get_rdistance(s2.sp) << std::endl;
            if ((l1.get_rdistance(s1.fp) >= 0 && l1.get_rdistance(s1.sp) >= 0) ||
                (l1.get_rdistance(s1.fp) <= 0 && l1.get_rdistance(s1.sp) <= 0)) {
                return 0;
            } else {
                if ((l2.get_rdistance(s2.fp) >= 0 && l2.get_rdistance(s2.sp) >= 0) ||
                    (l2.get_rdistance(s2.fp) <= 0 && l2.get_rdistance(s2.sp) <= 0)) {
                    return 0;
                } else
                if (l2.get_rdistance(s2.sp) != 0)
                    return 1;
            }
        }
        return 0;
    }

int main() {
  Point point;
    int n;
    std::cin >> n >> point.x >> point.y;
    std::vector<Point> points;
 
    Segment beam(point, Point(1e5, 1e5 + 1) + point);
    Point a;
    bool is_on_vertex = 0;
 
    for (int i = 0; i < n; ++i) {
        std::cin >> a.x >> a.y;
        points.push_back(a);
        if (a == point)
            is_on_vertex = 1;
    }
 
    if (is_on_vertex) {
        std::cout << "YES";
        return 0;
    }
 
    points.push_back(points[0]);
 
    int number_of_intersections = 0;
    for (int i = 0; i < n; ++i)
        if (is_intersected_segments(beam, Segment(points[i], points[i + 1])))
            ++number_of_intersections;
    if (number_of_intersections % 2) std::cout << "YES"; else std::cout << "NO";
    return 0;
}