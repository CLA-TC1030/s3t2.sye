# Ejercicio S3T2-Serpientes y Escaleras Polimórfico

## Descripción del Problema

Esta tarea consiste en extender el Juego de Serpientes y Escaleras usando Polimorfismo.

## Diagrama de Clases
Construye aquí el Diagrama de Clases de tu solución, usando el [Lenguaje Mermaid](https://mermaid.js.org/syntax/classDiagram.html).
```mermaid
classDiagram
      class Game
      <<abstract>> Game
      Game <|-- GameAutomatic
      Game <|-- GameManual
      Casilla <|-- Normal
      Casilla <|-- Escalera
      Casilla <|-- Serpiente
      Tablero --> "30" Casilla
      Game --> "1" Tablero
      Game --> "2" Jugador
      Game --> "1" Dado
      
      Game:+getInput()* string
      Game:+start()
  
      GameAutomatic:+getInput() string
      GameManual:+getInput() string
      Jugador: -numero
      Casilla: -numero
      Casilla: -tipo
      Dado: -valor
```
Puedes apoyarte con el editor [Mermaid-live](https://mermaid.live/).
## Objetivo

- Busca que el código pase correctamente todas las pruebas
   * Solamente cambia los archivos permitidos para lograr este objetivo (abajo se indican las reglas específicas)
   
- Las GitHub Actions deberán presentar una palomita en verde si se han satisfecho todas las pruebas, y una cruz roja cuando alguna (o todas) las pruebas han fallado.
   * **Recomendación:** Puedes dar clic en la cruz roja para verificar cual de las pruebas ha fallado (o si el código no ha compilado correctamente).
   * **Recomendación:** En caso de que el Autograding no muestre pruebas o no funcione, contacta a tu profesor mediante un issue.

## Instrucciones

- Deberás modificar los archivos que consideres conveniente.
Explicación de los otros archivos:

- Archivo `test/tests.cpp` tiene las pruebas de esta actividad (NO LO CAMBIES!)
- Archivo `test/catch.hpp` tiene la biblioteca de pruebas  CATCH2 (NO LA CAMBIES!)
- Archivo `makefile` tienes los comandos para ejecutar la actividad (NO LO CAMBIES!)
- Archivo  `./build/appTests` se generará después de compilar (para **pruebas locales**, solo ejecútalo)

## Comandos para pruebas locales, ejecución y depuración

- Comando para construir y ejecutar pruebas: `make` o `make test`
    * Si el ejecutable ya está construido, sólo teclea : `./build/appTests`

- Comando para construir y ejecutar la aplicación: `make run` 
    * Si el ejecutable ya está construido, sólo teclea : `./build/exercise`

- Comando para depurar por línea de comandos: `make debug`
    * Para conocer los comandos de depuración consulta:
     https://u.osu.edu/cstutorials/2018/09/28/how-to-debug-c-program-using-gdb-in-6-simple-steps/
     
- Comando para depurar la ejecución del programa con `vsCode` : `make debugvs` 
    * Utilizar el depurador de la IDE.

- Comando para depurar la ejecución de las pruebas con `vsCode` : `make debugtest` 
    * Utilizar el depurador de la IDE.

## Notas

- El código será evaluado solamente si compila.
   * La razón de esto es, si no compila no es posible generar el ejecutable y realizar las pruebas.

- Algunos casos de prueba podrían recibir calificación individual, otros podrían recibir calificación y si pasan todos juntos (o todas las pruebas en conjunto).

- La calificación final se otorgará de manera automática en cada *commit*, y se evaluará solamente hasta la fecha limite de la actividad.

Para dudas adicionales, consulta a tu profesor.

## License

MIT License 2020
