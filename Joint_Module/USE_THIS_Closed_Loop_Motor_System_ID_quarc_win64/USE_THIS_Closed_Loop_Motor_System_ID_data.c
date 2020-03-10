/*
 * USE_THIS_Closed_Loop_Motor_System_ID_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "USE_THIS_Closed_Loop_Motor_System_ID".
 *
 * Model version              : 1.232
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Thu Mar  5 17:27:47 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "USE_THIS_Closed_Loop_Motor_System_ID.h"
#include "USE_THIS_Closed_Loop_Motor_System_ID_private.h"

/* Block parameters (default storage) */
P_USE_THIS_Closed_Loop_Motor__T USE_THIS_Closed_Loop_Motor_Sy_P = {
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
  { 0U, 1U },

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

  /* Expression: 2*pi/4096
   * Referenced by: '<S1>/Servo:  Counts to Rad1'
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
  { 3.0669471578605618, 5.410648539720035, 4.5016250220536884,
    3.8976651448546544, 0.5640643782887752, 0.70221802870346528,
    3.6165341364752819, 2.9006793954331176, 3.4271592514237388,
    0.23883806118682507, 3.6397624175556933, 3.951984540902556,
    3.0280390282898675, 1.0086207861029421, 4.7399022931537287,
    4.9856821144236285, 1.8307270307002645, 3.1893970294256189,
    1.4953506058785557, 1.2106731931383767, 5.08119366608258,
    0.41892060317301028, 1.230640147620796, 6.1247351261569616,
    3.6133997939023708, 3.6644391007846031, 5.969162076062414,
    0.62856486646191556, 5.5212473806678624, 5.6011494166086351,
    1.3448327202903771, 1.0489934848826976, 4.0597261949703132,
    1.1331319366251962, 0.7323052441804262, 2.2954615142832648,
    2.528197193388301, 0.564292168315597, 4.2962415245152128, 3.4362378932324287,
    6.1949616300805905, 1.3367449933977731, 5.7741878090187964,
    4.1793339594691563, 4.671411796330653, 2.3779180518726086,
    2.9830573942461061, 0.66766207580741987, 5.5529794379900359,
    2.7966660914112036, 4.1986024742728461, 4.5755148329704429,
    1.7947497531342937, 3.7302438375015892, 2.3281101884746565,
    4.9991386534730564, 0.46203082976536225, 6.2375544988351947,
    4.8759363721673417, 0.046309950095366634, 5.5854276358347255,
    5.4294573415959331, 4.383110748757411, 5.5605692531053537,
    2.9257309755430869, 2.3345705975503663, 0.52164012105301183,
    6.2657089863456612, 5.4653021869741965, 0.00044146068980879138,
    4.272419751659438, 4.1147328034656754, 2.5874976549245479,
    2.9931107438970459, 2.439578679908974, 2.8403581979776185,
    0.1681370290628979, 2.6721531739613313, 0.66479425139604076,
    0.27087606503763567, 3.4942188835076604, 3.840829784816822,
    4.6422199628988938, 1.6142714170288301, 4.5632194835631825,
    4.4815003509258036, 3.1652458416166422, 5.6094367157658, 4.8970216666068254,
    3.1092981153796826, 4.7846906230835486, 4.1911654865596928,
    6.1456602697541856, 0.735577804838989, 5.4621191034105259,
    3.5679395289581355, 0.75493263916606923, 6.0967595473050631,
    5.2776660743249026, 0.39154703675722474, 1.7471814007819704,
    2.5737811091835843, 3.9383556325189524, 5.7748950579331995,
    2.6084750021767276, 4.4704873540312011, 6.1001859768032514,
    2.7361514214686493, 3.9922224930829753, 5.6646374316122436,
    5.4763218309111084, 0.89671063690885988, 1.2603915947840005,
    3.9014056809771409, 4.8696520043007876, 1.5507593406140276,
    2.3213366987670949, 2.1431785176542886, 2.8675798162950019,
    1.0733170168458832, 4.6847804394609156, 0.61561342214259807,
    5.5937276950579617, 0.51581286286280237, 4.9104516399343456,
    5.33240009181917, 2.8329461311696158, 3.8033708282887511, 2.2272009513679421,
    4.7695374181343642, 3.7035661331574539, 3.8426073716408626,
    5.2977974570115087, 2.8713396838021121, 5.5467313510271685,
    3.1012084207810009, 3.9134860444559294, 3.5321875233810487,
    4.5343290184068312, 3.4354566484490281, 4.9287907612048869,
    2.8045161983427422, 5.7296867386004822, 0.544042475257015,
    6.2765085154068272, 4.5715268340270274, 3.5085726044928172,
    0.89739048912519093, 5.2630280570486336, 4.5568634527400045,
    2.6224739331408493, 1.7163820352609949, 1.9773660349942974,
    3.6549040109512081, 4.33136572956766, 5.4278404271132716, 1.3248644512668117,
    3.184014327440734, 2.6706662750535335, 1.5060800281649793,
    4.7596589554804147, 4.9757292644591242, 2.4245548716882737,
    1.9983945596693076, 3.0217418420306394, 1.749904290531223, 0.992970573461392,
    2.4844218117118619, 1.7935732445348354, 1.5271322266918308,
    4.0370700665070265, 6.0125291574326063, 1.1707806586510634,
    5.714663313807046, 3.573501600101892, 1.2158998558850869, 4.4248606257045369,
    4.0939944719095189, 2.0853698983752458, 3.2771126077839288,
    0.15559327428923161, 0.13994489374171457, 5.0172763708107739,
    0.67740439958066934, 4.3279023032093829, 4.8696300278574736,
    4.9731031067553628, 4.4577254417784342, 5.9472730134804239,
    1.8725136577126813, 6.2569285649044195, 3.4836948942293979,
    4.1223255537324519, 5.9398016136124605, 1.4114373455592801,
    6.1670600860986244, 1.0720470443058372, 5.9128555090653547,
    6.0127571271165463, 1.0996499700986295, 0.34123862424034546,
    1.6852033892013614, 3.4306801813304606, 4.870640301866807,
    3.7935323579870279, 1.9860909787442274, 2.722834437607732,
    5.2953371605771418, 3.9341079294634604, 1.7124699025594328,
    3.232915118685737, 5.5819849992509907, 1.0951336876421343, 5.15264124951216,
    1.138462152224897, 0.61112567830729658, 0.19675672990162726,
    0.063936807412299665, 6.0786478954644849, 5.5797044486561171,
    0.31218236914262376, 4.2110343386649189, 6.1362927633954341,
    1.3839728634618376, 0.52815575957868965, 2.2548148972812334,
    4.6067257909023889, 3.7833837291250902, 2.8360464395022618,
    5.7353144524730828, 0.019963343096124141, 3.2049254393324316,
    0.907674729806226, 3.170808824570845, 3.570198342845857, 4.0348745067001328,
    1.3002035548436175, 2.1374589485520192, 2.0575814558566532,
    3.8639381641381827, 3.7145546603070647, 4.3223546120531342,
    1.0457595811769462, 4.0980660799923543, 4.829492867688467,
    2.4866734494150866, 2.4898011630626313, 4.3487196410803532,
    1.4933434760093465, 5.9620059126532183 },

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
const ConstP_USE_THIS_Closed_Loop_M_T USE_THIS_Closed_Loop_Mot_ConstP = {
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
