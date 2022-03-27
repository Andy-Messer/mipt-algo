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
#include <iomanip>
const long double eps = 0.00000000001;
namespace Geometry {
    struct Point {
        long double x, y;
        Point(long double x = 0, long double y = 0) : x(x), y(y) {}
        Point operator +(const Point& p) { return Point(x + p.x, y + p.y); }
        Point operator -(const Point& p) { return Point(x - p.x, y - p.y); }
        Point operator -(void) { return Point(-x, -y); }
        friend std::ostream& operator<<(std::ostream& out, const Point& value) {
            out << value.x << ' ' << value.y;
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
            Point get_intersection(Line l) const {
                return Point(
                    -((C * l.B - l.C * B) / (A * l.B - l.A * B)),
                    -((A * l.C - l.A * C) / (A * l.B - l.A * B))
                );
            }
        };
    };

    using namespace Geometry;

    int main() {
        long double A1, B1, C1;
        long double A2, B2, C2;
        std::cin >> A1 >> B1 >> C1 >> A2 >> B2 >> C2;
        Line line_1(A1, B1, C1);
        Line line_2(A2, B2, C2);
        std::cout << std::setprecision(20);
        std::cout << line_1.get_vector() << std::endl;
        std::cout << line_2.get_vector() << std::endl;
        if (line_1.A * line_2.B - line_1.B * line_2.A == 0) {
            if (line_1.A == 0 && line_1.B != 0)
                std::cout << line_2.get_distance(Point(1, line_1.calculate_y(1))) << '\n';
            else
                std::cout << line_2.get_distance(Point(line_1.calculate_x(1), 1)) << '\n';
        }
        else {
            std::cout << line_2.get_intersection(line_1);
        }
    }