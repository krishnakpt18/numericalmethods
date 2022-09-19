#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;
int main ()
{
  int i,j,k,n;
  double sumx=0,sumy=0,sumx2=0,sumY=0,sumxy=0,ax=0;
  double *x,*y,*z,*yfit;
  double x2,xy;
  ifstream fin;
  ofstream fout;
  fin.open("in.txt");
  fout.open("outexp.txt");
  fin>>n;
  fout<<setiosflags(ios::fixed | ios::showpoint)<<setprecision(5);
  x=new double[n];
  y=new double[n];
  z=new double[n];
  fout<<"# "<<string(70,'-')<<endl;
  fout<<"# "<<setw(10)<<"x"<<setw(10)<<"y"<<setw(10)<<"Y"<<setw(10);
  fout<<"x2"<<setw(10)<<"xy"<<endl;
  fout<<"# "<<string(70,'-')<<endl;

  for ( i = 0; i < n; i++) {
    fin>>x[i]>>y[i];
    x2=x[i]*x[i];
    sumx+=x[i];
    sumy+=y[i];
    z[i]=log(y[i]);
    xy=x[i]*z[i];
    sumx2+=x2;
    sumxy+=xy;
    sumY+=z[i];
    fout<<"#  "<<setw(10)<<x[i]<<setw(10)<<y[i]<<setw(10)<<z[i];
    fout<<setw(10)<<z[i]<<setw(10)<<x2<<setw(10)<<xy<<endl;
  }
  fout<<"# "<<string(70,'-')<<endl;
  fout<<"# "<<setw(10)<<sumx<<setw(10)<<sumy<<setw(10)<<sumY;
  fout<<setw(10)<<sumx2<<setw(10)<<sumxy<<endl;
  fout<<"# "<<string(70,'-')<<endl;

  double denom=0,suma=0,sumb=0,a=0,b=0,B=0;

  denom=n*sumx2-sumx*sumx;
  suma=n*sumxy-sumx*sumY;
  sumb=sumx2*sumY-sumxy*sumx;
  a=suma/denom; b=sumb/denom;
  B=exp(b);

  fout<<"# "<<setw(10)<<"a="<<a<<setw(15)<<"b="<<b<<setw(10)<<"B="<<B<<endl;
  fout<<"# "<<string(70,'-')<<endl;
  fout<<"# "<<setw(10)<<"x"<<setw(10)<<"y"<<setw(10)<<"Y"<<setw(10)<<"yfit"<<endl;
  fout<<"# "<<string(70,'-')<<endl;
  
  for ( i = 0; i < n; i++) {
    ax=a*x[i];
    yfit[i]=B*(exp(ax));
    fout<<setw(10)<<x[i]<<setw(10)<<y[i]<<setw(10)<<z[i]<<setw(10)<<yfit[i]<<endl;



  }

  fout<<"# "<<string(70,'-')<<endl;
  delete [] x;
  delete [] y;
  delete [] yfit;
  fin.close();
  fout.close();
  return 0;
}
