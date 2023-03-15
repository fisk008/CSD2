/**********************************************************************
*          Copyright (c) 2023, Hogeschool voor de Kunsten Utrecht
*                      Utrecht, the Netherlands
*                          All rights reserved
***********************************************************************
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.
*  If not, see <http://www.gnu.org/licenses/>.
***********************************************************************
*
*  File name     : SimpleData.h
*  System name   : SimpleData
*
*  Description   : SimpleData is a library for reading data from a serial
*
*  Authors       : Jochem van Iterson
*  E-mails       : jochem.vaniterson@audioware.nl
*
**********************************************************************/

#ifndef SimpleData_h
#define SimpleData_h

// -------------------------------------------------------------------------- //
// --------------------------------- SERIAL --------------------------------- //
// -------------------------------------------------------------------------- //
#define SERIAL_MESSAGE_LENGTH 5

static byte inBytesSerial[SERIAL_MESSAGE_LENGTH];

static void getSerial(byte inBytes[SERIAL_MESSAGE_LENGTH]) {
  if (Serial.available()) {
    Serial.readBytes((char *)inBytes, SERIAL_MESSAGE_LENGTH);
    return;
  }
}
static void clearInputSerial(byte inBytes[SERIAL_MESSAGE_LENGTH]) {
  memset(inBytes, 0, SERIAL_MESSAGE_LENGTH);
}

static void printDataBuffer(byte *inBytes){
  Serial.print("Data: ");
  for (int i = 0; i < SERIAL_MESSAGE_LENGTH; i++) {
    if (i > 0) Serial.print(", ");
    Serial.print(inBytes[i]);
  }
}
#endif
