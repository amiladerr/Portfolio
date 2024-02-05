#include <iostream>

using namespace std;

class Point{
    double x, y;
public:
    Point() { x = 0; y = 0; }
    Point(double newX, double newY) { SetCoordinates(newX, newY); }
    void SetCoordinates(double newX, double newY) { x = newX; y = newY; }
    double getX() const { return x; }
    double getY() const { return y; }
    static bool isEqual(const Point &p1, const Point &p2){
        return p1.x == p2.x && p1.y == p2.y;
    }
    void Display() const { cout << "(" << x << ", " << y << ")"; }
};

class Line{
    Point startingPoint, endPoint;
public:
    Line(const Point &p1, const Point &p2) : startingPoint(p1), endPoint(p2) {}
    Line (double x1, double y1, double x2, double y2) : startingPoint(x1, y1), endPoint(x2, y2) {}
    void SetLine(const Point &p1, const Point &p2) {
        startingPoint = p1;
        endPoint = p2;
    }
    void SetLine(double x1, double y1, double x2, double y2){
        startingPoint.SetCoordinates(x1, y1);
        endPoint.SetCoordinates(x2, y2);
    }
    Point getStartingPoint() const { return startingPoint; }
    Point getEndPoint() const { return endPoint; }
    static bool isEqualDirectedLines (const Line &l1, const Line &l2){
        return Point::isEqual(l1.startingPoint, l2.startingPoint) && Point::isEqual(l1.endPoint, l2.endPoint);
    }
    static bool isEqualUndirectedLines (const Line &l1, const Line &l2){
        return Point::isEqual(l1.startingPoint, l2.startingPoint) && Point::isEqual(l1.endPoint, l2.endPoint)
        || Point::isEqual(l1.startingPoint, l2.endPoint) && Point::isEqual(l1.endPoint, l2.startingPoint);
    }
    void DisplayLine() const { startingPoint.Display(); cout << "-"; endPoint.Display(); }
};

int main(){

    Point p1(3, 5), p2(4, 2);
    p1.Display(); cout << endl;
    cout << Point::isEqual(p1, p2) << " " << Point::isEqual(p1, p1) << endl;
    Line l1(p1, p2), l2(4, 2, 3, 5), l3(1, 2, 3, 4);
    l1.DisplayLine(); cout << endl;
    l2.DisplayLine(); cout << endl;
    cout << Line::isEqualDirectedLines(l1, l2) << " " << Line::isEqualUndirectedLines(l1, l2)
         << " " << Line::isEqualUndirectedLines(l1, l3) << endl;
return 0;
}
