#include <iostream>
#include <cmath>
using namespace std;
class Base
{
    virtual double length()=0;
    virtual void show()=0;
};
class Point
{
    public:
        friend class Line;
        Point() {x=0.0;y=0.0;}
        Point(double xInput,double yIuput) {x=xInput;y=yIuput;}
        void setPoint(double xInput,double yIuput)
            {x=xInput;y=yIuput;}
    private:
        double x,y;
    protected:
        double getX() {return x;}
        double getY() {return y;}
};
class Line:public Base
{
    public:
        Line(double spx,double spy,double epx,double epy):sp(spx,spy),ep(epx,epy) {}
        double length()
            {return sqrt(pow((ep.getX()-sp.getX()),2)+pow((ep.getY()-sp.getY()),2));}
        void show();
    private:
        Point sp,ep;
    protected:
};
void Line::show()
{
    cout<<"sp:("<<sp.getX()<<','<<sp.getY()<<")\n";
    cout<<"ep:("<<ep.getX()<<','<<ep.getY()<<")\n";
}
int main()
{
    Line l1(2.0,3.5,6.9,7.8);
    l1.show();
    cout<<l1.length()<<endl;
}