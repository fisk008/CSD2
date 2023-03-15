#ifndef SimpleSerialReceiver_h
#define SimpleSerialReceiver_h

#include "Arduino.h"

#include "../Base/Receiver.h"

/**
 * SimpleSerialReceiver inherit de beschrijving van SimpleDataReceiver. De serial receiver zorgt
 * dat de Arduino serial input werkt met de basis class.
*/

class SimpleSerialReceiver : public SimpleDataReceiver {
  public:
    SimpleSerialReceiver();
    SimpleSerialReceiver(byte inBytes[5], int startByte, int stopByte, int id);
    ~SimpleSerialReceiver();
  protected:
    void get();
};

#endif
