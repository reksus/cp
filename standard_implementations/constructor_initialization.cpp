class Point {
public:
    int x, y;
    // x(x): first x is the class propoerty and second x is the constructor parameter
    Point(int x, int y): x(x), y(y) {}
};

class Student {
public:
    string name;
    int rollNumber;
    Student(string name, int rollNumber)
    {
        this->name = name;
        Student::rollNumber = rollNumber;
    }
};