#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;
int main (int argc, char *argv[])
{
 
  int n,m,i,j,k;
  double temp[10][10],x[10][10],x1[10][10],x2[10][10],x3[10][10];
 // double x1,x2,x3,x4,x5;
  ifstream fin;
  ofstream fout;
  fin.open("gaussjo-in.txt");
  fout.open("gaussjo-out.txt");
  fout<<setiosflags(ios::fixed | ios::showpoint)<<setprecision(5);
  cin>>n>>m;
 fout<<"The augmented matrix is:"<<endl;
  for ( i = 0; i < n; ++i) {
    for ( j = 0; j < m; ++j) {
      fin>>x[i][j];
      fout<<setw(15)<<x[i][j];
    }fout<<endl;
  }
  fout<<endl;

  fout<<"Partial pivoting:"<<endl;
 for ( i = 0; i < n; i++) {
   for ( j = 0; j < m; j++) {
    if (abs(x[i][0])<abs(x[i+1][0])) {
      temp[i][0] = x[i][0];
      x[i][0] = x[i+1][0];
      x[i+1][0] = temp[i][0];
    } fout<<setw(15)<<x[i][j];
   }fout<<endl;
 }
fout<<endl;
fout<<"Jordan's first modification:"<<endl;
  for ( i = 0; i < n; i++) {
    for ( j = 0; j < m; j++) {
      x1[0][j]=(x[0][j])/(x[0][0]);     
      if (x1[0][j] != x1[i][j]) {
        x1[i][j] = x[i][j];
      }
    }
 }
for ( i = 0; i < n; i++) {
    for ( j = 0; j < m; j++) {
      
      fout<<setw(15)<<x1[i][j];        
    }fout<<endl;
  }
fout<<endl;
 for ( i = 0; i < n; i++) {
    for ( j = 0; j < m; j++) {
         x2[0][j] = x1[0][j];
       if (x1[0][j] != x1[i][j]) {
          x2[i][j]=x1[i][j]-x1[i][0]*x1[0][j];
       }       
    }
 }
 fout<<"First elimination:"<<endl;

 for ( i = 0; i < n; i++) {
    for ( j = 0; j < m; j++) {
      
      fout<<setw(15)<<x2[i][j];        
    }fout<<endl;
  }
fout<<endl;
  fin.close();
  fout.close();
  return 0;
}
