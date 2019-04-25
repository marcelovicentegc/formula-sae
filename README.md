# 🏎 Formula SAE

Formula SAE is a student design competition organized by SAE International (previously know as the Society of Automotive Engineers). The competition was started in 1980 by the SAE student branch at the University of Texas at Austin after a prior asphalt racing competition proved to be unsustainable.

The concept behind Formula SAE is that a fictional manufacturing company has contracted a student design team to develop a small Formula-style race car. The prototype race car is to be evaluated for its potential as a production item. The target marketing group for the race car is the non-professional weekend autocross racer. Each student team designs, builds and tests a prototype based on a series of rules, whose purpose is both ensuring on-track safety (the cars are driven by the students themselves) and promoting clever problem solving[...](https://en.wikipedia.org/wiki/Formula_SAE)

---

# CAN (Controller Area Network) bus

> _The vehicle nervous system_

> _A central networking system_

The CAN standard allows ECUs to communicate with each other without complex wiring. This allows for several features to be added via software alone. That is the primary purpose of CAN: to allow any ECU to communicate with the entire system without causing an over load to the controller computer.

- Why is CAN popular?

  - Low cost
    - ECUs communicate via a single CAN interface, not direct analogue signal lines, reducing errors, weight and costs related to analogue signal communication.
  - Centralized
    - The CAN bus system allows for central error diagnosis and configuration across all ECUs
  - Robust
    - The system is robust towards failure of subsystems and electromagnetic interference, making it ideal for vehicles
  - Efficient
    - CAN messages are prioritized based on IDs so that the highest priority IDs are non-interrupted - critical in vehicles
  - Flexible
    - Each ECU contains a chip allowing it to receive all transmitted messages, decide relevance and act accordingly. This allows easy modification and inclusion of additional nodes such as CAN bus data loggers.

- Electronic Control Units (ECUs): communication _nodes_ within the vehicle nervous system.

  - E.g.
    - Engine Control Unit
    - Airbag
    - Audio system
  - A modern car can have up to 70 ECU's (2019)

- A CAN message
  | Bit | Message part | Function |
  | --- | ------------ | ----------- |
  | 1 | SOF (Start of Frame) | Lets other ECUs know that a message is coming |
  | 29 | **CAN ID**\* | Contains the message priority. As well as functional address (i.e. RPM, wheel speed, etc.) |
  | 1 | RTR (Remote Transmission Request) | Allows ECUs to request messages from other ECUs |
  | 6 | **CONTROL**\* | Informs the length of the data in bytes |
  | 0-64 | **DATA**\* | Contains the actual data values, which need to be scaled or converted to be readable and ready for analysis |
  | 16 | CRC (Cyclic Redundancy Check) | Checks data integrity |
  | 2 | ACK | Indicates if the CRC process is OK |
  | 7 | EOF (End of Line) | Marks the end of the CAN message |

Can provides the basis for communication - but not a lot more. For example, the CAN standard does not specify how to handle messages larger than 8 bytes - or how to decode the raw data. Therefore, a set of standardized protocols exist to further define how data is communicated between ECUs of a given network. Somme of the most common and encountered standards include _SAE J1939_, _OBD-II_ and _CANOpen_.

- SAE J1939

  - This is the standard in-vehicle network for buses, trucks and other heavy-duty vehicles

- OBD2

  - On-board diagnostics (OBD) is a self-diagnostic and reporting capability that mechanics use to identify what is wrong with a vehicle. The OBD standard specifies a number of standardized diagnostic trouble codes (DTCs), which can be retrieved by a CAN logger or diagnostic tool from any vehicle.
  - What makes OBD2 really interesting?
    - OBD2 supports data on many basic real-time parameters (i.e. vehicle speed, RPM, fuel consumption). This means that OBD2 is also used for real-time vehicle telematics or post analysis using CAN data loggers. Applications include vehicle fleet management, fuel optimization, proactive vehicle diagnostics and more...

- CANOpen
  - CANOpen is used widely in industrial automation applications. It builds on CAN, in terms of physical layer (lines used, voltages, etc.) and the data link layer, utilizing a CAN frame message based protocol.
