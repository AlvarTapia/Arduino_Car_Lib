class Robot{
  public:
    //Constructores
    Robot(int, int, int, int, int, int); 
    //Destructores

    
    //Funciones del robot
    //Motores
    //Relacionado con velocidad
    void arranca();
    void para();
    void lento();
    void velGiro();
    void maxVelocidad();
    void giraIzda();
    void giraDcha();
    //Relacionado con direccion
    void alante();
    void atras();
    void rotaIzda();
    void rotaDcha();

    //Sensores siguelineas
    void setTodosSiguelineas(int, int, int);
    void setSiguelineasIzda(int);
    void setSiguelineasCentro(int);
    void setSiguelineasDcha(int);

    bool readSiguelineasIzda();
    bool readSiguelineasCentro();
    bool readSiguelineasDcha();

  protected: //Solo la clase y sus hijos pueden ver estos elementos
    int const VELOCIDAD_LENTA = 100;
    int const VELOCIDAD_GIRO = 175;
    int const MAX_VELOCIDAD = 255;
    
    int PIN_IZDA_ALANTE;
    int PIN_IZDA_ATRAS;
    int PIN_DCHA_ALANTE;
    int PIN_DCHA_ATRAS;
    
    int PIN_VEL_IZDA;
    int PIN_VEL_DCHA;
    
    int PIN_SIGUELINEAS_IZDA = -1;
    int PIN_SIGUELINEAS_CENTRO = -1;
    int PIN_SIGUELINEAS_DCHA = -1;
};

/** Inicializa un robot cuyo driver solo tiene 4 entradas para 8 cables de motores */
Robot::Robot(int pinIzdaAlante, int pinIzdaAtras, int pinDchaAlante, int pinDchaAtras, int pinVelIzda, int pinVelDcha){
    PIN_IZDA_ALANTE = pinIzdaAlante;
    pinMode(PIN_IZDA_ALANTE, OUTPUT);
    PIN_IZDA_ATRAS = pinIzdaAtras;
    pinMode(PIN_IZDA_ATRAS, OUTPUT);
    
    PIN_DCHA_ALANTE = pinDchaAlante;
    pinMode(PIN_DCHA_ALANTE, OUTPUT);
    PIN_DCHA_ATRAS = pinDchaAtras;
    pinMode(PIN_DCHA_ATRAS, OUTPUT);
    
    PIN_VEL_IZDA = pinVelIzda;
    pinMode(PIN_VEL_IZDA, OUTPUT);
    PIN_VEL_DCHA = pinVelDcha;
    pinMode(PIN_VEL_DCHA, OUTPUT);
}

/** Se aplica mucha tensión durante un corto periodo de tiempo para que los motores empiecen a funcionar*/
void Robot::arranca(){
  analogWrite(PIN_VEL_IZDA, MAX_VELOCIDAD);
  analogWrite(PIN_VEL_DCHA, MAX_VELOCIDAD);
  delay(100);
}

/** Mueve el coche al 40% de la capacidad de las pilas */
void Robot::lento(){ 
  analogWrite(PIN_VEL_IZDA, VELOCIDAD_LENTA);
  analogWrite(PIN_VEL_DCHA, VELOCIDAD_LENTA);
}

/** Velocidad a la que el coche es capaz de girar */
void Robot::velGiro(){
  analogWrite(PIN_VEL_IZDA, VELOCIDAD_GIRO);
  analogWrite(PIN_VEL_DCHA, VELOCIDAD_GIRO);
}

/** Mueve el coche al 100% de la capacidad de las pilas */
void Robot::maxVelocidad(){
  analogWrite(PIN_VEL_IZDA, MAX_VELOCIDAD);
  analogWrite(PIN_VEL_DCHA, MAX_VELOCIDAD);
}

/** Deja de alimentar los motores. Debe arrancarse de nuevo cuando quiera retomar la marcha */
void Robot::para(){
  analogWrite(PIN_VEL_IZDA, 0);
  analogWrite(PIN_VEL_DCHA, 0);
}

/** El robot gira hacia la izda parando los motores de la izda */
void Robot::giraIzda(){
  analogWrite(PIN_VEL_IZDA, MAX_VELOCIDAD);
  analogWrite(PIN_VEL_DCHA, 0);
}

