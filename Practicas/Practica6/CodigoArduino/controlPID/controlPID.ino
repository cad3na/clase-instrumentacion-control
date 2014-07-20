// Variables a calcular
float integral = 0.0;
float error_anterior = 0.0;
float error, salida;
// Variables a leer
float entrada, referencia;
float kp, ki, kd;
// Tiempo del ciclo de trabajo
float dt = 0.02;

// Rutina de inicializacion
void setup() {
    // Se inixializa el puerto serial a 9600 baud
    Serial.begin(9600);
}

// Ciclo de trabajo
void loop() {
    // Lectura de valores de calibración y entradas del sistema
    kp = analogRead(A0) / 1023.0;
    delay(10);
    ki = analogRead(A1) / 1023.0;
    delay(10);
    kd = analogRead(A2) / 1023.0;
    delay(10);
    referencia = analogRead(A3) / 1023.0;
    delay(10);
    entrada = analogRead(A4) / 1023.0;
    delay(10);

    // Calculo de error
    error = referencia - entrada;
    integral = integral + error;

    // Calculo de salida del controlador
    salida = kp*error + kd*(error - error_anterior) / dt + ki*integral*dt;

    // Se guarda el valor del error en una variable global
    error_anterior = error;

    // Se manda la salida del sistema por puerto serial y por puerto PWM
    Serial.println(salida*255);
    analogWrite(3, salida*255);
}
