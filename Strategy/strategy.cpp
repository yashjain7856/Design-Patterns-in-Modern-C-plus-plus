#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
using namespace std;

struct DiscriminantStrategy
{
    virtual double calculate_discriminant(double a, double b, double c) = 0;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy
{
    // todo
    double calculate_discriminant(double a, double b, double c){
        return b*b - 4*a*c;
    }
};

struct RealDiscriminantStrategy : DiscriminantStrategy
{
    // todo
    double calculate_discriminant(double a, double b, double c){
        cout<<"real"<<endl;
        double d =  b*b - 4*a*c;
        return (d>=0)?d:0.0/0.0;
    }
};

class QuadraticEquationSolver
{
    DiscriminantStrategy& strategy;
public:
    QuadraticEquationSolver(DiscriminantStrategy &strategy) : strategy(strategy) {}

    tuple<complex<double>, complex<double>> solve(double a, double b, double c)
    {
        // todo
        double d = strategy.calculate_discriminant(a,b,c);
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        complex<double> rootd = sqrt(complex<double>(d,0));
        return { ((-b) + rootd)/(2*a) , ((-b) - rootd)/(2*a) };
    }
};