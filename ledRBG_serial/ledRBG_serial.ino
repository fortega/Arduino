#define INTERVAL 8
struct LED {
  int pin;
  int v;
};

LED leds[3];
int b[3];
int value, sLed;

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
    b[0] = Serial.read();
    
    for(int i = 1; i <= 3; i++)
    {
      b[i] = Serial.read();
      b[i] -= 48;
    }
    
    value = (b[1]*100) + (b[2]*10) + b[3];
    if(value >= 0 && value <= 255)
    {
      sLed = -1;
      switch(b[0])
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
        default:
          Serial.print("ErrorLED");
          Serial.println(b[0]);
      }
      
      if(sLed != -1)
      {
        leds[sLed].v = value;
        Serial.print("p");
        Serial.print(leds[sLed].pin);
        Serial.print(" ");
        Serial.print("v");
        Serial.println(value);
      }
    }else{
      Serial.print("ErrorValue");
      Serial.println(value);
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
