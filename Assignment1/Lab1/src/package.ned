package lab1;

@license(LGPL);
//
// TODO documentation
//
network section
{
    @display("bgb=574,162");
    submodules:
        tic: Node {
            @display("p=84,56");
        }
        toc: Node {
            @display("p=471,59");
        }
    connections:
        tic.out --> toc.in;
        toc.out --> tic.in;
}

