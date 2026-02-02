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
        INFO("FUNCIONALIDAD ESPERADA: La casilla base debe iniciar en 1.\nSUGERENCIA DE PROGRAMACIÓN: Verifica el valor inicial en el constructor por omisión de CCasilla.");
        REQUIRE( c1.getNumeroCasilla() == 1 );
        INFO("FUNCIONALIDAD ESPERADA: El tipo de casilla base debe ser 'N'.\nSUGERENCIA DE PROGRAMACIÓN: Revisa el valor por defecto del atributo tipo en CCasilla.");
        REQUIRE( c1.getTipo() == "N" );
        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe ser la actual más NOR_PREMIO_CASTIGO.\nSUGERENCIA DE PROGRAMACIÓN: Asegúrate de que getSiguienteCasilla() sume correctamente el premio/castigo.");
        REQUIRE( c1.getSiguienteCasilla() == c1.getNumeroCasilla() + NOR_PREMIO_CASTIGO );
        INFO("FUNCIONALIDAD ESPERADA: El número de casilla debe coincidir con el valor dado al constructor.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la asignación del parámetro en el constructor de CCasilla.");
        REQUIRE( c2.getNumeroCasilla() == 2);
        INFO("FUNCIONALIDAD ESPERADA: El tipo debe ser 'E' para casilla especial.\nSUGERENCIA DE PROGRAMACIÓN: Revisa la asignación del tipo en el constructor.");
        REQUIRE( c2.getTipo() == "E" );
        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe considerar NOR_PREMIO_CASTIGO.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la lógica de getSiguienteCasilla().");
        REQUIRE( c2.getSiguienteCasilla() == c2.getNumeroCasilla() + NOR_PREMIO_CASTIGO);
        INFO("FUNCIONALIDAD ESPERADA: El número de casilla debe ser 3.\nSUGERENCIA DE PROGRAMACIÓN: Confirma que el constructor asigne correctamente el número.");
        REQUIRE( c3.getNumeroCasilla() == 3);
        INFO("FUNCIONALIDAD ESPERADA: El tipo debe ser 'S' para casilla serpiente.\nSUGERENCIA DE PROGRAMACIÓN: Revisa la lógica de asignación del tipo.");
        REQUIRE( c3.getTipo() == "S" );
        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe sumar NOR_PREMIO_CASTIGO.\nSUGERENCIA DE PROGRAMACIÓN: Asegúrate de que la suma sea correcta.");
        REQUIRE( c3.getSiguienteCasilla() == c3.getNumeroCasilla() + NOR_PREMIO_CASTIGO);
    }
}

TEST_CASE("ex1", "[Casillas Normales bien formadas]")
{   
    CasillaNormal c1, c2(3);

    SECTION( "Validando casillas Normales" ) {
        INFO("FUNCIONALIDAD ESPERADA: CasillaNormal debe iniciar en 1 si no se indica otro valor.\nSUGERENCIA DE PROGRAMACIÓN: Revisa el constructor por omisión de CasillaNormal.");
        REQUIRE( c1.getNumeroCasilla() == 1 );
        INFO("FUNCIONALIDAD ESPERADA: El tipo de CasillaNormal debe ser 'N'.\nSUGERENCIA DE PROGRAMACIÓN: Verifica el valor de tipo en CasillaNormal.");
        REQUIRE( c1.getTipo() == "N" );
        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe sumar NOR_PREMIO_CASTIGO.\nSUGERENCIA DE PROGRAMACIÓN: Revisa la función getSiguienteCasilla().");
        REQUIRE( c1.getSiguienteCasilla() == c1.getNumeroCasilla() + NOR_PREMIO_CASTIGO);

        INFO("FUNCIONALIDAD ESPERADA: El número de casilla debe ser 3.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la asignación del parámetro en el constructor.");
        REQUIRE( c2.getNumeroCasilla() == 3 );
        INFO("FUNCIONALIDAD ESPERADA: El tipo debe ser 'N'.\nSUGERENCIA DE PROGRAMACIÓN: Revisa el valor asignado a tipo.");
        REQUIRE( c2.getTipo() == "N" );
        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe sumar NOR_PREMIO_CASTIGO.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la suma en getSiguienteCasilla().");
        REQUIRE( c2.getSiguienteCasilla() == c2.getNumeroCasilla() + NOR_PREMIO_CASTIGO);
    }
}

