# Introducción C
### Fecha: 29.may.2k23
----
Realización del "Hola Mundo" y comentarios:

```c
#include <stdio.h>

/* comentario_1 */
// comentario_2

int main()
{
    printf("Hola, pat_mic \n");
    return 0;
}
```

uso de variables:

```c
#include <stdio.h>

int main()
{
    //Variables int:
    int a;       // declarando
    int b=10;    // inicializado
    int c;   
    
    //Variables char:
    float f1 = 1.01, f2 = 2.02, f3r;

    //Variables char:
    char caracter ='*';

    a=5;
    c= a + b;
    printf("la suma int es : %i  \n", c);

    f3r = f1 + f2;
    printf("la suma float es : %.3f  \n", f3r);

    printf("El caracter es: %c  \n", caracter);
    return 0;
}
```
---
formato para la mostrar los valores de las variables:
![formato](res/img/roadmap.png)

##libreias en c
se agrefan ne a padsflsdkf s
sf sd dfgd

```c
#include "../lib/Serie.h"
#include "../lib/Utility.h"
```
----


## Scope: Confirm TDM-GCC Installation

Type: Command Line Application
Use: gcctest (executable)

```c
#include <iostream>
int main()
{
    printf("Compiled: g++ script.c\n");
    printf("Executed: script.c \n");
    printf("Executed-bash: ./script.c \n");
    return 0;
}
```

# Configuracion de la variable de entorno
echo %PATH%

<MINGW_HOME>/bin"

> gcc --version
g++ (GCC) 4.8.1
......
 
> g++ --version
g++ (GCC) 4.8.1
......
 
> gdb --version
GNU gdb (GDB) 7.6.1
......
SET PATH=%PATH%;c:\cygwin64\bin


