#include <OneWire.h>
#include <DallasTemperature.h>
//#include <math.h>

OneWire oneWire1(4);
DallasTemperature tempSensor(&oneWire1);
OneWire oneWire2(2);
DallasTemperature tempSensor(&oneWire2);
float td;
float tw;
double e = 2.71828182845904;
double N = 0.6687451584;
float k = 6.112;
float k1 = 17.502 * td;
float k2 = 240.97 + td;
float k3 = 17.502 * tw;
float k4 = 240.97 + tw;
double ed = k * pow(e,(k1/k2));

double ew = k*pow(e,(k3/k4));
double RH = ((ew-(N*(1+(0.00115*tw))*(td-tw))*100)/ed);

  
void setup(void)
{
  
  Serial.begin(115200);
  tempSensor1.begin();
  tempSensor2.begin();
  

}
  
void loop(void)
{
  td = tempSensor1.requestTemperaturesByIndex(0);
  
  Serial.print("Temperature 1: ");
  Serial.print(tempSensor.getTempCByIndex(0));
  Serial.println(" C");

  tw = tempSensor2.requestTemperaturesByIndex(0);
  
  Serial.print("Temperature 2: ");
  Serial.print(tempSensor.getTempCByIndex(0));
  Serial.println(" C");

  //Serial.print(RH);
  Serial.println(ed);
  Serial.println("\n");
  Serial.println(ew);
  
  delay(2000);
}
