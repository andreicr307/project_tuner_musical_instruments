// set pin numbers:
int bit1=2;
int bit2=3;
int bit3=4;
int bit4=5;
int bit5=6;
int bit6=7;

//the library that defines the 16x2 LCD display module in arduino:
#include <LiquidCrystal.h>

//defining the pins related to the display:
LiquidCrystal lcd(P2_3, P2_4, P2_5, P1_6, P1_7, P2_7);


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


const int buttonPin2 = 8; //inainte pe pinul 8
const int buttonPin1 = 9; //inapoi pe pinul 9
const int buttonPin3 = 10; //OK pe pinul 10

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

int instrSel = 0;
int notaChitaraSel = 1;
int notaVioaraSel = 1;
int notaTrombonSel = 1;

void setup()
{  
  // initialize the digital pin as an output.
  pinMode(bit1, OUTPUT);
  pinMode(bit2, OUTPUT);
  pinMode(bit3, OUTPUT); 
  pinMode(bit4, OUTPUT);
  pinMode(bit5, OUTPUT);
  pinMode(bit6, OUTPUT);
  
  pinMode(buttonPin1, INPUT_PULLUP); 
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  
  lcd.begin(16, 2);
  
  //begin welcome
  lcd.setCursor(1,0);
  lcd.print("BINE ATI VENIT !");
  delay(3000);
  lcd.clear();
  
  lcd.setCursor(1,0);
  lcd.print("Aparat     de");
  lcd.setCursor(1,1);
  lcd.print("   acordaj");
  //end welcome
  }
  
void citireButoane(){
// read the state of the pushbutton value:

  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
}

void afisChitara(){  
// enter the guitar menu
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Chitara");
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
    instrSel == 2;
    afisVioara();
  }
  
  if(buttonState2 == LOW){  
    instrSel = 3;
    afisTrombon();
  }
  if(buttonState3 == LOW)
    afisNota1Chitara();
}

void afisVioara(){  
// enter the violin menu
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Vioara");
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
    instrSel == 3;
    afisTrombon();
  }
  
  if(buttonState2 == LOW){  
    instrSel = 1;
    afisChitara();  
  }
  
  if(buttonState3 == LOW)
    afisNota1Vioara();
}

void afisTrombon(){  
// enter the trombone menu
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Trombon");
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
    instrSel == 1;
    afisChitara();
  }
  
  if(buttonState2 == LOW){  
    instrSel = 2;
    afisVioara();
  }
  
  if(buttonState3 == LOW)
    afisNota1Trombon();
}

//musical notes guitar - note chitara
void afisNota1Chitara(){  //Nota1Chitara
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("1. Mi -  Chitara");  //first note Mi - E
  lcd.setCursor(0,1);
  lcd.print("f = 329.2 Hz");
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
     notaChitaraSel == 2;
     afisNota2Chitara();   
   }
   
  if(buttonState2 == LOW){  
    notaChitaraSel = 0;
    afisInapoiChitara();
  }
  
  if(buttonState3 == LOW)
    sunetNota1Chitara();
}

void afisNota2Chitara(){  //Nota2Chitara
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("2. Si - Chitara"); //second note Si - B
  lcd.setCursor(0,1);
  lcd.print("f = 246.9 Hz");
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
     notaChitaraSel == 3;
     afisNota3Chitara();
   }
   
  if(buttonState2 == LOW){  
    notaChitaraSel = 1;
    afisNota1Chitara(); 
  }
  
  if(buttonState3 == LOW)
    sunetNota2Chitara();
}

void afisNota3Chitara(){  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("3. Sol - Chitara"); //Nota3Chitara - the third note Sol - G
  lcd.setCursor(0,1);
  lcd.print("f = 196 Hz");
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
     notaChitaraSel == 4;
    afisNota4Chitara();
  }
  
  if(buttonState2 == LOW){  
    notaChitaraSel = 2;
    afisNota2Chitara(); 
  }
  
  if(buttonState3 == LOW)
    sunetNota3Chitara();
}

