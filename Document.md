# I.	INTRODUCTION
IoT has transformed the physical devices in communication with the digital world. It allows sensors, microcontrollers, and cloud services to create one network that can make intelligent decisions and monitor them even remotely. Most applications of IoT, such as smart houses, accurate farming, automated industry, and health condition monitoring require the capability to identify environmental changes and display the information.
 
 
 Two major environmental factors are temperature and humidity. They influence the level of comfort individuals experience, performance of crops and the working of factories. Older systems of monitoring tend to have wired sensors or data that has to be written by hand, and is slow, expensive, and can be difficult to scale out. Inexpensive Wi-Fi boards like the ESP32 allow individuals to construct real-time displays with extremely limited hardware and software.
 In our project an ESP32-C3 microcontroller has been connected to a DHT11 temperature and humidity sensor and a NeoPixel LED. The ESP32 interface receives the sensor and transmits the data in MQTT over wireless transmission. MQTT is quick and small and depends due to the low bandwidth requirement and use of a publish/subscribe model. Our brokers will be published in the public under broker broker.hivemq.com, and therefore anyone may use it without installing his/her server.
 The recipient side uses Node-RED, which is an open-source flow-based tool. It subscribes to MQTT topic and displays the information on a web dashboard. The dashboard form of the device has gauge modules informing the present values and chart modules displaying the previous trends. The NeoPixel LED provides a quick user feedback by turning different colors when the temperature attains certain values as blue (cold), green (normal), and red (hot).
 It is our aim to demonstrate the method of integrating hardware sensing, wireless communication as well as data analysis in a single IoT device. The project emphasizes a point that extremely low-cost hardware and freely available tools can create scaleable, low-energy consumption, and monitoring of schools, houses, and factories. Since MQTT and Node -RED are not complex, it is not difficult to add more sensors, cloud storage, or automatic controls. The prototype has the potential to become a larger IoT system.
# II.	SYSTEM OVERVIEW 
The IoT temperature and humidity monitoring system combines both hardware and software to monitor all the data that includes data collection up to real-time display and alerts.
## A.	Hardware Components
The hardware layer provides parts that do a major task in the monitoring process, which are small and inexpensive and require low power: 
•	ESP32-C3 Microcontroller: It serves as the primary processor and speech maker. It has an inbuilt Wi-Fi and Bluetooth, has enough power, and operates with popular IoT tools. It periodically scans the sensors and performs minor data tasks on the device and transmits data over the air. 
•	DHT11 Sensor: It is a simple digital sensor, which measures both humidity and temperature. It is simple to join and learn or fast projects. It transmits sanitized signals of temperature (0 to 50 o C) and humidity (20ps to 90ps) which are interpreted by the ESP32 on a predetermined interval. 
•	NeoPixel (WS2812) LED: It is an LED that displays the surrounding environment. It can switch color (blue, green, orange, red) such that its users are able to know how things are without having to open a dashboard.
•	 Power Supply and Circuitry: The supply is built-in to the ESP32 and so powering of the parts is simple and the system is small. The components are installed on the breadboard to quickly build, but can be transferred to a specialized board to be more durable, or to actual implementation.
## B.	Software Tools
The software side integrates firmware, communication protocols, and user-facing interfaces:
•	Arduino IDE: The primary code editor, library utility, and flashів. It allows amateur and professional designers to prototype fast since most libraries are available. 
•	MQTT Broker (broker.hivemq.com): A public server, which is cloud based and an MQTT Broker that communicates all the messages of publish/subscribe. MQTT was selected due to little bandwidth that it uses, reliably delivered, and is prevalent in the IoT.
•	 Node-RED Dashboard[5][9][15]: It is operated by a computer or a server. Node-RED is a MQTT consumer that takes live data, deconstructs JSON messages and displays the information on a web page. Its drag-and-drop functionality allows any person, including non-technical users to create charts, gauges and alerts, to monitor trends, review historical data and receive notification of events.
## C.	System Architecture and Operational Flow
At its core, the system features a tightly integrated architecture:
1. The ESP32 receives temperature and humidity measurement of the DHT11 after every 10 seconds.
 2. To provide immediate feedback, the read data is tested locally to select the correct color LED to use with NeoPixel which is an LED. 
