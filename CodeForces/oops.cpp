#include <iostream>
#include <string>
using namespace std;

class Shape { // abstract class
    virtual void draw() {}; // pure virtual function
};

class Circle : public Shape {
public:
    int x;
    Circle(int x) : x(x) {}
    void inc() {
        ++x;
    }
    void draw() {
        cout << "drawing a circle\n";
    }
};

int main() {
    static Circle c1 (1);
    cout << c1.x<< '\n';
    c1.inc();
    c1.inc();
    c1.inc();
    return 0;
}
