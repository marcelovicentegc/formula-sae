const int sensor = A0;
float rawSensorData;

Serial dataLogger;
PrintWriter output;
   

void setup()
{
    pinMode(sensor, INPUT);
    Serial.begin(9600);
}

void loop()
{
    rawSensorData = analogRead(sensor);
    float celsius = (rawSensorData * 500) / 1023;
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

   dataLogger = new Serial(this, Serial.list()[0], 9600);
   output = createWriter("lm35_data_log.txt");
}

void draw() {
    if (dataLogger.available() > 0 ) {
        String data = dataLogger.readString();
        if ( data != null ) {
            output.println( data );
        }
    }
}

void keyPressed() {
    output.flush(); // Writes the remaining data to the file
    output.close(); // Finishes the file
    exit(); // Stops the program
}