/* Copyright 2016, Eric Pernia.
 * All rights reserved.
 *
 * This file is part sAPI library for microcontrollers.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 * Date: 2016-04-26
 */

/*==================[inclusions]=============================================*/

#include "main.h"         /* <= own header */

#include "sAPI.h"         /* <= sAPI header */

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */
int main(void){

   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();

   /* Inicializar DigitalIO */
   digitalConfig( 0, ENABLE_DIGITAL_IO );

   /* Configuración de pines de entrada para Teclas de la CIAA-NXP */
   digitalConfig( TEC1, INPUT );
   digitalConfig( TEC2, INPUT );
   digitalConfig( TEC3, INPUT );
   digitalConfig( TEC4, INPUT );

   digitalConfig( DIO14, INPUT );

   /* Configuración de pines de salida para Leds de la CIAA-NXP */
   digitalConfig( LEDR, OUTPUT );
   digitalConfig( LEDG, OUTPUT );
   digitalConfig( LEDB, OUTPUT );
   digitalConfig( LED1, OUTPUT );
   digitalConfig( LED2, OUTPUT );
   digitalConfig( LED3, OUTPUT );

   digitalConfig( DIO15, OUTPUT );

   /* Variable para almacenar el valor de tecla leido */
   bool_t valor;

   /* ------------- REPETIR POR SIEMPRE ------------- */
   while(1) {
       int encendido;

      if(digitalRead(TEC1)==OFF){
           encendido++;
         while(digitalRead(TEC1)==OFF){
         }
      }
         if (encendido==1){
            digitalWrite(LED1,ON);
            encendido=0;
         }
         if (encendido==2){
            digitalWrite(LED1,OFF);
         }
       if (encendido>=3){
          digitalWrite(LED1,OFF);
       }

       if(digitalRead(TEC2)==OFF){
                 encendido++;
               while(digitalRead(TEC2)==OFF){
               }
            }
               if (encendido==1){
                  digitalWrite(LED2,ON);
                  encendido=0;
               }
               if (encendido==2){
                  digitalWrite(LED2,OFF);
               }
             if (encendido>=3){
                digitalWrite(LED2,OFF);
             }

          if(digitalRead(TEC3)==OFF){
                     encendido++;
                   while(digitalRead(TEC3)==OFF){
                   }
                }
                   if (encendido==1){
                      digitalWrite(LED3,ON);
                      encendido=0;
                   }
                   if (encendido==2){
                      digitalWrite(LED3,OFF);
                   }
                 if (encendido>=3){
                    digitalWrite(LED3,OFF);
                 }

              if(digitalRead(TEC4)==OFF){
                        encendido++;
                      while(digitalRead(TEC4)==OFF){
                      }
                   }
                      if (encendido==1){
                         digitalWrite(LEDR,ON);
                         encendido=0;
                      }
                      if (encendido==2){
                         digitalWrite(LEDR,OFF);
                      }
                    if (encendido>=3){
                       digitalWrite(LEDR,OFF);
                    }
         }

   /* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */
   return 0 ;
}

/*==================[end of file]============================================*/
