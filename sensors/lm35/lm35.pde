import processing.serial.*;

Serial dataLogger;
PrintWriter output;
String logPath = "C:/Users/marce/Documents/Projects/Dev/Venvs/formula-sae/sensors/lm35/__datalog__/";
String fileName = "lm35_data_log.txt"
String port = "COM7";

void setup () {
   dataLogger = new Serial(this, port, 9600);
   output = createWriter(logPath + fileName);
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