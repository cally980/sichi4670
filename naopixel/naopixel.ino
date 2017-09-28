/*
* 불빛을 키 색을 조정하여 만들 수 있는것 
*/
 
#include <Adafruit_NeoPixel.h>
 
#define PIN 6 // 네오픽셀의 Din을 아두이노 pin6에 연결한다.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800); // 제어하고자 하는 LED의 개수, 네오픽셀 Din에 연결한 핀 번호, 네오픽셀 색 종류

void setup() {
  strip.begin();  // strip 초기화
}

void loop() {

  strip.setPixelColor(0, strip.Color(25, 0, 85)); // 제어하고자 하는 해당 네오픽셀 번호, strip.color(R,G,B)의 조합으로 색 표현
  strip.setPixelColor(1, strip.Color(0, 60, 100)); //
  strip.setPixelColor(2, strip.Color(0, 128, 128)); //
  strip.setPixelColor(3, strip.Color(0, 100, 255)); //
  strip.setPixelColor(4, strip.Color(100, 255, 28)); //
  strip.setPixelColor(5, strip.Color(0, 100, 0)); //
  strip.setPixelColor(6, strip.Color(64, 64, 0)); //
  strip.setPixelColor(7, strip.Color(100, 0, 85)); //
  strip.setPixelColor(8, strip.Color(0, 0, 90)); //
  strip.show(); // strip에 지정된 색을 표현한다.

}

