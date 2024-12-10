# Ejercicio S3T2-Serpientes y Escaleras Polimórfico

## Descripción del Problema

Esta tarea consiste en extender el Juego de Serpientes y Escaleras usando Polimorfismo.

## Ejemplo de Ejecución-1:
```
Juego Manual : Entrada desde el Teclado : Salida en la Pantalla:
Press C to continue next turn, or E to end the game
C
1 1 1 2 N 3
C
2 2 1 3 N 4
C
3 1 3 4 S 4
C
4 2 4 5 N 9
E
--GAME OVER--
Thanks for playing

Juego Automático : Entrada desde el Archivo build/input : Salida hacia el Archivo build/output:
Press C to continue next turn, or E to end the game
1 1 1 2 N 3
2 2 1 3 N 4
3 1 3 4 S 4
4 2 4 5 N 9
5 1 4 6 L 13
6 2 9 1 L 13
7 1 13 2 L 18
8 2 13 3 N 16
9 1 18 4 N 22
10 2 16 5 N 21
11 1 22 6 N 28
12 2 21 1 N 22
13 1 28 2 N 30
--GAME OVER--
Player 1 is the winner!!!

```
## Ejemplo de Ejecución-2:
```
Juego Manual : Entrada desde el Teclado : Salida en la Pantalla:
Press C to continue next turn, or E to end the game
C
1 1 1 2 N 3
C
2 2 1 3 N 4
C
3 1 3 4 S 4
C
4 2 4 5 N 9
C
5 1 4 6 L 13
C
6 2 9 1 L 13
C
7 1 13 2 L 18
C
8 2 13 3 N 16
C
9 1 18 4 N 22
C
10 2 16 5 N 21
C
11 1 22 6 N 28
C
12 2 21 1 N 22
C
13 1 28 2 N 30
--GAME OVER--
Player 1 is the winner!!!

Juego Automático : Entrada desde el Archivo build/input : Salida hacia el Archivo build/output:
Press C to continue next turn, or E to end the game
1 1 1 2 N 3
2 2 1 3 N 4
3 1 3 4 S 4
4 2 4 5 N 9
5 1 4 6 L 13
6 2 9 1 L 13
7 1 13 2 L 18
8 2 13 3 N 16
9 1 18 4 N 22
10 2 16 5 N 21
11 1 22 6 N 28
12 2 21 1 N 22
13 1 28 2 N 30
--GAME OVER--
Player 1 is the winner!!!

```
## Diagrama de Clases
Construye aquí el Diagrama de Clases de tu solución, usando el [Lenguaje Mermaid](https://mermaid.js.org/syntax/classDiagram.html).
```mermaid
classDiagram
      class Game
      <<abstract>> Game
      class GameAutomatic
      class GameManual
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
[Diagramas de clase en el lenguaje Mermaid](https://mermaid.js.org/syntax/classDiagram.html)

## Prompt para generar el Diagrama de Clases con IA - mermAID
```
@mermaid /uml
```
## Diagrama de clases UML con draw.io

El repositorio está configurado para crear Diagramas de clases UML con ```draw.io```. Para usarlo simplemente das doble clic en el archivo  ```uml.class.drawio.png``` y se activará el editor ```draw.io``` incrustado en ```VSCode``` para edición. Asegúrate de agregar las formas UML en el menú de formas del lado izquierdo (opción ```+Más formas```). Al final insertas el archivo ```uml.class.drawio.png``` en apartado de UML de este archivo README.

Para más información consulta el [MarketPlace](https://marketplace.visualstudio.com/items?itemName=hediet.vscode-drawio).

## Objetivo

- Busca que el código pase correctamente todas las pruebas
   * Solamente cambia los archivos permitidos para lograr este objetivo (abajo se indican las reglas específicas)
   
- Las GitHub Actions deberán presentar una palomita en verde si se han satisfecho todas las pruebas, y una cruz roja cuando alguna (o todas) las pruebas han fallado.
   * **Recomendación:** Puedes dar clic en la cruz roja para verificar cual de las pruebas ha fallado (o si el código no ha compilado correctamente).
   * **Recomendación:** En caso de que el Autograding no muestre pruebas o no funcione, contacta a tu profesor mediante un issue.

## Instrucciones

- Deberás modificar el archivo `exercise.cpp`  y agregar la programación adicional que sea necesaria.

Explicación de los otros archivos:

- Archivo `test/tests.cpp` tiene las pruebas de esta actividad (NO LO CAMBIES!)
- Archivo `makefile` tienes los comandos para ejecutar la actividad (NO LO CAMBIES!)
- Archivo  `./build/appTests` se generará después de compilar (para **pruebas locales**, solo ejecútalo)

## Comandos para pruebas locales, ejecución y depuración

- Comando para construir y ejecutar pruebas: `make` o `make test` o `make ctest`
    * Si el ejecutable ya está construido, sólo teclea : `./build/appTests`

- Comando para construir y ejecutar la aplicación: `make run` 
    * Si el ejecutable ya está construido, sólo teclea : `./build/exercise`
      
- Comando para depurar: `make debug`
    * Para conocer los comandos de depuración consulta:
     https://u.osu.edu/cstutorials/2018/09/28/how-to-debug-c-program-using-gdb-in-6-simple-steps/

- Comando para depurar con `vsCode`: `make debugvs` 
    * Abre el programa principal.
    * Utiliza el depurador de la IDE.
      
- Comando para depurar pruebas con `vsCode`: `make debugtest` 
    * Abre el programa principal.
    * Utilizar el depurador de la IDE.
- Comando para limpieza de binarios `make clean`
    * Úselo cuando desee eliminar cualquier binario que se haya generado en la carpeta `build`.
    * Úselo cuando detecte que algún binario no está actualizado o bien no se hubiere construido conrrectamente.

## Instrucciones para construir y ejecutar la aplicación y pruebas usando CMake

1. Entrar al directorio de construcción:
   ```sh
   cd build
   ```

2. Configurar el proyecto con CMake:
   ```sh
   cmake -DTEST_EXECUTABLE=ON ..
   cmake -DMAIN_EXECUTABLE=ON ..
   ```

3. Construir la aplicación:
   ```sh
   cmake --build .
   ```

4. Ejecutar la aplicación:
   ```sh
   ./exercise
   cd ..
   ```
5. Ejecutar las pruebas:
   ```sh
   ./appTests
   cd ..
   ```
## Notas

- El código será evaluado solamente si compila.
   * La razón de esto es, si no compila no es posible generar el ejecutable y realizar las pruebas.

- Algunos casos de prueba podrían recibir calificación individual, otros podrían recibir calificación y si pasan todos juntos (o todas las pruebas en conjunto).

- La calificación final se otorgará de manera automática en cada *commit*, y se evaluará solamente hasta la fecha limite de la actividad.

Para dudas adicionales, consulta a tu profesor.

## License

MIT License 2020