void afisNota4Chitara(){  //Nota4Chitara
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("4. Re - Chitara"); // the fourth note Re - D
  lcd.setCursor(0,1);
  lcd.print("f = 146.83 Hz");
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
     notaChitaraSel == 5;
     afisNota5Chitara();
  }
  
  if(buttonState2 == LOW){  
    notaChitaraSel = 3;
    afisNota3Chitara(); 
  }
  
  if(buttonState3 == LOW)
    sunetNota4Chitara();
 }
 
void afisNota5Chitara(){  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("5. La - Chitara"); //Nota5 Chitara - the fifth note La - A
  lcd.setCursor(0,1);
  lcd.print("f = 110 Hz");
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
     notaChitaraSel == 6;
     afisNota6Chitara();
   }
   
  if(buttonState2 == LOW){  
    notaChitaraSel = 4;
    afisNota4Chitara(); 
  }
  
  if(buttonState3 == LOW)
    sunetNota5Chitara();
}

void afisNota6Chitara(){  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("6. Mi - Chitara"); //Nota6 Chitara - the sixth note Mi - E
  lcd.setCursor(0,1);
  lcd.print("f = 82.41 Hz");
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
     notaChitaraSel == 0;
     afisInapoiChitara();  
  }
  
  if(buttonState2 == LOW){  
    notaChitaraSel = 5;
    afisNota5Chitara();
  }
  if(buttonState3 == LOW)
    sunetNota6Chitara();
}

void afisInapoiChitara(){  
// the return menu 
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Inapoi");
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
     notaChitaraSel == 1;
     afisNota1Chitara();
   }
   
  if(buttonState2 == LOW){  
    notaChitaraSel = 6;
    afisNota6Chitara(); 
  }
  
  if(buttonState3 == LOW)
    afisChitara();
}
//end guitar notes - sfarsit note chitara

// violin notes - note vioara
void afisNota1Vioara(){  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("1. Sol - Vioara"); //Nota1 Vioara - first violin note Sol - G
  lcd.setCursor(0,1);
  lcd.print("f = 196 Hz"); //the frequency corresponding to the note
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
     notaChitaraSel == 2;
     afisNota2Vioara();   
  }

  if(buttonState2 == LOW){  
    notaVioaraSel = 0;
    afisInapoiVioara();
  }
  
  if(buttonState3 == LOW)
    sunetNota1Vioara();
}

void afisNota2Vioara(){  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("2. Re - Vioara"); //Nota2 Vioara - the second note Re - D
  lcd.setCursor(0,1);
  lcd.print("f = 293.7 Hz"); //the frequency corresponding to the note
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
     notaVioaraSel == 3;
     afisNota3Vioara();
  }
  
  if(buttonState2 == LOW){  
    notaVioaraSel = 1;
    afisNota1Vioara();  
  }  
  
  if(buttonState3 == LOW)
    sunetNota2Vioara();
}  

void afisNota3Vioara(){  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("3. La - Vioara");  //Nota3 Vioara - the third note La - A
  lcd.setCursor(0,1);
  lcd.print("f = 440 Hz"); //the frequency corresponding to the note
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
     notaVioaraSel == 4;
     afisNota4Vioara();
  }
  
  if(buttonState2 == LOW){  
    notaVioaraSel = 2;
    afisNota2Vioara();  
  }
  
  if(buttonState3 == LOW)
    sunetNota3Vioara();
}

void afisNota4Vioara(){  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("4. Mi - Vioara"); //Nota4 Vioara - the fourth note Mi - E
  lcd.setCursor(0,1);
  lcd.print("f = 659.3 Hz"); // the frequency corresponding to the note
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
     notaVioaraSel == 0;
     afisInapoiVioara();
   }
   
  if(buttonState2 == LOW){  
    notaVioaraSel = 3;
    afisNota3Vioara();
  }
  
  if(buttonState3 == LOW)
    sunetNota4Vioara();
}

void afisInapoiVioara(){  
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Inapoi");
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
     notaVioaraSel == 1;
     afisNota1Vioara();
  }
  
  if(buttonState2 == LOW){  
    notaVioaraSel = 4;
    afisNota4Vioara();
  }
  if(buttonState3 == LOW)
    afisVioara();
}
//sfarsit note vioara