TEST_CASE("ex2", "[Casillas Escalera bien formadas]")
{   
    CasillaEscalera c1, c2(3);

    SECTION( "Validando casillas Escalera" ) {
        INFO("FUNCIONALIDAD ESPERADA: CasillaEscalera debe iniciar en 1 si no se indica otro valor.\nSUGERENCIA DE PROGRAMACIÓN: Revisa el constructor por omisión de CasillaEscalera.");
        REQUIRE( c1.getNumeroCasilla() == 1 );
        INFO("FUNCIONALIDAD ESPERADA: El tipo de CasillaEscalera debe ser 'L'.\nSUGERENCIA DE PROGRAMACIÓN: Verifica el valor de tipo en CasillaEscalera.");
        REQUIRE( c1.getTipo() == "L" );
        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe sumar ESC_PREMIO_CASTIGO.\nSUGERENCIA DE PROGRAMACIÓN: Revisa la función getSiguienteCasilla().");
        REQUIRE( c1.getSiguienteCasilla() == c1.getNumeroCasilla() + ESC_PREMIO_CASTIGO );

        INFO("FUNCIONALIDAD ESPERADA: El número de casilla debe ser 3.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la asignación del parámetro en el constructor.");
        REQUIRE( c2.getNumeroCasilla() == 3 );
        INFO("FUNCIONALIDAD ESPERADA: El tipo debe ser 'L'.\nSUGERENCIA DE PROGRAMACIÓN: Revisa el valor asignado a tipo.");
        REQUIRE( c2.getTipo() == "L" );
        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe sumar ESC_PREMIO_CASTIGO.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la suma en getSiguienteCasilla().");
        REQUIRE( c2.getSiguienteCasilla() == c2.getNumeroCasilla() + ESC_PREMIO_CASTIGO );
    }
}

TEST_CASE("ex3", "[Casillas Serpiente bien formadas]")
{   
    CasillaSerpiente c1, c2(10);

    SECTION( "Validando casillas Serpiente" ) {
        INFO("FUNCIONALIDAD ESPERADA: CasillaSerpiente debe iniciar en 1 menos SER_PREMIO_CASTIGO si no se indica otro valor.\nSUGERENCIA DE PROGRAMACIÓN: Revisa el constructor por omisión de CasillaSerpiente.");
        REQUIRE( c1.getNumeroCasilla() == 1 - SER_PREMIO_CASTIGO );
        INFO("FUNCIONALIDAD ESPERADA: El tipo de CasillaSerpiente debe ser 'S'.\nSUGERENCIA DE PROGRAMACIÓN: Verifica el valor de tipo en CasillaSerpiente.");
        REQUIRE( c1.getTipo() == "S" );
        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe sumar SER_PREMIO_CASTIGO.\nSUGERENCIA DE PROGRAMACIÓN: Revisa la función getSiguienteCasilla().");
        REQUIRE( c1.getSiguienteCasilla() == c1.getNumeroCasilla() + SER_PREMIO_CASTIGO);

        INFO("FUNCIONALIDAD ESPERADA: El número de casilla debe ser 10.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la asignación del parámetro en el constructor.");
        REQUIRE( c2.getNumeroCasilla() == 10 );
        INFO("FUNCIONALIDAD ESPERADA: El tipo debe ser 'S'.\nSUGERENCIA DE PROGRAMACIÓN: Revisa el valor asignado a tipo.");
        REQUIRE( c2.getTipo() == "S" );
        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe sumar SER_PREMIO_CASTIGO.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la suma en getSiguienteCasilla().");
        REQUIRE( c2.getSiguienteCasilla() == c2.getNumeroCasilla() + SER_PREMIO_CASTIGO);
    }
}

