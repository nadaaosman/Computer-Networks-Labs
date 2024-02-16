package assignment3_req1;

@license(LGPL);
//
// TODO documentation
//
network Network
{
      parameters:
        int N ;
    submodules:
        nodes[N]: Node;
        HUB: Center;
    connections:
        for i=0..N-1 {
            nodes[i].port <--> HUB.port++;
        }
}