//inceput note trombon
void afisNota1Trombon(){  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("1. Fa - Trombon"); //Nota1 Trombon - first trombone note Fa - F
  lcd.setCursor(0,1);
  lcd.print("f = 349.2 Hz"); //the frequency corresponding to the note
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
     notaTrombonSel == 2;
     afisNota2Trombon();
   }
  
  if(buttonState2 == LOW){  
    notaTrombonSel = 0;
    afisInapoiTrombon();
  }
  
  if(buttonState3 == LOW)
    sunetNota1Trombon();
}

void afisNota2Trombon(){  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("2. La - Trombon");  //Nota2 Trombon - second trombone note La - A
  lcd.setCursor(0,1);
  lcd.print("f = 440 Hz"); //the frequency corresponding to the note
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
     notaTrombonSel == 0;
     afisInapoiTrombon();
   }
   
  if(buttonState2 == LOW){  
    notaTrombonSel = 1;
    afisNota1Vioara(); 
  }
  
  if(buttonState3 == LOW)
    sunetNota2Trombon();
}

void afisInapoiTrombon(){  
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Inapoi");
  delay(1000);
  citireButoane();
  
  while((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState3 == HIGH))
    citireButoane();
  
  if(buttonState1 == LOW){  
     notaTrombonSel == 1;
     afisNota1Trombon();
   }
   
  if(buttonState2 == LOW){  
    notaTrombonSel = 2;
    afisNota2Trombon(); 
  }
  
  if(buttonState3 == LOW)
    afisTrombon();
}
//end trombone notes - sfarsit note trombon

//do stuff - sending data to the digital-analog converter on the high position:
void doStaffHigh(int i){  
  if(i == 0)
    digitalWrite(bit1, HIGH);
  if(i == 1)
    digitalWrite(bit2, HIGH);
  if(i == 2)
    digitalWrite(bit3, HIGH);
  if(i == 3)
    digitalWrite(bit4, HIGH);
  if(i == 4)
    digitalWrite(bit5, HIGH);
  if(i == 5)
    digitalWrite(bit6, HIGH);
 //delay(0.00227);
  }

//sending data to the digital-analog converter on the low position:
void doStaffLow(int i){  
  if(i == 0)
    digitalWrite(bit1, LOW);
  if(i == 1)
    digitalWrite(bit2, LOW);
  if(i == 2)
    digitalWrite(bit3, LOW);
  if(i == 3)
    digitalWrite(bit4, LOW);
  if(i == 4)
    digitalWrite(bit5, LOW);
  if(i == 5)
    digitalWrite(bit6, LOW);
  //delay(0.00227);
  }
//end do stuff

//guitar notes - note chitara
//sending the appropriate bits to generate note 1 for the guitar instrument:
void sunetNota1Chitara(){ 
  delay(1000); 
  citireButoane(); //the function for reading the state of the buttons
  
  while(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH){ 
    int v[60]={0, 3, 6 ,9, 15, 19, 20, 25, 30,37, 43, 64,43,37, 30, 25, 20, 19, 15, 9, 6, 3, 0, -3, -6 ,-9, -15, -19, -20, -25, -30,-37, -43, -64,-43,-37, -30, -25, -20, -19, -15, -9, -6, -3, 0 };
  
    for(int g = 0; g < 440; ++g){  
    	for (int k = 0; k < 65; ++k){  
    	  int j = 0, r, num, arr[6];
          // initializez vectorul arr
          for(int j = 0; j < 6; ++j)arr[j] = 0;
          // descompunerea lui v[k] in baza 2
          num = v[k];
          while (num != 0) {  
    	      r = num % 2;
    	      arr[j++] = r;
    	      num /= 2;
    	    }
    
          int i=5;
          while(arr[i] == 0)i--;
              
          while(i >= 0){  
            if(arr[i] == 1)
              doStaffHigh(i);
            else
              doStaffLow(i);
            i--;
            }

          delayMicroseconds(18.6);
        }
      }
      citireButoane(); //the function for reading the state of the buttons
    }
    afisNota1Chitara();
  }

