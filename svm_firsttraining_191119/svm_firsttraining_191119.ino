#include <ArduinoJson.h>

// here the data is measured which should be predicted by the SVM
int sensor1, sensor2, sensor3, sensor4, sensor5;
int sensor6, sensor7, sensor8, sensor9;
int action = 0;
boolean measur = true;
char inputCsvString[1000];
char state = 'U';
char pins[20] = {};
const int buffSize = 1000;
char inputSeveral[buffSize];



void setup(){
    Serial.begin(9600);

}

void loop(){
  StaticJsonBuffer<1000> jsonBuffer;
  if(Serial.available() > 0){
    readCSV();
    JsonObject& parsed = jsonBuffer.parseObject("{\"state\":\"T\",\"InPins\":[0,1,2,3,4,5,6],\"ToggelOutPins\":[5,8],\"sequencielWait\":500,\"measurementWait\":500,\"sequenciellReads\":[7]}");
    // Test if parsing succeeds.
    if (!parsed.success()) {
      Serial.println("parseObject() failed");
    } else {
      const char* state = parsed["state"];
      if(state[0] == 'T'){
        // do the input setting
        int arraySizeIn =  parsed["InPins"].size();
        int inPins[arraySizeIn];

        for (int i = 0; i< arraySizeIn; i++){
          int pin=parsed["InPins"][i];
          inPins[i] = pin;
          pinMode(pin, INPUT);
        }
        // do the output setting
        int arraySizeOut =  parsed["ToggelOutPins"].size();
        int outPins[arraySizeOut];
        for (int i = 0; i< arraySizeOut; i++){
          int pin=parsed["ToggelOutPins"][i];
          outPins[i] = pin;
          pinMode(pin, OUTPUT);
        }
        int sequencielWait = parsed.get<int>("sequencielWait");
        int measurementWait = parsed.get<int>("measurementWait");
        // read in the ammount of pins read pertoggel round
        int arraySizeSequenciellReads =  parsed["sequenciellReads"].size();
//        Serial.print(arraySizeSequenciellReads);
        int sequenciellReads[arraySizeSequenciellReads];
        int sensorDataSize = 0;
        for (int i = 0; i< arraySizeSequenciellReads; i++){
          int reads=parsed["sequenciellReads"][i];
          sequenciellReads[i] = reads;
          sensorDataSize += reads;
        }
        // we are clearing the JSON Buffer, since we have all data that we need.
        jsonBuffer.clear();


      //z98zu  while(Serial.available()<= 0){
          int sensoreReads[sensorDataSize];
          int currentOut = 0;
          int dataSize = 0;


          for(int i = 0; i< arraySizeSequenciellReads; i++){
            for(int y = 0; y<sequenciellReads[i]; y++){
              sensoreReads[dataSize]= analogRead(inPins[y]);
              dataSize ++;
            }
            for(int k = 0; k< arraySizeOut; k++){
               digitalWrite(outPins[k],LOW);
            }
            digitalWrite(outPins[currentOut],LOW);
            currentOut ++;
            delay(sequencielWait);
          }
          currentOut = 0;
          dataSize = 0;
            Serial.println();
            Serial.print(inputSeveral[0]);
            Serial.print(" ");
            for(int i = 0; i< sensorDataSize; i++){

              Serial.print(i+1);
              Serial.print(": ");
              Serial.print(sensoreReads[i]);
              Serial.print(" ");
              }
              //Serial.print("]]");
              delay(measurementWait);

    //    }


   } else if (state[0] == 'R'){

    }

    }
}
}



    void readCSV() {
    inputSeveral[0] = 0;
    int maxChars = 4000 - 1; // use full size of buffer for this function
    byte charCount = 0;
    byte ndx = 0;

    if (Serial.available() > 0) {
      while (Serial.available() > 0) {

        if(sizeof(inputSeveral)>2) {
          inputSeveral[ndx] = Serial.read();
        }
        ndx ++;
        charCount ++;
      }
    }

}
