#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

const int sensor = A0;
float rawSensorData;
int testLoop = 20;
bool test = false;
bool getKelvin = false;
bool getFahrenheit = false;
bool saveToTxt = false;
bool saveToCsv = true;

void setup()
{
    pinMode(sensor, INPUT);
    Serial.begin(9600);
    mlx.begin();
}

void getTemperatures()
{
    rawSensorData = analogRead(sensor);
    float celsius = (rawSensorData * 500) / 1024;
    float fahrenheit = (celsius * 1.8) + 32;

    if (saveToTxt == true)
    {
        Serial.print("LM35 temp.: ");
        Serial.print(celsius);
        Serial.print(" C");
        Serial.println();
        Serial.print("MLX90614 ambient temp.: ");
        Serial.print(mlx.readAmbientTempC());
        Serial.print(" C");
        Serial.println();
        Serial.print("MLX90614 object temp.: ");
        Serial.print(mlx.readObjectTempC());
        Serial.print(" C");
        Serial.println();
        delay(2000);

        if (getKelvin == true)
        {
            float kelvin = celsius + 273.15;
            float ambientKelvin = mlx.readAmbientTempC() + 273.15;
            float objectKelvin = mlx.readObjectTempC() + 273.15;
            Serial.print("LM35 temperature ");
            Serial.print(kelvin);
            Serial.print(" K");
            Serial.println();
            Serial.print("MLX90614 ambient temperature: ");
            Serial.print(ambientKelvin);
            Serial.print(" K");
            Serial.println();
            Serial.print("MLX90614 object temperature: ");
            Serial.print(objectKelvin);
            Serial.print(" K");
            Serial.println();
        }

        if (getFahrenheit == true)
        {

            Serial.print("LM35 temperature: ");
            Serial.print(fahrenheit);
            Serial.print(" F");
            Serial.println();
            Serial.print("MLX90614 ambient temperature: ");
            Serial.print(mlx.readAmbientTempF());
            Serial.print(" F");
            Serial.println();
            Serial.print("MLX90614 object temperature: ");
            Serial.print(mlx.readObjectTempF());
            Serial.print(" F");
            Serial.println();
        }
    }

    if (saveToCsv == true)
    {
        Serial.print(mlx.readAmbientTempC());
        Serial.print(",");
        Serial.print(mlx.readObjectTempC());
        Serial.print(",");
        Serial.print(celsius);
        Serial.println();
        delay(2000);
    }
}

void loop()
{
    if (test == true)
    {
        for (int a = 0; a < testLoop; a++)
        {
            getTemperatures();
        }
        Serial.print("Test suit completed.");
        Serial.println();

        // Since Arduino has no O.S., exit() is useless. There is no correct way to stop an Arduino program
        // since it is supposed to loop forever. For output purposes, calling while(1) {} traps the program
        // into a outputless loop, "stopping" it.
        while (1)
        {
        }
    }
    else
    {
        getTemperatures();
    }
}
