import processing.serial.*;

Serial dataLogger;
PrintWriter output;
String logPath = "./__datalog__/";
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
        String date = str(year() + "-" + month() + "-" + day());
        String hour = str(hour() + ":" + minute() + ":" + seconds());
        String data = dataLogger.readString();
        if (data != null)
        {
            output.println(date);
            output.println(hour);
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