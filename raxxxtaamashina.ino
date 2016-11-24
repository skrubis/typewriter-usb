/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/
#include <Keyboard.h>
// the setup routine runs once when you press reset:

#define BUCKET_SIZE 20
float values[BUCKET_SIZE];

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  memset(values, 0, sizeof(values));
}

// the loop routine runs over and over again forever:


void loop() {
  static float filtered_val = 0.0f;
  static float prev_filtered_val = 0.0f;
  static float triggered_val = 0.0f;
  
  static uint8_t settle_counter=0;
  delayMicroseconds(10);
  float read_val = analogRead(A3);

  static uint8_t idx=0;
  float avg_val = 0.0f;
  values[idx] = read_val;
  idx++;
  
  if (idx >= BUCKET_SIZE)
    idx = 0;

  
  for (uint16_t i = 0; i < BUCKET_SIZE; i++) {
    avg_val += values[i];
  }
  avg_val = avg_val / BUCKET_SIZE;
  if (avg_val < 15)
    triggered_val = 0.0f;
  if (abs(prev_filtered_val - avg_val) < 5) {
    settle_counter++;
  } else {
    settle_counter = 0;
    prev_filtered_val = avg_val;
  }

  if (settle_counter < 50)
    return;

  if (abs(triggered_val - avg_val) < 5) {
    settle_counter = 0;
    return;
  }
  triggered_val = avg_val;

  
  int key = round(avg_val);
  Serial.println(key);

  // read the input on analog pin 0:
  //int key = analogRead(A3);
  //delay(20);
  //int keyd = analogRead(A3);
  //if ((key - keyd < 5 && key + keyd < 5))key = 0;
  // print out the value you read:

  //delay(1);
  int delayValue = 10;

  switch (key) {
    case 17 ... 25: 
      Keyboard.write(10); delay(delayValue);//enter
      break;
    case 42 ... 50: 
      Keyboard.write(8); delay(delayValue);//backspace
      break;
    case 65 ... 73: 
      Keyboard.write(' '); delay(delayValue);
      break;
    case 89 ... 97: 
      Keyboard.write('¾'); delay(delayValue);
      break;
    case 112 ... 120: 
      Keyboard.write(';'); delay(delayValue);
      break;
    case 136 ... 144: 
      Keyboard.write('p'); delay(delayValue);
      break;
    case 159 ... 167: 
      Keyboard.write('.'); delay(delayValue);
      break;
    case 183 ... 192: 
      Keyboard.write('0'); delay(delayValue);
      break;
    case 207 ... 215: 
      Keyboard.write('l'); delay(delayValue);
      break;
    case 232 ... 240: 
      Keyboard.write('o'); delay(delayValue);
      break; 
    case 255 ... 264: 
      Keyboard.write(','); delay(delayValue);
      break;
    case 278 ... 287: 
      Keyboard.write('9'); delay(delayValue);
      break; 
    case 301 ... 309: 
      Keyboard.write('k'); delay(delayValue);
      break;
    case 325 ... 333: 
      Keyboard.write('i'); delay(delayValue);
      break; 
    case 347 ... 356: 
      Keyboard.write('m'); delay(delayValue);
      break;
    case 372 ... 380: 
      Keyboard.write('8'); delay(delayValue);
      break; 
    case 395 ... 403: 
      Keyboard.write('j'); delay(delayValue);
      break;
    case 419 ... 427: 
      Keyboard.write('u'); delay(delayValue);
      break;
    case 444 ... 452: 
      Keyboard.write('n'); delay(delayValue);
      break;
    case 466 ... 474: 
      Keyboard.write('7'); delay(delayValue);
      break;
    case 490 ... 498: 
      Keyboard.write('h'); delay(delayValue);
      break;
    case 514 ... 523: 
      Keyboard.write('y'); delay(delayValue);
      break;
    case 537 ... 546: 
      Keyboard.write('b'); delay(delayValue);
      break;
    case 562 ... 570: 
      Keyboard.write('6'); delay(delayValue);
      break;  
    case 584 ... 593: 
      Keyboard.write('g'); delay(delayValue);
      break;
    case 608 ... 616: 
      Keyboard.write('t'); delay(delayValue);
      break; 
    case 632 ... 642: 
      Keyboard.write('v'); delay(delayValue);
      break;
    case 656 ... 664: 
      Keyboard.write('5'); delay(delayValue);
      break; 
    case 678 ... 688: 
      Keyboard.write('f'); delay(delayValue);
      break;
    case 703 ... 712: 
      Keyboard.write('r'); delay(delayValue);
      break; 
    case 726 ... 735: 
      Keyboard.write('c'); delay(delayValue);
      break;
    case 753 ... 760: 
      Keyboard.write('4'); delay(delayValue);
      break;
    case 775 ... 784: 
      Keyboard.write('d'); delay(delayValue);
      break;
    case 796 ... 815: 
      Keyboard.write('e'); delay(delayValue);
      break;
    case 822 ... 832: 
      Keyboard.write('x'); delay(delayValue);
      break;
    case 847 ... 856: 
      Keyboard.write('3'); delay(delayValue);
      break;
    case 871 ... 880: 
      Keyboard.write('s'); delay(delayValue);
      break;
    case 896 ... 907: 
      Keyboard.write('w'); delay(delayValue);
      break;
    case 920 ... 930: 
      Keyboard.write('z'); delay(delayValue);
      break;
    case 945 ... 954: 
      Keyboard.write('2'); delay(delayValue);
      break;  
    case 969 ... 981: 
      Keyboard.write('a'); delay(delayValue);
      break;
    case 995 ... 1004: 
      Keyboard.write('q'); delay(delayValue);
      break; 
    case 1017 ... 1024: 
      Keyboard.write('1'); delay(delayValue);
      break;
    
    default: 
      // if nothing else matches, do the default
      // default is optional
    break;
  }
}
