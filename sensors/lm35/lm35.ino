const int sensor = A0;
float rawSensorData;
int testLoop = 10;

void setup()
{
    pinMode(sensor, INPUT);
    Serial.begin(9600);
}

void loop()
{
    for (int a = 0; a < testLoop; a++)
    {
        rawSensorData = analogRead(sensor);
        float celsius = (rawSensorData * 500) / 1024;
        float fahrenheit = (celsius * 1.8) + 32;

        Serial.print("Temperatura: ");
        Serial.print(celsius);
        Serial.print("*C");
        Serial.println();
        delay(2000);

        // Uncomment these lines to get temperature in Kelvin
        /* float kelvin = celsius + 273.15;
      Serial.print("Temperatura em Kelvin: ");
      Serial.print(kelvin);
      Serial.println(); */

        // Uncomment these lines to get temperature in Fahrenheit
        /* Serial.print("Temperatura: ");
      Serial.print(fahrenheit);
      Serial.print("�F");
      Serial.println();

      Serial.print("Temperatura crua: ");
      Serial.print(rawSensorData);
      Serial.println();
      */
    }

    Serial.print("Completed test loop");
    exit(0);
}
