/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Sistema_2022b.c
 *
 * Code generated for Simulink model 'Sistema_2022b'.
 *
 * Model version                  : 4.17
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Jun  1 14:41:59 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Sistema_2022b.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<Root>/Sistema_2022b' */
#define CALL_EVENT                     (-1)
#define IN_APERTO                      ((uint8_T)1U)
#define IN_APERTURA                    ((uint8_T)2U)
#define IN_AVVIO                       ((uint8_T)3U)
#define IN_CHIUSO                      ((uint8_T)4U)
#define IN_CHIUSURA                    ((uint8_T)5U)
#define IN_ERRORE                      ((uint8_T)6U)
#define IN_GREEN_acceso                ((uint8_T)1U)
#define IN_GREEN_spento                ((uint8_T)2U)
#define IN_LOGIC                       ((uint8_T)1U)
#define IN_LONGPRESSED                 ((uint8_T)1U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_PRESSED                     ((uint8_T)2U)
#define IN_RELEASED                    ((uint8_T)3U)
#define IN_RIGETTO_RICHIESTA           ((uint8_T)7U)
#define IN_STATO_ALLARME               ((uint8_T)8U)
#define IN_TEMPO_DI_CHIUSURA           ((uint8_T)9U)
#define IN_TEMPO_DI_LAVORO             ((uint8_T)10U)
#define IN_YELLOW_acceso               ((uint8_T)1U)
#define IN_YELLOW_spento               ((uint8_T)2U)
#define OFF                            (false)
#define ON                             (true)
#define event_buttonpressed1           (0)
#define event_buttonpressed2           (1)
#define event_buttonpressed3           (2)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static void CHIUSURA(void);
static void RIGETTO_RICHIESTA(void);
static void CANCELLO(void);
static void broadcast_buttonpressed1(void);
static void broadcast_buttonpressed2(void);
static void broadcast_buttonpressed3(void);
static void c1_Sistema_2022b(void);

/* Function for Chart: '<Root>/Sistema_2022b' */
static void CHIUSURA(void)
{
  /* Inport: '<Root>/sensor1' incorporates:
   *  Inport: '<Root>/sensor2'
   */
  if ((rtDW.sfEvent == event_buttonpressed1) || rtU.sensor1) {
    switch (rtDW.is_CHIUSURA) {
     case IN_YELLOW_acceso:
      rtDW.is_CHIUSURA = IN_NO_ACTIVE_CHILD;
      break;

     case IN_YELLOW_spento:
      rtDW.is_CHIUSURA = IN_NO_ACTIVE_CHILD;
      break;
    }

    rtDW.temporalCounter_i1 = 0U;
    rtDW.is_CANCELLO = IN_APERTURA;
    rtDW.temporalCounter_i2 = 0U;
    rtDW.is_APERTURA = IN_YELLOW_spento;

    /* Outport: '<Root>/redled' */
    rtY.redled = OFF;

    /* Outport: '<Root>/yellowled' */
    rtY.yellowled = OFF;

    /* Outport: '<Root>/greenled' */
    rtY.greenled = OFF;
  } else if (rtU.sensor2) {
    switch (rtDW.is_CHIUSURA) {
     case IN_YELLOW_acceso:
      rtDW.is_CHIUSURA = IN_NO_ACTIVE_CHILD;
      break;

     case IN_YELLOW_spento:
      rtDW.is_CHIUSURA = IN_NO_ACTIVE_CHILD;
      break;
    }

    rtDW.is_CANCELLO = IN_CHIUSO;

    /* Outport: '<Root>/redled' */
    rtY.redled = OFF;

    /* Outport: '<Root>/yellowled' */
    rtY.yellowled = OFF;

    /* Outport: '<Root>/greenled' */
    rtY.greenled = OFF;
  } else if ((rtDW.temporalCounter_i1 >= (uint32_T)((uint16_T)
               rtDW.tempo_di_lavoro * 10)) && (!rtU.sensor2)) {
    switch (rtDW.is_CHIUSURA) {
     case IN_YELLOW_acceso:
      /* Outport: '<Root>/yellowled' */
      rtY.yellowled = OFF;
      rtDW.is_CHIUSURA = IN_NO_ACTIVE_CHILD;
      break;

     case IN_YELLOW_spento:
      rtDW.is_CHIUSURA = IN_NO_ACTIVE_CHILD;
      break;
    }

    rtDW.temporalCounter_i1 = 0U;
    rtDW.is_CANCELLO = IN_ERRORE;
  } else {
    switch (rtDW.is_CHIUSURA) {
     case IN_YELLOW_acceso:
      if (rtDW.temporalCounter_i2 >= 20U) {
        rtDW.temporalCounter_i2 = 0U;
        rtDW.is_CHIUSURA = IN_YELLOW_spento;

        /* Outport: '<Root>/redled' */
        rtY.redled = OFF;

        /* Outport: '<Root>/yellowled' */
        rtY.yellowled = OFF;

        /* Outport: '<Root>/greenled' */
        rtY.greenled = OFF;
      }
      break;

     case IN_YELLOW_spento:
      if (rtDW.temporalCounter_i2 >= 20U) {
        rtDW.temporalCounter_i2 = 0U;
        rtDW.is_CHIUSURA = IN_YELLOW_acceso;

        /* Outport: '<Root>/yellowled' */
        rtY.yellowled = ON;
      }
      break;
    }
  }

  /* End of Inport: '<Root>/sensor1' */
}

