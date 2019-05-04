import processing.serial.*;

Serial dataLogger;
PrintWriter output;
   
void setup () {
   dataLogger = new Serial(this, Serial.list()[0], 9600);
   output = createWriter("lm35_data_log.txt");
}

void draw()
{
    if (dataLogger.available() > 0)
    {
        String data = dataLogger.readString();
        if (data != null)
        {
            output.println(data);
        }
    }
}

void keyPressed()
{
    output.flush(); // Writes the remaining data to the file
    output.close(); // Finishes the file
    exit();         // Stops the program
}