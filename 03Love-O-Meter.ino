/*materials:
- arduino board
- 3 leds (cathode-short leg- to resistor and anode- long leg- to ground)
- wires (get a few)
- 3 220 ohm resistors
- 1 low voltage temp sensor (TMP36)

once the program is uploaded, tough the low voltage temp sensor to
get the leds to light up (warmer you are, more leds light up)
*/

//pin the sensor is connected to
const int sensorPin = A0;
//temp in cel
const float baselineTemp = 20.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for(int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //reads analog pin
  int sensVal = analogRead(sensorPin);

  //sends sens val to serial port
  Serial.print("sensor value: ");
  Serial.print(sensVal);

  //converts adc to voltage
  float volt = (sensVal/1024.0)*5.0;

  //voltage to serial port
  Serial.print(", Volts: ");
  Serial.print(volt);

  //far-->cel
  Serial.print(", degrees C: ");
  float temp = (volt-0.5)*100;
  Serial.println(temp);

  //which leds are switched on/off
  if(temp < baselineTemp+2){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);    
  }

  else if(temp >= baselineTemp+2 && temp < baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }

  else if(temp >= baselineTemp+4 && temp < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }

  else if(temp >= baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
}