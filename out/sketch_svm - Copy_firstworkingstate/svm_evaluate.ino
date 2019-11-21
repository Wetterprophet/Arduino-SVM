#ifndef VEC_DIM
#error
#endif


inline float svm_evaluate(int n_sv, float* coeffs, float* sv_class, float* sensors){
  float result= 0;
  float* sv_current = sv_class;
  for (int i=0; i<n_sv; i++, sv_current += VEC_DIM){
    float coeff = coeffs [i];


    result += coeff * rbf_kernel(sv_current, sensors);

  }

  return result;

}