void sunetNota2Chitara(){ 
//sending the appropriate bits to generate note 2 for the guitar instrument:
  delay(1000); 
  citireButoane(); 
  
  while(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH){ 
    int v[60]={ 0, 3, 6 ,9, 15, 19, 20, 25, 30,37, 43, 75,43,37, 30, 25, 20, 19, 15, 9, 6, 3, 0, -3, -6 ,-9, -15, -19, -20, -25, -30,-37, -43, -75,-43,-37, -30, -25, -20, -19, -15, -9, -6, -3, 0 };
  
    for(int g = 0; g < 440; ++g){  
    	for (int k = 0; k < 65; ++k){  
    	  int j = 0, r, num, arr[6];
          // initializez vectorul arr
          for(int j = 0; j < 6; ++j)arr[j] = 0;
          // descompunerea lui v[k] in baza 2
          num = v[k];
          while (num != 0) {  
    	      r = num % 2;
    	      arr[j++] = r;
    	      num /= 2;
    	    }
    
          int i=5;
          while(arr[i] == 0)i--;
              
          while(i >= 0){  
            if(arr[i] == 1)
              doStaffHigh(i);
            else
              doStaffLow(i);
            i--;
            }
          
          delayMicroseconds(35.2);
        }
      }
      citireButoane();
    }
    afisNota2Chitara();
  }

void sunetNota3Chitara(){
//sending the appropriate bits to generate note 3 for the guitar instrument:
  delay(1000); 
  citireButoane();  
  
  while(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH){  
    int v[60]={0, 3, 6 ,9, 15, 19, 20, 25, 30,37, 43, 75,43,37, 30, 25, 20, 19, 15, 9, 6, 3, 0, -3, -6 ,-9, -15, -19, -20, -25, -30,-37, -43, -75,-43,-37, -30, -25, -20, -19, -15, -9, -6, -3, 0 };
    
    for(int g = 0; g < 440; ++g){  
    	for (int k = 0; k < 65; ++k){  
    	  int j = 0, r, num, arr[6];
          // initializez vectorul arr
          for(int j = 0; j < 6; ++j)arr[j] = 0;
          // descompunerea lui v[k] in baza 2
          num = v[k];
          while (num != 0) {  
    	      r = num % 2;
    	      arr[j++] = r;
    	      num /= 2;
    	    }
    
          int i=5;
          while(arr[i] == 0)i--;
              
          while(i >= 0){  
            if(arr[i] == 1)
              doStaffHigh(i);
            else
              doStaffLow(i);
            i--;
            }
          
          delayMicroseconds(50);
        }
      }
      citireButoane();
    }
    afisNota3Chitara();
  }

void sunetNota4Chitara(){
//sending the appropriate bits to generate note 4 for the guitar instrument:
  delay(1000); 
  citireButoane();
  
  while(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH){  
    int v[60]={ 0, 3, 6 ,9, 15, 19, 20, 25, 30,37, 43, 75,43,37, 30, 25, 20, 19, 15, 9, 6, 3, 0, -3, -6 ,-9, -15, -19, -20, -25, -30,-37, -43, -75,-43,-37, -30, -25, -20, -19, -15, -9, -6, -3, 0 };
  
    for(int g = 0; g < 440; ++g){  
    	for (int k = 0; k < 65; ++k){  
    	  int j = 0, r, num, arr[6];
          // initializez vectorul arr
          for(int j = 0; j < 6; ++j)arr[j] = 0;
          // descompunerea lui v[k] in baza 2
          num = v[k];
          while (num != 0) {  
    	      r = num % 2;
    	      arr[j++] = r;
    	      num /= 2;
    	    }
    
          int i=5;
          while(arr[i] == 0)i--;
              
          while(i >= 0){  
            if(arr[i] == 1)
              doStaffHigh(i);
            else
              doStaffLow(i);
            i--;
            }
          
          delayMicroseconds(76);
        }
      }
      citireButoane();
    }
    afisNota4Chitara();
  }

