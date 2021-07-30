#include <Arduino.h>



//----------------------------------------------functions 

//---------------------------------------------convert char to a morse string
String charToMorse(char x){

  switch (x)
  {
  case 'a':
    return "._";
    break;

  case 'b':
  return "_...";
  break;

  case 'c':
  return "_._.";
  break;

  case 'd':
  return "_..";
  break;

  case 'e':
  return ".";
  break;

  case 'f':
  return ".._.";
  break;

  case 'g':
  return "__.";
  break;

  case 'h':
  return "....";
  break;

  case 'i':
  return "..";
  break;

  case 'j':
  return ".___";
  break;

  case 'k':
  return "_._";
  break;

  case 'l':
  return "._..";
  break;

  case 'm':
  return "__";
  break;

  case 'n':
  return "_.";
  break;

  case 'o':
  return "___";
  break;

  case 'p':
  return ".__.";
  break;

  case 'q':
  return "__._";
  break;

  case 'r':
  return "._.";
  break;

  case 's':
  return "...";
  break;

  case 't':
  return "_";
  break;

  case 'u':
  return ".._";
  break;

  case 'v':
  return "..._";
  break;

  case 'w':
  return ".__";
  break;

  case 'x':
  return "_.._";
  break;

  case 'y':
  return "_.__";
  break;

  case 'z':
  return "__..";
  break;
  //and so on...
  }
}
//--------------------------------------------joins all morse letters into a word
String stringToMorse(String str){
    String TranslatedString = "";
      for (int i = 0; i< str.length(); i++){
        String x = charToMorse(str[i]);//sending chars to the letters translator
        TranslatedString += x +" ";//appending morse letter to the word + space to know where the morse letter ends
      }

      return TranslatedString;
}
//----------------------------------------------------------------converting morse to blink pattern
void lightControl(String str){

  for (int i = 0; i< str.length(); i++){
      switch (str[i])
      {
      case '.':
        digitalWrite(LED_BUILTIN,HIGH);
        delay(500);
        digitalWrite(LED_BUILTIN,LOW);
        delay(500);
        break;
        
      case '_':
      digitalWrite(LED_BUILTIN,HIGH);
      delay(1500);
      digitalWrite(LED_BUILTIN,LOW);
      delay(500);
      break;

      default:
      digitalWrite(LED_BUILTIN,LOW);
      delay(1500);

      }
  }
}

//---------------------------------------------------------------set up
void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
 
}
//----------------------------------------------------------------loop
void loop(){
  String str = "shahar lavon ";

  String morseStr = stringToMorse(str);

  lightControl(morseStr);
}

