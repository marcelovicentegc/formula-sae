const int sensor = A0;
float rawSensorData;

void setup()
{
    pinMode(sensor, INPUT);
    Serial.begin(9600);
}

void loop()
{
    rawSensorData = analogRead(sensor);
    float celsius = (rawSensorData * 500) / 1024;
    float fahrenheit = (celsius * 1.8) + 32;

    Serial.print("Temperatura: ");
    Serial.print(celsius);
    Serial.print("*C");
    Serial.println();
    delay(1000);

    /* Uncomment these lines to get temperature in fahrenheit 
    Serial.print("Temperatura: ");
    Serial.print(fahrenheit);
    Serial.print("*F");
    Serial.println();
    */
}