#include <SPI.h>
#include <SD.h>

const int buzzer = 9; //bzucak je na pinu deve to je v pravo dole na chipu

File data;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT); //inicializace pinu pro bzucak
}

unsigned long previousPulse = 0;
unsigned long lastPulse = 0;

int state = -1;
int count = 0;
int soucet = 0;

void loop() {
    
  int value = analogRead(A4); //<-----------------------------------nahraje hodnotu pinu A4 tu pak bud primo zobrazime nebo s ni este manipulujeme 
  lastPulse = millis();
  
  if(Serial.available() > 0){ //<----------------------------------cteni prikazu
    char command = Serial.read();

    if(command == '0'){//<---------------------------------------------konec
      state = 0;
      data.close();
      Serial.println("Konec zapisu");

      
    }else if(command == '1'){ //<--------------------------------------start
      state = 1;

      if (!SD.begin()) { //<-------------------------------------------------------inicializace SD karty
        Serial.println("SD card initialization failed. Try again");
      }
      
      data = SD.open("log.txt", FILE_WRITE);
      Serial.println("Zapis");
    }     
  }
  
  if(value>750){
    tone(buzzer, 1000);  //<--------------------------bzuc pokud je hodnota vetsi nez 800 
  }else{
    noTone(buzzer);    //<---------------------------
  }

  if(value > 990 && (lastPulse - previousPulse) > 250){
    int perioda = lastPulse - previousPulse; //<--------------------------------perioda
    int tep = 60000/perioda; //<-----------------------tepu za minutu 
    previousPulse = lastPulse;
    soucet += tep;
    count++;
    if(state == 1){//<---------------------------------------zapis dat na sd kartu ve formatu "tep, perioda (ms), prumerny tep (od spusteni), cas od spusteni
      data.print(tep);
      data.print(" ");
      data.print(perioda);
      data.print(" ");
      data.print(soucet/count); //<-----------------------------prumerny tep
      data.print(" ");
      data.println(float(millis())/1000); //<---------------------------------cas v sekundach od spusteni programu
    }
  }
  if(state == -1)
    Serial.println(value); //<-----------------------------------------------tisk prubehu na monitor
}
