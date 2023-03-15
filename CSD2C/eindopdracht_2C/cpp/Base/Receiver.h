#ifndef SimpleDataReceiver_h
#define SimpleDataReceiver_h
#pragma once
#include "Arduino.h"

/**
 * SimpleDataReceiver is een inheritance class die aan de basis staat van het ontvangen van het
 * 5byte protocol. Het beschrijft de vertaling van de twee data bytes naar hun oorspronkelijke
 * waarde.
*/

class SimpleDataReceiver {
  public:
    struct twoByte
    {
      byte val1;
      byte val2;
    };
    SimpleDataReceiver();
    SimpleDataReceiver(byte inBytes[5], int startByte, int stopByte, int id);
    virtual ~SimpleDataReceiver();
    bool match();
    bool match(bool await);
    long data();
    unsigned long dataUInt();
    long dataInt();
    double dataFloat();
    bool dataBool();
    twoByte dataBytes();

  protected:
    virtual void get();
    byte *inBytes;

  private:
    unsigned long checkTimeStart = 0;
    byte matchData[2];
    int id;
};

#endif
