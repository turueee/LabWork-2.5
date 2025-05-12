#pragma once
#include <iostream>
#include <cmath>
#include "TError.h"

template<class T,int DIM>
class TPoint {
protected:
  T coordinates[DIM];
  int color;
  int size;
public:
  TPoint();
  TPoint(T* coordinates_, int color_, int size_);
  ~TPoint();

  int GetDim();
  int GetColor();
  int GetSize();
  
  void SetColor(int color_);
  void SetSize(int size_);

  T& operator[](int index);

  double DistToOrigin();
  double DistTo(TPoint<T, DIM>& p);

  template<class I, int DIM>
  friend std::istream& operator>>(std::istream& i, TPoint<I, DIM>& p);

  template<class O, int DIM>
  friend std::ostream& operator<<(std::ostream& o, TPoint<O, DIM>& p);
};

template<class T, int DIM>
inline TPoint<T, DIM>::TPoint()
{
  color = 1;
  size = 1;
  for (int i = 0; i < DIM; ++i)
    coordinates[i] = 0;
}

template<class T, int DIM>
inline TPoint<T, DIM>::TPoint(T* coordinates_, int color_, int size_)
{
  if (size_ <= 0)
    ERROR("size_ <= 0");
  if (color_ <= 0)
    ERROR("color_ <= 0");
  try
  {
    T a = coordinates_[DIM - 1];
  }
  catch(...)
  {
    ERROR("Indexes error");
  }
  color = color_;
  size = size_;
  for (int i = 0; i < DIM; ++i)
    coordinates[i] = coordinates_[i];
}

template<class T, int DIM>
inline TPoint<T, DIM>::~TPoint()
{
  size = 0;
  color = 0;
}

template<class T, int DIM>
inline int TPoint<T, DIM>::GetDim()
{
  return DIM;
}

template<class T, int DIM>
inline int TPoint<T, DIM>::GetColor()
{
  return color;
}

template<class T, int DIM>
inline int TPoint<T, DIM>::GetSize()
{
  return size;
}

template<class T, int DIM>
inline void TPoint<T, DIM>::SetColor(int color_)
{
  if (color_ <= 0)
    ERROR("color_ <= 0");
  color = color_;
}

template<class T, int DIM>
inline void TPoint<T, DIM>::SetSize(int size_)
{
  if (size_ <= 0)
    ERROR("size_ <= 0");
  size = size_;
}

template<class T, int DIM>
inline T& TPoint<T, DIM>::operator[](int index)
{
  if (index >= DIM)
    ERROR("index >= DIM");
  return coordinates[index];
}

template<class T, int DIM>
inline double TPoint<T, DIM>::DistToOrigin()
{
  T res = 0;
  for (int i = 0; i < DIM; ++i)
    res += coordinates[i] * coordinates[i];
  return pow(res,0.5);
}

template<class T, int DIM>
inline double TPoint<T, DIM>::DistTo(TPoint<T, DIM>& p)
{
  T res = 0;
  for (int i = 0; i < DIM; ++i)
    res += (coordinates[i]-p[i]) * (coordinates[i]-p[i]);
  return pow(res, 0.5);
}

template<class I, int DIM>
inline std::istream& operator>>(std::istream& i, TPoint<I, DIM>& p)
{
  int color_,size_;

  cout << "Enter the size of point." << endl;
  i >> size_;
  cout << "Enter the color of point." << endl;
  i >> color_;
  if (color_ <= 0)
    ERROR("color_ <= 0");
  if (size_ <= 0)
    ERROR("size_ <= 0");
  p.SetColor(color_);
  p.SetSize(size_);
  cout << "Dimension of point is " << DIM << ".\n";
  for (int i = 0; i < DIM; ++i)
  {
    cout << "p[" << i << "] = ";
    cin >> p.coordinates[i];
  }
  return i;
}

template<class V, int DIM>
inline std::ostream& operator<<(std::ostream& o, TPoint<V, DIM>& p)
{
  o << "Object: point.\nSize: " << p.GetSize() << "\nColor: " << p.GetColor() << "\nCoordinates: (";
  for (int i = 0; i < DIM-1; ++i)
    o << p[i] << "; ";
  o << p[DIM - 1] << ")";
  return o;
}
