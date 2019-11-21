#ifndef VEC_DIM
#error
#endif

#ifndef GAMMA
#error
#endif


inline float rbf_kernel(float* u, float* v){
  float result=0;
  for (int j=0; j<VEC_DIM; j++){
    float temp = u [j] - v[j];
    result += temp * temp;
  }
  return exp(-GAMMA * result);
}