TEST_CASE("ex4", "[Polimorfismo de casillas]")
{   
    CCasilla c1{CasillaNormal(1)}, c2{CasillaEscalera(3)}, c3{CasillaSerpiente(10)};

    SECTION( "Validando casillas Normales, Escalera, Serpiente polimorficamente" ) {
        INFO("FUNCIONALIDAD ESPERADA: El número de casilla debe ser 1 para CasillaNormal.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la correcta construcción y conversión polimórfica.");
        REQUIRE( c1.getNumeroCasilla() == 1 );
        INFO("FUNCIONALIDAD ESPERADA: El tipo debe ser 'N' para CasillaNormal.\nSUGERENCIA DE PROGRAMACIÓN: Revisa la herencia y el método getTipo().");
        REQUIRE( c1.getTipo() == "N" );
        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe sumar NOR_PREMIO_CASTIGO.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la función getSiguienteCasilla().");
        REQUIRE( c1.getSiguienteCasilla() == c1.getNumeroCasilla() + NOR_PREMIO_CASTIGO );

        INFO("FUNCIONALIDAD ESPERADA: El número de casilla debe ser 3 para CasillaEscalera.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la correcta construcción y conversión polimórfica.");
        REQUIRE( c2.getNumeroCasilla() == 3 );
        INFO("FUNCIONALIDAD ESPERADA: El tipo debe ser 'L' para CasillaEscalera.\nSUGERENCIA DE PROGRAMACIÓN: Revisa la herencia y el método getTipo().");
        REQUIRE( c2.getTipo() == "L" );
        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe sumar ESC_PREMIO_CASTIGO.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la función getSiguienteCasilla().");
        REQUIRE( c2.getSiguienteCasilla() == c2.getNumeroCasilla() + ESC_PREMIO_CASTIGO );

        INFO("FUNCIONALIDAD ESPERADA: El número de casilla debe ser 10 para CasillaSerpiente.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la correcta construcción y conversión polimórfica.");
        REQUIRE( c3.getNumeroCasilla() == 10 );
        INFO("FUNCIONALIDAD ESPERADA: El tipo debe ser 'S' para CasillaSerpiente.\nSUGERENCIA DE PROGRAMACIÓN: Revisa la herencia y el método getTipo().");
        REQUIRE( c3.getTipo() == "S" );
        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe sumar SER_PREMIO_CASTIGO.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la función getSiguienteCasilla().");
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
        INFO("FUNCIONALIDAD ESPERADA: El tablero debe permitir agregar casillas especiales y mostrarlas correctamente.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la implementación de setCasilla y print.");
        REQUIRE( true );
    }

    SECTION( "Validando desde Archivo" ) {
        Tablero tf("t1.tab");

        tf.print();
        INFO("FUNCIONALIDAD ESPERADA: El tablero debe cargarse correctamente desde archivo.\nSUGERENCIA DE PROGRAMACIÓN: Revisa la lectura y parseo del archivo en el constructor de Tablero.");
        REQUIRE( true );
    }

    SECTION( "Validando casillas en Tablero ") {
        Tablero tf("t1.tab");

        INFO("FUNCIONALIDAD ESPERADA: La casilla 1 debe existir y tener número 1.\nSUGERENCIA DE PROGRAMACIÓN: Verifica el método getCasilla y la inicialización del tablero.");
        REQUIRE (tf.getCasilla(1).getNumeroCasilla()==1);
        INFO("FUNCIONALIDAD ESPERADA: El tipo de la casilla 1 debe ser 'N'.\nSUGERENCIA DE PROGRAMACIÓN: Revisa la asignación de tipo en la carga del tablero.");
        REQUIRE (tf.getCasilla(1).getTipo()=="N");
        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe sumar NOR_PREMIO_CASTIGO.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la lógica de getSiguienteCasilla().");
        REQUIRE (tf.getCasilla(1).getSiguienteCasilla()==tf.getCasilla(1).getNumeroCasilla()+NOR_PREMIO_CASTIGO);

        INFO("FUNCIONALIDAD ESPERADA: La casilla 10 debe existir y tener número 10.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la carga de casillas especiales.");
        REQUIRE (tf.getCasilla(10).getNumeroCasilla()==10);
        INFO("FUNCIONALIDAD ESPERADA: El tipo de la casilla 10 debe ser 'L'.\nSUGERENCIA DE PROGRAMACIÓN: Revisa la asignación de tipo en la carga del tablero.");
        REQUIRE (tf.getCasilla(10).getTipo()=="L");
        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe sumar ESC_PREMIO_CASTIGO.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la lógica de getSiguienteCasilla().");
        REQUIRE (tf.getCasilla(10).getSiguienteCasilla()==tf.getCasilla(10).getNumeroCasilla()+ESC_PREMIO_CASTIGO);

        INFO("FUNCIONALIDAD ESPERADA: La casilla 25 debe existir y tener número 25.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la carga de casillas especiales.");
        REQUIRE (tf.getCasilla(25).getNumeroCasilla()==25);
        INFO("FUNCIONALIDAD ESPERADA: El tipo de la casilla 25 debe ser 'S'.\nSUGERENCIA DE PROGRAMACIÓN: Revisa la asignación de tipo en la carga del tablero.");
        REQUIRE (tf.getCasilla(25).getTipo()=="S");
        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe sumar SER_PREMIO_CASTIGO.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la lógica de getSiguienteCasilla().");
        REQUIRE (tf.getCasilla(25).getSiguienteCasilla()==tf.getCasilla(25).getNumeroCasilla()+SER_PREMIO_CASTIGO);

    }
}

TEST_CASE("ex6", "[Jugador bien formado]")
{   
    SECTION( "Validando Jugador" ) {
        Jugador j(1), k(2);

        INFO("FUNCIONALIDAD ESPERADA: El jugador debe iniciar en la casilla indicada.\nSUGERENCIA DE PROGRAMACIÓN: Verifica el constructor y el valor inicial de casilla_actual.");
        REQUIRE(j.getCasilla_actual()==1);

        k.setCasilla_actual(10);
        INFO("FUNCIONALIDAD ESPERADA: El método setCasilla_actual debe actualizar la posición del jugador.\nSUGERENCIA DE PROGRAMACIÓN: Revisa la implementación de setCasilla_actual.");
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
        INFO("FUNCIONALIDAD ESPERADA: El dado debe generar valores secuenciales del 1 al 6 si no es aleatorio.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la lógica de incremento y reinicio en getValorDado().");
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
        
        INFO("FUNCIONALIDAD ESPERADA: El juego manual debe ejecutarse correctamente y generar el archivo de salida esperado.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la lógica de flujo en GameManual y la escritura de archivos.");
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
            
        INFO("FUNCIONALIDAD ESPERADA: La entrada del juego automático debe ser siempre 'C'.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la función getInput() en GameAutomatic.");
        REQUIRE(isC);   
        INFO("FUNCIONALIDAD ESPERADA: El juego automático debe generar el archivo de salida esperado.\nSUGERENCIA DE PROGRAMACIÓN: Verifica la lógica de flujo en GameAutomatic y la escritura de archivos.");
        REQUIRE(chkFiles("output", "test/toutput"));
    }
}
