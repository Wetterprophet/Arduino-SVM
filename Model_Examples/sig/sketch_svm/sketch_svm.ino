#if (defined(__AVR__))
#include <avr\pgmspace.h>
#else
#include <pgmspace.h>
#endif
#define VEC_DIM 9

#define SVM_TYPE c_svc
#define KERNEL_TYPE sigmoid
#define GAMMA 0.111111
#define COEF0 0
#define NR_CLASS 5
#define TOTAL_SV 44
const  PROGMEM float rho[] = {0.660523, 0.247178, 0.19397, 0.256064, -0.0561636, 0.0215861, -0.0917099, 0.0323295, 0.0241942, -0.0793826};
const int label[] = {0, 1, 2, 3, 4};
const int nr_sv[] = {8, 9, 9, 8, 10};
 const PROGMEM float yalpha1[8 * (NR_CLASS-1)] = {1, 1, 1, 0.5908915908032174, 1, 1, 1, 1, 1, 0.3801888895120982, 0, 0, 0, 0.3180633214857793, 1, 0, 1, 0, 0, 0, 0, 1, 0.3133207468729625, 0, 1, 0.9727535880815427, 0, 0, 0, 1, 0, 0};

 const PROGMEM float sv1[8 * VEC_DIM] = {0.114754, 0.583333, 0.676768, 0.676768, 0.547826, 0.622222, 0.655172, 0.666667, 0.52381, 0.0983607, 0.791667, 0.79798, 0.717172, 0.6, 0.555556, 0.741379, 0.716667, 0.790476, 0.0983607, 0.861111, 0.959596, 0.818182, 0.617391, 0.488889, 0.689655, 0.65, 0.67619, 0.0819672, 0.805556, 1, 0.494949, 0.478261, 0.511111, 0.62069, 0.816667, 1, 0.147541, 0.902778, 0.919192, 0.515152, 0.617391, 0.511111, 0.603448, 0.766667, 0.92381, 0.0655738, 0.819444, 0.818182, 0.272727, 0.6, 0.6, 0.568966, 0.75, 0.942857, 0.0819672, 0.75, 0.919192, 0.59596, 0.513043, 0.555556, 0.517241, 0.766667, 0.885714, 0.213115, 0.847222, 0.919192, 0.616162, 0.46087, 0.711111, 0.431034, 0.85, 0.980952};

 const PROGMEM float yalpha2[9 * (NR_CLASS-1)] = {1, -1, -1, -1, -1, -0.5908915908032173, -1, -0, -1, 0, 0, 0.4382504803351162, 1, 1, 1, 1, 1, 0.4014894348441783, 0, 0, 0.4395151718971399, 0.7714643387169527, 1, 1, 0, 0.1714104528089549, 0, 0, 0, 0.6513823177726588, 0, 0.6769957431113649, 1, 1, 1, 1};

 const PROGMEM float sv2[9 * VEC_DIM] = {0.213115, 0.847222, 0.919192, 0.616162, 0.46087, 0.711111, 0.431034, 0.85, 0.980952, 0.42623, 0.0972222, 0.353535, 0.959596, 0.773913, 0.688889, 0.362069, -0.483333, 0.638095, 0.213115, 0.194444, 0.292929, 0.515152, 0.86087, 0.688889, 0.327586, 0.55, 0.333333, 0.0327869, -0.111111, 0.616162, 0.757576, 0.791304, 0.488889, 0.310345, -0.5, 0.561905, 0, -0.263889, 0.636364, 0.636364, 0.756522, 0.488889, 0.310345, -0.45, 0.580952, 0.131148, 0.0555556, 0.0707071, 0.353535, 0.86087, 0.377778, 0.327586, -0.45, 0.657143, 0.311475, 0.194444, 0.272727, 0.575758, 0.913043, 0.844444, 0.0862069, -0.4, 0.6, 0.180328, -0.166667, -0.0909091, 0.515152, 0.86087, 0.488889, 0.517241, -0.316667, 0.714286, 0.262295, 0.472222, -0.232323, 0.414141, 0.86087, 0.444444, 0.293103, -0.566667, 0.809524};

 const PROGMEM float yalpha3[9 * (NR_CLASS-1)] = {-1, -1, -1, -1, -0, -0, -0, -0.6982522109978776, -0, 0.4014894348441783, 0, -1, -1, -0, -0.8397399151792945, -1, -1, -0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0.3616923704127539, 0, 1};

 const PROGMEM float sv3[9 * VEC_DIM] = {0.262295, 0.472222, -0.232323, 0.414141, 0.86087, 0.444444, 0.293103, -0.566667, 0.809524, 0.180328, 0.138889, 0.757576, 0.818182, 0.791304, 0.488889, 0.362069, -0.45, 0.638095, 0.0327869, -0.555556, -0.292929, 0.555556, 0.617391, 0.466667, -0.551724, -0.216667, -0.180952, -0.0327869, -0.569444, 0.0707071, 0.272727, 0.478261, 0.355556, -0.603448, -0.35, -0.142857, -0.114754, -0.0277778, -0.79798, 0.373737, 0.513043, -0.266667, -0.517241, -0.883333, -0.828571, 0.147541, -0.541667, -0.717172, 0.313131, 0.46087, 0.111111, -0.482759, -0.583333, -0.638095, -0.229508, -0.916667, -0.676768, 0.212121, 0.530435, 0.444444, -0.637931, -0.583333, -0.0666667, -0.327869, -0.847222, -0.313131, 0.656566, 0.530435, 0.266667, -0.465517, -0.55, -0.0666667, -0.0983607, -0.847222, -0.89899, -0.414141, 0.391304, 0.111111, -0.931034, -0.833333, -0.390476};

 const PROGMEM float yalpha4[8 * (NR_CLASS-1)] = {-0, -0, -0, -0, -0.3133207468729625, -0, -0, -1, -0, -1, -0, -0, -1, -0, -0, -1, 1, 0, 1, -1, -1, -0, -1, -1, 1, 0, 0, 1, 1, 0.7352540059550801, 0, 0};

 const PROGMEM float sv4[8 * VEC_DIM] = {-0.0983607, -0.847222, -0.89899, -0.414141, 0.391304, 0.111111, -0.931034, -0.833333, -0.390476, -0.196721, -0.875, -0.252525, 1, 0.582609, 0.155556, -0.982759, -0.733333, -0.047619, 0, -0.472222, -0.858586, 0.656566, 0.408696, -0.422222, -1, -0.6, -0.714286, -0.885246, -0.638889, -0.474747, -0.353535, -0.252174, -0.933333, -0.137931, -0.45, -0.542857, -0.836066, -0.625, -0.272727, -0.131313, -0.00869565, -0.955556, 0, -0.2, -0.447619, -0.459016, -0.513889, -0.292929, -0.79798, -1, -0.777778, -0.448276, -0.233333, 0.0666667, -0.918033, -0.513889, -0.373737, -0.292929, -0.321739, -0.466667, -0.517241, 0.166667, -0.504762, -0.819672, -0.263889, -0.212121, 0.111111, -0.513043, -0.355556, -0.689655, 0.116667, -0.295238};

 const PROGMEM float yalpha5[10 * (NR_CLASS-1)] = {-1, -0, -0, -1, -0, -0.4566853256751703, -0, -1, -0.5160682624063724, -0, -1, -0, -0.3823899634230476, -1, -0, -0, -1, -1, -1, -0, -1, -1, -1, -1, -1, -0, -0, -1, -0.3616923704127539, -0, 0, 0, 1, 1, -1, -0, -0, -0, -1, -1};

 const PROGMEM float sv5[10 * VEC_DIM] = {-0.819672, -0.263889, -0.212121, 0.111111, -0.513043, -0.355556, -0.689655, 0.116667, -0.295238, -1, -1, -0.79798, -0.454545, -0.321739, -0.622222, -0.62069, -0.383333, -0.447619, -0.459016, -0.222222, 0.252525, -0.313131, -0.2, -0.422222, -0.896552, -0.65, -1, -0.557377, -0.402778, 0.373737, -0.353535, 0.0608696, -0.444444, -0.551724, -0.5, 0.466667, 0.508197, -0.583333, -0.515152, -0.636364, 0.408696, -0.0888889, 0.793103, -0.5, -0.67619, 0.622951, 0.583333, -0.030303, -0.292929, -0.026087, 0.866667, 0.706897, -0.916667, -0.771429, 1, 0.291667, -0.0909091, -0.717172, 1, 1, 0.62069, -0.966667, -0.6, 0.57377, 0.319444, -0.252525, -0.515152, 0.373913, 0.422222, 0.603448, -0.666667, -0.447619, 0.278689, 0.180556, 0.030303, -0.373737, 0.356522, -0.577778, 0.862069, -0.7, -0.619048, 0.459016, -0.0972222, -0.232323, -0.757576, -0.113043, 0.0666667, 0.965517, -0.416667, -0.352381};

