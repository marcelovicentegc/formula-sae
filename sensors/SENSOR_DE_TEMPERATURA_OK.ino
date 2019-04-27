

#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();



void setup() {
  Serial.begin(9600);

  Serial.println("Adafruit MLX90614 test");  

  mlx.begin();  
}

void loop() {
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF()); 
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");

  Serial.println();
  delay(500);
void setup() {
  String portName = Serial.list()[0]; //configura a porta serial
  mySerial = new Serial(this, portName, 9600); //Configura a porta serial
  output = createWriter( "data.txt" ); //Cria o objeto arquivo para gravar os dados
}


  if (mySerial.available() > 0 ) { //Se receber um valor na porta serial
    String value = mySerial.readStringUntil('\n'); //Le o valor recebido
    if ( value != null ) { // Se o valor nao for nulo
      output.print(hour()); //Escreve no arquivo as horas e os minutos atuais seguido do valor lido pelo sensor
      output.print(":");
      output.print(minute());
      output.print("->");
      output.println(value); //value é o valor recebido pela porta serial (valor que o LDR enviou)
    }
  }
}

void keyPressed() { //Se alguma tecla for pressionada
  output.flush(); // Termina de escrever os dados pro arquivo
  output.close(); // Fecha o arquivo
  exit(); // Para o programa
}
