/*
    Controlador PID
    Roberto Cadena Vega

    Este es un ejemplo de implementación de un controlador PID con fines
    educativos. No lo recomendaria para un sistema practico, mucho menos uno
    industrial.

    No se han implementado algoritmos avanzados para mejorar su rendimiento,
    debido a que oscureceria la implementación del PID.
*/

// Variables a calcular
float integral = 0.0;
float error_anterior = 0.0;
float error, salida;
// Variables a leer
float entrada, referencia;
float kp, ki, kd;
// Valor en Volts de offset
float offset = 3.5;
// Valor en Volts de alimentacion
float alimentacion = 5.0;


// Rutina de inicializacion
void setup() {
    // Se inixializa el puerto serial a 9600 baud
    Serial.begin(9600);
    kp = 1;
    ki = 0;
    kd = 0;
}

// Ciclo de trabajo
void loop() {
    // Lectura de valores de calibración y entradas del sistema
    kp = analogRead(A0) / 4.0;
    delay(2);
    ki = analogRead(A1) / 1024.0;
    delay(2);
    kd = analogRead(A2) / 4.0;
    delay(2);
    referencia = analogRead(A3) / 1024.0 * alimentacion + offset;
    delay(2);
    entrada = analogRead(A4) / 1024.0 * alimentacion;
    delay(2);

    // Calculo de error
    error = referencia - entrada;
    // y de la integral del error
    integral = integral + error;

    // Calculo de salida del controlador
    salida = kp*error + kd*(error - error_anterior) + ki*integral;
    if (salida < 0.0 ) {
        salida = 0.0;
    }
    // Se guarda el valor del error en una variable global
    error_anterior = error;

    // Se manda la salida del sistema por puerto serial y por puerto PWM
    Serial.println(salida);
    analogWrite(3, salida/alimentacion);
}
