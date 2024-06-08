
/**
  ******************************************************************************
  * @file    app_x-cube-ai.c
  * @author  X-CUBE-AI C code generator
  * @brief   AI program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

 /*
  * Description
  *   v1.0 - Minimum template to show how to use the Embedded Client API
  *          model. Only one input and one output is supported. All
  *          memory resources are allocated statically (AI_NETWORK_XX, defines
  *          are used).
  *          Re-target of the printf function is out-of-scope.
  *   v2.0 - add multiple IO and/or multiple heap support
  *
  *   For more information, see the embeded documentation:
  *
  *       [1] %X_CUBE_AI_DIR%/Documentation/index.html
  *
  *   X_CUBE_AI_DIR indicates the location where the X-CUBE-AI pack is installed
  *   typical : C:\Users\<user_name>\STM32Cube\Repository\STMicroelectronics\X-CUBE-AI\7.1.0
  */

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#if defined ( __ICCARM__ )
#elif defined ( __CC_ARM ) || ( __GNUC__ )
#endif

/* System headers */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "app_x-cube-ai.h"
#include "main.h"
#include "ai_datatypes_defines.h"
#include "sinewave.h"
#include "sinewave_data.h"

/* USER CODE BEGIN includes */
/* USER CODE END includes */

/* IO buffers ----------------------------------------------------------------*/

#if !defined(AI_SINEWAVE_INPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_i8 data_in_1[AI_SINEWAVE_IN_1_SIZE_BYTES];
ai_i8* data_ins[AI_SINEWAVE_IN_NUM] = {
data_in_1
};
#else
ai_i8* data_ins[AI_SINEWAVE_IN_NUM] = {
NULL
};
#endif

#if !defined(AI_SINEWAVE_OUTPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_i8 data_out_1[AI_SINEWAVE_OUT_1_SIZE_BYTES];
ai_i8* data_outs[AI_SINEWAVE_OUT_NUM] = {
data_out_1
};
#else
ai_i8* data_outs[AI_SINEWAVE_OUT_NUM] = {
NULL
};
#endif

/* Activations buffers -------------------------------------------------------*/

AI_ALIGNED(32)
static uint8_t pool0[AI_SINEWAVE_DATA_ACTIVATION_1_SIZE];

ai_handle data_activations0[] = {pool0};

/* AI objects ----------------------------------------------------------------*/

static ai_handle sinewave = AI_HANDLE_NULL;

static ai_buffer* ai_input;
static ai_buffer* ai_output;

static void ai_log_err(const ai_error err, const char *fct)
{
  /* USER CODE BEGIN log */
  if (fct)
    printf("TEMPLATE - Error (%s) - type=0x%02x code=0x%02x\r\n", fct,
        err.type, err.code);
  else
    printf("TEMPLATE - Error - type=0x%02x code=0x%02x\r\n", err.type, err.code);

  do {} while (1);
  /* USER CODE END log */
}

static int ai_boostrap(ai_handle *act_addr)
{
  ai_error err;

  /* Create and initialize an instance of the model */
  err = ai_sinewave_create_and_init(&sinewave, act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
    ai_log_err(err, "ai_sinewave_create_and_init");
    return -1;
  }

  ai_input = ai_sinewave_inputs_get(sinewave, NULL);
  ai_output = ai_sinewave_outputs_get(sinewave, NULL);

#if defined(AI_SINEWAVE_INPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-inputs" option is used, memory buffer can be
   *  used from the activations buffer. This is not mandatory.
   */
  for (int idx=0; idx < AI_SINEWAVE_IN_NUM; idx++) {
	data_ins[idx] = ai_input[idx].data;
  }
#else
  for (int idx=0; idx < AI_SINEWAVE_IN_NUM; idx++) {
	  ai_input[idx].data = data_ins[idx];
  }
#endif

#if defined(AI_SINEWAVE_OUTPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-outputs" option is used, memory buffer can be
   *  used from the activations buffer. This is no mandatory.
   */
  for (int idx=0; idx < AI_SINEWAVE_OUT_NUM; idx++) {
	data_outs[idx] = ai_output[idx].data;
  }
#else
  for (int idx=0; idx < AI_SINEWAVE_OUT_NUM; idx++) {
	ai_output[idx].data = data_outs[idx];
  }
#endif

  return 0;
}

static int ai_run(void)
{
  ai_i32 batch;

  batch = ai_sinewave_run(sinewave, ai_input, ai_output);
  if (batch != 1) {
    ai_log_err(ai_sinewave_get_error(sinewave),
        "ai_sinewave_run");
    return -1;
  }

  return 0;
}

