
#include "CMLib.h" 
EnergyMonitor cm1;

void setup()
{    
  Serial.begin(9600); 
  cm1.current(1, 120); // Current: input pin, calibration.
}

void loop()
{
  double Irms = cm1.calcIrms(1450)-.55; // Clac Irms: num of reads - an offset

  if(Irms<0.04){ //readings under 0.04 is assumed noise
    Irms = 0;
  }
  Serial.println(Irms*115.0); // current x voltage
}
