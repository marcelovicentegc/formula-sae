import processing.serial.*;

Serial dataLogger;

Table dataTable;

String logPath = "../../__datalog__/";
String fileName;
String port = "COM9";

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
    dataTable.addColumn("temperature");
}

void serialEvent(Serial dataLogger) {
    try {
        String val = dataLogger.readStringUntil('\n');
        
        if (val != null) {
            val = trim(val);
            println(val);
            float sensorVals[] = float(split(val, ','));
            println(sensorVals);
            
            TableRow newRow = dataTable.addRow(); 
            newRow.setInt("id", dataTable.lastRowIndex());
            newRow.setInt("date", year() + month() + day());
            newRow.setInt("time", hour() + minute() + second());
            newRow.setFloat("temperature", sensorVals[0]);

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