float errores[100];
float err, ent, sal;
float dt = 0.01;
int i = 0;

void setup() {
  Serial.begin(9600);
  for (i = 0; i < 100; i = i + 1) {
    errores[i] = 0.0;
  }
}

void loop() {
  float kp, ki, kd, ref, integral;
  kp = analogRead(A0) / 1023.0;
  delay(2);
  ki = analogRead(A1) / 1023.0;
  delay(2);
  kd = analogRead(A2) / 1023.0;
  delay(2);
  ref = analogRead(A3) / 1023.0; 
  delay(2);
  ent = analogRead(A4) / 1023.0;
  delay(2);
  
  err = ent - ref;
  i = 0;
  integral = 0;
  for (i = 0; i < 100; i = i + 1) {
    integral = errores[i];
  }
  
  sal = kp*err + kd*(err - errores[i]) / dt + ki*integral*dt;
  
  Serial.println(sal*255);
  analogWrite(3, sal*255);
  errores[i] = err;
  i = (i+1) % 100;
}

