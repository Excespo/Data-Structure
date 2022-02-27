#include <iostream>
#include "tabtenn0.h"

int main(){
    using std::cout;
    using std::endl;
    TableTennisPlayer player1("Tara", "Boomda", false);
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);

    rplayer1.Name(); // derived object use base method
    if (rplayer1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";

    player1.Name(); // base object use base method
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    
    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;

    // initialize RatedPlayer using TableTennisPlayer object
    RatedPlayer rplayer2(1200, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;

    return 0;
}

/* g++ -c tabletenn0.cpp usett0.cpp && g++ -o usett0.out tabletenn0.o usett0.o && ./usett0.out */