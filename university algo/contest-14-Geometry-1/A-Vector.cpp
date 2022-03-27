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

namespace Geometry {
    struct Point {
        long double x, y;
        Point(long double x = 0, long double y = 0) : x(x), y(y) {}
        Point operator +(const Point& p) { return Point(x + p.x, y + p.y); }
        Point operator -(const Point& p) { return Point(x - p.x, y - p.y); }
        Point operator -(void) { return Point(-x, -y); }
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
};

using Geometry::Vector;
using Geometry::Point;

int main() {
    Point a, b;
    std::cin >> a.x >> a.y >> b.x >> b.y;
    Vector x1(a, b);
    std::cin >> a.x >> a.y >> b.x >> b.y;
    Vector x2(a, b);
    std::cout << std::setprecision(10);
    std::cout << x1.length() << ' ' << x2.length() << std::endl;
    std::cout << x1 + x2 << std::endl;
    std::cout << x1 * x2 << ' ' << Vector::pseudovector(x1, x2) << std::endl;
    std::cout << abs(Vector::pseudovector(x1, x2) / 2);

}