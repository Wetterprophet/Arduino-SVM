#ifndef VEC_DIM
#error
#endif

#if (defined(__AVR__))
#include <avr\pgmspace.h>
#else
#include <pgmspace.h>
#endif

inline float linear_kernel(float* u, float* v){
  float result=0;
  for (int j=0; j<VEC_DIM; j++){
    result += pgm_read_float(u + j) * v[j];
  }
  return result;
}
