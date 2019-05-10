const int sensor = A0;
float rawSensorData;
int testLoop = 20;
bool test = true;
bool getKelvin = false;
bool getFahrenheit = false;
bool saveToTxt = true;
bool saveToCsv = false;

void setup()
{
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void getTemperature()
{
  rawSensorData = analogRead(sensor);
  float celsius = (rawSensorData * 500) / 1024;
  float fahrenheit = (celsius * 1.8) + 32;

  if (saveToTxt == true)
  {
    Serial.print("Temperature: ");
    Serial.print(celsius);
    Serial.print(" C");
    Serial.println();
    delay(2000);

    if (getKelvin == true)
    {
      float kelvin = celsius + 273.15;
      Serial.print("Temperature ");
      Serial.print(kelvin);
      Serial.print(" K");
      Serial.println();
    }

    if (getFahrenheit == true)
    {

      Serial.print("Temperature in Fahrenheit: ");
      Serial.print(fahrenheit);
      Serial.print(" F");
      Serial.println();
    }
  }

  if (saveToCsv == true)
  {
    Serial.println(celsius);
  }
}

void loop()
{
  if (test == true)
  {
    for (int a = 0; a < testLoop; a++)
    {
      getTemperature();
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
    getTemperature();
  }
}