//This program is for get live date and time from NTP WiFi Clinet, using WiFi module.
//Follow me for more awesome code.
//Linkediln- https://www.linkedin.com/in/uttam-basu/
//Github- https://github.com/UttamBasu

//Usefull Link for Calculation
//http://www.cplusplus.com/reference/ctime/strftime/
//See https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv for Timezone codes for your region


#include <NTPClient.h>
#include <ESP8266WiFi.h> // or #include <WiFI.h> for ESP32
#include <time.h>
void setup() 
{
  Serial.begin(9600);
  WiFi.begin("Uttam", "12345678");
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");
  setenv("TZ","IST-5:30", 1);
  delay(5000);
}

void loop() 
{
  Serial.println(get_time());
  delay(1000);
}

String get_time() 
{
  time_t now;
  time(&now);
  char time_output[30];
  // See http://www.cplusplus.com/reference/ctime/strftime/ for strftime functions
  strftime(time_output, 30, "%A  %d-%m-%y %T", localtime(&now));
  return String(time_output); // returns Monday 18-04-2022 18:20:45
}
