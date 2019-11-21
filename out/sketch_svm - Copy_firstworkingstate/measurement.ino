 // In this section you should implement the handling of your sensor data, which you would like to classify.
 // and an example would be:

 int sensor1, sensor2, sensor3, sensor4, sensor5, sensor6, sensor7;

 void setup(){
  Serial.begin(9600);
}

void loop(){

  sensor1 = analogRead(0);
  sensor2 = analogRead(1);
  sensor3 = analogRead(2);
  sensor4 = analogRead(3);
  sensor5 = analogRead(4);
  sensor6 = analogRead(5);
  sensor7 = analogRead(6);
  delay(600);
 int  sensors[7]= {sensor1, sensor2, sensor3, sensor4, sensor5, sensor6, sensor7};

  svm_predict(sensors);
}
