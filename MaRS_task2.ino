#define REMOTEXY_MODE__WIFI_POINT

#include <ESP8266WiFi.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377
#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t const PROGMEM RemoteXY_CONF_PROGMEM[] =   // 54 bytes V19 
  { 255,2,0,0,0,47,0,19,0,0,0,0,31,1,106,200,1,1,2,0,
  10,38,52,24,24,48,4,26,31,79,78,0,31,79,70,70,0,10,35,103,
  24,24,48,4,26,31,79,78,0,31,79,70,70,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t pushSwitch_01; // =1 if state is ON, else =0, from 0 to 1
  uint8_t pushSwitch_02_dir; // =1 if state is ON, else =0, from 0 to 1

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////
int motorpin1 = D3;
int motorpin2 = D4;
int enablepin = D5;
int state;
uint8_t pushSwitch_01; // =1 if state is ON, else =0, from 0 to 1
uint8_t pushSwitch_02_dir; // =1 if state is ON, else =0, from 0 to 1

    // other variable
uint8_t connect_flag;  
void setup() 
{
  RemoteXY_Init ();  // initialization by macros 
  pinMode(motorpin1,OUTPUT);
  pinMode(motorpin2,OUTPUT);
  pinMode(enablepin,OUTPUT);
  digitalWrite(enablepin,HIGH);
  Serial.begin(9600);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXYEngine.handler ();   
  if(Serial.available()>0){
    state=Serial.read();
    connect_flag=0;
  }
  if(pushSwitch_01==0){
    digitalWrite(motorpin1,LOW);
    digitalWrite(motorpin2,LOW);
    if(connect_flag==0){
      Serial.println("motor:off");
      connect_flag=1;
    }
  }
  else if(pushSwitch_01==1 && pushSwitch_02_dir==1){
    digitalWrite(motorpin1,LOW);
    digitalWrite(motorpin2,HIGH);
    if (connect_flag==0){
      Serial.println("motor:right");
      connect_flag=1;
    }
  }
  else if(pushSwitch_01==1 && pushSwitch_02_dir==0){
    digitalWrite(motorpin1,HIGH);
    digitalWrite(motorpin2,LOW);
    if (connect_flag==0){
      Serial.println("motor:left");
      connect_flag=1;
    }
  }  

}
