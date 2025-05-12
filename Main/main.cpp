#include "TVector.h"
#include "TPoint.h"
#include "TLine.h"

int main()
{
  system("chcp 1251> nul");
  double* r = new double[4] {0};
  double* u = new double[4] {1,1,1,1};
  TLine<double, 4> a(r,u,2,3);
  cout << a;
  a.Begin()[0] = 9;
  cout << a;
  delete[]r, u;
}