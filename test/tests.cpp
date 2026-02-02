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
        INFO("FUNCIONALIDAD ESPERADA: La casilla base debe iniciar en 1 por defecto.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que el constructor por omisión de CCasilla inicialice el número en 1.");
        REQUIRE( c1.getNumeroCasilla() == 1 );

        INFO("FUNCIONALIDAD ESPERADA: El tipo de casilla base debe ser 'N' por defecto.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Asegúrate de que el atributo tipo se inicialice con 'N' en CCasilla.");
        REQUIRE( c1.getTipo() == "N" );

        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe calcularse sumando NOR_PREMIO_CASTIGO al número actual.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Revisa que getSiguienteCasilla() use correctamente premio_castigo.");
        REQUIRE( c1.getSiguienteCasilla() == c1.getNumeroCasilla() + NOR_PREMIO_CASTIGO );

        INFO("FUNCIONALIDAD ESPERADA: El constructor debe asignar el número de casilla especificado.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que el constructor con parámetros asigne correctamente el número.");
        REQUIRE( c2.getNumeroCasilla() == 2);

        INFO("FUNCIONALIDAD ESPERADA: El tipo debe ser el especificado en el constructor ('E').");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Asegúrate de que el constructor asigne el tipo recibido como parámetro.");
        REQUIRE( c2.getTipo() == "E" );

        INFO("FUNCIONALIDAD ESPERADA: Debe calcular correctamente la siguiente casilla con NOR_PREMIO_CASTIGO.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica la inicialización de premio_castigo en el constructor.");
        REQUIRE( c2.getSiguienteCasilla() == c2.getNumeroCasilla() + NOR_PREMIO_CASTIGO);

        INFO("FUNCIONALIDAD ESPERADA: El número debe ser 3 según el constructor.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Confirma la asignación correcta en el constructor parametrizado.");
        REQUIRE( c3.getNumeroCasilla() == 3);

        INFO("FUNCIONALIDAD ESPERADA: El tipo debe ser 'S' como se especificó.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que el parámetro tipo se asigne correctamente.");
        REQUIRE( c3.getTipo() == "S" );

        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe sumarse con NOR_PREMIO_CASTIGO.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Revisa que premio_castigo tenga el valor correcto en CCasilla.");
        REQUIRE( c3.getSiguienteCasilla() == c3.getNumeroCasilla() + NOR_PREMIO_CASTIGO);
    }
}

TEST_CASE("ex1", "[Casillas Normales bien formadas]")
{   
    CasillaNormal c1, c2(3);

    SECTION( "Validando casillas Normales" ) {
        INFO("FUNCIONALIDAD ESPERADA: CasillaNormal debe iniciar en 1 por defecto.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que el constructor por omisión invoque correctamente al constructor base.");
        REQUIRE( c1.getNumeroCasilla() == 1 );

        INFO("FUNCIONALIDAD ESPERADA: El tipo de CasillaNormal debe ser 'N'.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Asegúrate de heredar correctamente el tipo de CCasilla.");
        REQUIRE( c1.getTipo() == "N" );

        INFO("FUNCIONALIDAD ESPERADA: Debe calcular la siguiente casilla sumando NOR_PREMIO_CASTIGO.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que premio_castigo mantenga el valor de NOR_PREMIO_CASTIGO.");
        REQUIRE( c1.getSiguienteCasilla() == c1.getNumeroCasilla() + NOR_PREMIO_CASTIGO);

        INFO("FUNCIONALIDAD ESPERADA: El constructor debe asignar el número especificado (3).");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica la asignación del parámetro numero en CasillaNormal.");
        REQUIRE( c2.getNumeroCasilla() == 3 );

        INFO("FUNCIONALIDAD ESPERADA: El tipo debe seguir siendo 'N'.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Confirma que tipo no se modifique en el constructor parametrizado.");
        REQUIRE( c2.getTipo() == "N" );

        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe calcularse correctamente.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Asegúrate de que getSiguienteCasilla() funcione con herencia.");
        REQUIRE( c2.getSiguienteCasilla() == c2.getNumeroCasilla() + NOR_PREMIO_CASTIGO);
    }
}

TEST_CASE("ex2", "[Casillas Escalera bien formadas]")
{   
    CasillaEscalera c1, c2(3);

    SECTION( "Validando casillas Escalera" ) {
        INFO("FUNCIONALIDAD ESPERADA: CasillaEscalera debe iniciar en 1 por defecto.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica el constructor por omisión de CasillaEscalera.");
        REQUIRE( c1.getNumeroCasilla() == 1 );

        INFO("FUNCIONALIDAD ESPERADA: El tipo de CasillaEscalera debe ser 'L'.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Asegúrate de asignar 'L' al atributo tipo en CasillaEscalera.");
        REQUIRE( c1.getTipo() == "L" );

        INFO("FUNCIONALIDAD ESPERADA: Debe sumar ESC_PREMIO_CASTIGO para obtener la siguiente casilla.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que premio_castigo se inicialice con ESC_PREMIO_CASTIGO.");
        REQUIRE( c1.getSiguienteCasilla() == c1.getNumeroCasilla() + ESC_PREMIO_CASTIGO );

        INFO("FUNCIONALIDAD ESPERADA: El número debe ser 3 según el constructor.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Confirma la asignación del parámetro en CasillaEscalera.");
        REQUIRE( c2.getNumeroCasilla() == 3 );

        INFO("FUNCIONALIDAD ESPERADA: El tipo debe ser 'L' para escaleras.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que el constructor invoque correctamente al constructor base con 'L'.");
        REQUIRE( c2.getTipo() == "L" );

        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe calcularse con ESC_PREMIO_CASTIGO.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Asegúrate de que premio_castigo mantenga el valor correcto.");
        REQUIRE( c2.getSiguienteCasilla() == c2.getNumeroCasilla() + ESC_PREMIO_CASTIGO );
    }
}

