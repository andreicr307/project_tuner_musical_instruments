/*The circuit:
 =================================
 LCD pin              Connect to
 ---------------------------------
 01 - GND             GND, pot
 02 - VCC             +3.3V
 03 - Contrast        Pot wiper
 04 - RS              Pin11 (P2.3)
 05 - R/W             GND
 06 - EN              Pin12 (P2.4)
 07 - DB0             
 08 - DB1             
 09 - DB2             
 10 - DB3             
 11 - DB4             Pin13 (P2.5)
 12 - DB5             Pin14 (P1.6)
 13 - DB6             Pin15 (P1.7)
 14 - DB7             Pin18 (P2.7)
 15 - BL+             +3.3V
 16 - BL-             GND
 =================================
 
 */

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(P2_3, P2_4, P2_5, P1_6, P1_7, P2_7);


const int buttonPin2 = 8; //inainte pe pinul 8
const int buttonPin1 = 9; //inapoi pe pinul 9
const int buttonPin3 = 10; //OK pe pinul 10

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

int bit1=2; //Definesc pinii
int bit2=3;
int bit3=4;
int bit4=5;
int bit5=6;
int bit6=7;

void SelectInstr(){
  
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Selectati");
  lcd.setCursor(1,1);
  lcd.print("Instrumentul:");
}

void setup()
{ 
  pinMode(bit1, OUTPUT);
  pinMode(bit2, OUTPUT);
  pinMode(bit3, OUTPUT);
  pinMode(bit4, OUTPUT);
  pinMode(bit5, OUTPUT);
  pinMode(bit6, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP); 
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  
  lcd.setCursor(1,0);
  lcd.print("BINE ATI VENIT !");
  delay(3000);
  lcd.clear();
  
  lcd.setCursor(1,0);
  lcd.print("Aparat     de");
  lcd.setCursor(1,1);
  lcd.print("   acordaj");
  delay(3000);
  lcd.clear();
  
  SelectInstr();
      
      
      // put your setup code here, to run once:
}

void loop()
{
  //if(digitalRead(...)==LOW)
  
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  
  
 int a[3]; int ab[6]; int ac[4]; int ad[2];
 
 int j=0; //Parcurg instrumentele
 if(buttonState1 == LOW){
      for(int i=0;i<=3;i++) 
      {a[j]=i;
      j++;
        if(a[j]=0)
           {lcd.clear();
           lcd.setCursor(1,0);
           lcd.print("Chitara");}
         if(a[j]=1){
           lcd.clear();
           lcd.setCursor(1,0);
           lcd.print("Trombon");}
         if(a[j]=2){
           lcd.clear();
           lcd.setCursor(1,0);
           lcd.print("Vioara"); }
      } }
      if(buttonState2 == LOW)
      {a[j]=i;
      j--;}
      if(buttonState3 == LOW)
          switch(a[j]){
           case 1:
           lcd.clear();
           lcd.setCursor(1,0);
           lcd.print("Chitara");
           break;
           case 2:
           lcd.clear();
           lcd.setCursor(1,0);
           lcd.print("Trombon");
           break;
           case 3:
           lcd.clear();
           lcd.setCursor(1,0);
           lcd.print("Vioara");
           break;
           
 } 
 } 

int k=0;   //Parcurg notele instrument 1
 for(int i=0;i<=6;i++){
      if(buttonState1 == LOW) 
      {ab[k]=i;
      j++;}
      if(buttonState2 == LOW)
      {ab[k]=i;
      j--;}
 }
 
int l=0;    //Parcurg notele instrument 2
 for(int i=0;i<=4;i++){
       if(buttonState1 == LOW) 
      {ac[l]=i;
      j++;}
      if(buttonState2 == LOW)
      {ac[l]=i;
      j--;}
 }
 
int m=0;    //Parcurg notele instrument 3
 for(int i=0;i<=4;i++){
       if(buttonState1 == LOW) 
      {ad[m]=i;
      j++;}
      if(buttonState2 == LOW)
      {ad[m]=i;
      j--;}
 }
 
 /* if(buttonState3 == LOW)
  { lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Chitara");
      { if(buttonState1 == LOW)
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("Trombon");
          lcd.clear();
              if(buttonState3 == LOW){
                 lcd.clear();
                 lcd.setCursor(1,0);
                 lcd.print("Selectati  o");
                 lcd.setCursor(1,1);
                 lcd.print("   nota:");
                 delay(3000); }
                 
      }
        if(buttonState2 == LOW){
            lcd.clear();
            lcd.setCursor(1,0);
            lcd.print("Vioara");
             if(buttonState3 == LOW){
                 lcd.clear();
                 lcd.setCursor(1,0);
                 lcd.print("Selectati  o");
                 lcd.setCursor(1,1);
                 lcd.print("   nota:");
                 delay(3000);}
        }       
      }
  
*/
  
  // put your main code here, to run repeatedly:
  
}

/* Note:     

              //1   lcd.clear();
                    lcd.setCursor(1,0);
                    lcd.print("  1.");
                    lcd.setCursor(1,1);
                    lcd.print("   MI");
              //2   lcd.clear();
                    lcd.setCursor(1,0);
                    lcd.print("  2.");
                    lcd.setCursor(1,1);
                    lcd.print("   FA");
              //3   lcd.clear();
                    lcd.setCursor(1,0);
                    lcd.print("  3.");
                    lcd.setCursor(1,1);
                    lcd.print("   SOL");
              //4   lcd.clear();
                    lcd.setCursor(1,0);
                    lcd.print("  4.");
                    lcd.setCursor(1,1);
                    lcd.print("   RE");
              //5   lcd.clear();
                    lcd.setCursor(1,0);
                    lcd.print("  5.");
                    lcd.setCursor(1,1);
                    lcd.print("   LA");
              //6   lcd.clear();
                    lcd.setCursor(1,0);
                    lcd.print("  6.");
                    lcd.setCursor(1,1);
                    lcd.print("   SI"); */
