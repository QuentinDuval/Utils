#include "utils/Numeric.h"
#include <cmath>

namespace prob
{
   bool equalWithDelta(double a, double b, double delta)
   {
      return abs(a - b) < delta;
   }
}
