#pragma once
#include <iostream>
#include "TError.h"
#include "TPoint.h"
#include "TVector.h"

template<class T,int DIM>
class TLine
{
protected:
  TPoint<T, DIM> begin;
  TPoint<T, DIM> end;
  int size;
  int color;
public:
  TLine();
  TLine(T* beginc_, T* endc_,int size_, int color_);
  ~TLine();

  int GetDim();
  int GetSize();
  int GetColor();

  void SetSize(int size_);
  void SetColor(int color_);
  TPoint<T,DIM>& Begin();
  TPoint<T,DIM>& End();

  double Len();
  TVector<T> Vector();

  template<class I, int DIM>
  friend std::istream& operator>>(std::istream& i, TLine<I, DIM>& p);

  template<class O, int DIM>
  friend std::ostream& operator<<(std::ostream& o, TLine<O, DIM>& p);
};

template<class T, int DIM>
inline TLine<T, DIM>::TLine()
{
  size = 1;
  color = 1;
}

template<class T, int DIM>
inline TLine<T, DIM>::TLine(T* beginc_, T* endc_, int size_, int color_)
{
  if (size_ <= 0)
    ERROR("size_ <= 0");
  if (color_ <= 0)
    ERROR("color_ <= 0");
  try
  {
    T a = beginc_[DIM - 1];
  }
  catch (...)
  {
    ERROR("Indexes of begin error");
  }
  try
  {
    T a = endc_[DIM - 1];
  }
  catch (...)
  {
    ERROR("Indexes of end error");
  }

  color = color_;
  begin.SetColor(color);
  end.SetColor(color);

  size = size_;
  begin.SetSize(size);
  end.SetSize(size);

  for (int i = 0; i < DIM; ++i)
  {
    begin[i] = beginc_[i];
    end[i] = endc_[i];
  }
}


template<class T, int DIM>
inline TLine<T, DIM>::~TLine()
{
  size = 0;
  color = 0;
}

template<class T, int DIM>
inline int TLine<T, DIM>::GetDim()
{
  return DIM;
}

template<class T, int DIM>
inline int TLine<T, DIM>::GetSize()
{
  return size;
}

template<class T, int DIM>
inline int TLine<T, DIM>::GetColor()
{
  return color;
}

template<class T, int DIM>
inline void TLine<T, DIM>::SetSize(int size_)
{
  if (size_ <= 0)
    ERROR("size_ <= 0");
  size = size_;
  begin.SetSize(size);
  end.SetSize(size);
}

template<class T, int DIM>
inline void TLine<T, DIM>::SetColor(int color_)
{
  if (color_ <= 0)
    ERROR("color_ <= 0");
  color = color_;
  begin.SetColor(color);
  end.GetColor(color);
}

template<class T, int DIM>
inline TPoint<T, DIM>& TLine<T, DIM>::Begin()
{
  return begin;
}

template<class T, int DIM>
inline TPoint<T, DIM>& TLine<T, DIM>::End()
{
  return end;
}

template<class T, int DIM>
inline double TLine<T, DIM>::Len()
{
  begin.DistTo(end);
}

template<class T, int DIM>
inline TVector<T> TLine<T, DIM>::Vector()
{
  TVector<T> a(DIM);
  for (int i = 0; i < DIM; ++i)
    a[i] = end[i] - begin[i];
  return TVector<T>(a);
}

template<class I, int DIM>
inline std::istream& operator>>(std::istream& in, TLine<I, DIM>& p)
{
  int color_, size_;

  cout << "Enter the size of line." << endl;
  in >> size_;
  cout << "Enter the color of line." << endl;
  in >> color_;
  if (color_ <= 0)
    ERROR("color_ <= 0");
  if (size_ <= 0)
    ERROR("size_ <= 0");
  p.SetColor(color_);
  p.SetSize(size_);
  cout << "Dimension of point is " << DIM << ".\n";
  for (int i = 0; i < DIM; ++i)
  {
    cout << "begin[" << i << "] = ";
    in >> p.begin[i];
  }
  for (int i = 0; i < DIM; ++i)
  {
    cout << "end[" << i << "] = ";
    in >> p.end[i];
  }
  return in;
}

template<class O, int DIM>
inline std::ostream& operator<<(std::ostream& o, TLine<O, DIM>& p)
{
  o << "Object: line.\nSize: " << p.GetSize() << "\nColor: " << p.GetColor()<<"\nCoordinates of begin: (";
  for (int i = 0; i < DIM - 1; ++i)
    o << p.begin[i] << "; ";
  o << p.begin[DIM - 1] << ")\nCoordinates of end: (";
  for (int i = 0; i < DIM - 1; ++i)
    o << p.end[i] << "; ";
  o << p.end[DIM - 1] << ")\n";
  return o;
}
