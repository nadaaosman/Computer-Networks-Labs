//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Reciever.h"
#include <bitset>
Define_Module(Reciever);

void Reciever::initialize()
{
    // TODO - Generated method body
    send(new cMessage("start"), "out");

}

void Reciever::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    std::string Message = msg->getName();
    std::string charCount =  std::bitset<8>(Message[0]).to_string();
    std::string paritySend =  std::bitset<8>(Message[Message.length() - 1]).to_string();
    std::string data = Message.substr(1, Message.length() - 2);
             // Calculate even parity for the character count and the data bits
    std::string parity;
    std::string one_character;
    std::string bitstream;

                     for(int i=0;i<8;i++)
                     {
                         int columnParity = charCount[charCount.length() - 1 - i] - '0';
                                  for (int j = 0; j < data.length(); j++) {
                                      if(i==0)
                                      {
                                      bitstream += std::bitset<8>((int)data[j]).to_string();
                                      }
                                      one_character= std::bitset<8>((int)data[j]).to_string();

                                      columnParity^=(one_character[one_character.length() - 1 - i] - '0');
                                  }
                                  parity += (columnParity == 0) ? '0' : '1';
                              }

                     std::string reversedString;
                     // Loop through the inputString in reverse and append characters to reversedString
                     for (int i = parity.length() - 1; i >= 0; i--) {
                         reversedString += parity[i];
                     }
                     parity = reversedString;

               // Add the column parity to the bit stream

               if(parity == paritySend)
               {
                   EV << "original Message:" << data<< "\n";
               }
               else
               {
                   EV<<"error in the Message"<<"\n";
               }

               msg->setName("continue");
                          send(msg, "out");

}
