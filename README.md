# TDA-Lista

LISTA SIMPLEMENTE ENLAZADA Y AMIGOS
Se pide implementar una Lista utilizando nodos simplemente enlazados. Para ello se brindan las firmas de las funciones públicas a implementar y se deja a criterio del alumno la creación de las funciones privadas del TDA para el correcto funcionamiento de la Lista cumpliendo con las buenas prácticas de programación. Adicionalmente se pide la creación de un iterador interno y uno externo para la lista, como así también REUTILIZAR la implementación de lista simplemente enlazada para implementar los TDAS Pila y Cola.

El TDA entregado deberá compilar y pasar las pruebas dispuestas por la cátedra (Chanutron't) sin errores, adicionalmente estas pruebas deberán ser ejecutadas sin pérdida de memoria.

A modo de ejemplo, se brindará al alumno un archivo simple de ejemplo. Este archivo no es mas que un programa mínimo de ejemplo de utilización del TDA a implementar y es provisto sólo a fines ilustrativos como una ayuda extra para entender el funcionamiento del mismo. No es necesario modificar ni entregar el archivo de ejemplo, pero si la implementación es correcta, debería correr con valgrind sin errores de memoria.

Para la resolución de este trabajo se recomienda utilizar una metodología orientada a pruebas. A tal fin, se incluye un archivo pruebas.c que debe ser completado con las pruebas pertinentes de cada una de las diferentes primitivas del TDA. El archivo de pruebas forma parte de la entrega y por lo tanto de la nota final. Aún mas importante, las pruebas van a resultar fundamentales para lograr no solamente una implementación correcta, si no también una experiencia de desarrollo menos turbulenta.

CONSEJOS PARA LA ELABORACIÓN DEL TRABAJO
Intenta comprender primero el funcionamiento de los nodos enlazados. Propone una lista de elementos y dibujá a mano (lápiz y papel) varias operaciones de inserción y eliminación de la lista. Dibujá cada uno de los nodos enlazados con sus punteros y datos. Una vez hecho el dibujo, intenta aplicar sobre el mismo cada una de las operaciones propuestas para el TDA. Poder dibujar el problema exitosamente y entender cómo funciona va a ser fundamental a la hora de la implementación.

Empezá la implementación de cada primitiva escribiendo una prueba. A la hora de escribir cada prueba preguntate primero cuál es el comportamiento correcto de la primitiva en cuestión. Elaborá una prueba en base a ese conocimiento. Luego implementá el código de la primitiva que satisfaga esa prueba. Por último preguntate qué casos erróneos conoces y qué posibles entradas pueden hacer que la primitiva falle. Implementá pruebas para estos casos y si es necesario, modificá la implementación para que el funcionamiento sea el correcto.

Recordá al escribir pruebas: no se busca en el código de pruebas la encapsulación ni simplificación de las mismas, no es incorrecto tener pruebas con código repetitivo. Las pruebas son una especificación del comportamiento deseado de las primitivas. Como tal, deben ser fáciles de leer y entender su objetivo.

En general, para todo el código: utilizá nombres claros de variables y funciones auxiliares. Una variable con el nombre cantidad_elementos_recorridos o incluso cantidad es mucho mas claro que una variable con el nombre n, cant, o rec. Intentá darle un significado el nombre de cada variable, dentro de lo posible (por supuesto, quedan excluidos casos como i, j, etc para bucles y cosas así).

NO escribas código a lo loco sin compilar cada tanto. Implementá la solución de a poco y compilando a cada paso. Dejar la compilación para el final es uno de los peores errores que podés cometer. Para la compilación del trabajo se provee un Makefile. Utilizá el comando make frecuentemente para compilar y correr el programa.

NO avances en la implementación si quedan errores sin resolver en alguna prueba. Cada vez que escribas una prueba implementá toda la funcionalidad necesaria para que funcione correctamente. Esto incluye liberar memoria y accesos inválidos a la misma. Solamente una vez que hayas logrado que la prueba pase exitosamente es que podés comenzar a escribir la próxima prueba para continuar el trabajo.

NO está permitido modificar los archivos .h. Se pueden hacer modificaciones al makefile, pero recordá que el trabajo será compilado por el sistema de entregas con las cabeceras y el makefile original.

TIP: Quizás no sea necesario definir estructuras para la pila y la cola si se reutiliza por completo la lista. Léase también: casteo de punteros.

ENTREGA
La entrega deberá contar con todos los archivos que se adjuntan (todo lo necesario para compilar y correr correctamente) y las pruebas que demuestran que su implementación funciona. Dichos archivos deberán formar parte de un único archivo .zip el cual será entregado a través de la plataforma de corrección automática Chanutron't.

El archivo comprimido deberá contar, además de los archivos del TDA, con un informe que contenga la siguiente información:

Explicá qué es una lista y cómo funciona para las diferentes implementaciones vistas en clase.
Explicá qué es una pila y cómo funciona para las diferentes implementaciones vistas en clase.
Explicá qué es una cola y cómo funciona para las diferentes implementaciones vistas en clase.
Explicá cómo funcionan las partes importantes del código (inserciones, eliminaciones e iteradores). No expliques línea por línea lo que hiciste, la explicación tiene que poder ayudar a entender lo que implementaste. Por ejemplo: explicar algún movimiento complejo de punteros que hagas o un detalle de implementación de insertar en la pila sirve; explicar que una línea que hace malloc hace malloc no aporta nada.
CRITERIOS MÍNIMOS DE CORRECCIÓN
GENERAL
 Cada malloc tiene su verificación
 Libera(cierra) memoria(archivos) en los casos de error
 Reallocs sobre punteros auxiliares
 No hay código comentado
 No hay printfs donde no es necesario
 Los entregables compilan y corren sin error
 Verifica los punteros recibidos
 No hay variables globales
 No reserva memoria cuando no es necesario
 Usa constantes y tienen sentido.
ESTILO
 El estilo es el apropiado
 Los nombres de función me dicen lo que hacen
 No hay variables con nombre confuso
PRUEBAS
 Corren sin error y pasan
 Son fáciles de leer y entender qué hacen
 Cantidad razonable
Si prueba lo necesario no importa que sean pocas
Si son excesivas sin motivo no es bueno
 No hace printf para verificar el resultado visualmente. Eso no es una prueba automatizada.
LISTA
 Reutiliza funciones donde es apropiado
 Las complejidades son adecuadas
Push/Pop deben ser O(1)
Lo mismo con Encolar/Desencolar.
 El iterador interno NO usa lista_en_posición
 El iterador interno NO usa el externo
 El iterador externo NO usa lista_en_posición
 Responde las preguntas teóricas en el informe.
