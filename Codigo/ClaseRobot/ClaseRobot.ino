class Robot{
  public:
    //Constructores
    Robot(int, int, int, int); //Pares de motores
    Robot(int, int, int, int, int, int, int, int); //Cada motor por separado
    //Destructores
    ~Robot(); 

    void arranca();
    void lento();
    void maxVelocidad();
    void giraIzda();
    void giraDcha();

  protected: //Solo la clase y sus hijos pueden ver estos elementos
    int PIN_GIRO_IZDA_ARRIBA;
    int PIN_GIRO_IZDA_ABAJO;
    int PIN_GIRO_DCHA_ARRIBA;
    int PIN_GIRO_DCHA_ABAJO;
    
    int PIN_VEL_IZDA_ARRIBA;
    int PIN_VEL_IZDA_ABAJO;
    int PIN_VEL_DCHA_ARRIBA;
    int PIN_VEL_DCHA_ABAJO;
    
    int pinSiguelineasIzda;
    int pinSiguelineasCentro;
    int pinSiguelineasDcha;
};

/** Inicializa un robot cuyo driver solo tiene 4 entradas para 8 cables de motores */
Robot::Robot(int pinGiroIzda, int pinGiroDcha, int pinVelIzda, int pinVelDcha){
    PIN_GIRO_IZDA_ARRIBA = pinGiroIzda;
    PIN_GIRO_IZDA_ABAJO = pinGiroIzda;
    pinMode(pinGiroIzda, OUTPUT);
    
    PIN_GIRO_DCHA_ARRIBA = pinGiroDcha;
    PIN_GIRO_DCHA_ABAJO = pinGiroDcha;
    pinMode(pinGiroDcha, OUTPUT);

    
    PIN_VEL_IZDA_ARRIBA = pinVelIzda;
    PIN_VEL_IZDA_ABAJO = pinVelIzda;
    pinMode(pinVelIzda, OUTPUT);
    
    PIN_VEL_DCHA_ARRIBA = pinVelDcha;
    PIN_VEL_DCHA_ABAJO = pinVelDcha;
    pinMode(pinVelDcha, OUTPUT);
}

/** Destructor TODO */
Robot::~Robot(){};

/** Se aplica mucha tensión durante un corto periodo de tiempo para que los motores empiecen a funcionar*/
void Robot::arranca(){
  analogWrite(PIN_VEL_IZDA_ARRIBA, 255);
  analogWrite(PIN_VEL_IZDA_ABAJO, 255);
  analogWrite(PIN_VEL_DCHA_ARRIBA, 255);
  analogWrite(PIN_VEL_DCHA_ABAJO, 255);
  delay(150);
}

/** Mueve el coche al 40% de la capacidad de las pilas */
void Robot::lento(){ 
  analogWrite(PIN_VEL_IZDA_ARRIBA, 100);
  analogWrite(PIN_VEL_IZDA_ABAJO, 100);
  analogWrite(PIN_VEL_DCHA_ARRIBA, 100);
  analogWrite(PIN_VEL_DCHA_ABAJO, 100);
}

/** Mueve el coche al 100% de la capacidad de las pilas */
void Robot::maxVelocidad(){
  analogWrite(PIN_VEL_IZDA_ARRIBA, 255);
  analogWrite(PIN_VEL_IZDA_ABAJO, 255);
  analogWrite(PIN_VEL_DCHA_ARRIBA, 255);
  analogWrite(PIN_VEL_DCHA_ABAJO, 255);
};