void sunetNota5Chitara(){
//sending the appropriate bits to generate note 5 for the guitar instrument:
  delay(1000); 
  citireButoane();  
  
  while(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH){  
    int v[60]={ 0, 3, 6 ,9, 15, 19, 20, 25, 30,37, 43, 75,43,37, 30, 25, 20, 19, 15, 9, 6, 3, 0, -3, -6 ,-9, -15, -19, -20, -25, -30,-37, -43, -75,-43,-37, -30, -25, -20, -19, -15, -9, -6, -3, 0 };
  
    for(int g = 0; g < 440; ++g){  
    	for (int k = 0; k < 65; ++k){  
    	  int j = 0, r, num, arr[6];
          // initializez vectorul arr
          for(int j = 0; j < 6; ++j)arr[j] = 0;
          // descompunerea lui v[k] in baza 2
          num = v[k];
          while (num != 0) {  
    	      r = num % 2;
    	      arr[j++] = r;
    	      num /= 2;
    	    }
    
          int i=5;
          while(arr[i] == 0)i--;
              
          while(i >= 0){  
            if(arr[i] == 1)
              doStaffHigh(i);
            else
              doStaffLow(i);
            i--;
            }
          
          delayMicroseconds(109);
        }
      }
      citireButoane();
    }
    afisNota5Chitara();
  }

void sunetNota6Chitara(){
//sending the appropriate bits to generate note 6 for the guitar instrument:  
  delay(1000); 
  citireButoane();
  
  while(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH){  
    int v[60]={ 0, 3, 6 ,9, 15, 19, 20, 25, 30,37, 43, 68,43,37, 30, 25, 20, 19, 15, 9, 6, 3, 0, -3, -6 ,-9, -15, -19, -20, -25, -30,-37, -43, -68,-43,-37, -30, -25, -20, -19, -15, -9, -6, -3, 0 };
  
    for(int g = 0; g < 440; ++g){  
    	for (int k = 0; k < 65; ++k){  
    	  int j = 0, r, num, arr[6];
          // initializez vectorul arr
          for(int j = 0; j < 6; ++j)arr[j] = 0;
          // descompunerea lui v[k] in baza 2
          num = v[k];
          while (num != 0) {  
    	      r = num % 2;
    	      arr[j++] = r;
    	      num /= 2;
    	    }
    
          int i=5;
          while(arr[i] == 0)i--;
              
          while(i >= 0){  
            if(arr[i] == 1)
              doStaffHigh(i);
            else
              doStaffLow(i);
            i--;
            }
          
          delayMicroseconds(161.4958);
        }
      }
      citireButoane();
    }
    afisNota6Chitara();
}
//end nota chitara


//note vioara 
//sending the appropriate bits to generate note 1 for the violin instrument:
void sunetNota1Vioara(){
  delay(1000); 
  citireButoane();  
  
  while(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH){  
    int v[60]={ 0, 3, 6 ,9, 15, 19, 20, 25, 30,37, 43, 63,43,37, 30, 25, 20, 19, 15, 9, 6, 3, 0, -3, -6 ,-9, -15, -19, -20, -25, -30,-37, -43, -63,-43,-37, -30, -25, -20, -19, -15, -9, -6, -3, 0 };
  
    for(int g = 0; g < 440; ++g){  
    	for (int k = 0; k < 65; ++k){  
    	  int j = 0, r, num, arr[6];
          // initializez vectorul arr
          for(int j = 0; j < 6; ++j)arr[j] = 0;
          // descompunerea lui v[k] in baza 2
          num = v[k];
          while (num != 0) {  
    	      r = num % 2;
    	      arr[j++] = r;
    	      num /= 2;
    	    }
    
          int i=5;
          while(arr[i] == 0)i--;
              
          while(i >= 0){  
            if(arr[i] == 1)
              doStaffHigh(i);
            else
              doStaffLow(i);
            i--;
            }
          
          delayMicroseconds(50);
        }
      }
      citireButoane();
    }
    afisNota1Vioara();
  }