3. The readings are converted to the form of a JSON object and proposed to the HiveMQ MQTT broker with a unique topic name. 
On that topic Node-RED receives the data, visualizes it (live displays), and stores in history. This cloud architecture allows a large number of nodes to collaborate and may be expanded to larger sensor networks or intelligent control systems.
D.	Expandability and Integration
The modular design of the system enables:
•	Add or remove sensors (such as air quality or soil moisture).
•	Change to more powerful microcontrollers or other cloud services. 
•	 Integrate with other IoT platforms (ThingSpeak, AWS IoT) with only a switch of the MQTT server or dashboard flow. 
Concisely, the design provides a scalable and user-friendly blueprint of a sustainable and uninterrupted environmental surveillance blending real-time sensing with adaptable and open-source data visualization and correspondence.
# III.	METHODOLOGY
## A.	System Overview
The project was constructed to be an IoT temperature and humidity sensor using an ESP32 -C3 and DHT11 sensor and Adafruit NeoPixel RGB LED. It reads the temperature and humidity of the air and displays the condition using LED colors and transmits it to HiveMQ MQTT cloud. It also subscribes to instructions on a certain topic about MQTT to manage or text data.
B.	Hardware Components
•	ESP32-C3 Microcontrolle[3][7[r- the primary communication controller and wireless communicator, which works with Wi-Fi and MQTT. 
•	DHT11 Temperature and Humidity sensor[6][10]- provides real time temperature and humidity data. 
•	AV/EM Adafruit NeoPixel RGB LED- temperature display using changing colors. 
•	Power Supply - connection through 5 vac USB or external 5 vac DC.
C.	Software Tools and Libraries
The firmware of ESP32 had been coded in the Arduino IDE, using the libraries: 
•	Wireless network functionality is provided by wifi.h. 
•	PubSubClient.h- to communicate with the MQTT broker. 
•	DHT.h - to read the sensor DHT11. 
•	NeoRetro.h Adafruit_NeoPixel.h - to control the RGB LED. 
•	ArduinoJson.h - to pack and format the data into the form of JSON to send it.
D.	System Architecture
The system architecture was divided into four primary layers:
1.	Data Acquisition Layer:
The DHT11 sensor was interfaced with the ESP32-C3 to measure temperature and humidity at 10-second intervals.
2.	Processing Layer:
The ESP32-C3 processed the sensor readings and determined the corresponding temperature range. Depending on the measured temperature, the LED color was updated to represent specific environmental conditions.
3.	Communication Layer:
The ESP32-C3 connected to a local Wi-Fi network using predefined SSID and password credentials. It then established a connection to the HiveMQ public MQTT broker[2][4][8] at broker.hivemq.com via port 1883.
o	Sensor data were published to the topic:
H00519258/evt/status/fmt/json
o	The device subscribed to the topic:
H00519258/cmd/display/fmt/json
to receive remote control or configuration messages.
4.	Visualization Layer:
The NeoPixel RGB LED provided immediate visual feedback on the temperature conditions according to the following scheme:
Temperature Range (°C)			Condition	LED Color
< 0			Alarm (Low)	Blue
0 – 10			Warning (Low)	Light Blue
10 – 25			Normal	Green
25 – 30			Warning (High)	Dark Red
> 30			Alarm (High)	Red
E.	Data Formatting and Transmission
The collected sensor data were structured into a JSON object before being transmitted to the MQTT broker. The data format used is shown below:
```
{
  "d": {
    "temp": <temperature_value>,
    "humidity": <humidity_value>
  }
}
```
This lightweight JSON format facilitated efficient data exchange and compatibility with other IoT dashboards or cloud platforms.

F.	Communication and Control Flow
  When started, the ESP32-C3 established all the peripherals, such as the DHT11 sensor, the NeoPixel LED, and the Wi-Fi module. The system then tried to connect to the monitored Wi-Fi network. As it was connected, it established a connection to the MQTT broker. 
 At normal operation, the system continuously:
•	Get sensor values of read temperature and humidity. 
•	Adjust the LED color based on the temperature limits. 
•	Store the readings using a JSON format. Transmit the data to MQTT topic. 
•	Receive incoming MQTT messages on the topic that is subscribed to. 
This was done in 10 seconds interval to ensure real time monitoring.

G.	Error Detection and Handling

A number of reliability measures were used in the firmware: When the DHT11 sensor did not get any information (e.g., it gave NaN values), the information was not sent during that cycle. The ESP32-C3 would keep checking on its connection. In the case of Wi-Fi or MQTT connection loss, the system attempted to reconnect automatically on a periodical basis until it achieved a stable connection.

  The full operational cycle of the system consisted of sensor reading, data processing, LED color adjustment, data packaging, and MQTT publishing. This cycle repeated every 10 seconds, enabling continuous monitoring and data transmission to the MQTT cloud server.

H.	Operational Cycle 
The entire operational cycle of the system included sensor reading, data processing, LED color adjustment, data packaging and the MQTT publication. This loop was repeated with a time delay of 10 seconds, and it was possible to monitor the process and send the data to the MQTT cloud server.

# IV.	RESULTS AND DISCUSSION
    The environmental monitoring system in IoT was developed and installed successfully and tested in the laboratory. Both the Arduino serial monitor and the Node -RED dashboard yielded results that confirmed the proper operation of the sensor, the correct functioning of the MQTT communication system, and the active work of the LED indicators. The discussion of the experimental outcomes is done below
A.	 Arduino Serial Output Analysis[3]
. Once the program was uploaded into ESP32 microcontroller, the serial monitor was launched at a baud rate of 115200 to confirm the data flow and the process of MQTT publishing. The following series of messages was noticed: 

![ProjectImage](https://raw.githubusercontent.com/Spandana1mc/IOT-Assignment/main/Images/Picture3.png)

•	Connecting to Wi Fi... Wi Fi 
•	Connected. IP Address: 192.168.1.8 
•	Connecting to MQTT broker... 
•	MQTT Connected! 
•	Temperature: 26.50 degC 
•	Humidity: 61.20 % 
•	Publishing to topic: H00519258/evt/status/fmt/json
This proves that the device has been able to
•	Wi-Fi and MQTT connections are established. 
•	Readings of the DHT11 sensor were accurate and were retrieved. 
•	Published messages to the HiveMK broker as JSON messages. 
The serial output was constant in the course of hours, with controlable data loss, which means that the network connection was steady, and MQTT was processed efficiently by ESP32. 
B.	Node-RED Dashboard Visualization.
    After the data were finally published, the Flow in Node-RED was subscribed to the MQTT topic and displayed the received data. The dashboard was made up of two gauges and two charts one of temperature and one of humidity.
![Project Image](https://raw.githubusercontent.com/Spandana1mc/IOT-Assignment/main/Images/Picture2.png)


![Project Image](https://raw.githubusercontent.com/Spandana1mc/IOT-Assignment/main/Images/Picture1.png)

1)	Gauge Display
 The gauge indicators were used to show the temperature and humidity in real time. The thermostat was 0 to 50 degrees C. The humidity indicator was between 0 and 100 percentage. All the gauges were dynamically updated after every 10 seconds according to new MQTT messages. The publish subscribe model proved to be reliable as shown by the real time response.[12]
2)	Chart Display 
The nodes in the chart were the continuous temperature and humidity versus time. Such visual effects enabled me to observe the changes in the environment like the small changes in temperature during testing. The charts stored past information and performance could be analyzed.
C.	NeoPixel LED Indication
 The NeoPixel LED served as a visual source of information about the environmental conditions in addition to the numerical performance displayed in Node-RED. The LED action was in accordance with the programmed logic: 
•	Blue (10 deg C or lower): Low temperature zone. 
•	Green (10 -25 degC): Comfortable/ normal. 
•	Orange (25 – 30 degC): Moderate warmth 
•	Red (above 30 degC): Warnings of high temperature. 
The temperature in the surrounding was circa 26 degC in the course of the experiments and the LED was always light orange, which validated the proper logic mapping and functionality of the code. The change in LED color was nearly immediate (less than 1 second) following every new sensor reading which indicated efficient sensor-actuator coordination. 
D.	MQTT Communication Checking.
 In order to check the reliability of the communication, various intervals of publishing messages (5 s, 10 s, and 20 s) were conducted. The MQTT connection[8][4] worked well in all configurations. Messages were received and sent to the Node-RED client with the MQTT broker (broker.hivemq.com). The system demonstrated: 
•	Low latency: Less than 150 ms to pass messages. 
•	Minimal loss of packets: There was no loss of messages in 30 minutes of continuous tests.
•	 Auto-reconnection: The ESP32 automatically reconnects within 5-8 seconds of a temporary disconnection in Wi-Fi, and the publishing is restarted automatically without the need to reset it. 
The findings prove that MQTT protocol is highly appropriate in real-time transmission of IoT data over open networks. 
E.	Comparative Accuracy of DHT11 Sensor[6][10] 
  It is crucial to mention that both DHT11 and DHT11CP Sensors share the same accuracy deviation. A digital thermometer with a calibration was used to compare readings of DHT11 sensor with temperature reading. The mean error was found to be ±1.5 degC, which is acceptable by cheap IoT systems.
   Though not a high-precision sensor, the DHT11 is simple, consumes less power and can be integrated easily, which makes it ideal to use in educational and small-scale IoT contexts make it ideal for educational and small-scale IoT applications.

F.	System Performance Evaluation
The overall system performance was evaluated based on accuracy, stability, latency, and user interface responsiveness.[14]

Parameter	Observed Performance	Remarks
Wi-Fi Connection Time	5–10 seconds	Stable after connection
MQTT Publish Interval	10 seconds	Configurable
Data Accuracy	±2°C, ±5% RH	Acceptable for DHT11
LED Response Delay	< 1 second	Immediate indication
Node-RED Update Delay	~2 seconds	Real-time visualization
Power Consumption	~150 mA	Suitable for 3.3V operation

The results indicate that the system performs efficiently with minimal delay and provides both visual and analytical feedback in real time.
G.	Discussion
 The integration of ESP32, DHT11, NeoPixel, and Node-RED demonstrates a cost-effective IoT monitoring framework that can be easily scaled. The use of the MQTT protocol ensures lightweight communication suitable for constrained devices, while Node-RED provides an intuitive interface for non-technical users.
 Furthermore, the modular structure allows for expansion to include multiple sensors such as gas, light, or motion detectors. Data storage and remote monitoring could be enhanced by integrating cloud databases like ThingSpeak or Firebase in future versions.
 The system’s effectiveness lies in its real-time monitoring, visual feedback, and wireless data accessibility, which make it highly useful for smart home environments, greenhouse monitoring, and industrial safety applications.

H.	Summary
The successful implementation and testing confirm that the system fulfills its objectives:
•	Real-time data collection and transmission using MQTT.
•	Visual indication of environmental changes via LED.
•	Continuous monitoring through Node-RED charts and gauges.
The experiment validates the feasibility of integrating low-cost IoT components to create an efficient and user-friendly monitoring system.

# V.	APPLICATIONS AND USES
The proposed IoT-based temperature and humidity monitoring system has numerous practical applications in various domains due to its scalability, affordability, and real-time operation. By integrating sensing, cloud communication, and visualization, the system can be deployed in both domestic and industrial environments. Some of its key applications and use cases are described below.
A.	Smart Home Monitoring
In smart home environments, maintaining optimal temperature and humidity levels is essential for comfort, energy efficiency, and appliance performance. The system can be used to automatically monitor environmental conditions and trigger alerts or control HVAC (Heating, Ventilation, and Air Conditioning) systems. For example, if the temperature exceeds a set threshold, the system could automatically switch on fans or air conditioners, thereby optimizing energy consumption.[11]

B.	Agricultural and Greenhouse Monitoring
In agricultural applications, the system can be deployed to monitor greenhouse environments, where temperature and humidity significantly affect crop yield. By providing real-time readings and visual alerts, farmers can maintain ideal growing conditions. The integration of MQTT enables data to be stored or analyzed remotely, supporting precision agriculture and automated irrigation systems.[13]
C.	Industrial and Warehouse Environments
In manufacturing plants, warehouses, and data centers, temperature and humidity fluctuations can cause equipment malfunctions or product degradation. The proposed system offers a low-cost solution to continuously track environmental parameters and send alerts if abnormal conditions are detected, ensuring preventive maintenance and asset protection.[12][14]
D.	Healthcare and Laboratory Applications
In healthcare facilities and laboratories, maintaining stable environmental conditions is critical for storing biological samples, medicines, and sensitive instruments. This system can monitor the environment continuously and notify personnel of any deviations that may compromise sample integrity or equipment performance.[11]
E.	Educational and Research Applications
The setup provides a practical learning platform for students and researchers studying IoT, embedded systems, or data visualization. It demonstrates real-world integration of sensors, microcontrollers, and cloud technologies. Furthermore, the system’s modularity allows learners to experiment by adding sensors such as light, motion, or gas detectors to build more advanced IoT prototypes.[5]
F.	Environmental and Smart City Monitoring
When deployed in outdoor conditions, this system can contribute to broader environmental monitoring networks. By scaling the design across multiple nodes, cities can collect distributed climate data to analyze microclimates, pollution trends, or urban heat effects. This supports data-driven policy decisions and contributes to sustainable urban planning.[1][14]
G.	IoT System Development and Prototyping
Due to its open-source tools (Arduino IDE, Node-RED, MQTT), this system serves as a foundation for IoT prototyping. Developers can extend its functionality to include remote control, cloud databases, or AI-based decision-making modules for smarter automation.

Summary of Key Benefits
Feature	Description	Benefit
Wireless Communication	MQTT protocol via Wi-Fi	Real-time remote monitoring
Visual Feedback	NeoPixel LED	Instant temperature indication
Open-Source Tools	Arduino IDE & Node-RED	Cost-effective and flexible
Scalability	Multiple devices can publish to broker	Suitable for large networks
Cross-Domain Utility	Smart homes, agriculture, industry	Broad range of applications


# VI.	CONCLUSION AND FUTURE SCOPE

A.	Conclusion
  This project successfully demonstrated a cost-effective IoT-based environmental monitoring system[12] using an ESP32 microcontroller, DHT11 sensor, and NeoPixel LED. The system efficiently measured temperature and humidity, transmitted the data to a public MQTT broker (broker.hivemq.com), and visualized it through Node-RED using gauges and charts.
Experimental results confirmed the accuracy, stability, and low latency of the setup. The NeoPixel LED provided immediate local visual feedback, while Node-RED enabled intuitive web-based monitoring. Together, these features make the system an ideal example of integrating hardware sensing, wireless communication, and data visualization into one IoT framework.
The use of open-source tools (Arduino IDE, Node-RED, and HiveMQ) ensured easy implementation without the need for proprietary software or expensive infrastructure. Moreover, the MQTT protocol proved highly effective for low-bandwidth, real-time data exchange, validating its suitability for IoT networks with constrained resources.[2][4]
This project demonstrates how low-cost embedded platforms can contribute to smart automation solutions and serve as a prototype for scalable IoT deployments in multiple sectors.
B.	Future Scope
  Although the system performs well at the moment, we may introduce additional features and make it expand: 
Future work would involve using cloud integration: ThingSpeak databases, Google Firebase databases, or AWS IoT core could all be linked to log data and conduct more sophisticated analytics.[14][15]
•	Mobile App Tracking: A mobile phone companion app may be developed to operate in real-time alerts and control which enhances the ease of access by end users. 
•	Multi-Sensor Expansion: It would be better to have more sensors (adding CO 2, air quality, light intensity, soil moisture) that will provide a more comprehensive picture of the environment.
•	 Edge Processing: It may be possible to put AI or machine learning on the ESP32 and make predictions and smart decisions without cloud assistance.
•	Low-Power Optimization: It would be appropriate to use deep-sleep and battery mode and allow it to be used in a remote or outdoor environment. 
•	Security Improvements: Encryption and addition of authentication of MQTT messages would secure information against unauthorized access.
•	Scalable Network Design: A distributed monitoring system would be developed when many ESP32 nodes are extended to a central broker. 

