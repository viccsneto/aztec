#include "Bitwise.h"

namespace Aztec {
  long Bitwise::XOR(long a, long b)
  {
    return a ^ b;
  }

  long Bitwise::AND(long a, long b)
  {
    return a & b;
  }

  long Bitwise::OR(long a, long b)
  {
    return a | b;
  }

  long Bitwise::NOT(long a)
  {
    return ~a;
  }
} // namespace Aztec