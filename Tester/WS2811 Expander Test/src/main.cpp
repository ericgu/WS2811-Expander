#include <Arduino.h>
#include <NeoPixelBus.h>

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> *_pStrip;

const int LED = 2;

void setup()
{
  Serial.begin(115200);

  _pStrip = new NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>(1);

  _pStrip->Begin();

  pinMode(LED, OUTPUT);

  // put your setup code here, to run once:
}

void UpDown(int redDelta, int greenDelta, int blueDelta)
{
  int red = 0;
  int green = 0;
  int blue = 0;

  digitalWrite(LED, LOW);
  Serial.println("ON");
  for (int j = 0; j < 256; j++)
  {
    _pStrip->SetPixelColor(0, RgbColor(red, green, blue));
    _pStrip->Show();
    red += redDelta;
    green += greenDelta;
    blue += blueDelta;
    delay(1);
  }

  digitalWrite(LED, HIGH);
  Serial.println("OFF");
  for (int j = 255; j >= 0; j--)
  {
    _pStrip->SetPixelColor(0, RgbColor(red, green, blue));
    _pStrip->Show();
    red -= redDelta;
    green -= greenDelta;
    blue -= blueDelta;
    delay(1);
  }
}

void loop()
{
  UpDown(1, 0, 0);
  UpDown(0, 1, 0);
  UpDown(0, 0, 1);
  UpDown(1, 1, 1);
}