#define CATCH_CONFIG_MAIN // defines main() automatically
#include <catch2/catch.hpp>

#include "../Ctesconf.hpp"
#include "../CCasilla.hpp"
#include "../CasillaNormal.hpp"
#include "../CasillaEscalera.hpp"
#include "../CasillaSerpiente.hpp"
#include "../Tablero.hpp"
#include "../Jugador.hpp"
#include "../CDado.hpp"
#include "../GameManual.hpp"
#include "../GameAutomatic.hpp"
#include "../Game.hpp"
#include "chkFiles.hpp"

// Pruebas para casillas -----------------------------------------------------------

TEST_CASE("ex0", "[Casillas Base bien formadas]")
{   
    CCasilla c1, c2(2,"E"), c3(3,"S");

    SECTION( "Validando casillas Base normales" ) {
        REQUIRE( c1.getNumeroCasilla() == 1 );
        REQUIRE( c1.getTipo() == "N" );
        REQUIRE( c1.getSiguienteCasilla() == c1.getNumeroCasilla() + NOR_PREMIO_CASTIGO );
        REQUIRE( c2.getNumeroCasilla() == 2);
        REQUIRE( c2.getTipo() == "E" );
        REQUIRE( c2.getSiguienteCasilla() == c2.getNumeroCasilla() + NOR_PREMIO_CASTIGO);
        REQUIRE( c3.getNumeroCasilla() == 3);
        REQUIRE( c3.getTipo() == "S" );
        REQUIRE( c3.getSiguienteCasilla() == c3.getNumeroCasilla() + NOR_PREMIO_CASTIGO);
    }
}

TEST_CASE("ex1", "[Casillas Normales bien formadas]")
{   
    CasillaNormal c1, c2(3);

    SECTION( "Validando casillas Normales" ) {
        REQUIRE( c1.getNumeroCasilla() == 1 );
        REQUIRE( c1.getTipo() == "N" );
        REQUIRE( c1.getSiguienteCasilla() == c1.getNumeroCasilla() + NOR_PREMIO_CASTIGO);

        REQUIRE( c2.getNumeroCasilla() == 3 );
        REQUIRE( c2.getTipo() == "N" );
        REQUIRE( c2.getSiguienteCasilla() == c2.getNumeroCasilla() + NOR_PREMIO_CASTIGO);
    }
}

TEST_CASE("ex2", "[Casillas Escalera bien formadas]")
{   
    CasillaEscalera c1, c2(3);

    SECTION( "Validando casillas Escalera" ) {
        REQUIRE( c1.getNumeroCasilla() == 1 );
        REQUIRE( c1.getTipo() == "L" );
        REQUIRE( c1.getSiguienteCasilla() == c1.getNumeroCasilla() + ESC_PREMIO_CASTIGO );

        REQUIRE( c2.getNumeroCasilla() == 3 );
        REQUIRE( c2.getTipo() == "L" );
        REQUIRE( c2.getSiguienteCasilla() == c2.getNumeroCasilla() + ESC_PREMIO_CASTIGO );
    }
}

TEST_CASE("ex3", "[Casillas Serpiente bien formadas]")
{   
    CasillaSerpiente c1, c2(10);

    SECTION( "Validando casillas Serpiente" ) {
        REQUIRE( c1.getNumeroCasilla() == 1 - SER_PREMIO_CASTIGO );
        REQUIRE( c1.getTipo() == "S" );
        REQUIRE( c1.getSiguienteCasilla() == c1.getNumeroCasilla() + SER_PREMIO_CASTIGO);

        REQUIRE( c2.getNumeroCasilla() == 10 );
        REQUIRE( c2.getTipo() == "S" );
        REQUIRE( c2.getSiguienteCasilla() == c2.getNumeroCasilla() + SER_PREMIO_CASTIGO);
    }
}

