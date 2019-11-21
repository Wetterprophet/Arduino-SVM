#define VEC_DIM 7

#define SVM_TYPE c_svc
#define KERNEL_TYPE rbf
#define GAMMA 0.14285714285714285
#define NR_CLASS 5
#define TOTAL_SV 20
const  float rho[] = {0.018901336564369316, -0.044189336281644329, -0.20305288345592842, -0.10140090068353252, 0.16983355581760406, -0.11423281235413102, -0.030941089320256715, -0.13830622848489729, -0.12819972634315491, 0.00044327974319458008};
const int label[] = {1, 2, 3, 4, 5};
const int nr_sv[] = {4, 4, 4, 4, 4};
 const float yalpha1[4 * (NR_CLASS-1)] = {0.32977838014608579, 0.11170933889147759, 1, 1, 0.37618125078601716, 0, 1, 0.79895917803107852, 0.23003299488143936, 0, 0.77509125567194415, 0.61650136913289189, 0.20405972066006828, 0, 1, 0.73470344737297766}; 

 const float sv1[4 * VEC_DIM] = {-0.586207, -0.406162, -0.296625, -0.93254, 0.50152, -0.545946, -1, 0.172414, -0.602241, -0.463588, -0.829365, 0.604863, 0.32973, -0.945854, -0.724138, -0.663866, -0.332149, -0.781746, 1, -0.783784, -0.58714, 1, -0.411765, -0.715808, -1, 0.428571, 1, -0.79357}; 

 const float yalpha2[4 * (NR_CLASS-1)] = {-0.63668244247180394, -0, -0.8048052765657594, -1, 1, 1, 1, 1, 0.73672486319943553, 0, 1, 0.520902645216479, 0.89170547674523459, 0.91390165404696588, 1, 0.26985099467140433}; 

 const float sv2[4 * VEC_DIM] = {-0.586207, -0.955182, -0.325044, 0.968254, 0.477204, -0.632432, 0.529611, 0.103448, -0.473389, -0.829485, 1, 0.927052, 0.0702703, 0.712352, -0.655172, -0.355742, -0.101243, 0.694444, 0.325228, -0.664865, 0.945854, 0.793103, -1, -1, 0.710317, 0.513678, 0.913514, 0.692047}; 

 const float yalpha3[4 * (NR_CLASS-1)] = {-0, -0.92434626942578935, -0.25079415939130623, -1, -1, -1, -1, -1, 1, 0.34567601910200108, 1, 0.5947921165670268, 1, 1, 1, 1}; 

 const float sv3[4 * VEC_DIM] = {0.103448, -0.00280112, 0.634103, 0.928571, 0.75076, 0.156757, 0.77665, 0.448276, -0.0980392, 0.250444, 0.988095, 0.920973, 0.113514, 0.979695, -0.862069, -0.563025, 0.669627, 0.825397, 0.227964, -0.913514, 0.671743, -0.931034, -0.77591, 0.641208, 0.555556, 0.878419, -0.924324, 0.658206}; 

 const float yalpha4[4 * (NR_CLASS-1)] = {-0, -1, -0.6216256196862755, -0, -0, -1, -0.7492733251914484, -0.50835418322446624, -0, -1, -1, -0.94046813566902787, 0.97041622505593228, 1, 1, 1}; 

 const float sv4[4 * VEC_DIM] = {-0.172414, 1, 0.886323, 0.68254, -1, -0.459459, 0.915398, -0.517241, 0.579832, 0.626998, 0.396825, -0.568389, -0.232432, 1, -0.517241, 0.753501, 1, 0.587302, -0.525836, -0.935135, 0.722504, -1, 0.686275, 0.982238, 0.734127, -0.641337, -0.805405, 0.92555}; 

 const float yalpha5[4 * (NR_CLASS-1)] = {-0, -0, -1, -0.93876316803304583, -0.075458125463604794, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -0.97041622505593228}; 

 const float sv5[4 * VEC_DIM] = {-0.310345, 0.714286, 0.754885, 0.865079, 0.191489, -0.502703, 0.837563, -0.172414, 0.579832, 0.754885, 0.821429, 0.647416, -0.243243, 0.8511, -1, 0.383754, 0.861456, 0.670635, 0.458967, -1, 0.661591, 0.310345, 0.697479, 0.705151, 0.757937, 0.702128, -0.00540541, 0.790186}; 

const int scalePar[] = {-1,1};
const int low[] = {218,427,457,513,547,671,383};
const int high[] = {247,784,1020,1017,876,856,974};  
int result[NR_CLASS]={0};

 float const* const supportVectors[NR_CLASS] = {
sv1, sv2, sv3, sv4, sv5, };
 const float* const valuesForSupport[NR_CLASS] = {
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


      float* sv_class1 = (float*) supportVectors [i];
      float* sv_class2 = (float*) supportVectors [j];
      float* coeffs1   = (float*) valuesForSupport [i] + nr_sv[i] * (j-1);
     float* coeffs2   = (float*) valuesForSupport [j] + nr_sv[j] * i;


      accumulator += svm_evaluate(nr_sv[i], coeffs1, sv_class1, scaledSensor);
      accumulator += svm_evaluate(nr_sv[j], coeffs2, sv_class2, scaledSensor);


      float rhoNr = rho [rhoCounter];
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
