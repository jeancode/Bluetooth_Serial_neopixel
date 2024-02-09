#include <BluetoothSerial.h>
#include <Adafruit_NeoPixel.h>


#define PIN  15    
#define NUMPIXELS 16

BluetoothSerial SerialBT;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

typedef void (*RGBCallback)(int, int, int);

void extraerRGB(const char* inputString, void (*callback)(int, int, int)) {
  // Buscar índices de las letras r, g, b
  int indiceR = indexOf(inputString, "r:");
  int indiceG = indexOf(inputString, "g:");
  int indiceB = indexOf(inputString, "b:");

  // Extraer substrings que contienen los valores de r, g, b
  char valorR[4], valorG[4], valorB[4];
  strncpy(valorR, inputString + indiceR + 2, indiceG - indiceR - 2);
  strncpy(valorG, inputString + indiceG + 2, indiceB - indiceG - 2);

  // Encontrar el índice del final del valor b
  int indiceFinB = indexOf(inputString + indiceB, ",");
  if (indiceFinB == -1) {
    indiceFinB = strlen(inputString);
  }

  // Extraer el valor b
  strncpy(valorB, inputString + indiceB + 2, indiceFinB);

  // Convertir los valores a enteros
  int intR = atoi(valorR);
  int intG = atoi(valorG);
  int intB = atoi(valorB);

  // Llamar al callback con los valores enteros
  callback(intR, intG, intB);
}

// Función auxiliar para buscar la posición de una subcadena en un string
int indexOf(const char* str, const char* subStr) {
  const char* ptr = strstr(str, subStr);
  return ptr != NULL ? ptr - str : -1;
}


void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32SerialBT"); // El nombre del dispositivo Bluetooth
  pixels.begin();
}


void loop() {

    
  if (Serial.available()) {

    Serial.setTimeout(10);
    String dataSend =  Serial.readStringUntil('\n');

    SerialBT.println(dataSend);
    

  }

  if (SerialBT.available()) {

    SerialBT.setTimeout(10);
    String dataSendB =  SerialBT.readStringUntil('\n');
    
    Serial.println(dataSendB);

        // Elimina el carácter de nueva línea
    dataSendB.trim();

    extraerRGB(dataSendB.c_str(), [](int r, int g, int b) {
      // Your code to handle RGB values goes here
      Serial.print("Red: ");
      Serial.println(r);
      Serial.print("Green: ");
      Serial.println(g);
      Serial.print("Blue: ");
      Serial.println(b);

      pixels.clear(); // Set all pixel colors to 'off'
      
      for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
          
        pixels.setPixelColor(i, pixels.Color(r, g, b));
    
       
      }

      pixels.show();  
 

    });
  
    
  }
}
