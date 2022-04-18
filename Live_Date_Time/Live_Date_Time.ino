//This program is for get live date and time from NTP WiFi Clinet, using WiFi module.
//Follow me for more awesome code.
//Linkediln- https://www.linkedin.com/in/uttam-basu/
//Github- https://github.com/UttamBasu


#include <NTPClient.h>
#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char WIFI_SSID[] = "Uttam";
const char WIFI_PASSWORD[] = "12345678";

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

// Variables to save date and time
String formattedTime;
String dayStamp;
String timeStamp;
String arr_days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup()
{
  Serial.begin(9600);
  Serial.println(String("Attempting to connect to SSID: ") + String(WIFI_SSID));
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  timeClient.begin();
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +5:30 for india
  // 5x60x60 = 18000
  // 30x60  = 1800
  // 18000+1800 = +19800  // TimeOffset
  timeClient.setTimeOffset(19800);
}
void loop()
{
  while (!timeClient.update())
  {
    timeClient.forceUpdate();
  }
  Serial.println("Hello All................................");
  // The formattedDate comes with the following format:
  // yyyy.mm.ddThh:mm:ssZ
  // We need to extract date and time
  //formattedDate = timeClient.getFormattedDate();
  formattedTime = timeClient.getFormattedTime();
  //Serial.println(formattedTime);

  // Extract date
  int splitT = formattedTime.indexOf("T");
  dayStamp = formattedTime.substring(0, splitT);
  Serial.print("TIME: ");
  Serial.println(dayStamp);                      // \n for new line

  // Extract time
  //  timeStamp = formattedTime.substring(splitT + 1, formattedTime.length() - 1);
  //  Serial.print("HOUR: ");
  //  Serial.println(timeStamp);
    int day = timeClient.getDay();
    Serial.println(arr_days[day]);  //  it will print day
    Serial.println(" ");
  delay(1000);
}