TEST_CASE("ex3", "[Casillas Serpiente bien formadas]")
{   
    CasillaSerpiente c1, c2(10);

    SECTION( "Validando casillas Serpiente" ) {
        INFO("FUNCIONALIDAD ESPERADA: CasillaSerpiente debe iniciar en 1 - SER_PREMIO_CASTIGO por defecto.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que el constructor ajuste el número considerando el castigo.");
        REQUIRE( c1.getNumeroCasilla() == 1 - SER_PREMIO_CASTIGO );

        INFO("FUNCIONALIDAD ESPERADA: El tipo de CasillaSerpiente debe ser 'S'.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Asegúrate de asignar 'S' al atributo tipo.");
        REQUIRE( c1.getTipo() == "S" );

        INFO("FUNCIONALIDAD ESPERADA: Debe sumar SER_PREMIO_CASTIGO (negativo) para retroceder.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que premio_castigo tenga el valor SER_PREMIO_CASTIGO.");
        REQUIRE( c1.getSiguienteCasilla() == c1.getNumeroCasilla() + SER_PREMIO_CASTIGO);

        INFO("FUNCIONALIDAD ESPERADA: El número debe ser 10 como se especificó.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Confirma que el constructor parametrizado asigne correctamente el número.");
        REQUIRE( c2.getNumeroCasilla() == 10 );

        INFO("FUNCIONALIDAD ESPERADA: El tipo debe ser 'S' para serpientes.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica la asignación del tipo en el constructor con parámetros.");
        REQUIRE( c2.getTipo() == "S" );

        INFO("FUNCIONALIDAD ESPERADA: La siguiente casilla debe considerar el castigo negativo.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Asegúrate de inicializar premio_castigo con SER_PREMIO_CASTIGO.");
        REQUIRE( c2.getSiguienteCasilla() == c2.getNumeroCasilla() + SER_PREMIO_CASTIGO);
    }
}

