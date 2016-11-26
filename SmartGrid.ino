/*
 * This is a project is based on the grid systme 
 * how the grid and renewabel(like solar) power can combine 
 * and how the renewable sources(like:solar) can manage maintanance itself
 * Abdullah Al Mamun,EEE(EWU)
 *Dhaka, Bangladesh
 *26/11/2016
 */


#include <LiquidCrystal.h>                          //LCD screen 16*2
#include <SoftwareSerial.h>

LiquidCrystal lcd(12, 11, 5, 4, 7, 8); // here we give 3 as 7 and 2 as 8

SoftwareSerial mySerial(2,3); //RX,TX

int a=0;

void setup()
{
  mySerial.begin(9600);               // the GPRS baud rate   
  Serial.begin(9600);                // baud rate 
  delay(500);
 pinMode(13,INPUT); 
 
 lcd.begin(16, 2);
  lcd.setCursor(1, 0);
  lcd.print("Central Office");
}

void loop() {

if(digitalRead(13)==HIGH){ 
 Serial.println(digitalRead(12)); 
 problem();
}
  delay(500);
  // delay(1000);
   // delay(5000);
Serial.println(a);
  
  if(a==1){                   //Send the problem massage to the central office
  if(digitalRead(13)==HIGH){
   lcd.setCursor(1, 0);
  lcd.print("Central Office");
  lcd.setCursor(0,1);
  lcd.print("Sector 1 problem");
  
    a=1;
  }
  if(digitalRead(13)==LOW){        // send the problem solution massage to the central office
  lcd.setCursor(1, 0);
  lcd.print("Central Office");
  lcd.setCursor(0, 1);
 lcd.print("                 ");
  
    a=0;
  }
  }

}


  void problem()
  {
  mySerial.println("AT+CMGF=1");    //Because we want to send the SMS in text mode
  delay(1000);
  mySerial.println("AT + CMGS = \"+88019xxxxxxxx\"\r");//send sms message, be careful need to add a country code before the cellphone number
  delay(1000);
  mySerial.println("Your solar plan has a problem.Please monitor it!!!");//the content of the message
  delay(100);
  mySerial.println((char)26);//the ASCII code of the ctrl+z is 26 
  delay(100);
  mySerial.println(); 
a=1;
  delay(4000);
  
  mySerial.println("AT+CMGF=1");    //Because we want to send the SMS in text mode
  delay(1000);
  mySerial.println("AT + CMGS = \"+88016xxxxxxxx\"\r");//send sms message, be careful need to add a country code before the cellphone number
  delay(1000);
  mySerial.println("There is a problem in House:26;Road:12;Rampura.");//the content of the message
  delay(100);
  mySerial.println((char)26);//the ASCII code of the ctrl+z is 26
  delay(100);
  mySerial.println(); 
  
    }


