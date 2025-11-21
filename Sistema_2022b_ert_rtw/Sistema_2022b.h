/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Sistema_2022b.h
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

#ifndef Sistema_2022b_h_
#define Sistema_2022b_h_
#ifndef Sistema_2022b_COMMON_INCLUDES_
#define Sistema_2022b_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* Sistema_2022b_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  int32_T sfEvent;                     /* '<Root>/Sistema_2022b' */
  uint32_T temporalCounter_i1;         /* '<Root>/Sistema_2022b' */
  int16_T tempo_di_chiusura;           /* '<Root>/Sistema_2022b' */
  int16_T tempo_di_lavoro;             /* '<Root>/Sistema_2022b' */
  uint8_T is_active_c1_Sistema_2022b;  /* '<Root>/Sistema_2022b' */
  uint8_T is_c1_Sistema_2022b;         /* '<Root>/Sistema_2022b' */
  uint8_T is_active_CANCELLO;          /* '<Root>/Sistema_2022b' */
  uint8_T is_CANCELLO;                 /* '<Root>/Sistema_2022b' */
  uint8_T is_APERTURA;                 /* '<Root>/Sistema_2022b' */
  uint8_T is_CHIUSURA;                 /* '<Root>/Sistema_2022b' */
  uint8_T is_RIGETTO_RICHIESTA;        /* '<Root>/Sistema_2022b' */
  uint8_T is_active_BUTTON1;           /* '<Root>/Sistema_2022b' */
  uint8_T is_BUTTON1;                  /* '<Root>/Sistema_2022b' */
  uint8_T is_active_BUTTON2;           /* '<Root>/Sistema_2022b' */
  uint8_T is_BUTTON2;                  /* '<Root>/Sistema_2022b' */
  uint8_T is_active_BUTTON3;           /* '<Root>/Sistema_2022b' */
  uint8_T is_BUTTON3;                  /* '<Root>/Sistema_2022b' */
  uint8_T temporalCounter_i2;          /* '<Root>/Sistema_2022b' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T button1;                   /* '<Root>/button1' */
  boolean_T sensor2;                   /* '<Root>/sensor2' */
  boolean_T sensor1;                   /* '<Root>/sensor1' */
  boolean_T button3;                   /* '<Root>/button3' */
  boolean_T button2;                   /* '<Root>/button2' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T redled;                    /* '<Root>/redled' */
  boolean_T yellowled;                 /* '<Root>/yellowled' */
  boolean_T greenled;                  /* '<Root>/greenled' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Sistema_2022b_initialize(void);
extern void Sistema_2022b_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('cancello_2022b/Sistema_2022b')    - opens subsystem cancello_2022b/Sistema_2022b
 * hilite_system('cancello_2022b/Sistema_2022b/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'cancello_2022b'
 * '<S1>'   : 'cancello_2022b/Sistema_2022b'
 */
#endif                                 /* Sistema_2022b_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
