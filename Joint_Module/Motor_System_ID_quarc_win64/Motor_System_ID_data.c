/*
 * Motor_System_ID_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Motor_System_ID".
 *
 * Model version              : 1.230
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Thu Mar  5 17:06:18 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Motor_System_ID.h"
#include "Motor_System_ID_private.h"

/* Block parameters (default storage) */
P_Motor_System_ID_T Motor_System_ID_P = {
  /* Variable: T
   * Referenced by: '<Root>/Sine Wave'
   */
  20.0,

  /* Variable: a
   * Referenced by: '<Root>/Sine Wave'
   */
  0.2,

  /* Mask Parameter: HILWrite_analog_channels
   * Referenced by: '<S1>/HIL Write'
   */
  0U,

  /* Mask Parameter: HILReadEncoder_channels
   * Referenced by: '<S1>/HIL Read Encoder'
   */
  0U,

  /* Mask Parameter: HILReadAnalog_channels
   * Referenced by: '<S1>/HIL Read Analog'
   */
  0U,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<S1>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<S1>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<S1>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<S1>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<S1>/HIL Initialize'
   */
  50.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: 2*pi/4096
   * Referenced by: '<S1>/Servo:  Counts to Rad'
   */
  0.0015339807878856412,

  /* Expression: -1
   * Referenced by: '<S1>/Tach Dir'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 2*pi*rand(1,N)
   * Referenced by: '<Root>/Sine Wave'
   */
  { 3.0121867049092304, 5.64574046133386, 5.8729513501450805, 5.1389345371376454,
    4.4542064803636041, 4.6697925679592345, 5.6530432862337241,
    0.40991378321201677, 2.110592136317786, 0.02723806452115806,
    5.20307812664824, 3.188310507014446, 2.300666438852871, 1.4240193439264375,
    3.3604467395529629, 1.8188870591497608, 0.42958701826638718,
    0.533886940086207, 0.42938954208002916, 2.57495300610221,
    0.77522808850580793, 2.7835553458521267, 5.64820494733397,
    2.2219793800653185, 0.75510139501691564, 3.5758300332218154,
    5.4979927696009527, 2.1901611745896346, 0.26339744210498445,
    0.89434683348920752, 0.48124697473073613, 4.6528657854711426,
    2.8684319723290321, 4.1987342795233511, 4.3934926683325566,
    3.5899432420446975, 3.9501967688897794, 5.5151533972980928,
    4.1616787186157325, 5.5003859438367657, 2.937496063620753,
    0.88804045662004927, 0.42810142059645584, 4.4877173969235216,
    1.9351332870959415, 4.2170476057663846, 4.0992810072230021,
    3.3366782584847305, 4.4931499950297216, 3.1718186894867988,
    3.0661903992731143, 3.1280103486484334, 5.8809078445273286,
    2.4459289497012726, 0.73604478410662488, 1.5106257418119859,
    4.30340699021634, 5.2731859831398067, 6.0955985032640649, 1.3519505497218236,
    4.7773781426268274, 3.6700264441097152, 2.531819431700459,
    3.2046779562672589, 3.1142244749436747, 4.0926679993571833,
    4.6728435207540553, 1.8972296006721288, 0.56304839460991374, 5.1896941837825,
    2.4478473703248249, 4.8713840626437968, 1.1270092640503764,
    0.6871367460741914, 5.6872775705684662, 5.5062757517779355,
    6.281881951146663, 5.4302723450949735, 0.23170830617921637,
    3.4223407166986322, 6.26820733810042, 3.2107589266077179, 5.4884388694817963,
    0.44121452323345872, 6.2048888815083556, 5.7975794632651514,
    3.5453559194449662, 2.7109560362521732, 2.1227400085300641,
    4.5284388523899564, 0.085800455820278579, 2.3502895072498196,
    5.7974022199198281, 3.433632895170196, 2.9775190172918804,
    3.1198359836897827, 1.9413225578610771, 5.974288579223697,
    6.1700457541304354, 3.2268121464882764, 6.2366257634797764,
    2.8641504511867319, 2.6768938030790825, 1.3396679654165804,
    1.2142222960533107, 5.2323492427722158, 4.56559554788948, 3.3284903604904197,
    5.2092679083214035, 3.2162019061054217, 3.4680785625102835,
    1.3401085123240337, 3.6933859225680776, 0.897007799913005,
    0.32813010272006987, 4.2933502537297636, 3.8236919733026986,
    1.3801389420517873, 2.5527321640695804, 3.9578283434073063,
    3.4891007086397643, 0.80160288810256541, 1.0631044714578508,
    0.0062795292269141453, 2.6273922950396731, 3.069246040284122,
    1.0044855663713992, 4.18987035067286, 0.11259699952208428,
    0.75194244171317925, 5.9823797513360288, 6.1314713321140051,
    0.19424177513956228, 3.1031511441543573, 5.4206429997006, 1.5260359595169741,
    5.2418740348962656, 5.1119442261564219, 3.95195456613914,
    0.014063016311978243, 2.3858758788766212, 5.6825485839307888,
    4.2747755856495937, 2.3802159289984419, 3.9706885530878315,
    1.5285074892718051, 3.5902942158319604, 6.1683838070274506, 5.33870957696183,
    1.7809323429269879, 4.2880079700457063, 2.2501627912066851,
    6.201043780286505, 0.52770145949972447, 1.5727182674883997,
    5.0978411323771322, 0.53044600587328206, 3.3379670993637531,
    5.0304625391727491, 4.6421633382412155, 0.8900947564076811,
    2.7513707673671481, 2.2015048078724213, 3.0064884439147281,
    3.6907644130470389, 0.91612420190640143, 5.68835996957776,
    4.0224590948618966, 1.0237795212341552, 3.5557211105589293,
    5.8535168237865145, 4.9203742495919309, 4.3082993443884181,
    2.9293421613273383, 1.6356268338849089, 3.5768174083561215, 1.56307217391569,
    2.0062310684031579, 5.7227392032118507, 5.562001555196991, 4.99255259515917,
    5.817034577633688, 1.1236845510517171, 3.2518069384602097,
    3.9395905915864606, 5.7376938985403489, 4.1718355769536837,
    2.4453706270869318, 4.6496047627554686, 5.13735133715974, 3.7720775837283087,
    0.53405230683677807, 5.7953462404085609, 0.3367650056939232,
    3.3113954391794422, 0.74677716136734951, 2.3885088509095946, 5.1071774286381,
    1.5336998702625912, 5.5569914569534493, 4.4776918700393153,
    2.3759767100906322, 1.5640080424785054, 1.5887269369527308, 4.82073368015929,
    0.31329146351709786, 4.3057950591784424, 3.897322383464116,
    4.6915578961163193, 6.1402783310437705, 2.4121997419768824,
    1.6349200173033949, 5.513303696181632, 5.0648504397705727, 2.897309193302593,
    0.57152914108172148, 3.5454055922560435, 1.1773614159153873,
    3.3407041940741822, 2.2307401509256803, 1.9778430920222152,
    4.5662513191505241, 3.2406964440666686, 4.967768405760185,
    1.2848647826218211, 4.2606661432328883, 0.32977639034257777,
    5.0339144157144124, 4.263572501342364, 5.94394950421264, 0.57527677806378186,
    5.7078866224949731, 3.2041294297642988, 3.8635530458203395,
    1.9859339254292696, 0.48686820534804759, 5.3445658015947766,
    0.90808933823100191, 2.3278308889224704, 3.9106007076505631,
    6.2678034565058294, 3.2505690567648942, 6.2235655136290591,
    1.4233580067006695, 2.5007403394967609, 4.3766701553808751,
    0.4061498700433035, 4.6976962691423738, 2.6414538126539733,
    5.0976576942983938 },

  /* Expression: 10
   * Referenced by: '<S1>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S1>/Saturation'
   */
  -10.0,

  /* Expression: -1
   * Referenced by: '<S1>/Motor Dir '
   */
  -1.0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<S1>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<S1>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<S1>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<S1>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<S1>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<S1>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<S1>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILReadEncoder_Active
   * Referenced by: '<S1>/HIL Read Encoder'
   */
  1,

  /* Computed Parameter: HILReadAnalog_Active
   * Referenced by: '<S1>/HIL Read Analog'
   */
  1,

  /* Computed Parameter: HILWrite_Active
   * Referenced by: '<S1>/HIL Write'
   */
  0
};

