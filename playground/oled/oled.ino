#include <Mouse.h>
#include <Keyboard.h>
#include <Adafruit_GFX.h> //Liberia para gráficos
#include <Adafruit_SSD1306.h> //Liberia para Oleds monocromáticos basados ​​en controladores SSD1306

#define OLED_RESET 13 
Adafruit_SSD1306 display(OLED_RESET);
/*Se define una condición para saber si en la librería esta definida la altura de 32 de lo contrario 
 *no dejara compilar el código hasta que se cambie la altura correcta desde la librería*/
#if (SSD1306_LCDHEIGHT != 32)
#error("Altura incorrecta, cambie en la librería de Adafruit_SSD1306.h!");
#endif

int responseDelay = 2;
int angle = 0;
int radious = 5;


void setup() {
  Mouse.begin();
  Keyboard.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  leer_oled();
}

void loop() {
  //leer_oled();
  
  delay(responseDelay);
}


void leer_oled() { 
  display.clearDisplay(); //Borra el buffer
  display.setTextSize(1); //Establece el tamaño de fuente, admite tamaños de 1 a 8
  display.setTextColor(WHITE); //Establece el color 
  display.setCursor(35,10); //Establecer las coordenadas para mostrar la posición del texto
  display.println("SALUDOS DE");
  display.setCursor(20,20); //Establecer las coordenadas para mostrar la posición del texto
  display.println("ELOI"); 
  display.display(); //Muestra el texto 
}
