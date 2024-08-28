#include <M5StickCPlus.h>


int stepCount = 0;

void setup() {
  M5.begin();

  if (M5.IMU.Init()) { // -1: failed?
    M5.Lcd.fillScreen(RED);
  } else {
    M5.Lcd.fillScreen(BLACK);
  }

  M5.Lcd.setTextSize(4);
  M5.Lcd.setRotation(3);
  M5.Lcd.print(" In-Pocket");
  M5.Lcd.println();
  M5.Lcd.print(" Pedometer");
  M5.Lcd.println();
  M5.Lcd.println();
  M5.Lcd.setTextSize(2);
  M5.Lcd.print(" Measuring will");
  M5.Lcd.println();
  M5.Lcd.print(" start in 5 seconds.");
  delay(5000);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(3);
}

void loop() {
  float accX, accY, accZ;

  M5.IMU.getAccelData(&accX, &accY, &accZ);

  if (abs(accX) > 1.6) {
    stepCount++;
    delay(300);
  }
  
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.println();
  M5.Lcd.println();
  M5.Lcd.println();
  M5.Lcd.println();
  M5.Lcd.printf(" Step: %d\n", stepCount);

}
