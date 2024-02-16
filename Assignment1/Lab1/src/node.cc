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

#include "node.h"
#include <string>

Define_Module(Node);

void Node::initialize()
{
    if(strcmp(this->getName(),"tic")==0)
        {
            cMessage * msg=new cMessage("tic_0");
            send(msg,"out");
        }
    // TODO - Generated method body
}

void Node::handleMessage(cMessage *msg)
{
    std::string message;
    char value = msg->getName()[4];
    int number = value -'0';
    if(number<9)
    {
    message = (strcmp(this->getName(), "tic") == 0) ? "tic_" : "toc_";
    message += std::to_string(++number);
    send(new cMessage(message.c_str()),"out");
    }
    // TODO - Generated method body
}