/* Constant parameters (default storage) */
const ConstP_Motor_System_ID_T Motor_System_ID_ConstP = {
  /* Expression: 2*pi*(1:N)/T
   * Referenced by: '<Root>/Sine Wave'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0,
    15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0,
    28.0, 29.0, 30.0, 31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0, 40.0,
    41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0, 53.0,
    54.0, 55.0, 56.0, 57.0, 58.0, 59.0, 60.0, 61.0, 62.0, 63.0, 64.0, 65.0, 66.0,
    67.0, 68.0, 69.0, 70.0, 71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0,
    80.0, 81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0, 90.0, 91.0, 92.0,
    93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0, 101.0, 102.0, 103.0, 104.0,
    105.0, 106.0, 107.0, 108.0, 109.0, 110.0, 111.0, 112.0, 113.0, 114.0, 115.0,
    116.0, 117.0, 118.0, 119.0, 120.0, 121.0, 122.0, 123.0, 124.0, 125.0, 126.0,
    127.0, 128.0, 129.0, 130.0, 131.0, 132.0, 133.0, 134.0, 135.0, 136.0, 137.0,
    138.0, 139.0, 140.0, 141.0, 142.0, 143.0, 144.0, 145.0, 146.0, 147.0, 148.0,
    149.0, 150.0, 151.0, 152.0, 153.0, 154.0, 155.0, 156.0, 157.0, 158.0, 159.0,
    160.0, 161.0, 162.0, 163.0, 164.0, 165.0, 166.0, 167.0, 168.0, 169.0, 170.0,
    171.0, 172.0, 173.0, 174.0, 175.0, 176.0, 177.0, 178.0, 179.0, 180.0, 181.0,
    182.0, 183.0, 184.0, 185.0, 186.0, 187.0, 188.0, 189.0, 190.0, 191.0, 192.0,
    193.0, 194.0, 195.0, 196.0, 197.0, 198.0, 199.0, 200.0, 201.0, 202.0, 203.0,
    204.0, 205.0, 206.0, 207.0, 208.0, 209.0, 210.0, 211.0, 212.0, 213.0, 214.0,
    215.0, 216.0, 217.0, 218.0, 219.0, 220.0, 221.0, 222.0, 223.0, 224.0, 225.0,
    226.0, 227.0, 228.0, 229.0, 230.0, 231.0, 232.0, 233.0, 234.0, 235.0, 236.0,
    237.0, 238.0, 239.0, 240.0, 241.0, 242.0, 243.0, 244.0, 245.0, 246.0, 247.0,
    248.0, 249.0, 250.0 }
};
