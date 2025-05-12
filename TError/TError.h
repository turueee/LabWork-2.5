#pragma once
#include <iostream>
#include <string>
#include <utility>
#include "TString.h"


class TError
{
protected:
  TString err;
  TString func;
  TString fil;
  int lin;
public:
  TError(char* error,
    char* function,
    char* file,
    int line)
  {
    err.SetStr(error);
    func.SetStr(function);
    fil.SetStr(file);
    lin = line;
    cout << "\nError: " << err << "Function: " << func << "File: " << fil <<"Line:"<<line<< endl;
  }

  void what()
  {
    cout << "\nError: " << err << "Function: " << func << "File: " << fil << "Line:" << lin << endl;
  }
};

#define ERROR(err,...) throw TError(err, __func__, __FILE__, __LINE__)