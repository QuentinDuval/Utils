#pragma once
#include <cmath>

namespace prob
{
   //TODO - todo
   inline bool equalWithDelta(double a, double b, double delta)
   {
      return abs(a - b) < delta;
   }
}
