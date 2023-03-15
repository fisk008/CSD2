#include "Receiver.h"

/**
 * Lege constructor van SimpleDataReceiver
*/
SimpleDataReceiver::SimpleDataReceiver(){}

/**
 * Constructor van SimpleDataReceiver
 * @param inBytes Pointer naar de input buffer
 * @param startByte Start byte
 * @param stopByte Stop byte
 * @param id id nummer van de poort
*/
SimpleDataReceiver::SimpleDataReceiver(byte inBytes[5], int startByte, int stopByte, int id){
  matchData[0] = startByte;
  matchData[1] = stopByte;
  this->id = id;
  this->inBytes = inBytes;
}

SimpleDataReceiver::~SimpleDataReceiver() {}
void SimpleDataReceiver::get() {}

bool SimpleDataReceiver::match(){return match(false);}

/**
 * Kijkt of de start-, stop- en id bytes kloppen.
 * @param await Boolean of de code moet wachten tot input ontvangen is. Default naar false. Anders
 * wacht hij 100 miliseconden
*/
bool SimpleDataReceiver::match(bool await){
  if(await) this->get();
  bool response = false;
  checkTimeStart = millis();
  do {
    response =
      (this->inBytes[0] == matchData[0]) &&
      (this->inBytes[1] == id) &&
      (this->inBytes[4] == matchData[1]);
    // printDataBuffer(this->inBytes);
    if(!response && await){
      if(millis() - checkTimeStart > 10){
        Serial.println("Timeout");
        return false;
      }
      this->get();
    } else {
      await = false;
    }
  } while(await);
  return response;
}
unsigned long SimpleDataReceiver::dataUInt(){
  return inBytes[2]*256+inBytes[3];
}
long SimpleDataReceiver::dataInt(){
  long value = inBytes[2]*256+inBytes[3];
  value -= 32.768;
  return value;
}
double SimpleDataReceiver::dataFloat(){
  double value = inBytes[2]*256+inBytes[3];
  value -= 32.768;
  value /= 100.;
  return value;
}
bool SimpleDataReceiver::dataBool(){
  return inBytes[3] != 0;
}
SimpleDataReceiver::twoByte SimpleDataReceiver::dataBytes() {
  SimpleDataReceiver::twoByte returnable;
  returnable.val1 = inBytes[2];
  returnable.val2 = inBytes[3];
  return returnable;
}
