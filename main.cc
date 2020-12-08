#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include 

int main () {
    cin.exceptions(ios::eofbit|ios::failbit);
    string cmd;
    Board board;
    while ( cin >> cmd ) {
        cout << "Builder <colour>'s turn" << endl;
    }
    try {
        while ( cin >> cmd ) {
            try {
                if ( cmd == "board" ) {
                    // print the current board;
                } else if ( cmd == "status" ) {
                    // print the current status of all builders in order from 0 to 3
                } else if ( cmd == "residences" ) {
                    // print the residences current builder has completed
                    try {
                        int r, c;
                        for ( std::cin >> r >> c; ; std::cin >> r >> c ) {
                            if ( r == -1 && c == -1 ) break;
                            g.turnOn(r,c);
                         } // for

                    } catch (std::invalid_argument & e) {
                        std::cerr << e.what() << std::endl;
                    } // catch

                } else if ( cmd == "step" ) {
                    g.tick();
                } else if ( cmd == "save" ) {
                    int n;
                    std::cin >> n;
                    for ( int i = 0; i < n; ++i ) g.tick();
                } else if ( cmd == "help" ) {
                    std::cout << g;
                } else {
                    cout << "Invalid command." << endl;
                }
            } catch (std::invalid_argument & e) {
                std::cerr << e.what() << std::endl;
            }  // catch
        } // while
    } catch (ios::failure &) {}  // Any I/O failure quits
} // main

