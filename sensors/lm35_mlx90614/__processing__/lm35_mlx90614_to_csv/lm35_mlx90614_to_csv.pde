import processing.serial.*;

Serial dataLogger;

Table dataTable;

String logPath = "../../__datalog__/";
String fileName;
String port = "COM7";

boolean test = true;
int numReadings;
int readingCounter;

void setup () {
    dataLogger = new Serial(this, port, 9600);
    dataTable = new Table();

    if (test == true) {
        numReadings = 20;
        readingCounter = 0;
    }

    dataTable.addColumn("id");
    dataTable.addColumn("date");
    dataTable.addColumn("time");
    dataTable.addColumn("LM35Temperature");
    dataTable.addColumn("MLX90614AmbientTemperature");
    dataTable.addColumn("MLX90614ObjectTemperature");
}

void serialEvent(Serial dataLogger) {
    try {
        String val = dataLogger.readStringUntil('\n');
        
        if (val != null) {
            val = trim(val);
            float sensorVals[] = float(split(val, ','));
            println(sensorVals);
            
            TableRow newRow = dataTable.addRow(); 
            newRow.setInt("id", dataTable.lastRowIndex());
            newRow.setString("date", year() + "-" + month() + "-" + day());
            newRow.setString("time", hour() + ":" + minute() + ":" + second());
            newRow.setFloat("LM35Temperature", sensorVals[0]);
            newRow.setFloat("MLX90614AmbientTemperature", sensorVals[1]);
            newRow.setFloat("MLX90614ObjectTemperature", sensorVals[2]);

            if (test == true) {
                readingCounter++;

                if (readingCounter % numReadings == 0) {
                    fileName = str(year()) + "-" + str(month()) + "-" + str(day()) + "-" + str(dataTable.lastRowIndex()) + ".csv";
                    println(fileName);
                    saveTable(dataTable, logPath + fileName);
                }
            }
        }
    } catch(RuntimeException error) {
    error.printStackTrace();
    }
}

void draw()
{
}