const int scalePar[] = {-1,1};
const int low[] = {517,544,543,546,733,576,552,526,552};
const int high[] = {639,688,642,645,848,666,668,646,657};
int result[NR_CLASS]={0};

 float const* const supportVectors[NR_CLASS] PROGMEM = {
sv1, sv2, sv3, sv4, sv5, };
 const float* const valuesForSupport[NR_CLASS] PROGMEM = {
yalpha1, yalpha2, yalpha3, yalpha4, yalpha5, };

void scale(const int* sensor, float* scaledSensor){
  for(int p=0; p<VEC_DIM;p++){
    scaledSensor[p] = (float)scalePar[0] +((float)scalePar[1] -((float)scalePar[0]))*((float)sensor[p]-(float)low[p])/((float)high[p]-(float)low[p]);
  }
}

inline void svm_predict(int sensor[]){
  int recognizedClass = 1;
  float scaledSensor[VEC_DIM];
  scale(sensor,scaledSensor);
  int rhoCounter = 0;


  for(int i=0; i<NR_CLASS; i++){
    for(int j=i+1; j<NR_CLASS; j++){
      float accumulator = 0;


      float* sv_class1 = (float*) pgm_read_word(supportVectors + i);
      float* sv_class2 = (float*) pgm_read_word(supportVectors + j);
      float* coeffs1   = (float*) pgm_read_word(valuesForSupport + i) + nr_sv[i] * (j-1);
     float* coeffs2   = (float*) pgm_read_word(valuesForSupport + j) + nr_sv[j] * i;


      accumulator += svm_evaluate(nr_sv[i], coeffs1, sv_class1, scaledSensor);
      accumulator += svm_evaluate(nr_sv[j], coeffs2, sv_class2, scaledSensor);


      float rhoNr = pgm_read_float(rho + rhoCounter);
      accumulator -= rhoNr;


      if (accumulator > 0) {
        result[i]++;
      } else {
        result[j]++;
      }
      rhoCounter++;
    }
  }


  int temp = 0;
  for(int t = 0; t < NR_CLASS; t++){
    if(result[temp] <= result[t]){
      recognizedClass = t;
      temp = t;
    }
  }


  Serial.println(recognizedClass, DEC);
  delay(500);
  for(int q = 0; q < NR_CLASS; q++){
    result[q]=0;
  }
}
