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

#include "Center.h"

Define_Module(Center);

void Center::initialize()
{
    EV<<"starting Hub "<<this->getIndex()<<endl;
     scheduleAt(simTime()+this->par("interval"),new cMessage(""));
     // TODO - Generated method body
}

void Center::handleMessage(cMessage *msg)
{
    int n =getParentModule()->par("N");
      int m = int(uniform(0,n));
      if(msg->isSelfMessage())
      {
           msg->setName("hello from hub");
           cGate *myPort = gate("port$o", m);
            send(msg, myPort);

      }
      else{
          scheduleAt(simTime()+this->par("interval"),new cMessage(""));
      }
    // TODO - Generated method body
}
