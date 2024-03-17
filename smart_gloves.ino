
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 13); //RX=pin 10, TX=pin 13


const int button1 = 6;
int buttonStatus1 = 0; //led connected here
const int button2 = 7;
int buttonStatus2 = 0;


int vrbutton1 = 8;
int vrbutton2 = 9;

//push button connected here





void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);//This opens up communications to the GPS
  Serial.println("GPS Start");//Just show to the monitor that the sketch has started
  

  pinMode(button1, LOW);
  pinMode(button2, LOW);
 
  pinMode(vrbutton1, OUTPUT);
  pinMode(vrbutton2, OUTPUT);

}

void loop() {
 
  buttonStatus1 = digitalRead(button1);
  buttonStatus2 = digitalRead(button2);



  if (buttonStatus1 == HIGH)
  {

   
    mySerial.println("AT+CMGF=1");    //To send SMS in Text Mode
    delay(1000);
    mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r"); //Change xxxxxxxxxx to your destination phone number
    delay(1000);
   mySerial.println("food");
    mySerial.println((char)26); //the stopping character Ctrl+Z
    delay(3000);
    
    digitalWrite(vrbutton1, LOW);
    delay(1000);
    digitalWrite(vrbutton1, HIGH);

  }


  if (buttonStatus2== HIGH)
  {

    
    mySerial.println("AT+CMGF=1");    //To send SMS in Text Mode
    delay(1000);
    mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r"); //Change xxxxxxxxxx to your destination phone number
    delay(1000);
    mySerial.println("medicine");//the content of the message
    delay(200);
    mySerial.println((char)26); //the stopping character Ctrl+Z
    delay(1000);
    delay(3000);
    
    digitalWrite(vrbutton2, LOW);
    delay(1000);
    digitalWrite(vrbutton2, HIGH);


  }
}
  
