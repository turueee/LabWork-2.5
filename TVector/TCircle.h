#pragma once
#include "TPoint.h"
#include "TString.h"


template<class T,int DIM>
class TCircle
{
protected:
  TPoint<T, DIM> center;
  T radius;
public:
  TCircle();
  TCircle(const TPoint<T, DIM>& p, T radius_);
  ~TCircle();

  int GetDim();
  T GetRadius();
  TPoint<T, DIM> GetCenter();

  void SetRadius(T radius_);
  void SetCenter(const TPoint<T,DIM>& p);

  double Perimeter();
  double Area();

  bool IsInCircle(const TPoint<T,DIM>& p);
  bool IsInCircumference(const TPoint<T, DIM>& p);


  template<class I, int DIM>
  friend std::istream& operator>>(std::istream& i, TCircle<I, DIM>& p);

  template<class O, int DIM>
  friend std::ostream& operator<<(std::ostream& o, TCircle <O, DIM>& p);
};