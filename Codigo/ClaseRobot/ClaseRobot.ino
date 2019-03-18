class Robot{
  public:
    //Constructores
    Robot(int, int, int, int, int, int); 
    //Destructores
    ~Robot(); 

    void arranca();
    void para();
    void lento();
    void maxVelocidad();
    void giraIzda();
    void giraDcha();
    void alante();
    void atras();
    void rotaIzda();
    void rotaDcha();

  protected: //Solo la clase y sus hijos pueden ver estos elementos
    int PIN_IZDA_ALANTE;
    int PIN_IZDA_ATRAS;
    int PIN_DCHA_ALANTE;
    int PIN_DCHA_ATRAS;
    
    int PIN_VEL_IZDA;
    int PIN_VEL_DCHA;
    
    int PIN_SIGUELINEAS_IZDA;
    int PIN_SIGUELINEAS_CENTRO;
    int PIN_SIGUELINEAS_DCHA;
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

/** Destructor TODO */
Robot::~Robot(){};

/** Se aplica mucha tensión durante un corto periodo de tiempo para que los motores empiecen a funcionar*/
void Robot::arranca(){
  analogWrite(PIN_VEL_IZDA, 255);
  analogWrite(PIN_VEL_DCHA, 255);
  delay(150);
}

/** Mueve el coche al 40% de la capacidad de las pilas */
void Robot::lento(){ 
  analogWrite(PIN_VEL_IZDA, 100);
  analogWrite(PIN_VEL_DCHA, 100);
}

/** Mueve el coche al 100% de la capacidad de las pilas */
void Robot::maxVelocidad(){
  analogWrite(PIN_VEL_IZDA, 255);
  analogWrite(PIN_VEL_DCHA, 255);
};

/** Deja de alimentar los motores. Debe arrancarse de nuevo cuando quiera retomar la marcha*/
void Robot::para(){
  analogWrite(PIN_VEL_IZDA, 0);
  analogWrite(PIN_VEL_DCHA, 0);
}

/** El robot gira hacia la izda parando los motores de la izda*/
void Robot::giraIzda(){
  analogWrite(PIN_VEL_IZDA, 255);
  analogWrite(PIN_VEL_DCHA, 0);
}

/** El robot gira hacia la dcha parando los motores de la dcha*/
void Robot::giraDcha(){
  analogWrite(PIN_VEL_IZDA, 0);
  analogWrite(PIN_VEL_DCHA, 255);
}

void Robot::alante(){
  digitalWrite(PIN_IZDA_ALANTE, HIGH);
  digitalWrite(PIN_IZDA_ATRAS, LOW);
  digitalWrite(PIN_DCHA_ALANTE, HIGH);
  digitalWrite(PIN_DCHA_ATRAS, LOW);
}

void Robot::atras(){
  digitalWrite(PIN_IZDA_ALANTE, LOW);
  digitalWrite(PIN_IZDA_ATRAS, HIGH);
  digitalWrite(PIN_DCHA_ALANTE, LOW);
  digitalWrite(PIN_DCHA_ATRAS, HIGH);
}

/** El robot pivota hacia la izda cambiando la direccion de giro de los motores de la izda*/
void Robot::rotaIzda(){
  digitalWrite(PIN_IZDA_ALANTE, LOW);
  digitalWrite(PIN_IZDA_ATRAS, HIGH);
  digitalWrite(PIN_DCHA_ALANTE, HIGH);
  digitalWrite(PIN_DCHA_ATRAS, LOW);
}

/** El robot pivota hacia la dcha cambiando la direccion de giro de los motores de la dcha*/
void Robot::rotaDcha(){
  digitalWrite(PIN_IZDA_ALANTE, HIGH);
  digitalWrite(PIN_IZDA_ATRAS, LOW);
  digitalWrite(PIN_DCHA_ALANTE, LOW);
  digitalWrite(PIN_DCHA_ATRAS, HIGH);
}




/** OBJETOS YA DISEÑADOS */
Robot arduino(9, 12, 9, 13, 10, 11); //El pin 9 no está siendo usado, 
//y me permite escribir "digitalWrite"s sin afectar al funcionamiento del robot
