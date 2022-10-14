#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

uint64_t mod(uint64_t a, uint64_t m) {
  if (a < m) {
    return a;
  } else {
    while (a >= m) {
      uint64_t mm = m;
      while (a > (mm << 1)) {
        mm <<= 1;
      }
      a -= mm;
    }
    return a;
  }
}

uint64_t addmod(uint64_t a, uint64_t b, uint64_t m) {
  uint64_t r1 = mod(a, m);
  uint64_t r2 = mod(b, m);
  if (r2!=0 && r1 >= -r2)
    return mod(r1 + r2 - m, m);
  else
    return mod(r1 + r2, m);

  // return mod(mod(a,m)+mod(b,m),m);
}

uint64_t multimod(uint64_t a, uint64_t b, uint64_t m) {
  uint64_t result = 0;
  while (b) {
    if (b & 1) {
      result = addmod(result, a, m);
    }
    a = addmod(a, a, m);
    b >>= 1;
  }
  return result;
}
