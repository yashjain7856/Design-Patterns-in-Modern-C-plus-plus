#include <string>
using namespace std;

struct Flower
{
    virtual string str() = 0;
    virtual bool isRed() const { return false; }
    virtual bool isBlue() const { return false; }
};

struct Rose : Flower
{
    string str() override {
        return "A rose";
    }
};

struct RedFlower : Flower
{
    Flower& f;
    RedFlower(Flower& f) : f(f) {}

    string str() override {
        if (f.isRed() && f.isBlue()) return f.str();
        else if (f.isBlue()) return f.str() + " and red";
        else return f.str() + " that is red";
    }

    bool isRed() const override { return true; }
    bool isBlue() const override { return f.isBlue(); }
};

struct BlueFlower : Flower
{
    Flower& f;
    BlueFlower(Flower& f) : f(f) {}

    string str() override {
        if (f.isRed() && f.isBlue()) return f.str();
        else if (f.isRed()) return f.str() + " and blue";
        else return f.str() + " that is blue";
    }

    bool isRed() const override { return f.isRed(); }
    bool isBlue() const override { return true; }
};
