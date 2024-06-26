#pragma once

#include "Ctesconf.hpp"
#include "Tablero.hpp"
#include "Jugador.hpp"
#include "CDado.hpp"
#include <fstream>
#include <ostream>

class Game {
protected:
    Tablero t;
    Jugador j[MAX_JUGADORES];
    CDado d;
    bool swio; // IO por Archivo=true, IO por Teclado=false

// Archivos de entrada/salida para el caso de configuracion de IO por archivos ---------
    std::ifstream fi{"input"};
    std::ofstream fo{"output"};    
public:
    static int turno;
    Game();
// Game("Archivo de tablero", Dado aleatorio=true/false, IO por Archivo=true, IO por Teclado=false)
    Game(std::string, bool, bool);
    void start();
    void outMsg(std::string);
    virtual std::string getInput()=0;
};