/** El robot gira hacia la dcha parando los motores de la dcha */
void Robot::giraDcha(){
  analogWrite(PIN_VEL_IZDA, 0);
  analogWrite(PIN_VEL_DCHA, MAX_VELOCIDAD);
}

/** El robot hace que los motores giren hacia alante del robot */
void Robot::alante(){
  digitalWrite(PIN_IZDA_ALANTE, HIGH);
  digitalWrite(PIN_IZDA_ATRAS, LOW);
  digitalWrite(PIN_DCHA_ALANTE, HIGH);
  digitalWrite(PIN_DCHA_ATRAS, LOW);
  this->arranca();
  this->lento();
}

/** El robot hace que los motores giren hacia atras del robot */
void Robot::atras(){
  digitalWrite(PIN_IZDA_ALANTE, LOW);
  digitalWrite(PIN_IZDA_ATRAS, HIGH);
  digitalWrite(PIN_DCHA_ALANTE, LOW);
  digitalWrite(PIN_DCHA_ATRAS, HIGH);
  this->arranca();
  this->lento();
}

/** El robot pivota hacia la izda cambiando la direccion de giro de los motores de la izda */
void Robot::rotaIzda(){
  digitalWrite(PIN_IZDA_ALANTE, HIGH);
  digitalWrite(PIN_IZDA_ATRAS, LOW);
  digitalWrite(PIN_DCHA_ALANTE, LOW);
  digitalWrite(PIN_DCHA_ATRAS, HIGH);
  this->arranca();
  this->velGiro();
}

/** El robot pivota hacia la dcha cambiando la direccion de giro de los motores de la dcha */
void Robot::rotaDcha(){
  digitalWrite(PIN_IZDA_ALANTE, LOW);
  digitalWrite(PIN_IZDA_ATRAS, HIGH);
  digitalWrite(PIN_DCHA_ALANTE, HIGH);
  digitalWrite(PIN_DCHA_ATRAS, LOW);
  this->arranca();
  this->velGiro();
}


/** Establece el pin del sensor infrarrojo izquierdo */
void Robot::setSiguelineasIzda(int siguelineasIzda){
  PIN_SIGUELINEAS_IZDA = siguelineasIzda;
  pinMode(PIN_SIGUELINEAS_IZDA, INPUT);
}

/** Establece el pin del sensor infrarrojo central */
void Robot::setSiguelineasCentro(int siguelineasCentro){
  PIN_SIGUELINEAS_CENTRO = siguelineasCentro;
  pinMode(PIN_SIGUELINEAS_CENTRO, INPUT);
}

/** Establece el pin del sensor infrarrojo derecho */
void Robot::setSiguelineasDcha(int siguelineasDcha){
  PIN_SIGUELINEAS_DCHA = siguelineasDcha;
  pinMode(PIN_SIGUELINEAS_DCHA, INPUT);
}


void Robot::setTodosSiguelineas(int izda, int centro, int dcha){
  this->setSiguelineasIzda(izda);
  this->setSiguelineasCentro(centro);
  this->setSiguelineasDcha(dcha);
}


bool Robot::readSiguelineasIzda(){
  if(PIN_SIGUELINEAS_IZDA < 0){
    //error
  }else{
    bool lectura =  (bool) digitalRead(PIN_SIGUELINEAS_IZDA);
    return lectura;
  }
}

bool Robot::readSiguelineasCentro(){
  if(PIN_SIGUELINEAS_CENTRO < 0){
    //error
  }else{
    bool lectura =  (bool) digitalRead(PIN_SIGUELINEAS_CENTRO);
    return lectura;
  }
}

bool Robot::readSiguelineasDcha(){
  if(PIN_SIGUELINEAS_DCHA < 0){
    //error
  }else{
    bool lectura =  (bool) digitalRead(PIN_SIGUELINEAS_DCHA);
    return lectura;
  }
}


/** OBJETOS YA DISEÑADOS */
Robot arduino(9, 12, 9, 13, 10, 11); //El pin 9 no está siendo usado, 
//y me permite escribir "digitalWrite"s sin afectar al funcionamiento del robot

Robot elegoo(6, 7, 9, 8, 5, 11);
