#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;

double simp(double[],double,int);
double fun(double);

int main (int argc, char *argv[])
{
  ofstream fout;
  fout.open("simpson-out.txt");
  const int npts=5;
  int n[npts] = {100,200,250,500,1000};
  int m; double a=0.0,b=1.0,h;
  double ana =2. + (sin(2.0) - 2.0 * cos(2.0))/2.0;
  double num; double* p;
  
  fout<<setiosflags(ios::fixed | ios::showpoint);
  fout<<"# "<<string(70,'-')<<endl;
  fout<<"# "<<setw(5)<<"h"<<setw(14)<<"Numerical";
  fout<<setw(13)<<"Exact"<<setw(20)<<"Error in %\n";
  fout<<"# "<<string(70,'-')<<endl;
   for (int j = 0; j < npts; j++) {
        m = n[j] + 1;
        p = new double[m];
        h=1.0/n[j];
        for (int i = 0; i < m; i++) 
           p[i] = fun(i * h);
           num =simp(p,h,m);
           fout<<setprecision(3)<<setw(8)<<h;
           fout<<setprecision(6)<<setw(12)<<num;
           fout<<setprecision(6)<<setw(15)<<ana;
           fout<<setprecision(6)<<setw(16)<<abs(ana-num)<<endl;
           delete [] p;
        }
   fout<<"# "<<string(70,'-')<<endl;
   return 0;
}
double simp(double y[],double h,int n)
{
  double f1 = 0.0,f2 =0.0;
  int m =n - 1;
  f1 = y[1] - y[m-1];
  f2 = y[2];
  for (int i = 0; i < m-3; i +=2) {
    f1 +=y[i];
    f2 += y[i+1];
  }
  return h*(y[0] + 4.0 *f1 + 2.0*f2 + y[m])/3.0;
}
double fun(double x)
{
  return 2.0 + sin(2.0 * sqrt(x));
}


