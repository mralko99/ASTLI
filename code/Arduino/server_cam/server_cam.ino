#include "WiFiConnect.h" 
#include <esp32cam.h>
#include <WiFiClient.h> 
#include <WebServer.h> 
#include <HTTPClient.h>

int LED_BUILTIN = 33;
void blink(int temp){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(temp);
  digitalWrite(LED_BUILTIN, LOW);
  delay(temp);
}

WebServer server(80);
 
static auto loRes = esp32cam::Resolution::find(320, 240);
static auto midRes = esp32cam::Resolution::find(350, 530);
static auto hiRes = esp32cam::Resolution::find(800, 600);
void serveJpg()
{
  auto frame = esp32cam::capture();
  if (frame == nullptr) {
    Serial.println("CAPTURE FAIL");
    server.send(503, "", "");
    return;
  }
  Serial.printf("CAPTURE OK %dx%d %db\n", frame->getWidth(), frame->getHeight(),
                static_cast<int>(frame->size()));
 
  server.setContentLength(frame->size());
  server.send(200, "image/jpeg");
  WiFiClient client = server.client();
  frame->writeTo(client);
}
 
void handleJpgLo()
{
  if (!esp32cam::Camera.changeResolution(loRes)) {
    Serial.println("SET-LO-RES FAIL");
  }
  serveJpg();
}
 
void handleJpgHi()
{
  if (!esp32cam::Camera.changeResolution(hiRes)) {
    Serial.println("SET-HI-RES FAIL");
  }
  serveJpg();
}
 
void handleJpgMid()
{
  if (!esp32cam::Camera.changeResolution(midRes)) {
    Serial.println("SET-MID-RES FAIL");
  }
  serveJpg();
}



WiFiConnect wc;

// For internet connection
WiFiClient client;
HTTPClient http;
 
void configModeCallback(WiFiConnect *mWiFiConnect) {
  Serial.println("Entering Access Point");
}


void startWiFi(boolean showParams = false) {
 
  wc.setDebug(true);
  
  /* Set our callbacks */
  wc.setAPCallback(configModeCallback);

  //wc.resetSettings(); //helper to remove the stored wifi connection, comment out after first upload and re upload

    /*
       AP_NONE = Continue executing code
       AP_LOOP = Trap in a continuous loop - Device is useless
       AP_RESET = Restart the chip
       AP_WAIT  = Trap in a continuous loop with captive portal until we have a working WiFi connection
    */
    if (!wc.autoConnect()) { // try to connect to wifi
      /* We could also use button etc. to trigger the portal on demand within main loop */
      wc.startConfigurationPortal(AP_WAIT);//if not connected show the configuration portal
      digitalWrite(LED_BUILTIN, HIGH);
    }
}


void setup() {
  pinMode (LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  while (!Serial) {
    delay(100);
  }
  Serial.println("....");
  Serial.println("....");
  delay (5000);
  startWiFi();
  using namespace esp32cam;
  Config cfg;
  cfg.setPins(pins::AiThinker);
  cfg.setResolution(hiRes);
  cfg.setBufferCount(2);
  cfg.setJpeg(80);

  bool ok = Camera.begin(cfg);
  Serial.println(ok ? "CAMERA OK" : "CAMERA FAIL");

  if (ok){
    Serial.print("http://");
    Serial.println(WiFi.localIP());
    Serial.println("  /cam-lo.jpg");
    Serial.println("  /cam-hi.jpg");
    Serial.println("  /cam-mid.jpg");
   
    server.on("/cam-lo.jpg", handleJpgLo);
    server.on("/cam-hi.jpg", handleJpgHi);
    server.on("/cam-mid.jpg", handleJpgMid);
    
    server.begin();
  }
  else{
    Serial.print("RESET");
    while(true){
      blink(100);
      }
    }

}

void loop() {
    server.handleClient();
    
    blink(1000);
    // Wifi Dies? Start Portal Again
    if (WiFi.status() != WL_CONNECTED) {
      ESP.restart();
      //if (!wc.autoConnect()) wc.startConfigurationPortal(AP_WAIT);
    }
}
