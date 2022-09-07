#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;
int main (int argc, char *argv[])
{
  int i,j,n;
  double x2,xy,sumx=0,sumy=0,sumx2=0,sumxy=0;
  double *x,*y,*yfit;
  ifstream fin;
  ofstream fout;

  fin.open("in.txt");
  fout.open("out.txt");
  fin>>n;
  fout<<setiosflags(ios::fixed | ios::showpoint)<<setprecision(5);
  x=new double[n];
  y=new double[n];
  fout<<"# "<<string(60,'-')<<"#"<<endl;
  fout<<"#  x     y     x^2     xy"<<endl;
  for (i = 0; i < n; i++) {
    fin>>x[i]>>y[i];
    x2=x[i]*x[i]; 
    xy=x[i]*y[i];
    sumx+=x[i];
    sumy+=y[i];
    sumx2+=x2;
    sumxy+=xy;
     fout<<"# "<<setw(10)<<x[i]<<setw(10)<<y[i]<<setw(10)<<x2<<setw(10)<<xy<<endl;
  }
  fout<<"# "<<string(60,'-')<<"#"<<endl;
  fout<<"# "<<setw(10)<<sumx<<setw(10)<<setw(10)<<sumy;
  fout<<setw(10)<<sumx2<<setw(10)<<sumxy<<endl;
 
  double denom,numa,numb,a,b;
  denom=n*sumx2-sumx*sumx;
  numa=n*sumxy-sumx*sumy;
  numb=sumx2*sumy-sumx*sumxy;
  a=numa/denom; b=numb/denom;
  fout<<"# "<<string(60,'-')<<endl;
  fout<<"# "<<setw(18)<<"a="<<a<<setw(18)<<"b="<<b<<endl;
  fout<<"# "<<string(60,'-')<<"#"<<endl;
  yfit=new double[n];
  for ( i = 0; i < n; i++) {
    yfit[i]=a*x[i]+b;
    fout<<setw(10)<<x[i]<<setw(10)<<y[i]<<setw(10)<<yfit[i]<<endl;
  }
  fout<<"# "<<string(60,'-')<<"#";
  delete [] x;
  delete [] y;
  fin.close();
  fout.close();
  return 0; 
}
