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

#include "Player1.h"

Define_Module(Player1);

void Player1::initialize()
{
    //generate the random number
    this->par("number") =int( uniform(0, 10));
    EV <<"the number is "<<this->par("number").intValue()<<endl;
    cMessage * msg=new cMessage("start");
             send(msg,"out");
    // TODO - Generated method body
}

void Player1::handleMessage(cMessage *msg)
{
   int guessNumber = atoi(msg->getName());
   if(guessNumber==par("number").intValue())
       {
       msg->setName("correct guess");
       }
   else
   {
       msg->setName("wrong guess");
   }
   EV <<msg->getName()<<endl;
   EV <<"the guessed number is "<<guessNumber<<endl;
    send(msg,"out");

    // TODO - Generated method body
}
