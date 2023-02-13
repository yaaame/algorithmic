#include <iostream>
#include"../Eigen/Dense"
using namespace std;
using namespace Eigen;
class Point
{
public:
    double x;
    double y;
    Point(double xx=0,double yy=0)
    {
        x=xx;
        y=yy;
    }
    void SetValue(double xx,double yy) {
        x = xx;
        y = yy;
    }
};
double NewtonInterpolation(Point* p,int count, int num)
{
    auto form=new double*[count];
    for(int i=0;i<count;i++)
    {
        form[i]=new double[count];
        form[i][0]=p[i].y;
    }
    for(int i=1;i<count;i++)
        for(int j=1;j<=i;j++)
            form[i][j]=(form[i][j-1]-form[i-1][j-1])/(p[i].x-p[i-j].x);
    double fai=1,ans=0;
    for(int i=0;i<count;i++)
    {
        ans+=fai*form[i][i];
        fai*=num-p[i].x;
    }
    for(int i=0;i<count;i++)
        delete[]form[i];
    delete []form;
    return ans;
}
double Lagrange(Point *p,int count, int num)
{
    double ans=0;
    for(int i=0;i<count;i++)
    {
        double pi=1;
        for(int j=0;j<count;j++)
            if(i!=j)
                pi*=(num-p[j].x)/(p[i].x-p[j].x);
        ans+=pi*p[i].y;
    }
    return ans;
}
int main() {
    Matrix3i i3=Matrix3i::Random();
    cout<<i3<<endl;
    std::cout << "Hello, World!" << std::endl;
    Point p[3];
    p[0].SetValue(+0,1);
    p[1].SetValue(1,2);
    p[2].SetValue(3,6);
    int count=3;
    cout<<NewtonInterpolation(p,count,5)<<endl;
    cout<<Lagrange(p,count,5)<<endl;
    return 0;
}