/* Function for Chart: '<Root>/Sistema_2022b' */
static void RIGETTO_RICHIESTA(void)
{
  boolean_T tmp;

  /* Inport: '<Root>/sensor1' */
  tmp = ((rtDW.temporalCounter_i1 >= 300U) || (!rtU.sensor1));

  /* Inport: '<Root>/sensor2' */
  if (rtU.sensor2 && tmp) {
    switch (rtDW.is_RIGETTO_RICHIESTA) {
     case IN_GREEN_acceso:
      rtDW.is_RIGETTO_RICHIESTA = IN_NO_ACTIVE_CHILD;
      break;

     case IN_GREEN_spento:
      rtDW.is_RIGETTO_RICHIESTA = IN_NO_ACTIVE_CHILD;
      break;
    }

    rtDW.is_CANCELLO = IN_CHIUSO;

    /* Outport: '<Root>/redled' */
    rtY.redled = OFF;

    /* Outport: '<Root>/yellowled' */
    rtY.yellowled = OFF;

    /* Outport: '<Root>/greenled' */
    rtY.greenled = OFF;
  } else if ((!rtU.sensor2) && tmp) {
    switch (rtDW.is_RIGETTO_RICHIESTA) {
     case IN_GREEN_acceso:
      rtDW.is_RIGETTO_RICHIESTA = IN_NO_ACTIVE_CHILD;
      break;

     case IN_GREEN_spento:
      rtDW.is_RIGETTO_RICHIESTA = IN_NO_ACTIVE_CHILD;
      break;
    }

    rtDW.temporalCounter_i1 = 0U;
    rtDW.is_CANCELLO = IN_APERTO;

    /* Outport: '<Root>/redled' */
    rtY.redled = ON;

    /* Outport: '<Root>/yellowled' */
    rtY.yellowled = ON;

    /* Outport: '<Root>/greenled' */
    rtY.greenled = ON;
  } else {
    switch (rtDW.is_RIGETTO_RICHIESTA) {
     case IN_GREEN_acceso:
      if (rtDW.temporalCounter_i2 >= 10U) {
        rtDW.temporalCounter_i2 = 0U;
        rtDW.is_RIGETTO_RICHIESTA = IN_GREEN_spento;

        /* Outport: '<Root>/redled' */
        rtY.redled = OFF;

        /* Outport: '<Root>/yellowled' */
        rtY.yellowled = OFF;

        /* Outport: '<Root>/greenled' */
        rtY.greenled = OFF;
      }
      break;

     case IN_GREEN_spento:
      if (rtDW.temporalCounter_i2 >= 10U) {
        rtDW.temporalCounter_i2 = 0U;
        rtDW.is_RIGETTO_RICHIESTA = IN_GREEN_acceso;

        /* Outport: '<Root>/greenled' */
        rtY.greenled = ON;
      }
      break;
    }
  }

  /* End of Inport: '<Root>/sensor2' */
}

