## Control de Luces RGB a través de Bluetooth con ESP32 y NeoPixel

En este artículo, exploraremos cómo utilizar un módulo ESP32 junto con una tira de luces NeoPixel para crear un sistema de control de luces RGB a través de Bluetooth. Este proyecto es ideal para aquellos interesados en la programación de microcontroladores y la creación de proyectos de iluminación personalizados.

### Introducción

El ESP32 es un microcontrolador de bajo costo y alto rendimiento que se ha vuelto muy popular en el ámbito de la electrónica de bricolaje y la creación de prototipos. En combinación con la biblioteca BluetoothSerial y la biblioteca Adafruit_NeoPixel, podemos crear un sistema que permita controlar las luces RGB de manera inalámbrica mediante una conexión Bluetooth desde un dispositivo móvil u otro dispositivo compatible.

### Materiales necesarios

- ESP32 (puede ser cualquier placa basada en ESP32, como el NodeMCU-32S)
- Tira de luces NeoPixel RGB
- Dispositivo Bluetooth compatible (teléfono móvil, tableta, computadora portátil, etc.)

### Configuración del hardware

Conecte la tira de luces NeoPixel a su ESP32. Asegúrese de conectar la alimentación (VCC) y la tierra (GND) correctamente, y conecte el pin de datos a un pin digital disponible en su ESP32. En nuestro caso, estamos usando el pin 15, pero puede usar cualquier pin digital disponible y actualizar el código en consecuencia.

### Configuración del software

Antes de cargar el código en su ESP32, asegúrese de tener instaladas las bibliotecas necesarias. Utilizaremos la biblioteca BluetoothSerial para la comunicación Bluetooth y la biblioteca Adafruit_NeoPixel para controlar la tira de luces NeoPixel.

### Código

El código proporcionado es una combinación de la configuración del ESP32, la comunicación Bluetooth y el control de las luces NeoPixel. El ESP32 está configurado para comunicarse tanto a través del puerto serial estándar como a través de Bluetooth. Cuando recibe datos a través de Bluetooth, el ESP32 interpreta los valores de rojo (R), verde (G) y azul (B) y los utiliza para configurar el color de las luces NeoPixel.
### Paso 1
``` C++
// Incluir bibliotecas
#include <BluetoothSerial.h>
#include <Adafruit_NeoPixel.h>

// Definir pin y número de píxeles
#define PIN  15    
#define NUMPIXELS 16

// Inicializar objetos
BluetoothSerial SerialBT;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
```
### Paso 2
``` C++
// Función para extraer valores RGB de una cadena de entrada
void extraerRGB(const char* inputString, void (*callback)(int, int, int)) {
  // Buscar índices de las letras r, g, b
  int indiceR = indexOf(inputString, "r:");
  int indiceG = indexOf(inputString, "g:");
  int indiceB = indexOf(inputString, "b:");
  
  // ...
}

// Función para buscar la posición de una subcadena en un string
int indexOf(const char* str, const char* subStr) {
  const char* ptr = strstr(str, subStr);
  return ptr != NULL ? ptr - str : -1;
}
```
### Paso 3
``` C++
// Configuración inicial
void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32SerialBT"); // El nombre del dispositivo Bluetooth
  pixels.begin();
}
```
### Paso 4
``` C++
// Bucle principal
void loop() {
  if (Serial.available()) {
    // ...
  }

  if (SerialBT.available()) {
    // ...
  }
}
```
### Uso

Una vez que haya cargado el código en su ESP32 y haya conectado la tira de luces NeoPixel, puede emparejar su dispositivo Bluetooth con el ESP32. Una vez emparejado, puede enviar comandos de texto con los valores de R, G y B separados por comas a través de una aplicación de terminal serial o cualquier otra aplicación compatible con Bluetooth. El ESP32 interpretará estos comandos y ajustará el color de las luces NeoPixel en consecuencia.

### Conclusiones

Con este proyecto, hemos demostrado cómo crear un sistema de control de luces RGB a través de Bluetooth utilizando un ESP32 y una tira de luces NeoPixel. Este proyecto se puede personalizar aún más agregando características adicionales, como efectos de iluminación preprogramados o control de brillo. ¡Experimente y diviértase creando su propio sistema de iluminación personalizado!

Recuerde tener en cuenta las consideraciones de seguridad al manipular dispositivos electrónicos y al trabajar con electricidad. ¡Disfrute explorando el mundo de los microcontroladores y la electrónica de bricolaje con este emocionante proyecto!