TEST_CASE("ex4", "[Polimorfismo de casillas]")
{   
    CCasilla c1{CasillaNormal(1)}, c2{CasillaEscalera(3)}, c3{CasillaSerpiente(10)};

    SECTION( "Validando casillas Normales, Escalera, Serpiente polimorficamente" ) {
        REQUIRE( c1.getNumeroCasilla() == 1 );
        REQUIRE( c1.getTipo() == "N" );
        REQUIRE( c1.getSiguienteCasilla() == c1.getNumeroCasilla() + NOR_PREMIO_CASTIGO );

        REQUIRE( c2.getNumeroCasilla() == 3 );
        REQUIRE( c2.getTipo() == "L" );
        REQUIRE( c2.getSiguienteCasilla() == c2.getNumeroCasilla() + ESC_PREMIO_CASTIGO );

        REQUIRE( c3.getNumeroCasilla() == 10 );
        REQUIRE( c3.getTipo() == "S" );
        REQUIRE( c3.getSiguienteCasilla() == c3.getNumeroCasilla() + SER_PREMIO_CASTIGO );
    }
}

// Pruebas para Tablero -----------------------------------------------------------

TEST_CASE("ex5", "[Tablero bien formado]")
{   
    SECTION( "Validando Tablero en memoria" ) {

        Tablero t;

        t.setCasilla(CasillaEscalera(5), 5);
        t.setCasilla(CasillaEscalera(10), 10);
        t.setCasilla(CasillaEscalera(15), 15);

        t.setCasilla(CasillaSerpiente(7), 7);
        t.setCasilla(CasillaSerpiente(12), 12);
        t.setCasilla(CasillaSerpiente(25), 25);

        t.print();
        REQUIRE( true );
    }

    SECTION( "Validando desde Archivo" ) {
        Tablero tf("t1.tab");

        tf.print();
        REQUIRE( true );
    }

    SECTION( "Validando casillas en Tablero ") {
        Tablero tf("t1.tab");

        REQUIRE (tf.getCasilla(1).getNumeroCasilla()==1);
        REQUIRE (tf.getCasilla(1).getTipo()=="N");
        REQUIRE (tf.getCasilla(1).getSiguienteCasilla()==tf.getCasilla(1).getNumeroCasilla()+NOR_PREMIO_CASTIGO);

        REQUIRE (tf.getCasilla(10).getNumeroCasilla()==10);
        REQUIRE (tf.getCasilla(10).getTipo()=="L");
        REQUIRE (tf.getCasilla(10).getSiguienteCasilla()==tf.getCasilla(10).getNumeroCasilla()+ESC_PREMIO_CASTIGO);

        REQUIRE (tf.getCasilla(25).getNumeroCasilla()==25);
        REQUIRE (tf.getCasilla(25).getTipo()=="S");
        REQUIRE (tf.getCasilla(25).getSiguienteCasilla()==tf.getCasilla(25).getNumeroCasilla()+SER_PREMIO_CASTIGO);

    }
}

TEST_CASE("ex6", "[Jugador bien formado]")
{   
    SECTION( "Validando Jugador" ) {
        Jugador j(1), k(2);

        REQUIRE(j.getCasilla_actual()==1);

        k.setCasilla_actual(10);
        REQUIRE(k.getCasilla_actual()==10);
    }
}

TEST_CASE("ex7", "[Dado no aleatorio-secuencial]")
{   
    SECTION( "Validando Dado no aleatorio-secuencial" ) {
        CDado d(false);

        for (auto i=0; i < 12; i++)
        {
            std::cout << d.getValorDado() << "\n";
        }
        REQUIRE(true);
    }
}


TEST_CASE("ex8", "[Ejecucion de Juego Manual]")
{   
    SECTION( "Validando Ejecucion de Juego Manual" ) {
        Game *gm = new GameManual("t1.tab");

        gm->setDadoAleatorio(false);
        gm->setOutputToFile(true);

        gm->start();

        delete gm;
        
        REQUIRE(chkFiles("output", "test/toutput"));
    }
}

TEST_CASE("ex9", "[Ejecucion de Juego Automatico]")
{   
    SECTION( "Validando Ejecucion de Juego Automatico" ) {
        Game *ga = new GameAutomatic("t1.tab");

        ga->setDadoAleatorio(false);
        ga->setOutputToFile(true);

// Prueba que la entrada del juego es solo "C", no proviene ni del teclado, ni del archivo "input". Proviene del "Automata" imaginario ...
        bool isC=true;
        for (auto i=0; i<99; i++) 
            if (ga->getInput() != "C")
                isC=false;
        
        ga->start();

        delete ga;
            
        REQUIRE(isC);   
        REQUIRE(chkFiles("output", "test/toutput"));
    }
}
