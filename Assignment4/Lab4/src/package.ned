package lab4;

@license(LGPL);
//
// TODO documentation
//
network Network
{
    @display("bgb=749,310");
    submodules:
        sender: Sender {
            @display("p=94,120");
        }
        reciever: Reciever {
            @display("p=348,120");
        }
    connections:
        sender.out --> reciever.in;
        reciever.out --> sender.in;
}

