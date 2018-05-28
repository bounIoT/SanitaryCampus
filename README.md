
# Smart WC, Sanitary Campus

Lack of toilet paper in toilets, causes an unsanitary environment, we want to track it before the toilet paper level drops below threshold.


## Team Members

* Nilsu Pamuk
* Anıl Yıldırım
* Berkay Taçyıldız 

## Technical Details

### Hardware setup
 We used an Arduino Uno, a breadboard, a HC-SR04 ultrasonic sensor and an ESP8266 wifi module
#### Connections of the devices are:
* RXD of wifi module to RXD of Arduino-uno
* TXD of wifi module to TXD of Arduino-uno
* VCC and CH_PD of wifi module to 3V3 of Arduino-uno
* GPIO0 and GND of wifi module to GND of Arduino-uno
* VCC of ultrasonic sensor to 5V of Arduino-uno
* Trig of ultrasonic sensor to digital 9 of Arduino-uno
* Echo of ultrasonic sensor to digital 8 of Arduino-uno
* GND of ultrasonic sensor to GNd of Arduino-uno

### Flow of data 
* Ultrasonic sensor sends data to Arduino-Uno. 
* Arduino sends the data to ESP8266 module for it to transfer the data to cloud(Heroku).
* This cloud provides GUI to the end user and also sends an e-mail if the toilet paper level is below threshold.

### Development Environment
* Development Operating System : OS X 
* Development tools:  Node.js, Heroku, Arduino IDE, WebStorm