/* Function for Chart: '<Root>/Sistema_2022b' */
static void CANCELLO(void)
{
  int32_T tmp;
  switch (rtDW.is_CANCELLO) {
   case IN_APERTO:
    /* Inport: '<Root>/sensor1' */
    if ((!rtU.sensor1) && ((rtDW.sfEvent == event_buttonpressed1) ||
                           (rtDW.temporalCounter_i1 >= (uint32_T)((uint16_T)
           rtDW.tempo_di_chiusura * 10)))) {
      rtDW.temporalCounter_i1 = 0U;
      rtDW.is_CANCELLO = IN_CHIUSURA;
      rtDW.temporalCounter_i2 = 0U;
      rtDW.is_CHIUSURA = IN_YELLOW_spento;

      /* Outport: '<Root>/redled' */
      rtY.redled = OFF;

      /* Outport: '<Root>/yellowled' */
      rtY.yellowled = OFF;

      /* Outport: '<Root>/greenled' */
      rtY.greenled = OFF;
    } else if ((rtDW.sfEvent == event_buttonpressed1) && rtU.sensor1) {
      rtDW.temporalCounter_i1 = 0U;
      rtDW.is_CANCELLO = IN_RIGETTO_RICHIESTA;
      rtDW.temporalCounter_i2 = 0U;
      rtDW.is_RIGETTO_RICHIESTA = IN_GREEN_spento;

      /* Outport: '<Root>/redled' */
      rtY.redled = OFF;

      /* Outport: '<Root>/yellowled' */
      rtY.yellowled = OFF;

      /* Outport: '<Root>/greenled' */
      rtY.greenled = OFF;
    }
    break;

   case IN_APERTURA:
    if (rtDW.sfEvent == event_buttonpressed1) {
      switch (rtDW.is_APERTURA) {
       case IN_YELLOW_acceso:
        rtDW.is_APERTURA = IN_NO_ACTIVE_CHILD;
        break;

       case IN_YELLOW_spento:
        rtDW.is_APERTURA = IN_NO_ACTIVE_CHILD;
        break;
      }

      rtDW.temporalCounter_i1 = 0U;
      rtDW.is_CANCELLO = IN_CHIUSURA;
      rtDW.temporalCounter_i2 = 0U;
      rtDW.is_CHIUSURA = IN_YELLOW_spento;

      /* Outport: '<Root>/redled' */
      rtY.redled = OFF;

      /* Outport: '<Root>/yellowled' */
      rtY.yellowled = OFF;

      /* Outport: '<Root>/greenled' */
      rtY.greenled = OFF;
    } else if (rtDW.temporalCounter_i1 >= (uint32_T)((uint16_T)
                rtDW.tempo_di_lavoro * 10)) {
      switch (rtDW.is_APERTURA) {
       case IN_YELLOW_acceso:
        rtDW.is_APERTURA = IN_NO_ACTIVE_CHILD;
        break;

       case IN_YELLOW_spento:
        rtDW.is_APERTURA = IN_NO_ACTIVE_CHILD;
        break;
      }

      rtDW.temporalCounter_i1 = 0U;
      rtDW.is_CANCELLO = IN_APERTO;

      /* Outport: '<Root>/redled' */
      rtY.redled = ON;

      /* Outport: '<Root>/yellowled' */
      rtY.yellowled = ON;

      /* Outport: '<Root>/greenled' */
      rtY.greenled = ON;
    } else {
      switch (rtDW.is_APERTURA) {
       case IN_YELLOW_acceso:
        if (rtDW.temporalCounter_i2 >= 20U) {
          rtDW.temporalCounter_i2 = 0U;
          rtDW.is_APERTURA = IN_YELLOW_spento;

          /* Outport: '<Root>/redled' */
          rtY.redled = OFF;

          /* Outport: '<Root>/yellowled' */
          rtY.yellowled = OFF;

          /* Outport: '<Root>/greenled' */
          rtY.greenled = OFF;
        }
        break;

       case IN_YELLOW_spento:
        if (rtDW.temporalCounter_i2 >= 20U) {
          rtDW.temporalCounter_i2 = 0U;
          rtDW.is_APERTURA = IN_YELLOW_acceso;

          /* Outport: '<Root>/yellowled' */
          rtY.yellowled = ON;
        }
        break;
      }
    }
    break;

   case IN_AVVIO:
    /* Inport: '<Root>/sensor2' */
    if (rtU.sensor2) {
      rtDW.is_CANCELLO = IN_CHIUSO;

      /* Outport: '<Root>/redled' */
      rtY.redled = OFF;

      /* Outport: '<Root>/yellowled' */
      rtY.yellowled = OFF;

      /* Outport: '<Root>/greenled' */
      rtY.greenled = OFF;
    } else {
      rtDW.temporalCounter_i1 = 0U;
      rtDW.is_CANCELLO = IN_CHIUSURA;
      rtDW.temporalCounter_i2 = 0U;
      rtDW.is_CHIUSURA = IN_YELLOW_spento;

      /* Outport: '<Root>/redled' */
      rtY.redled = OFF;

      /* Outport: '<Root>/yellowled' */
      rtY.yellowled = OFF;

      /* Outport: '<Root>/greenled' */
      rtY.greenled = OFF;
    }
    break;

   case IN_CHIUSO:
    /* Inport: '<Root>/sensor1' */
    if ((rtDW.sfEvent == event_buttonpressed1) && (!rtU.sensor1)) {
      rtDW.temporalCounter_i1 = 0U;
      rtDW.is_CANCELLO = IN_APERTURA;
      rtDW.temporalCounter_i2 = 0U;
      rtDW.is_APERTURA = IN_YELLOW_spento;

      /* Outport: '<Root>/redled' */
      rtY.redled = OFF;

      /* Outport: '<Root>/yellowled' */
      rtY.yellowled = OFF;

      /* Outport: '<Root>/greenled' */
      rtY.greenled = OFF;
    } else if ((rtDW.sfEvent == event_buttonpressed1) && rtU.sensor1) {
      rtDW.temporalCounter_i1 = 0U;
      rtDW.is_CANCELLO = IN_RIGETTO_RICHIESTA;
      rtDW.temporalCounter_i2 = 0U;
      rtDW.is_RIGETTO_RICHIESTA = IN_GREEN_spento;

      /* Outport: '<Root>/redled' */
      rtY.redled = OFF;

      /* Outport: '<Root>/yellowled' */
      rtY.yellowled = OFF;

      /* Outport: '<Root>/greenled' */
      rtY.greenled = OFF;
    } else {
      switch (rtDW.sfEvent) {
       case event_buttonpressed3:
        rtDW.is_CANCELLO = IN_TEMPO_DI_LAVORO;
        if (rtDW.tempo_di_lavoro == 120) {
          rtDW.tempo_di_lavoro = 10;
        } else {
          tmp = rtDW.tempo_di_lavoro + 10;
          if (rtDW.tempo_di_lavoro + 10 > 32767) {
            tmp = 32767;
          }

          rtDW.tempo_di_lavoro = (int16_T)tmp;
        }
        break;

       case event_buttonpressed2:
        rtDW.is_CANCELLO = IN_TEMPO_DI_CHIUSURA;
        if (rtDW.tempo_di_chiusura == 120) {
          rtDW.tempo_di_chiusura = 10;
        } else {
          tmp = rtDW.tempo_di_chiusura + 10;
          if (rtDW.tempo_di_chiusura + 10 > 32767) {
            tmp = 32767;
          }

          rtDW.tempo_di_chiusura = (int16_T)tmp;
        }
        break;
      }
    }
    break;

   case IN_CHIUSURA:
    CHIUSURA();
    break;

   case IN_ERRORE:
    /* Inport: '<Root>/sensor2' */
    if ((!rtU.sensor2) && (rtDW.temporalCounter_i1 >= 100U)) {
      rtDW.is_CANCELLO = IN_STATO_ALLARME;

      /* Outport: '<Root>/redled' */
      rtY.redled = ON;
    } else if (rtU.sensor2) {
      rtDW.is_CANCELLO = IN_CHIUSO;

      /* Outport: '<Root>/redled' */
      rtY.redled = OFF;

      /* Outport: '<Root>/yellowled' */
      rtY.yellowled = OFF;

      /* Outport: '<Root>/greenled' */
      rtY.greenled = OFF;
    }
    break;

   case IN_RIGETTO_RICHIESTA:
    RIGETTO_RICHIESTA();
    break;

   case IN_STATO_ALLARME:
    /* Inport: '<Root>/sensor2' */
    if (rtU.sensor2) {
      rtDW.is_CANCELLO = IN_CHIUSO;

      /* Outport: '<Root>/redled' */
      rtY.redled = OFF;

      /* Outport: '<Root>/yellowled' */
      rtY.yellowled = OFF;

      /* Outport: '<Root>/greenled' */
      rtY.greenled = OFF;
    }
    break;

   case IN_TEMPO_DI_CHIUSURA:
    rtDW.is_CANCELLO = IN_CHIUSO;

    /* Outport: '<Root>/redled' */
    rtY.redled = OFF;

    /* Outport: '<Root>/yellowled' */
    rtY.yellowled = OFF;

    /* Outport: '<Root>/greenled' */
    rtY.greenled = OFF;
    break;

   case IN_TEMPO_DI_LAVORO:
    rtDW.is_CANCELLO = IN_CHIUSO;

    /* Outport: '<Root>/redled' */
    rtY.redled = OFF;

    /* Outport: '<Root>/yellowled' */
    rtY.yellowled = OFF;

    /* Outport: '<Root>/greenled' */
    rtY.greenled = OFF;
    break;
  }
}

