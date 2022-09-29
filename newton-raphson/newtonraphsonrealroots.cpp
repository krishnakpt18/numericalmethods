#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

double real_roots(double);

int main ()
{
  
  double a=0,b=0,c=0;
  double fx=0,fpx=0,eps=0,x=0,x2=0,x3=0,x4=0,x5=0;
  cout<<"Enter the initial value\n";
  cin>>a;

  return real_roots(a);
  
}
double real_roots(double x){

  double fx=0,fpx=0,eps=0,x2=0,x3=0,x4=0,x5=0;

  ofstream fout;
  fout.open("realout.txt");
  fout<<setiosflags(ios :: scientific | ios :: showpoint)<<setprecision(5);
  fout<<'#'<<string(60,'-')<<endl;
  fout<<'#'<<setw(5)<<'x'<<setw(15)<<"fx"<<setw(17)<<"fpx"<<endl;
  fout<<'#'<<string(60,'-')<<endl;

  for (int i = 0; i < 51; i++) {
    x2 = x * x;
    x3 = x * x2;
    x4 = x * x3;
    x5 = x * x4;
//    fx = x3 + x2 * 6.0 + x * 11.0 + 6.0;
  //  fpx = x2 * 3.0 + x * 12.0 + 11.0;
    fx=0.5-(exp(-x/5));
    fpx=exp(-x/5);
    eps=fx/fpx;
    x -= eps;

    fout<<setw(10)<<x<<setw(15)<<fx<<setw(18)<<fpx<<endl;
  }
   fout<<'#'<<string(60,'-')<<endl;
   fout<<'#'<<"The Root is , x="<<x<<endl;
   fout<<'#'<<string(60,'-')<<endl;
  return 0;
}