//sending the appropriate bits to generate note 2 for the violin instrument:
void sunetNota2Vioara(){
  delay(1000); 
  citireButoane();  
  
  while(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH){ 
    int v[60]={ 0, 3, 6 ,9, 15, 19, 20, 25, 30,37, 43, 64,43,37, 30, 25, 20, 19, 15, 9, 6, 3, 0, -3, -6 ,-9, -15, -19, -20, -25, -30,-37, -43, -64,-43,-37, -30, -25, -20, -19, -15, -9, -6, -3, 0 };
  
    for(int g = 0; g < 440; ++g){  
    	for (int k = 0; k < 65; ++k){  
    	  int j = 0, r, num, arr[6];
          // initializez vectorul arr
          for(int j = 0; j < 6; ++j)arr[j] = 0;
          // descompunerea lui v[k] in baza 2
          num = v[k];
          while (num != 0) {  
    	      r = num % 2;
    	      arr[j++] = r;
    	      num /= 2;
    	    }
    
          int i=5;
          while(arr[i] == 0)i--;
              
          while(i >= 0){  
            if(arr[i] == 1)
              doStaffHigh(i);
            else
              doStaffLow(i);
            i--;
            }
          
          delayMicroseconds(25.071);
        }
      }
      citireButoane();
    }
    afisNota2Vioara();
  }

//sending the appropriate bits to generate note 3 for the violin instrument:
void sunetNota3Vioara(){
  delay(1000); 
  citireButoane();  
  
  while(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH){ 
    int v[60]={ 0, 3, 6 ,9, 15, 19, 20, 25, 30,37, 43, 63,43,37, 30, 25, 20, 19, 15, 9, 6, 3, 0, -3, -6 ,-9, -15, -19, -20, -25, -30,-37, -43, -63,-43,-37, -30, -25, -20, -19, -15, -9, -6, -3, 0 };
  
    for(int g = 0; g < 440; ++g){  
    	for (int k = 0; k < 65; ++k){  
    	  int j = 0, r, num, arr[6];
          // initializez vectorul arr
          for(int j = 0; j < 6; ++j)arr[j] = 0;
          // descompunerea lui v[k] in baza 2
          num = v[k];
          while (num != 0) {  
    	      r = num % 2;
    	      arr[j++] = r;
    	      num /= 2;
    	    }
    
          int i=5;
          while(arr[i] == 0)i--;
              
          while(i >= 0){  
            if(arr[i] == 1)
              doStaffHigh(i);
            else
              doStaffLow(i);
            i--;
            }
          
          delayMicroseconds(7.548);
        }
      }
      citireButoane();
    }
    afisNota3Vioara();
  }

//sending the appropriate bits to generate note 4 for the violin instrument:
void sunetNota4Vioara(){
  delay(1000); 
  citireButoane();  
  
  while(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH){ 
    int v[60]={ 0, 3, 6 ,9, 15, 19, 20, 25, 30,37, 43, 63,43,37, 30, 25, 20, 19, 15, 9, 6, 3, 0, -3, -6 ,-9, -15, -19, -20, -25, -30,-37, -43, -63,-43,-37, -30, -25, -20, -19, -15, -9, -6, -3, 0 };
  
    for(int g = 0; g < 440; ++g){  
    	for (int k = 0; k < 65; ++k){  
    	  int j = 0, r, num, arr[6];
          // initializez vectorul arr
          for(int j = 0; j < 6; ++j)arr[j] = 0;
          // descompunerea lui v[k] in baza 2
          num = v[k];
          while (num != 0) {  
    	      r = num % 2;
    	      arr[j++] = r;
    	      num /= 2;
    	    }
    
          int i=5;
          while(arr[i] == 0)i--;
              
          while(i >= 0){  
            if(arr[i] == 1)
              doStaffHigh(i);
            else
              doStaffLow(i);
            i--;
            }
          
          delayMicroseconds(0.855);
        }
      }
      citireButoane();
    }
    afisNota4Vioara();
  }
//end notes violin 

//notes for trombone

