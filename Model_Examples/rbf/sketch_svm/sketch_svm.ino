#include <avr/pgmspace.h>
#define VEC_DIM 9

#define SVM_TYPE c_svc
#define KERNEL_TYPE rbf
#define GAMMA 1
#define NR_CLASS 5
#define TOTAL_SV 34
const  PROGMEM float rho[] = {0.36276, 0.371906, 0.473969, 0.451522, 0.137938, 0.25699, 0.231955, 0.142067, 0.0977635, -0.0295956};
const int label[] = {0, 1, 2, 3, 4};
const int nr_sv[] = {5, 6, 8, 8, 7};
 const PROGMEM float yalpha1[5 * (NR_CLASS-1)] = {2.107335316049639, 0, 0.2964265104934171, 0.2295626192109151, 0.05271834980593445, 0.732576868565294, 0.1003888070674556, 0, 0.5958535967753404, 0.3937788597496962, 0.7819447269800799, 0.1095371855556466, 0, 0.6412513842416325, 0.4244461486714203, 0.7736147721476789, 0.1085783037267564, 0, 0.629383488716891, 0.4167085121221615}; 

 const PROGMEM float sv1[5 * VEC_DIM] = {0.114754, 0.583333, 0.676768, 0.676768, 0.547826, 0.622222, 0.655172, 0.666667, 0.52381, 0.0983607, 0.861111, 0.959596, 0.818182, 0.617391, 0.488889, 0.689655, 0.65, 0.67619, 0.0655738, 0.819444, 0.818182, 0.272727, 0.6, 0.6, 0.568966, 0.75, 0.942857, -0.0819672, 1, 0.959596, 0.434343, 0.513043, 0.533333, 0.534483, 0.766667, 1, 0.196721, 0.694444, 1, 0.555556, 0.46087, 0.533333, 0.551724, 1, 1}; 

 const PROGMEM float yalpha2[6 * (NR_CLASS-1)] = {0.05271834980593445, -0, -1.736859881676639, -0, -0, -0.3689736056802617, 0.3937788597496962, 0.2591110144046342, 0.8367291914326392, 0.6725956776744122, 0.03482470347779317, 0.7436913873588609, 0.4244461486714203, 0.2646118216882179, 0.8944199942693069, 0.581171811381979, 0.01491533353693937, 0.8116112072253026, 0.4167085121221615, 0.260659683970744, 0.8813026753556298, 0.542198226750192, 0.03873916724600095, 0.8058610806097716}; 

 const PROGMEM float sv2[6 * VEC_DIM] = {0.196721, 0.694444, 1, 0.555556, 0.46087, 0.533333, 0.551724, 1, 1, 0.47541, 0.0416667, 0.212121, 0.838384, 0.878261, 0.844444, 0.327586, -0.533333, 0.657143, 0.213115, 0.194444, 0.292929, 0.515152, 0.86087, 0.688889, 0.327586, 0.55, 0.333333, 0, -0.263889, 0.636364, 0.636364, 0.756522, 0.488889, 0.310345, -0.45, 0.580952, 0.180328, -0.166667, -0.0909091, 0.515152, 0.86087, 0.488889, 0.517241, -0.316667, 0.714286, 0.262295, 0.472222, -0.232323, 0.414141, 0.86087, 0.444444, 0.293103, -0.566667, 0.809524}; 

 const PROGMEM float yalpha3[8 * (NR_CLASS-1)] = {-0.3689736056802617, -0.580209308203005, -0.1093331482812802, -0.2916458132181204, -0.3582523908090453, -0.07469041930962894, -0, -0.4159890905458756, 0.7436913873588609, 0.09481529177328665, -0.2795322611114798, -0.5077933408456813, -0.4876216582817534, -0.05530164919925538, -0, -0.5712516571134669, 0.8116112072253026, 0.2223914172017729, 0, 0.8614699454524755, 0.7287595824479804, 0.114259993040315, 0.01592139013398465, 0.8852447089321018, 0.8058610806097716, 0.2295852587515451, 0.1677228201223715, 0.5573917025217557, 0.6785914797644198, 0.1349397367869411, 0, 0.7398007723265512}; 

 const PROGMEM float sv3[8 * VEC_DIM] = {0.262295, 0.472222, -0.232323, 0.414141, 0.86087, 0.444444, 0.293103, -0.566667, 0.809524, 0.180328, 0.138889, 0.757576, 0.818182, 0.791304, 0.488889, 0.362069, -0.45, 0.638095, 0.0327869, -0.555556, -0.292929, 0.555556, 0.617391, 0.466667, -0.551724, -0.216667, -0.180952, -0.0327869, -0.569444, 0.0707071, 0.272727, 0.478261, 0.355556, -0.603448, -0.35, -0.142857, -0.114754, -0.0277778, -0.79798, 0.373737, 0.513043, -0.266667, -0.517241, -0.883333, -0.828571, -0.0163934, -0.930556, -1, 0.292929, 0.443478, 0.2, -0.775862, -0.566667, -0.104762, -0.327869, -0.847222, -0.313131, 0.656566, 0.530435, 0.266667, -0.465517, -0.55, -0.0666667, -0.0983607, -0.847222, -0.89899, -0.414141, 0.391304, 0.111111, -0.931034, -0.833333, -0.390476}; 

 const PROGMEM float yalpha4[8 * (NR_CLASS-1)] = {-0.4159890905458756, -0.3557046763627751, -0.2169825936310607, -0.2392642548476636, -0.3445824527086725, -0.04679384247420697, -0.2528992036021554, -0.08260696393925036, -0.5712516571134669, -0.4470083254077771, -0.2932583741622123, -0.3387455342513581, -0.4866186030476229, -0.06331807761542517, -0.3572200832163284, -0.1150603039022681, 0.8852447089321018, 0.6316433502561769, 0.4442323857022434, -0.4354982715915861, -0.567134806996659, -0.03712121172034775, -0.4872541821309158, -0.04596503618660204, 0.7398007723265512, 0.6149817749924394, 0.3542761621387836, 0.4895181806153506, 0.6181825492132028, 0.1174651559860139, 0.4548917961099569, 0.138596628081939}; 

 const PROGMEM float sv4[8 * VEC_DIM] = {-0.0983607, -0.847222, -0.89899, -0.414141, 0.391304, 0.111111, -0.931034, -0.833333, -0.390476, -0.196721, -0.875, -0.252525, 1, 0.582609, 0.155556, -0.982759, -0.733333, -0.047619, 0, -0.472222, -0.858586, 0.656566, 0.408696, -0.422222, -1, -0.6, -0.714286, -0.836066, -0.625, -0.272727, -0.131313, -0.00869565, -0.955556, 0, -0.2, -0.447619, -0.52459, -0.361111, -0.171717, -1, -1, -0.933333, -0.689655, -0.45, 0.0857143, -0.459016, -0.513889, -0.292929, -0.79798, -1, -0.777778, -0.448276, -0.233333, 0.0666667, -0.819672, -0.263889, -0.212121, 0.111111, -0.513043, -0.355556, -0.689655, 0.116667, -0.295238, -0.918033, -0.944444, -0.414141, -0.69697, -0.217391, -1, -0.534483, -0.516667, -0.561905}; 

 const PROGMEM float yalpha5[7 * (NR_CLASS-1)] = {-0.08260696393925036, -0.2514909283334567, -0.3704326345542678, -0.3691091649891058, -0.2609971730793799, -0.305120280187051, -0.4167423330825637, -0.1150603039022681, -0.3551621174144381, -0.5216665302776792, -0.5513303355783986, -0.3612923799202565, -0.4267604336201976, -0.5892315361207794, -0.04596503618660204, -0.5834549771827471, -0.77770699261461, -0.74739587754181, -0.4718212422210239, -0.49409104193335, -0.6779610865489653, 0.138596628081939, 0.459624866262384, 0.7024049091483534, 0.6939734027006816, -0.5030685606396823, -0.5689412376525855, -0.781744048817286}; 

 const PROGMEM float sv5[7 * VEC_DIM] = {-0.918033, -0.944444, -0.414141, -0.69697, -0.217391, -1, -0.534483, -0.516667, -0.561905, -1, -1, -0.79798, -0.454545, -0.321739, -0.622222, -0.62069, -0.383333, -0.447619, -0.459016, -0.222222, 0.252525, -0.313131, -0.2, -0.422222, -0.896552, -0.65, -1, -0.557377, -0.402778, 0.373737, -0.353535, 0.0608696, -0.444444, -0.551724, -0.5, 0.466667, 0.508197, -0.583333, -0.515152, -0.636364, 0.408696, -0.0888889, 0.793103, -0.5, -0.67619, 0.622951, 0.583333, -0.030303, -0.292929, -0.026087, 0.866667, 0.706897, -0.916667, -0.771429, 1, 0.291667, -0.0909091, -0.717172, 1, 1, 0.62069, -0.966667, -0.6}; 

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