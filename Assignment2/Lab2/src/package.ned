package lab2;

@license(LGPL);
//
// TODO documentation
//
network Game
{
    @display("bgb=567,260");
    submodules:
        player1: Player1 {
            @display("p=31,91");
        }
        player2: Player2 {
            @display("p=446,91");
        }
    connections:
        player1.out --> player2.in;
        player2.out --> player1.in;
}

