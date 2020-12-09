#include <MusicBuzzer.h>

/*
  Using sensors to turn on the music

  Written November 2020 by Lynn Lerat

--Connection
  Plug the first and second LEDs to pin 8 and 7 respectively
  The photoresistor is on pin A0 while the TMP sensor is plugged into pin A1
  
  Using music libraries from:
  Author: Everton Ramires
  More Tutorial: https://www.youtube.com/channel/UC7zG4YQJc8v-9jNGQknOx5Q

  Based on the great work of robsoncouto at github (https://github.com/robsoncouto/arduino-songs).

  CURRENT SONG OPTIONS:
  (PT-BR)OPÇÕES ATUAIS DE MUSICAS:


  music.asabranca();
  music.babyelephantwalk();
  music.bloodytears();
  music.brahmslullaby();
  music.cannonind();
  music.cantinaband();
  music.doom();
  music.furelise();
  music.gameofthrones();
  music.greenhill();
  music.greensleeves();
  music.happybirthday();
  music.harrypotter();
  music.imperialmarch();
  music.jigglypuffsong();
  music.keyboardcat();
  music.merrychristmas();
  music.miichannel();
  music.minuetg();
  music.nevergonnagiveyouup();
  music.odetojoy();
  music.pinkpanther();
  music.princeigor();
  music.professorlayton();
  music.pulodagaita();
  music.silentnight();
  music.songofstorms();
  music.startrekintro();
  music.starwars();
  music.supermariobros();
  music.takeonme();
  music.tetris();
  music.thegodfather();
  music.thelick();
  music.thelionsleepstonight();
  music.vampirekiller();
  music.zeldaslullaby();
  music.zeldatheme();
*/

#define buzzerpin 11

//constants
const int buttonPin = 2;
const int ledPin = 8;
const int ledPin2 = 7;
const int photoPin = A0;


//variables
int photo_value;


float AnalogToVolts(int reading);


// the setup function runs once when you press reset or power the board
void setup()
{
  Serial.begin (9600);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  //music
  music.init(buzzerpin);

}

// the loop function runs over and over again forever
void loop()
{
  int reading;
  float volts;
  float celcius;

  //read voltage from the photoresistor
  photo_value = analogRead(photoPin);

  Serial.print (F("Photo value: "));
  Serial.print (photo_value);
  Serial.print ("\t");

  //temperature reading
  reading = analogRead (A1);
  volts = AnalogToVolts(reading);  //Function call

  //Celcius conversion
  celcius = volts * 100 - 50;
  Serial.print ("       ");
  Serial.print ("C: ");
  Serial.print (celcius);

  if (photo_value < 40)
  {
    digitalWrite (ledPin, LOW);

    //music
    music.odetojoy();

    Serial.print (" ");
    Serial.print (F("LED:OFF "));

    Serial.print (" ");
    Serial.print (F("Enjoy the music!"));
  }
  else
  {
    if (celcius < 20)
    {
      digitalWrite (ledPin2, LOW);

      music.asabranca();

      Serial.print ("      ");
      Serial.print ("Enjoy the music!") ;
    }
    else
    {
      digitalWrite (ledPin2, HIGH);

      Serial.print ("      ");
      Serial.print ("Rest easy!");
    }

    digitalWrite (ledPin, HIGH);

    Serial.print (" ");
    Serial.print (F("LED:ON "));

    Serial.print (" ");
    Serial.println (F("Rest easy!"));
  }

}

// Function Definition
float AnalogToVolts(int reading)
{
  float volts;

  volts = reading / 1023.0 * 5.0; //Perform conversion
  return volts; //Return result
}
