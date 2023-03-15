#include "Receiver.h"

SimpleSerialReceiver::SimpleSerialReceiver() : SimpleDataReceiver(){}
SimpleSerialReceiver::SimpleSerialReceiver(byte inBytes[5], int startByte, int stopByte, int id) :
  SimpleDataReceiver(inBytes, startByte, stopByte, id)
{}
SimpleSerialReceiver::~SimpleSerialReceiver() {}

void SimpleSerialReceiver::get(){
  
}
