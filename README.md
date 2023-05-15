Code for an D1 Mini pro to measure water height via a JSN-SR04T and send the result to IFTTT that will send it to a Google spreadsheet.
![enter image description here](https://github.com/sylvainkalache/water-height-sensor/blob/main/sensor-final-form.jpg?raw=true)

## Project goal

There are only a few tide sensors in Fort Lauderdale's new river; after Andrews Avenue bridge, there are none. With 300 miles of canals, many owners don't know the water level in their canal at a given time. This can be an issue if there is a fixed bridge and high water levels mean that you cannot get out or get back home. A low water level could mean that you run your board aground.

That's why I decided to build a custom made arduino-based tide sensor. By placing it on my dock, I can have live data on the water height and decide if it's a good time to take the boat out.
![enter image description here](https://github.com/sylvainkalache/water-height-sensor/blob/main/Tide-predictions-sensors-Fort-lauderdale.png?raw=true)

## What the code does
The code is well document but in a nutshell. The board connects to the wifi and uses the JSN-SR04T to take 5 measurements. If the measurements match (within 1cm close), it is sent to IFTTT, if they do not, another 5 measurements are taken until they do match. This loop happens every 5 minutes.

## Wiring schema
![enter image description here](https://github.com/sylvainkalache/water-height-sensor/blob/main/water-height-sensor.png?raw=true)
Make sure to use D1 and D2. I tried using other ports to connect to the JSN-SR04T and it would not work.
Note: the ESP board on the schema isn't an exact reproduction pin-wise

## Box setup
We get some rough weather here in Florida and the air is often pretty humid, that's why I decided to go with an IP65 box that would be weatherproof.

 Because JSN-SR04T angle is super wide ([75](https://components101.com/sites/default/files/component_datasheet/JSN-SR04-Datasheet.pdf)°) I had to move the sensor away from my dock using a PVC pipe. I used PVC because it is cheap and light, easy to cut, and the box can handle it's weight

# Requirements
 - Arduino IDE
	 - Additional board manager URL: http://arduino.esp8266.com/stable/package_esp8266com_index.json
- The following libraries
	- ArduinoJson by Benoit Blanchon
	- ESP8266HTTPClient by Arduino
	- ESP8266WiFi by Arduino
	- HCSR04 by Martin Sonic
- IFTTT account
- Google account


## Hardware

What's needed for this project:
 - [TP4056](https://www.amazon.com/dp/B07PKND8KG?psc=1&amp;ref=ppx_yo2ov_dt_b_product_details&_encoding=UTF8&tag=skalache-20&linkCode=ur2&linkId=0cd9ea27e7e32310099742a9da0997c5&camp=1789&creative=9325)
 - [D1 Mini](https://www.amazon.com/Aokin-ESP8266-Internet-Development-Compatible/dp/B08MKLRSNH/?&_encoding=UTF8&tag=skalache-20&linkCode=ur2&linkId=f55a3bd9716e2a400b340a83700be39d&camp=1789&creative=9325)
 - [JSN-SR04T](https://www.amazon.com/dp/B07X5H77T7?psc=1&ref=ppx_yo2ov_dt_b_product_details)
- [Epoxy Solar Panel](https://www.amazon.com/dp/B0736W4HK1?psc=1&amp;ref=ppx_yo2ov_dt_b_product_details&_encoding=UTF8&tag=skalache-20&linkCode=ur2&linkId=1b6a063d330a6bee1932e44322e985bc&camp=1789&creative=9325)
 - [3000mAh Lipo Battery](https://www.amazon.com/dp/B09FL7QD88?psc=1&amp;ref=ppx_yo2ov_dt_b_product_details&_encoding=UTF8&tag=skalache-20&linkCode=ur2&linkId=e7640aea0cdd5f3e846f88d6d76a85e0&camp=1789&creative=9325)
 - [Dustproof Waterproof IP65 Electrical Boxes](%22https://www.amazon.com/dp/B0736W4HK1?psc=1&amp;ref=ppx_yo2ov_dt_b_product_details&_encoding=UTF8&tag=skalache-20&linkCode=ur2&linkId=1b6a063d330a6bee1932e44322e985bc&camp=1789&creative=9325)
 