#include <ArduinoJson.h>

// here the data is measured which should be predicted by the SVM
float sensor1, sensor2, sensor3, sensor4, sensor5, sensor6, sensor7, sensor8, sensor9, sensor10;
int action = 0;
boolean measuring = true;
char inputCsvString[1000];
char state = 'U';
char pins[20] = {};
const int buffSize = 1000;
char inputSeveral[buffSize];
#include <Arduino_LSM9DS1.h>
float MagX, MagY, MagZ;
const int flexsensors = 7;
const int sensorDataSize = (flexsensors+3);

void setup(){
    Serial.begin(9600);

}

void loop(){
  StaticJsonBuffer<1000> jsonBuffer;
  if(Serial.available() > 0){
    readCSV();
    JsonObject& parsed = jsonBuffer.parseObject("{\"state\":\"T\",\"InPins\":[0,1,2,3,4,5,6,7],\"ToggelOutPins\":[5,8],\"sequencielWait\":500,\"measurementWait\":500,\"sequenciellReads\":[7]}");
    // Test if parsing succeeds.
    if (!parsed.success()) {
      Serial.println("parseObject() failed");
    } else {
      const char* state = parsed["state"];
      if(state[0] == 'T'){
        // do the input setting
        int arraySizeIn =  flexsensors;
        int inPins[arraySizeIn];

        for (int i = 0; i< flexsensors; i++){

          pinMode(i, INPUT);
        }






        }
        // we are clearing the JSON Buffer, since we have all data that we need.
        jsonBuffer.clear();


          int sensoreReads[10];


          for(int i = 0; i< arraySizeSequenciellReads; i++){
            for(int j = 0; y<flexsensors; j++){
              sensoreReads[j]= analogRead(inPins[j]);
            }
            IMU.readMagneticField(MagX, MagY, MagZ);
            sensoreReads[flexsensors]=MagX;
            sensoreReads[(flexsensors+1)]=MagY;
            sensoreReads[(flexsensors+2)]=MagZ;

            delay(500);
          }
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
              delay(500);




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