/* Function for Chart: '<Root>/Sistema_2022b' */
static void broadcast_buttonpressed1(void)
{
  int32_T b_previousEvent;
  b_previousEvent = rtDW.sfEvent;
  rtDW.sfEvent = event_buttonpressed1;

  /* Chart: '<Root>/Sistema_2022b' */
  c1_Sistema_2022b();
  rtDW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/Sistema_2022b' */
static void broadcast_buttonpressed2(void)
{
  int32_T b_previousEvent;
  b_previousEvent = rtDW.sfEvent;
  rtDW.sfEvent = event_buttonpressed2;

  /* Chart: '<Root>/Sistema_2022b' */
  c1_Sistema_2022b();
  rtDW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/Sistema_2022b' */
static void broadcast_buttonpressed3(void)
{
  int32_T b_previousEvent;
  b_previousEvent = rtDW.sfEvent;
  rtDW.sfEvent = event_buttonpressed3;

  /* Chart: '<Root>/Sistema_2022b' */
  c1_Sistema_2022b();
  rtDW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/Sistema_2022b' */
static void c1_Sistema_2022b(void)
{
  /* Chart: '<Root>/Sistema_2022b' incorporates:
   *  Inport: '<Root>/button1'
   *  Inport: '<Root>/button2'
   *  Inport: '<Root>/button3'
   */
  if (rtDW.is_active_c1_Sistema_2022b == 0U) {
    rtDW.is_active_c1_Sistema_2022b = 1U;
    rtDW.is_c1_Sistema_2022b = IN_LOGIC;
    rtDW.is_active_CANCELLO = 1U;
    rtDW.is_CANCELLO = IN_AVVIO;
    rtDW.tempo_di_lavoro = 10;
    rtDW.tempo_di_chiusura = 10;
    rtDW.is_active_BUTTON1 = 1U;
    rtDW.is_BUTTON1 = IN_RELEASED;
    rtDW.is_active_BUTTON2 = 1U;
    rtDW.is_BUTTON2 = IN_RELEASED;
    rtDW.is_active_BUTTON3 = 1U;
    rtDW.is_BUTTON3 = IN_RELEASED;
  } else if (rtDW.is_c1_Sistema_2022b == IN_LOGIC) {
    if (rtDW.is_active_CANCELLO != 0U) {
      CANCELLO();
    }

    if (rtDW.is_active_BUTTON1 != 0U) {
      switch (rtDW.is_BUTTON1) {
       case IN_LONGPRESSED:
        if (!rtU.button1) {
          rtDW.is_BUTTON1 = IN_RELEASED;
        } else {
          broadcast_buttonpressed1();
        }
        break;

       case IN_PRESSED:
        if (!rtU.button1) {
          rtDW.is_BUTTON1 = IN_LONGPRESSED;
          broadcast_buttonpressed1();
        }
        break;

       case IN_RELEASED:
        if (rtU.button1) {
          rtDW.is_BUTTON1 = IN_PRESSED;
        }
        break;
      }
    }

    if (rtDW.is_active_BUTTON2 != 0U) {
      switch (rtDW.is_BUTTON2) {
       case IN_LONGPRESSED:
        if (!rtU.button2) {
          rtDW.is_BUTTON2 = IN_RELEASED;
        } else {
          broadcast_buttonpressed2();
        }
        break;

       case IN_PRESSED:
        if (!rtU.button2) {
          rtDW.is_BUTTON2 = IN_LONGPRESSED;
          broadcast_buttonpressed2();
        }
        break;

       case IN_RELEASED:
        if (rtU.button2) {
          rtDW.is_BUTTON2 = IN_PRESSED;
        }
        break;
      }
    }

    if (rtDW.is_active_BUTTON3 != 0U) {
      switch (rtDW.is_BUTTON3) {
       case IN_LONGPRESSED:
        if (!rtU.button3) {
          rtDW.is_BUTTON3 = IN_RELEASED;
        } else {
          broadcast_buttonpressed3();
        }
        break;

       case IN_PRESSED:
        if (!rtU.button3) {
          rtDW.is_BUTTON3 = IN_LONGPRESSED;
          broadcast_buttonpressed3();
        }
        break;

       case IN_RELEASED:
        if (rtU.button3) {
          rtDW.is_BUTTON3 = IN_PRESSED;
        }
        break;
      }
    }
  }

  /* End of Chart: '<Root>/Sistema_2022b' */
}

/* Model step function */
void Sistema_2022b_step(void)
{
  /* Chart: '<Root>/Sistema_2022b' */
  if (rtDW.temporalCounter_i1 < 524287U) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.temporalCounter_i2 < 31U) {
    rtDW.temporalCounter_i2++;
  }

  rtDW.sfEvent = CALL_EVENT;
  c1_Sistema_2022b();

  /* End of Chart: '<Root>/Sistema_2022b' */
}

/* Model initialize function */
void Sistema_2022b_initialize(void)
{
  /* SystemInitialize for Chart: '<Root>/Sistema_2022b' */
  rtDW.sfEvent = CALL_EVENT;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
