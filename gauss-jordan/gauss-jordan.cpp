#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;
int main (int argc, char *argv[])
{
 
  int n,m,i,j,k;
  double temp[10][10],x[10][10],x1[10][10],x2[10][10],
  x3[10][10],x4[10][10],x5[10][10],x6[10][10];
 // double x1,x2,x3,x4,x5;
  ifstream fin;
  ofstream fout;
  fin.open("gaussjo-in.txt");
  fout.open("gaussjo-out.txt");
  fout<<setiosflags(ios::fixed | ios::showpoint)<<setprecision(5);
  fin>>n>>m;
 fout<<"The augmented matrix is:"<<endl;
  for ( i = 0; i < n; ++i) {
    for ( j = 0; j < m; ++j) {
      fin>>x[i][j];
      fout<<setw(15)<<x[i][j];
    }fout<<endl;
  }
  fout<<endl;

fout<<endl;
fout<<"Jordan's first modification:"<<endl;
  for ( i = 0; i < n; i++) {
    for ( j = 0; j < m; j++) {
      x1[0][j]=(x[0][j])/(x[0][0]);     
      if (x1[0][j] != x1[i][j]) {
        x1[i][j] = x[i][j];
      }  fout<<setw(15)<<x1[i][j];       
    } fout<<endl;

 }
fout<<endl;
fout<<"First elimination:"<<endl;
 for ( i = 0; i < n; i++) {
    for ( j = 0; j < m; j++) {
         x2[0][j] = x1[0][j];
       if (x1[0][j] != x1[i][j]) {
          x2[i][j]=x1[i][j]-x1[i][0]*x1[0][j];
       } 
       fout<<setw(15)<<x2[i][j];   
    }fout<<endl;
 }
 fout<<endl;

 fout<<"Jordan's second modification:"<<endl;
  for ( i = 0; i < n; i++) {
    for ( j = 0; j < m; j++) {
      x3[1][j]=(x2[1][j])/(x2[1][1]);     
      if (x3[1][j] != x3[i][j]) {
        x3[i][j] = x2[i][j];
      }  fout<<setw(15)<<x3[i][j];       
    } fout<<endl;

 }fout<<endl;

fout<<"Second elimination:"<<endl;
 for ( i = 0; i < n; i++) {
    for ( j = 0; j < m; j++) {
         x4[1][j] = x3[1][j];
       if (x3[1][j] != x3[i][j]) {
            if (x3[1][j]<0) {
               x4[i][j]=x3[i][j]+x3[i][1]*x3[1][j];
            }
            else {
                x4[i][j]=x3[i][j]-x3[i][1]*x3[1][j];
            }
            }
     fout<<setw(15)<<x4[i][j];      
    }fout<<endl;
    } 
 fout<<endl;
 fout<<"Jordan's third modification:"<<endl;
  for ( i = 0; i < n; i++) {
    for ( j = 0; j < m; j++) {
      x5[2][j]=(x4[2][j])/(x4[2][2]);     
      if (x5[2][j] != x5[i][j]) {
        x5[i][j] = x4[i][j];
      }  fout<<setw(15)<<x5[i][j];       
    } fout<<endl;

 }fout<<endl;
fout<<"Third elimination:"<<endl;
 for ( i = 0; i < n; i++) {
    for ( j = 0; j < m; j++) {
         x6[2][j] = x5[2][j];
       if (x5[2][j] != x5[i][j]) {
            if (x5[2][j]<0) {
               x6[i][j]=x5[i][j]+x5[i][2]*x5[2][j];
            }
            else {
                x6[i][j]=x5[i][j]-x5[i][2]*x5[2][j];
            }
            }
     fout<<setw(15)<<x6[i][j];      
    }fout<<endl;
    } 
 fout<<endl;

  fin.close();
  fout.close();
  return 0;
}
