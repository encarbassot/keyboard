#include <SD.h>
File dataFile;

void setup(){
  Serial.begin(9600);
  delay(2000);
  
  Serial.print(F("Iniciando SD ..."));
  if (!SD.begin(10)){
    Serial.println(F("Error al iniciar"));
    return;
  }
  Serial.println(F("Iniciado correctamente"));
 
  // Abrir fichero y mostrar el resultado
  dataFile = SD.open("datalog.txt"); 
  if (dataFile){
   String dataLine;
    while (dataFile.available()){
      char a = dataFile.read(); 
       Serial.print(a);  // En un caso real se realizarían las acciones oportunas
    }
    dataFile.close();
  }else{
    Serial.println(F("Error al abrir el archivo"));
  }
}

void loop(){
}
