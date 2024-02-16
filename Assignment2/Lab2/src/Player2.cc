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

#include "Player2.h"
#include <string>
Define_Module(Player2);

void Player2::initialize()
{
    // TODO - Generated method body
}

void Player2::handleMessage(cMessage *msg)
{
    if(strcmp(msg->getName(),"correct guess")==0)
    {
        cancelAndDelete(msg);
    }
    else{
    std::string guessNumberStr = std::to_string(par("guessNumber").intValue());
    msg->setName(guessNumberStr.c_str());
        send(msg,"out");
    }
    // TODO - Generated method body
}
