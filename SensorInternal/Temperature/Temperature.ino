/* 
 *  https://circuits4you.com
 *  ESP32 Internal Temperature Sensor Example
 */

 #ifdef __cplusplus
  extern "C" {
 #endif

  uint8_t temprature_sens_read();

#ifdef __cplusplus
}
#endif

uint8_t temprature_sens_read();
//====================================================
//         Setup
//====================================================
void setup() {
  Serial.begin(115200);
}

//====================================================
//         Loop
//====================================================
void loop() {
  Serial.print("Temperature: ");
  
  // Convert raw temperature in F to Celsius degrees
  Serial.print((temprature_sens_read() - 32) / 1.8);
  Serial.println(" C");
  for (int i=0; i<100000000;i++){
    int a = a+i;
    for (int j=0;j<100000000;j++){
      int b = b+j;
    }
  }
}
