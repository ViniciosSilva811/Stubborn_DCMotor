/* ------------------------------------------------------------------------------------- *\
|                                                                                         |
|                                                                                         |
|                                   Stubborn_DCMotor.h                                    |
|                   Código baseado na biblioteca Adafruit Motor Shield	                  |
|                                   Developed by Venish                                   |
|                                                                                         |
|                                                                                         |
|                                                                                         |
\* ------------------------------------------------------------------------------------- */

// ------------------------------------------------------------------------------------- //

#include <Arduino.h>
#include "Stubborn_DCMotor.h"

// --------------------------------- MÉTODO CONSTRUTOR --------------------------------- //

Stubborn_DCMotor::Stubborn_DCMotor(uint8_t pino_A, uint8_t pino_B, uint8_t pwm_pino){
	
    _pino_A = pino_A;
    _pino_B = pino_B;
    _pwm_pino = pwm_pino;
	
    pinMode(_pino_A, OUTPUT);
    pinMode(_pino_B, OUTPUT);
    pinMode(_pwm_pino, OUTPUT);

}

// ---------------------- FUNÇÃO PARA CONFIGURAÇÃO DE VELOCIDADE ----------------------- //

void Stubborn_DCMotor::setSpeed(uint8_t velocidade){
	
	_velocidade = velocidade;

    analogWrite(_pwm_pino, _velocidade);

}

// ------------------- FUNÇÃO PARA CONFIGURAÇÃO DE SENTIDO DE ROTAÇÃO ------------------ //

void Stubborn_DCMotor::run(uint8_t sentido){
    
	_sentido = sentido;
	
	switch (_sentido) {
	    case FORWARD:
	      digitalWrite(_pino_A, HIGH);
	      digitalWrite(_pino_B, LOW);
	      break;
	    case BACKWARD:
	      digitalWrite(_pino_A, LOW);
	      digitalWrite(_pino_B, HIGH);
	      break;
	    case BRAKE:
	      digitalWrite(_pino_A, HIGH);
	      digitalWrite(_pino_B, HIGH);
	      break;
	    case RELEASE:
	      digitalWrite(_pino_A, LOW);
	      digitalWrite(_pino_B, LOW);
	      break;
	}
}

// ----------------------------------- FIM DO CÓDIGO ----------------------------------- //
