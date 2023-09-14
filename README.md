## EN: Arduino Water State Monitoring System with DHT22: Recognizing Humidity and Temperature

### Components Used
The Arduino code utilizes the following elements and components:

1. DHT22 Humidity and Temperature Sensor: Used to measure the humidity and temperature of the environment.
2. Bluetooth Module (HC-05): Used for wireless communication with another device, such as a mobile phone or computer, via Bluetooth.
3. Potentiometer: Allows the user to select a desired state (solid, liquid, or gaseous).
4. LEDs: Used to indicate the state selected by the user (solid, liquid, or gaseous).
5. Arduino: Monitors the entire process using its CPU.

### Functionality
The code implements a moisture detection system in substances in solid, liquid, or gaseous states. Below are the main functionalities of the code:

1. Initialization: The system is initialized upon startup. Serial communication is configured, and a welcome message and available user options are displayed to the user via Bluetooth module.

2. State Selection: The user can select the desired state (solid, liquid, or gaseous) using a potentiometer.

3. Humidity and Temperature Reading: Humidity and temperature readings of the environment are performed using the DHT22 sensor.

4. Calculations and Display: Calculations based on humidity and temperature readings are performed. Values are displayed via Bluetooth communication, allowing the user to know humidity, temperature, and other related values based on the selected state.

5. Indicator LEDs: LEDs are used to indicate the state selected by the user. For example, if the user selects "solid state," an LED corresponding to "solid" is lit.

### Solution
It addresses the issue of measuring humidity in substances in different states (solid, liquid, gaseous) and provides a wireless communication interface for users to obtain information about the humidity and temperature of the environment. Additionally, the code allows the user to select the desired state and displays the corresponding results.

This system could be useful in applications where monitoring and controlling humidity in different environments is required, such as in agriculture, climate control, or the storage of humidity-sensitive products.

-----------
## ES: Sistema de Reconocimiento de Humedad y Temperatura sobre los Estados del Agua usando sensor DHT22 con Arduino

### Componentes Utilizados
El código en Arduino utiliza los siguientes elementos y componentes:

1. Sensor de Humedad y Temperatura DHT22: Se utiliza para medir la humedad y temperatura del entorno.
2. Módulo Bluetooth (HC-05): Se utiliza para la comunicación inalámbrica con otro dispositivo, como un teléfono móvil o una computadora, a través de Bluetooth.
3. Potenciómetro: Se utiliza para permitir al usuario seleccionar un estado deseado (sólido, líquido o gaseoso).
4. LEDS: Se utilizan para indicar el estado seleccionado por el usuario (solido, líquido o gaseoso).
5. Arduino: Se utiliza para monitoriar todo el proceso por su CPU.

### Funcionalidad
El código implementa un sistema de detección de humedad en sustancias en estado sólido, líquido o gaseoso. A continuación, se describen las principales funcionalidades del código:

1. Inicialización: El sistema se inicializa al encenderse. Se configura la comunicación serial y se muestra un mensaje de bienvenida y las opciones disponibles al usuario a través del módulo Bluetooth.

2. Selección del Estado: El usuario puede seleccionar el estado deseado (sólido, líquido o gaseoso) utilizando un potenciómetro.

3. Lectura de Humedad y Temperatura: Se realiza la lectura de la humedad y temperatura del entorno utilizando el sensor DHT22.

4. Cálculos y Visualización: Se realizan cálculos basados en la lectura de humedad y temperatura. Los valores se muestran a través de la comunicación Bluetooth, lo que permite al usuario conocer la humedad, temperatura y otros valores relacionados con el estado seleccionado.

5. LEDs Indicadores: Se utilizan LEDs para indicar el estado seleccionado por el usuario. Por ejemplo, si el usuario selecciona "estado sólido," se enciende un LED correspondiente a "sólido."

### Solución
Resuelve el problema de medir la humedad en sustancias en diferentes estados (sólido, líquido, gaseoso) y proporciona una interfaz de comunicación inalámbrica para que los usuarios obtengan información sobre la humedad y temperatura del entorno. Además, el código permite al usuario seleccionar el estado deseado y muestra los resultados correspondientes.

Este sistema podría ser útil en aplicaciones donde se requiere monitorear y controlar la humedad en diferentes entornos, como en la agricultura, control de climatización, o almacenamiento de productos sensibles a la humedad.