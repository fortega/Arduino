#define INTERVAL 8
struct LED {
  int pin;
  int v;
};

LED leds[3];
int b,value, sLed;

void setup()
{
  leds[0].pin = 9;
  leds[0].v = 0;
  
  leds[1].pin = 10;
  leds[1].v = 0;
  
  leds[2].pin = 11;
  leds[2].v = 0;
  
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available() == 4)
  {
    b = Serial.read();    
    value =  Serial.read();
    
    sLed = -1;
    switch(b)
    {
      case 'r':
        sLed = 0;
        break;
      case 'g':
        sLed = 1;
        break;
      case 'b':
        sLed = 2;
        break;
    }
    if(sLed != -1)
    {
      leds[sLed].v = value;
    }
  }
  writeLed();
}

void writeLed(){
  for(int i = 0; i < 3; i++)
  {
    writePin(leds[i].pin, leds[i].v);
  }
}

void writePin(int pin, int v){
  analogWrite(pin,v);
}