TEST_CASE("ex4", "[Polimorfismo de casillas]")
{   
    CCasilla c1{CasillaNormal(1)}, c2{CasillaEscalera(3)}, c3{CasillaSerpiente(10)};

    SECTION( "Validando casillas Normales, Escalera, Serpiente polimorficamente" ) {
        INFO("FUNCIONALIDAD ESPERADA: Debe funcionar polimórficamente con CasillaNormal número 1.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que CCasilla permita conversión desde clases derivadas.");
        REQUIRE( c1.getNumeroCasilla() == 1 );

        INFO("FUNCIONALIDAD ESPERADA: El polimorfismo debe preservar el tipo 'N'.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Asegúrate de que getTipo() sea virtual si es necesario.");
        REQUIRE( c1.getTipo() == "N" );

        INFO("FUNCIONALIDAD ESPERADA: getSiguienteCasilla() debe funcionar polimórficamente.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que los métodos virtuales funcionen correctamente.");
        REQUIRE( c1.getSiguienteCasilla() == c1.getNumeroCasilla() + NOR_PREMIO_CASTIGO );

        INFO("FUNCIONALIDAD ESPERADA: Debe funcionar polimórficamente con CasillaEscalera número 3.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Confirma la construcción correcta desde clase derivada.");
        REQUIRE( c2.getNumeroCasilla() == 3 );

        INFO("FUNCIONALIDAD ESPERADA: El polimorfismo debe preservar el tipo 'L'.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica la herencia de atributos en el polimorfismo.");
        REQUIRE( c2.getTipo() == "L" );

        INFO("FUNCIONALIDAD ESPERADA: Debe calcular correctamente con ESC_PREMIO_CASTIGO.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Asegúrate de que premio_castigo se preserve en la conversión.");
        REQUIRE( c2.getSiguienteCasilla() == c2.getNumeroCasilla() + ESC_PREMIO_CASTIGO );

        INFO("FUNCIONALIDAD ESPERADA: Debe funcionar polimórficamente con CasillaSerpiente número 10.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica la conversión correcta de CasillaSerpiente a CCasilla.");
        REQUIRE( c3.getNumeroCasilla() == 10 );

        INFO("FUNCIONALIDAD ESPERADA: El polimorfismo debe preservar el tipo 'S'.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Confirma que los atributos se copien correctamente.");
        REQUIRE( c3.getTipo() == "S" );

        INFO("FUNCIONALIDAD ESPERADA: Debe calcular correctamente con SER_PREMIO_CASTIGO.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que el valor negativo se preserve en la conversión.");
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
        INFO("FUNCIONALIDAD ESPERADA: El tablero debe permitir agregar y mostrar casillas especiales.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que setCasilla() y print() funcionen correctamente.");
        REQUIRE( true );
    }

    SECTION( "Validando desde Archivo" ) {
        Tablero tf("t1.tab");

        tf.print();
        INFO("FUNCIONALIDAD ESPERADA: El tablero debe cargarse correctamente desde archivo.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica el constructor de Tablero que recibe un string con el nombre del archivo.");
        REQUIRE( true );
    }

    SECTION( "Validando casillas en Tablero ") {
        Tablero tf("t1.tab");

        INFO("FUNCIONALIDAD ESPERADA: getCasilla(1) debe devolver la casilla número 1.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que getCasilla() acceda correctamente al arreglo de casillas.");
        REQUIRE (tf.getCasilla(1).getNumeroCasilla()==1);

        INFO("FUNCIONALIDAD ESPERADA: La casilla 1 debe ser de tipo 'N' según el archivo.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Revisa la lectura y asignación de tipos desde el archivo.");
        REQUIRE (tf.getCasilla(1).getTipo()=="N");

        INFO("FUNCIONALIDAD ESPERADA: Debe calcular correctamente la siguiente casilla.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Asegúrate de que las casillas cargadas mantengan sus propiedades.");
        REQUIRE (tf.getCasilla(1).getSiguienteCasilla()==tf.getCasilla(1).getNumeroCasilla()+NOR_PREMIO_CASTIGO);

        INFO("FUNCIONALIDAD ESPERADA: getCasilla(10) debe devolver la casilla número 10.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Confirma que el índice se maneje correctamente (i-1 en el arreglo).");
        REQUIRE (tf.getCasilla(10).getNumeroCasilla()==10);

        INFO("FUNCIONALIDAD ESPERADA: La casilla 10 debe ser de tipo 'L' según el archivo t1.tab.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que el archivo se lea línea por línea correctamente.");
        REQUIRE (tf.getCasilla(10).getTipo()=="L");

        INFO("FUNCIONALIDAD ESPERADA: Debe usar ESC_PREMIO_CASTIGO para escaleras.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Asegúrate de que CasillaEscalera se instancie correctamente desde archivo.");
        REQUIRE (tf.getCasilla(10).getSiguienteCasilla()==tf.getCasilla(10).getNumeroCasilla()+ESC_PREMIO_CASTIGO);

        INFO("FUNCIONALIDAD ESPERADA: getCasilla(25) debe devolver la casilla número 25.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica el acceso al arreglo con índices grandes.");
        REQUIRE (tf.getCasilla(25).getNumeroCasilla()==25);

        INFO("FUNCIONALIDAD ESPERADA: La casilla 25 debe ser de tipo 'S' según el archivo.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Confirma que se creen CasillaSerpiente cuando corresponda.");
        REQUIRE (tf.getCasilla(25).getTipo()=="S");

        INFO("FUNCIONALIDAD ESPERADA: Debe usar SER_PREMIO_CASTIGO para serpientes.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que CasillaSerpiente mantenga el castigo negativo.");
        REQUIRE (tf.getCasilla(25).getSiguienteCasilla()==tf.getCasilla(25).getNumeroCasilla()+SER_PREMIO_CASTIGO);

    }
}

TEST_CASE("ex6", "[Jugador bien formado]")
{   
    SECTION( "Validando Jugador" ) {
        Jugador j(1), k(2);

        INFO("FUNCIONALIDAD ESPERADA: El jugador debe iniciar en la casilla 1.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que el constructor inicialice casilla_actual en 1.");
        REQUIRE(j.getCasilla_actual()==1);

        k.setCasilla_actual(10);
        INFO("FUNCIONALIDAD ESPERADA: setCasilla_actual debe actualizar la posición del jugador.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Confirma que el método asigne correctamente el nuevo valor.");
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
        INFO("FUNCIONALIDAD ESPERADA: El dado debe generar valores secuenciales 1-6 cuando no es aleatorio.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que getValorDado() incremente cara y use módulo 6.");
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
        
        INFO("FUNCIONALIDAD ESPERADA: El juego manual debe generar salida idéntica al archivo esperado.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que GameManual implemente correctamente getInput() y que start() genere la salida esperada.");
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
            
        INFO("FUNCIONALIDAD ESPERADA: GameAutomatic::getInput() debe siempre devolver 'C'.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Verifica que el método getInput() en GameAutomatic retorne la cadena 'C' sin leer de archivo o teclado.");
        REQUIRE(isC);   

        INFO("FUNCIONALIDAD ESPERADA: El juego automático debe generar salida idéntica al archivo esperado.");
        INFO("SUGERENCIA DE PROGRAMACIÓN: Confirma que la lógica de start() funcione correctamente con entrada automática.");
        REQUIRE(chkFiles("output", "test/toutput"));
    }
}
