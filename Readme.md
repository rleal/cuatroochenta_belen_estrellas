## Guía de desarrollo

Para el desarrollo habitual de funcionalidades del belén tan solo hay que definir los loops, eventos y estado necesarios. La lógica de infraestructura está separada en el módulo `system`.

La arquitectura de software utilizada para la lógica del belén se compone de:

+ Loops individuales que componen el loop principal.
+ Eventos externos. Actualmente vía MQTT.
+ Un estado global que pueden consultar y modificar los distintos loops y eventos.

### Ejemplos:

+ belen/event/helloWorldEvent: evento de ejemplo.
+ belen/loop/helloWorldLoop: loop individual de ejemplo.
+ belen/state/incrementAndGetHelloWorld: ejemplo de estado.
+ belen/base: configuración y uso de los elementos anteriores.
