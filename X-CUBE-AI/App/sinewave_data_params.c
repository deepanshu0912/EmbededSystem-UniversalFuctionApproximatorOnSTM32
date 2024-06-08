/**
  ******************************************************************************
  * @file    sinewave_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sun May  5 19:39:55 2024
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#include "sinewave_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_sinewave_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_sinewave_weights_array_u64[161] = {
  0x3eda53dc3dfd314eU, 0x3ee21750be485020U, 0xbf0efe693e6ed780U, 0xbf063f29bf10d80aU,
  0xbee2f688bc36dc80U, 0x3df21460bed511deU, 0xbe890e043ddc1f58U, 0x3eca6af9bd471e20U,
  0xbbaa4cef3e86146cU, 0xbba7be2b00000000U, 0xbe074048U, 0x0U,
  0x0U, 0xbe345f1b00000000U, 0x3e5984b1U, 0xbe1d242300000000U,
  0xbeab7783bcd27d30U, 0x3d15c9a83d761018U, 0x3e68e97abe43d822U, 0xbec05fdc3ed3674fU,
  0x3ea79c49be56ffb4U, 0xbe8140b1be6aefc9U, 0xbe1abd54bea6eea2U, 0x3e3564da3eab477dU,
  0x3eb2a1ad3e6f4548U, 0xbcf97bf73eae939bU, 0xbe5b48bd3e1017abU, 0xbdfbccb4bed47521U,
  0x3ddd76f4bde386ecU, 0xbe55d59e3e7d24b6U, 0x3dff0d2c3ef0d448U, 0xbe88c3013ec9e621U,
  0xbec967753dd5bdc8U, 0x3ec40efa3e198edeU, 0xbe6e349c39f63748U, 0xbe279e0abec63d63U,
  0xbe2277163ea3b409U, 0x3e198c97be68d3c4U, 0xbe74d3123e9d9076U, 0x3ebf2f63be55a3e3U,
  0xbf0ad55f3ec83097U, 0xbf68fceabe9fae94U, 0x3d94960c3f58b614U, 0xbd85bb8c3eaee749U,
  0xbe819c3cbe8f5dfbU, 0xbda60b90be265a64U, 0xbea654473e309fefU, 0xbeb18f693eca5527U,
  0x3ec3fdc93cb3112bU, 0xbb51bc9d3ce5b510U, 0xbeaa4733bbd9b1baU, 0x3e85d0cfbdb4bcecU,
  0xbe51501abec8fdc6U, 0x3e5cbb9ebe7d5434U, 0xbe8453b83e4d7234U, 0x3d9f0df13e039c02U,
  0x3e8bd731bea8d15dU, 0x3ef02e7bbcc30880U, 0x3e74ef4abd1a4976U, 0xbe70817b3e298852U,
  0x3cea9a70bed30a02U, 0xbc68361cbe8671c8U, 0xbe03273cbde344f2U, 0x3bd5751a3e333312U,
  0xbca5004c3e8fc1deU, 0xbecf68cf3e5a6066U, 0x3d672170bebee696U, 0xbe129df2be9f3a8eU,
  0x3e63d9063ed869cfU, 0x3e84182f3d900984U, 0x3e8a656fbd783ae7U, 0xbe1d4e00bead460aU,
  0xbe5f4f42beb9c24eU, 0xbe54fc5d3ec26237U, 0x3e440d66be9f8db2U, 0x3de5f22cbe4f33bbU,
  0x3eadb5893decbc14U, 0xbe996deebe026408U, 0xbda9c668bd5ab340U, 0xbece2256be7827d5U,
  0x3eddd689bd2b39a4U, 0x3e937914bd7befa0U, 0xbea4523cbec79fc2U, 0xbc3ef5603d8c6ba4U,
  0x3db89874bd795808U, 0xbeb5f908ba158000U, 0x3ea5d2a13dfc0c8aU, 0x3ec212e5bed03366U,
  0xbe755561beb9ca0cU, 0x3e189da23ebfb819U, 0xbec464e03ec973bfU, 0xbe88a328beae1b18U,
  0xbec3e38d3e77bcb6U, 0x3ecf0cc5bd8909fcU, 0x3e94270dbe2c13a8U, 0xbeb4fc133ea5f245U,
  0xbce258643e5630b9U, 0x3ec7ff453d80be1cU, 0xbe32af5a3ebfe37fU, 0x3ec750c1bed97c99U,
  0x3dad88bc3c506160U, 0xbd7bbcffbe6c3b72U, 0xbc3605603d89b93eU, 0xbed61f523eb71b27U,
  0x3dfbb3b83d644c9fU, 0x3e0a6719be2032e8U, 0xbecea5683ed7c337U, 0x3e93c5edbe036b2aU,
  0x3d8106c0be9f2210U, 0xbdfbce8c3ec08257U, 0x3e05127e3df539b7U, 0xbdcc3a95bde64b10U,
  0x3ecdeef6bed6aec2U, 0x3ef5d94fbe0fd112U, 0x3e562edabdec6c77U, 0x3e3cd072bd9df8f4U,
  0x3e4d31423d60cb48U, 0x3eabec8abe4a6731U, 0xbde97c6cbec30b3eU, 0x3e1975383e3cce02U,
  0xbe104e6ebe599e67U, 0x3ed01dbd3e83bda3U, 0x3d260b083ed7c46eU, 0xbe05e35ebe0b14d2U,
  0xbed7e1013ecf6e17U, 0x3ee1df49bc739320U, 0x3d80de34be30cbd6U, 0x3e7af60d3e77ce7eU,
  0x3e8edfd83e113829U, 0x3e3a18c1bece4357U, 0x3e11c1863e4f9147U, 0xbeac9137bed320e7U,
  0xbeaa2c723ec15de1U, 0x3ebaf40abea1a2d4U, 0xbe3b53febe85a840U, 0xbd3f1b513ed51cc9U,
  0xbea82bf6bd147210U, 0x3ebad387be88ae98U, 0x3eb035d3bd97d748U, 0xbe59cf583e511ecaU,
  0x3e910a573e788026U, 0x3c8b11703eba73dfU, 0x3ea80b75bde91dc0U, 0xbe1f8366bd6d6d08U,
  0x3e419a4b00000000U, 0x3ecea6e53e39df04U, 0xbe8e2f4bbeb4d566U, 0xbd7ed92cU,
  0x3e4011f7U, 0xbe8f812e3e432781U, 0xbe5a34e8be8a5c06U, 0xbe8f9492U,
  0x3e8af064be98bd89U, 0xbf6aa9df3dd63fb6U, 0xbf291b50bec7d65aU, 0x3d10ab503dce0750U,
  0xbef721583ee1ee55U, 0xbeb0f6713f1ee441U, 0xbec5a183bedd57eeU, 0xbeb6b2a0bf082a93U,
  0x3e434f5bU,
};


ai_handle g_sinewave_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_sinewave_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