/* USER CODE BEGIN 2 */
int acquire_and_process_data(void* data)
{
  /* fill the inputs of the c-model
  for (int idx=0; idx < AI_NEURAL_IN_NUM; idx++ )
  {
      data[idx] = ....
  }
    */
	ai_float input_array[300] = {6.17813852e+00, 1.27926723e+00, 4.83193017e+00, 9.37656928e-01,
		       2.01349728e+00, 3.01875306e+00, 6.07798785e+00, 2.37969647e+00,
		       3.75678811e+00, 8.98533921e-01, 2.60594101e+00, 2.34663424e+00,
		       1.03747467e+00, 2.01650677e+00, 1.78230822e+00, 2.12007530e-01,
		       2.30508653e+00, 5.83544469e+00, 2.32556494e+00, 1.64069994e+00,
		       5.87934494e+00, 5.51467109e+00, 4.68895531e+00, 4.93804438e+00,
		       1.88819810e+00, 6.19127717e+00, 3.89745067e+00, 1.03129666e+00,
		       2.31437996e+00, 3.83997770e+00, 8.30547930e-01, 1.03954943e+00,
		       2.40868285e+00, 4.16272192e+00, 5.67474343e+00, 5.51471146e+00,
		       8.95710999e-01, 6.01662789e+00, 1.65945070e+00, 4.28600608e+00,
		       4.66642233e+00, 4.14870863e+00, 2.02173321e+00, 1.05152078e+00,
		       2.98025320e+00, 4.76274622e+00, 4.01048199e-01, 5.02873868e+00,
		       6.32888077e-01, 1.76713313e+00, 5.30218341e+00, 2.29904539e+00,
		       4.13806691e+00, 1.73078424e+00, 1.48463086e+00, 5.86990804e+00,
		       5.69371293e+00, 5.15451922e+00, 3.40713751e+00, 1.24361634e+00,
		       4.51780129e+00, 1.41810525e+00, 4.58491816e+00, 3.82491792e+00,
		       5.05547632e-01, 4.02178647e+00, 3.66062496e+00, 3.32060559e+00,
		       1.64488983e+00, 2.28713176e+00, 1.57247380e+00, 5.60362901e+00,
		       4.40056663e+00, 5.82170116e+00, 7.68503123e-01, 3.53609156e-01,
		       5.74636040e+00, 1.29186334e-01, 5.61534043e+00, 5.09843465e+00,
		       2.50856257e+00, 3.72025888e+00, 2.85500549e+00, 3.33051672e+00,
		       8.35558580e-01, 4.56627565e+00, 4.53616761e+00, 5.70907971e+00,
		       1.51764628e+00, 1.28300242e+00, 4.13689323e+00, 1.66983457e+00,
		       5.26868863e+00, 5.13625777e+00, 6.91097869e-02, 1.38096449e+00,
		       1.59503345e+00, 1.24629208e+00, 5.93863925e+00, 5.03812174e+00,
		       3.03818670e+00, 3.32555568e+00, 4.34916471e+00, 3.80001510e+00,
		       2.87280971e+00, 4.79807944e+00, 2.64314103e+00, 2.39624643e+00,
		       7.41813632e-01, 2.85203439e-01, 5.13083819e+00, 1.47607352e-01,
		       3.54931777e-01, 2.97763716e+00, 3.33395891e+00, 4.64733115e+00,
		       4.06059855e+00, 3.17168245e+00, 7.97026766e-01, 6.11282687e+00,
		       3.96653091e+00, 1.09957174e+00, 5.17953153e+00, 3.25301149e+00,
		       8.60519019e-01, 2.83071027e+00, 4.18458841e+00, 1.03107321e+00,
		       6.08729078e+00, 1.14043576e+00, 4.99519487e+00, 3.39738496e+00,
		       4.78224871e+00, 2.47323973e+00, 1.28770553e+00, 8.38585341e-01,
		       5.82709559e+00, 4.15228884e+00, 5.15895169e+00, 1.37292985e+00,
		       3.12681424e+00, 2.32104620e+00, 2.37262989e+00, 3.02560495e+00,
		       4.67456789e+00, 4.57657518e+00, 3.71057065e+00, 2.49856035e+00,
		       1.20298479e+00, 1.24919410e+00, 4.87600646e+00, 1.75452668e+00,
		       2.59092124e+00, 1.40279748e-01, 5.14321974e+00, 4.71719944e+00,
		       3.97129078e+00, 3.73177617e+00, 1.50054100e+00, 2.17609356e+00,
		       8.30986306e-01, 2.17075927e+00, 3.05927424e-01, 2.16506078e+00,
		       5.07239570e-03, 4.07065530e+00, 4.09237765e+00, 5.22950703e+00,
		       3.48485506e+00, 3.47144990e+00, 2.08207523e+00, 3.42632555e+00,
		       4.14299229e+00, 1.76251281e+00, 5.92354527e+00, 1.23847986e+00,
		       5.48983128e+00, 5.01542782e+00, 4.44116436e+00, 4.72612056e+00,
		       2.79540801e+00, 5.22986572e+00, 2.92368238e+00, 2.59203188e+00,
		       1.37671628e+00, 6.10711391e+00, 1.20331153e+00, 4.90057920e+00,
		       2.78469557e+00, 1.15743089e+00, 6.09211825e+00, 3.25891682e+00,
		       5.77626380e+00, 7.91417295e-02, 1.10702340e+00, 2.72942671e+00,
		       2.72878017e+00, 9.01499985e-02, 5.67243781e+00, 5.60116502e+00,
		       3.48079990e+00, 2.78925353e+00, 5.37396677e+00, 4.94482990e-01,
		       5.96899742e+00, 2.30265457e+00, 5.43893920e-01, 5.33049442e+00,
		       9.74650346e-01, 1.15697955e+00, 5.60324375e+00, 5.72766889e+00,
		       5.03175060e+00, 3.87353037e+00, 9.64531483e-01, 1.94210169e+00,
		       3.14606104e+00, 3.97214801e+00, 1.43696262e+00, 2.12563906e+00,
		       4.46014681e+00, 4.43965659e+00, 3.71722582e+00, 1.89870669e+00,
		       4.00009634e+00, 7.83949599e-02, 4.13424387e-01, 4.09574509e+00,
		       2.52091032e+00, 5.59869902e+00, 3.92081674e+00, 5.83731614e-01,
		       5.69330822e+00, 3.45586934e+00, 5.64676839e+00, 4.18951526e+00,
		       8.08656226e-01, 1.56391096e+00, 5.81418585e+00, 4.56838786e+00,
		       9.16642182e-01, 5.92638043e+00, 2.59945492e+00, 4.01971382e+00,
		       2.81737814e+00, 3.47708252e+00, 1.77933850e+00, 4.38436305e+00,
		       2.51705113e+00, 6.17924821e+00, 3.87624067e+00, 1.34142524e+00,
		       6.12527415e+00, 4.84506494e+00, 5.03647066e+00, 2.46294268e+00,
		       4.52384284e+00, 2.35880818e-01, 5.06840387e+00, 4.52108626e+00,
		       5.47547624e+00, 3.84443937e+00, 4.58146089e+00, 4.02653272e+00,
		       6.28126048e+00, 6.36097218e-01, 1.40177576e+00, 8.38403538e-01,
		       5.71801905e+00, 4.05167496e+00, 2.07510675e+00, 2.00200900e+00,
		       4.18555811e+00, 5.16314663e+00, 1.32892685e+00, 2.37934252e+00,
		       2.87954991e+00, 1.40220447e+00, 5.81347755e+00, 5.87948636e+00,
		       5.38073182e+00, 3.28138711e+00, 6.17126400e+00, 3.11964756e+00,
		       5.98147570e+00, 3.12936166e-01, 5.77694593e-01, 5.66681040e+00,
		       3.35308261e+00, 1.56071661e+00, 5.15328285e+00, 2.21988678e+00,
		       1.70330952e+00, 4.01376220e+00, 4.09688847e+00, 3.60269031e+00,
		       2.31752088e+00, 5.76676125e+00, 4.81769722e+00, 9.31895908e-01
	};

for (int idx=0; idx < AI_SINEWAVE_IN_NUM; idx++ )
  {
      for(int j =0 ; j<10;j++ ){
    	  ((ai_float*)data_ins[idx])[j] = input_array[idx];
      }
  }


  return 0;
}
ai_float myoutput[10];
int post_process(void* data)
{
  /* process the predictions
  for (int idx=0; idx < AI_NEURAL_OUT_NUM; idx++ )
  {
      data[idx] = ....
  }
  */
 for (int idx=0; idx < AI_SINEWAVE_OUT_NUM; idx++ )
  {
      for(int j =0 ; j<10;j++ ){
    	  myoutput[j]=((ai_float *)data_outs[idx])[j];
      }
  }

  return 0;
}
/* USER CODE END 2 */

/* Entry points --------------------------------------------------------------*/

void MX_X_CUBE_AI_Init(void)
{
    /* USER CODE BEGIN 5 */
  printf("\r\nTEMPLATE - initialization\r\n");

  ai_boostrap(data_activations0);
    /* USER CODE END 5 */
}

void MX_X_CUBE_AI_Process(void)
{
    /* USER CODE BEGIN 6 */
  int res = -1;

  printf("TEMPLATE - run - main loop\r\n");

  if (sinewave) {

    do {
      /* 1 - acquire and pre-process input data */
      res = acquire_and_process_data(data_ins);
      /* 2 - process the data - call inference engine */
      if (res == 0)
        res = ai_run();
      /* 3- post-process the predictions */
      if (res == 0)
        res = post_process(data_outs);
    } while (res==0);
  }

  if (res) {
    ai_error err = {AI_ERROR_INVALID_STATE, AI_ERROR_CODE_NETWORK};
    ai_log_err(err, "Process has FAILED");
  }
    /* USER CODE END 6 */
}
#ifdef __cplusplus
}
#endif