//sending the appropriate bits to generate note 1 for the trombone instrument:
void sunetNota1Trombon(){
  delay(1000); 
  citireButoane();  
  
  while(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH){  
    int v[60]={ 0, 3, 6 ,9, 15, 19, 20, 25, 30,37, 43, 64,43,37, 30, 25, 20, 19, 15, 9, 6, 3, 0, -3, -6 ,-9, -15, -19, -20, -25, -30,-37, -43, -64,-43,-37, -30, -25, -20, -19, -15, -9, -6, -3, 0 };
  
    for(int g = 0; g < 440; ++g){  
    	for (int k = 0; k < 65; ++k){  
    	  int j = 0, r, num, arr[6];
          // initializez vectorul arr
          for(int j = 0; j < 6; ++j)arr[j] = 0;
          // descompunerea lui v[k] in baza 2
          num = v[k];
          while (num != 0) {  
    	      r = num % 2;
    	      arr[j++] = r;
    	      num /= 2;
    	    }
    
          int i=5;
          while(arr[i] == 0)i--;
              
          while(i >= 0){  
            if(arr[i] == 1)
              doStaffHigh(i);
            else
              doStaffLow(i);
            i--;
            }
          
          delayMicroseconds(17.49);
        }
      }
      citireButoane(); 
    }
    afisNota1Trombon();
  }

//sending the appropriate bits to generate note 2 for the trombone instrument:

void sunetNota2Trombon(){
  delay(1000); 
  citireButoane(); 
  
  while(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH){ 
    citireButoane(); 
    int v[60]={ 0, 3, 6 ,9, 15, 19, 20, 25, 30,37, 43, 63,43,37, 30, 25, 20, 19, 15, 9, 6, 3, 0, -3, -6 ,-9, -15, -19, -20, -25, -30,-37, -43, -63,-43,-37, -30, -25, -20, -19, -15, -9, -6, -3, 0 };
  
    for(int g = 0; g < 440; ++g){  
    	for (int k = 0; k < 65; ++k){  
    	  int j = 0, r, num, arr[6];
          // initializez vectorul arr
          for(int j = 0; j < 6; ++j)arr[j] = 0;
          // descompunerea lui v[k] in baza 2
          num = v[k];
          while (num != 0) {  
    	      r = num % 2;
    	      arr[j++] = r;
    	      num /= 2;
    	    }
    
          int i=5;
          while(arr[i] == 0)i--;
              
          while(i >= 0){  
            if(arr[i] == 1)
              doStaffHigh(i);
            else
              doStaffLow(i);
            i--;
            }
          
          delayMicroseconds(7.548);
        }
      }
      citireButoane(); 
    }
    afisNota2Trombon();
  }
//end notes trombone

void loop()
{  

  // put your main code here, to run repeatedly:
  // read the state of the pushbutton value:
  // loop to initialize the LCD menu:

  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  
  if (buttonState3 == LOW) {  
    delay(3000);
    if(instrSel == 0)
      {afisChitara();      //entering the guitar display menu
      }
  if(instrSel == 1){
      afisNota1Chitara();  
      }
      
    if(instrSel == 2){
      afisNota1Vioara();
      }
    if(instrSel == 3){
      afisNota1Trombon();
      
    }  
  }
  if (buttonState2 == LOW){  
    
    
    if(instrSel == 0){  
      instrSel = 1;
      afisChitara();
      
      }
    if(instrSel == 1){  
      instrSel = 3;
      afisTrombon();
      
      }
    if(instrSel == 2){  
      instrSel = 1;
      afisChitara();
      
      }
    if(instrSel == 3){  
      instrSel = 2;
      afisVioara();
      
      }
    }
  if (buttonState1 == LOW){  
    
    
    if(instrSel == 0){  
      instrSel = 1;
      afisChitara();
      
    }
    if(instrSel == 1){  
      instrSel = 2;
      afisVioara();
      
    }
    if(instrSel == 2){  
      instrSel = 3;
      afisTrombon();
      
    }
    if(instrSel == 3){  
      instrSel = 1;
      afisChitara();
      
      }
    }
  delay(30);
  }
