#pragma once
#include "TPoint.h"
#include "TLine.h"



#define LIB_EXPORT_API __declspec(dllexport)



extern "C" LIB_EXPORT_API TPoint<int, 2>* Init();