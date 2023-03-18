#ifndef MORSE_FL_WEIGHT_BIAS
#define MORSE_FL_WEIGHT_BIAS

#include "arm_nnfunctions.h"

namespace kimdictor_morse_fl {
namespace convolution_layer {
/* <Conv 1> */
/*
    in/output offset = 0
    stride = 1
    padding = 1
    dilated = 1
    activation = ReLu
    weight multiplier = 1303535969
    weight shift = -6
    bias quant is same with weight
    input dimension = N 1 / H 1 / W 64 / C_IN 1
    filter dimension = C_OUT 24 / H 1 / WK 3 / C_IN 1
    bias dimension = C_OUT 24
    output dimension = N 1 / H 1 / W 64 / C_OUT 24
*/
const cmsis_nn_tile conv1_stride = {1, 0};
const cmsis_nn_tile conv1_padding = {1, 0};
const cmsis_nn_tile conv1_dilation = {1, 0};
const cmsis_nn_activation conv1_activation = {-128, 127};
const cmsis_nn_conv_params conv1_params = {
    0, 0, conv1_stride, conv1_padding, conv1_dilation, conv1_activation};

const cmsis_nn_dims conv1_in_dims = {1, 1, 64, 1};
const cmsis_nn_dims conv1_filter_dims = {24, 1, 3, 1};
const cmsis_nn_dims conv1_bias_dims = {1, 1, 1, 24};
const cmsis_nn_dims conv1_out_dims = {1, 1, 64, 24};

const int32_t conv1_multiplier = 1303535969;
const int32_t conv1_shift = -6;
const int8_t conv1_zero = 14;
int32_t conv1_multiplier_array[24];
int32_t conv1_shift_array[24];
const cmsis_nn_per_channel_quant_params conv1_quant = {conv1_multiplier_array,
                                                       conv1_shift_array};

const q7_t conv1_weight[] = {
    -51, -1,  -12, 16,  74,  74,  47,  47,  46,  -51, -49, 24,   -48, 15,  29,
    102, 71,  -29, 69,  69,  69,  -34, -12, -33, 81,  82,  79,   -8,  -42, -22,
    -88, 79,  2,   107, -56, 61,  72,  37,  0,   -16, -52, -14,  7,   113, -122,
    -84, 30,  -23, -53, 16,  100, -87, -38, 82,  25,  107, -127, 52,  75,  31,
    68,  122, 26,  114, 55,  62,  62,  118, 14,  31,  -30, -57};
const int32_t conv1_bias[] = {-40, -65, -8, 76,  -49, -7,  7,  -29,
                              29,  -51, 7,  15,  48,  -55, 2,  77,
                              37,  43,  -5, -59, 41,  35,  62, 55};

void conv1_init() {
  for (int c = 0; c < conv1_filter_dims.n; c++) {
    conv1_multiplier_array[c] = conv1_multiplier;
    conv1_shift_array[c] = conv1_shift;
  }
}

const cmsis_nn_tile max1_stride = {2, 1};
const cmsis_nn_tile max1_padding = {0, 0};
const cmsis_nn_activation max1_activation = {-127, 128};
const cmsis_nn_pool_params max1_params = {max1_stride, max1_padding,
                                          max1_activation};
const cmsis_nn_dims max1_in_dims = conv1_out_dims;
const cmsis_nn_dims max1_filter_dims = {0, 1, 2, 0};
const cmsis_nn_dims max1_out_dims = {0, 1, 32, 24};

/* <Conv 2> */
/*
    in/output offset = 0
    stride = 1
    padding = 1
    dilated = 1
    activation = ReLu
    weight multiplier = 1623907548
    weight shift = -7
    bias quant is same with weight
    input dimension = N 1 / H 1 / W 32 / C_IN 24
    filter dimension = C_OUT 48 / H 1 / WK 3 / C_IN 24
    bias dimension = C_OUT 48
    output dimension = N 1 / H 1 / W 32 / C_OUT 48
*/
const cmsis_nn_tile conv2_stride = {1, 0};
const cmsis_nn_tile conv2_padding = {1, 0};
const cmsis_nn_tile conv2_dilation = {1, 0};
const cmsis_nn_activation conv2_activation = {-127, 128};
const cmsis_nn_conv_params conv2_params = {
    0, 0, conv2_stride, conv2_padding, conv2_dilation, conv2_activation};

const cmsis_nn_dims conv2_in_dims = {1, 1, 32, 24};
const cmsis_nn_dims conv2_filter_dims = {48, 1, 3, 24};
const cmsis_nn_dims conv2_bias_dims = {48, 48, 48, 48};
const cmsis_nn_dims conv2_out_dims = {1, 1, 32, 48};

const int32_t conv2_multiplier = 1623907549;
const int32_t conv2_shift = -7;
const int8_t conv2_zero = -1;
int32_t conv2_multiplier_array[48];
int32_t conv2_shift_array[48];
const cmsis_nn_per_channel_quant_params conv2_quant = {conv2_multiplier_array,
                                                       conv2_shift_array};

const q7_t conv2_weight[] = {
    16,   16,   9,   -15,  3,    9,   -8,   10,   29,   -5,  0,    -41,  -17,
    5,    16,   16,  1,    33,   -16, 6,    14,   6,    7,   -18,  -15,  24,
    36,   10,   17,  -11,  21,   52,  50,   29,   3,    22,  -17,  -9,   17,
    15,   -9,   7,   78,   7,    10,  10,   -9,   2,    -24, 2,    12,   -14,
    21,   -9,   70,  21,   10,   -16, -12,  22,   35,   -10, -22,  8,    20,
    35,   37,   -10, -18,  32,   -19, -43,  6,    -6,   16,  7,    9,    -20,
    18,   23,   -10, 13,   -12,  -2,  4,    -16,  -17,  -9,  42,   6,    3,
    31,   8,    20,  -16,  -5,   14,  26,   4,    8,    -18, 3,    14,   21,
    -16,  20,   8,   0,    16,   27,  -29,  -13,  9,    -15, 19,   37,   -4,
    1,    -19,  -5,  42,   -20,  -10, 38,   -30,  25,   19,  35,   -2,   16,
    19,   -26,  -15, 6,    1,    15,  -8,   -16,  -30,  20,  22,   -20,  -1,
    11,   0,    -8,  8,    -34,  -65, 13,   -34,  -16,  -10, 50,   -19,  -2,
    19,   19,   3,   -61,  12,   -19, -34,  -29,  -9,   12,  -4,   16,   -15,
    -11,  -18,  18,  -18,  11,   113, 53,   31,   1,    28,  -4,   -13,  3,
    -4,   19,   -4,  -6,   73,   88,  -27,  67,   24,   0,   34,   -14,  -1,
    68,   -21,  26,  85,   106,  -6,  -60,  -13,  16,   93,  77,   -16,  48,
    -18,  6,    59,  53,   3,    -34, 25,   -31,  15,   18,  -10,  13,   -72,
    -2,   7,    1,   -25,  10,   -12, 33,   -6,   14,   10,  -25,  31,   -48,
    -1,   -21,  -20, -16,  0,    5,   5,    -14,  -15,  -2,  14,   -15,  33,
    20,   18,   21,  16,   -29,  -23, 2,    -22,  -13,  -12, -13,  8,    9,
    14,   36,   19,  23,   29,   -17, 16,   50,   -14,  36,  43,   3,    -9,
    -10,  -18,  -7,  47,   54,   3,   31,   0,    4,    5,   37,   -12,  -7,
    25,   -9,   14,  13,   -2,   18,  11,   -21,  26,   13,  -11,  12,   -29,
    28,   7,    6,   8,    17,   34,  -15,  28,   17,   -25, 6,    -14,  -19,
    0,    25,   -30, 15,   11,   12,  25,   -23,  -16,  5,   16,   -23,  7,
    21,   -5,   -17, -19,  11,   9,   20,   -14,  -7,   -22, -12,  19,   -14,
    13,   44,   -16, 35,   -20,  5,   -3,   4,    19,   -43, -36,  4,    4,
    5,    1,    14,  -51,  24,   32,  -33,  23,   -5,   -19, 2,    -8,   -30,
    -32,  5,    -9,  -16,  0,    -35, 2,    -39,  -14,  -2,  6,    22,   -14,
    41,   24,   -20, 9,    -5,   -3,  -20,  18,   -3,   3,   -13,  5,    7,
    84,   101,  22,  8,    15,   5,   23,   -22,  26,   -18, -5,   10,   86,
    74,   35,   -22, 15,   -32,  0,   38,   1,    -14,  43,  -24,  88,   121,
    84,   17,   -12, 5,    34,   53,  34,   -3,   38,   6,   10,   22,   -7,
    15,   -17,  -11, 10,   6,    -19, -36,  -16,  -21,  -21, -9,   -31,  -32,
    -53,  -35,  5,   -16,  -13,  -38, -7,   10,   -33,  15,  -11,  -6,   -16,
    10,   -41,  -17, -14,  15,   17,  -7,   50,   96,   76,  4,    40,   36,
    -27,  7,    15,  -12,  11,   -13, 61,   99,   15,   11,  21,   -7,   0,
    8,    8,    -4,  -30,  12,   84,  96,   55,   -47,  -21, -30,  55,   44,
    74,   -22,  32,  -8,   28,   40,  64,   -8,   -4,   -28, 16,   14,   2,
    -14,  -15,  9,   -5,   -17,  -2,  -2,   -9,   2,    -10, 0,    -3,   16,
    11,   13,   4,   -4,   15,   -14, 2,    18,   3,    7,   -20,  0,    11,
    7,    -11,  -1,  1,    -20,  -15, 7,    -23,  -21,  -14, 8,    19,   2,
    -8,   10,   -9,  13,   -7,   10,  10,   8,    -12,  8,   6,    -4,   -13,
    -4,   -19,  -4,  11,   -19,  3,   -2,   -3,   -7,   -9,  -11,  -19,  -20,
    9,    9,    14,  17,   16,   -10, 19,   59,   52,   25,  45,   29,   6,
    17,   -74,  -63, 17,   -14,  19,  48,   1,    18,   23,  42,   39,   10,
    4,    -5,   29,  12,   40,   8,   -13,  14,   -2,   -67, -93,  10,   12,
    13,   4,    19,  12,   -7,   -17, -2,   -104, -51,  -17, 7,    -103, -57,
    2,    14,   1,   17,   -65,  -56, -127, -94,  -25,  72,  51,   30,   -90,
    -105, -55,  5,   -33,  -14,  -53, -107, -51,  -82,  -91, -15,  -2,   -18,
    2,    -64,  30,  -68,  -31,  -15, -42,  12,   9,    28,  -17,  -14,  20,
    -31,  -8,   -6,  -13,  -9,   -11, -1,   14,   -9,   -39, -18,  -29,  -8,
    10,   15,   6,   67,   20,   -18, 10,   27,   2,    -4,  22,   -18,  4,
    11,   27,   46,  13,   32,   37,  29,   -8,   22,   -26, 15,   16,   24,
    81,   50,   32,  -64,  9,    -47, 27,   27,   70,   -30, 29,   7,    49,
    12,   67,   15,  25,   39,   -2,  6,    -1,   -5,   -24, -25,  -42,  -14,
    -14,  30,   11,  36,   -16,  16,  -5,   -38,  10,   0,   -28,  -12,  15,
    -1,   18,   5,   -33,  -2,   13,  9,    -3,   -3,   63,  7,    21,   -7,
    -12,  -7,   -34, 7,    16,   -10, 15,   -19,  21,   27,  -15,  29,   3,
    9,    1,    1,   22,   29,   -17, 27,   9,    69,   4,   -39,  -14,  -7,
    43,   26,   14,  1,    10,   19,  26,   30,   14,   -6,  30,   -4,   -3,
    20,   -1,   62,  47,   71,   38,  26,   43,   -12,  -61, -51,  -12,  2,
    11,   49,   24,  22,   18,   45,  17,   -2,   -16,  3,   13,   20,   36,
    -17,  13,   3,   -21,  -56,  -68, 2,    5,    10,   9,   28,   32,   -2,
    -13,  -17,  -57, -52,  -8,   -40, -89,  -66,  -7,   10,  -3,   -20,  -37,
    -27,  -82,  -72, -27,  42,   31,  24,   -62,  -107, -78, 1,    -29,  -9,
    -35,  -100, -62, -59,  -67,  -33, -9,   16,   9,    -2,  7,    -13,  24,
    -2,   -3,   -25, -4,   -3,   -13, -3,   0,    21,   3,   19,   -5,   -3,
    9,    -11,  13,  7,    20,   9,   5,    16,   -13,  -2,  28,   -28,  7,
    -11,  -19,  -8,  21,   8,    -2,  13,   3,    -14,  26,  1,    13,   -13,
    6,    5,    -1,  16,   -9,   -14, 4,    18,   26,   5,   12,   -1,   -18,
    -7,   9,    -19, 2,    17,   4,   28,   -14,  -10,  -5,  4,    21,   5,
    -5,   -8,   -9,  -5,   11,   -27, 9,    10,   -10,  28,  -35,  -29,  5,
    10,   -4,   -15, 36,   9,    -4,  15,   -6,   -2,   10,  8,    -6,   24,
    13,   -14,  2,   -1,   35,   43,  19,   36,   25,   20,  -5,   19,   -1,
    17,   3,    2,   31,   65,   31,  2,    -29,  -32,  24,  -11,  9,    49,
    -17,  29,   23,  86,   52,   -39, 34,   -5,   21,   -13, 14,   34,   6,
    -18,  8,    -1,  27,   9,    -7,  -14,  19,   7,    -8,  24,   1,    1,
    14,   -3,   -17, 13,   -17,  -25, 4,    -11,  -5,   12,  26,   5,    22,
    28,   3,    -18, 11,   3,    12,  -5,   1,    11,   7,   -3,   66,   -13,
    29,   5,    4,   18,   -17,  1,   17,   20,   -4,   14,  8,    9,    26,
    -10,  -28,  -26, 25,   -18,  24,  38,   -1,   17,   35,  -13,  50,   20,
    -17,  16,   -23, 0,    10,   52,  -14,  19,   -5,   21,  11,   -27,  15,
    -6,   6,    -3,  -3,   42,   28,  64,   18,   25,   31,  21,   -61,  -69,
    -18,  -8,   -3,  -7,   18,   35,  17,   40,   27,   19,  12,   11,   -1,
    52,   46,   13,  0,    -1,   43,  -51,  -80,  -10,  -2,  15,   5,    20,
    11,   7,    -11, 9,    -80,  -89, 10,   -16,  -81,  -71, 33,   -6,   11,
    55,   -60,  -78, -96,  -111, -7,  26,   38,   42,   -32, -112, -103, 46,
    -23,  -25,  -40, -105, -90,  -69, -72,  -5,   5,    -11, 2,    -4,   -4,
    -40,  -14,  3,   2,    21,   16,  15,   12,   0,    -17, -59,  7,    -5,
    -4,   17,   15,  13,   -6,   -8,  -13,  23,   -11,  -11, 15,   -9,   -14,
    20,   -22,  -27, 13,   -19,  -27, 2,    -15,  15,   -12, -13,  -33,  27,
    -32,  -6,   31,  2,    18,   20,  9,    29,   9,    18,  -42,  44,   -31,
    -54,  -8,   -13, 16,   10,   24,  12,   17,   -8,   22,  28,   17,   14,
    -2,   12,   -2,  -14,  8,    -47, -20,  -56,  -34,  -3,  -26,  -1,   15,
    13,   -1,   -12, 8,    -61,  20,  -8,   -56,  4,    -37, -1,   -3,   7,
    -48,  -8,   2,   -13,  2,    1,   20,   74,   58,   16,  1,    8,    -38,
    -2,   -4,   1,   -19,  8,    78,  101,  8,    11,   6,   23,   -16,  34,
    5,    13,   21,  15,   93,   127, 37,   -76,  -6,   -23, 62,   56,   93,
    -9,   39,   6,   64,   15,   89,  -21,  9,    24,   18,  -8,   6,    -16,
    16,   0,    1,   -21,  13,   1,   -1,   0,    2,    -5,  14,   17,   -10,
    10,   -7,   2,   -6,   7,    14,  7,    -17,  -2,   -15, -12,  -4,   -6,
    -15,  -8,   1,   -13,  -12,  4,   13,   -7,   -14,  -10, 20,   -6,   -16,
    13,   -15,  -16, -5,   -13,  20,  -3,   10,   -13,  -2,  5,    -13,  14,
    7,    -13,  13,  -8,   -2,   10,  6,    6,    16,   -5,  5,    9,    -7,
    -16,  15,   6,   18,   -7,   0,   -4,   -36,  -30,  15,  -1,   -29,  -59,
    -8,   -16,  13,  16,   -18,  -15, -13,  34,   5,    -23, 1,    9,    17,
    -19,  10,   -23, -5,   4,    -10, -6,   -8,   50,   56,  -3,   22,   20,
    -33,  5,    32,  9,    20,   -13, 34,   66,   32,   -44, 5,    5,    12,
    10,   -13,  -35, 16,   -14,  21,  44,   67,   -15,  -38, -2,   -66,  50,
    68,   -45,  14,  5,    -53,  35,  42,   -32,  -6,   22,  -9,   11,   -7,
    20,   28,   -7,  30,   5,    -14, -35,  -44,  -2,   -6,  1,    -11,  41,
    -2,   12,   37,  34,   -2,   -19, 16,   9,    15,   20,  -1,   -13,  -10,
    -15,  -38,  -32, -41,  -8,   0,   10,   31,   -4,   10,  1,    15,   15,
    -38,  -3,   -25, -50,  -47,  -1,  -22,  2,    3,    -14, -12,  3,    -89,
    -16,  -25,  43,  17,   14,   -63, -50,  3,    -31,  -3,  -29,  -40,  -18,
    7,    -35,  -27, 24,   16,   -6,  -3,   -30,  -62,  24,  -17,  -22,  -17,
    21,   -16,  -10, -5,   -9,   -18, -78,  3,    -12,  -14, -18,  -11,  -20,
    6,    3,    -26, -21,  6,    3,   19,   -17,  89,   36,  60,   -3,   24,
    27,   -23,  0,   -12,  -12,  7,   -10,  45,   77,   -18, 57,   7,    3,
    22,   -5,   3,   59,   -33,  8,   14,   101,  -52,  -26, -29,  -11,  83,
    58,   -11,  55,  -29,  38,   67,  33,   -19,  -32,  5,   -10,  18,   16,
    -4,   16,   -3,  -12,  13,   -4,  6,    -15,  -8,   -17, -14,  -7,   20,
    -19,  -15,  -10, 11,   12,   10,  -15,  -20,  -5,   -18, -3,   -15,  1,
    -10,  16,   13,  19,   6,    -17, -12,  -4,   1,    4,   6,    -10,  16,
    1,    17,   6,   -15,  8,    -19, -2,   3,    11,   -10, -10,  13,   -18,
    -9,   -1,   -5,  -17,  18,   -9,  -20,  -8,   10,   19,  -15,  15,   2,
    -7,   -6,   -2,  4,    -11,  16,  -9,   -12,  8,    15,  -5,   23,   24,
    12,   46,   16,  -10,  -9,   9,   -14,  9,    26,   -4,  -3,   30,   -12,
    14,   -9,   -1,  12,   15,   14,  -9,   20,   -9,   -19, -13,  -54,  2,
    14,   -2,   16,  -2,   -11,  -6,  0,    3,    -63,  -39, 2,    9,    -11,
    -9,   27,   -13, 7,    40,   -9,  -14,  -94,  -60,  5,   25,   23,   1,
    -21,  -39,  -14, 26,   -10,  -28, -30,  -39,  -8,   -3,  -8,   45,   14,
    15,   -14,  -21, -1,   2,    -10, -21,  -19,  -6,   7,   2,    1,    -9,
    -12,  -5,   9,   -20,  10,   -9,  6,    -1,   -18,  10,  -4,   -13,  -3,
    8,    14,   -10, 8,    -5,   -16, 9,    12,   -18,  -14, 11,   15,   -8,
    8,    -19,  0,   -15,  0,    -13, -16,  6,    6,    -9,  0,    -17,  9,
    14,   6,    0,   -22,  -20,  -17, -3,   -1,   -9,   -4,  10,   6,    -8,
    14,   8,    -6,  2,    -10,  9,   -19,  -13,  -3,   -6,  -2,   17,   -2,
    1,    17,   -1,  -19,  1,    12,  -20,  -15,  -10,  -7,  12,   -15,  -29,
    -11,  11,   -18, -10,  3,    -21, -16,  -6,   -5,   -8,  11,   -17,  1,
    -17,  -6,   -15, -8,   -21,  12,  -17,  -10,  -16,  1,   -11,  -10,  8,
    7,    11,   4,   11,   -7,   8,   -4,   -16,  -7,   -1,  10,   16,   11,
    5,    15,   2,   -4,   -2,   -19, -1,   -6,   8,    -8,  11,   -4,   10,
    15,   -14,  -6,  -52,  24,   -1,  -15,  25,   -2,   24,  3,    -34,  19,
    6,    -8,   -18, 10,   1,    -20, 13,   18,   10,   2,   -11,  -29,  32,
    17,   7,    7,   2,    -38,  55,  -42,  3,    -16,  -6,  -24,  8,    10,
    1,    18,   -1,  21,   26,   -26, -16,  26,   -6,   13,  27,   -29,  47,
    36,   -47,  18,  18,   -28,  -11, 23,   5,    47,   -13, -46,  -12,  40,
    0,    38,   -18, -39,  20,   -16, -2,   -14,  15,   -10, -3,   -64,  18,
    16,   -7,   11,  -10,  5,    -25, 6,    17,   -6,   14,  -14,  40,   10,
    -9,   12,   -13, -19,  13,   19,  -31,  8,    14,   1,   18,   34,   72,
    14,   -5,   18,  7,    -12,  2,   2,    12,   10,   -1,  71,   67,   0,
    -16,  20,   -24, 29,   -7,   4,   9,    13,   -23,  107, 112,  61,   13,
    -78,  -8,   -11, 85,   2,    6,   33,   12,   -25,  38,  -18,  6,    4,
    -28,  -18,  -5,  -19,  -28,  -45, -24,  -12,  -7,   -14, 5,    11,   17,
    17,   9,    7,   -2,   23,   -46, 4,    4,    -10,  10,  -16,  12,   -11,
    -9,   -9,   -15, 16,   7,    25,  11,   15,   2,    8,   -11,  7,    19,
    -5,   -3,   4,   -19,  24,   29,  17,   32,   -5,   17,  12,   -23,  1,
    26,   -1,   25,  35,   29,   -21, -24,  -1,   -8,   25,  24,   24,   29,
    -1,   -1,   0,   -9,   9,    -12, 23,   21,   -9,   -9,  0,    -34,  1,
    -69,  -19,  3,   -24,  -12,  9,   -11,  -5,   -2,   13,  -4,   -24,  18,
    -22,  -29,  -31, -4,   -3,   12,  -13,  2,    -17,  -10, -6,   -14,  23,
    71,   7,    -6,  10,   16,   1,   -7,   11,   17,   -6,  17,   70,   55,
    79,   0,    5,   5,    3,    5,   -9,   -16,  10,   -17, 73,   85,   93,
    -36,  -26,  -14, -12,  39,   55,  -10,  35,   -8,   1,   49,   25,   -13,
    -33,  28,   -6,  -12,  -3,   -13, -20,  -5,   16,   0,   -15,  -19,  -5,
    15,   17,   -11, -9,   -6,   7,   11,   -3,   11,   2,   10,   18,   20,
    -11,  0,    -4,  -19,  -8,   5,   19,   -4,   -21,  -9,  -17,  5,    8,
    17,   -7,   9,   15,   8,    -19, 12,   -12,  6,    4,   0,    -6,   -18,
    3,    -4,   -22, 15,   4,    -2,  18,   -16,  -3,   -10, 12,   -8,   -19,
    -9,   -3,   -8,  -12,  1,    -1,  2,    -6,   -10,  3,   7,    18,   15,
    -1,   3,    -16, -11,  -21,  18,  13,   -2,   19,   4,   3,    12,   -9,
    -4,   -17,  9,   -18,  -18,  15,  18,   -11,  -10,  17,  10,   -19,  4,
    -19,  -15,  -16, 7,    -9,   11,  -17,  -7,   -14,  6,   -16,  2,    -17,
    -1,   -10,  7,   16,   -3,   15,  -18,  12,   15,   12,  8,    -15,  -16,
    19,   7,    -13, 17,   -17,  -8,  -9,   9,    -21,  2,   -7,   -19,  -2,
    11,   -6,   -4,  -5,   -15,  19,  21,   -28,  6,    -7,  -10,  -26,  -61,
    17,   10,   -14, -17,  -16,  -14, 28,   -17,  10,   14,  -16,  -1,   -1,
    -3,   17,   8,   8,    -11,  -20, 8,    -79,  -15,  41,  -12,  -13,  17,
    5,    -7,   4,   -9,   16,   12,  -16,  12,   21,   -91, 4,    33,   -26,
    -11,  28,   -71, -2,   25,   -33, 27,   -11,  9,    -22, -20,  -27,  8,
    18,   -52,  -30, 12,   -37,  43,  8,    -18,  33,   -13, 10,   0,    -10,
    7,    -26,  -16, 9,    16,   -8,  33,   -16,  28,   17,  13,   2,    -1,
    29,   -20,  17,  -13,  18,   10,  7,    4,    30,   18,  -11,  2,    -10,
    -20,  20,   -50, -18,  -8,   -16, -12,  12,   37,   -30, 19,   -8,   20,
    34,   -21,  -70, 1,    -16,  11,  42,   -8,   20,   42,  -11,  14,   3,
    7,    -116, -1,  20,   5,    -53, 19,   -43,  34,   -16, -11,  -45,  35,
    -9,   -42,  44,  -21,  7,    -1,  17,   -21,  -27,  -4,  -7,   -9,   19,
    -17,  -36,  -31, 2,    -7,   6,   7,    -2,   40,   -19, 19,   23,   -4,
    -16,  -19,  -4,  14,   0,    -16, -5,   -19,  68,   49,  25,   3,    16,
    -4,   -2,   -10, -9,   13,   -5,  20,   43,   58,   47,  -4,   16,   -28,
    25,   24,   -1,  32,   0,    2,   72,   84,   43,   2,   -15,  7,    11,
    49,   18,   10,  28,   0,    26,  40,   -12,  -17,  -6,  -4,   14,   -6,
    10,   -4,   -66, -10,  -9,   -10, 2,    -41,  -21,  -1,  -4,   5,    -1,
    0,    10,   19,  12,   13,   23,  -11,  -3,   1,    -20, 8,    -8,   18,
    -5,   1,    5,   85,   51,   -5,  21,   23,   -1,   -12, -5,   -18,  -15,
    -20,  18,   57,  29,   -11,  -4,  10,   11,   6,    22,  -17,  -8,   45,
    24,   53,   20,  -28,  3,    -6,  8,    84,   21,   -12, 6,    55,   -23,
    66,   -16,  -50, 12,   -33,  1,   6,    15,   -22,  11,  -38,  -18,  -16,
    -18,  -22,  -19, -10,  -6,   -8,  3,    -46,  27,   25,  -42,  -8,   -5,
    3,    -2,   -1,  -40,  -15,  -1,  -14,  -20,  2,    82,  68,   63,   7,
    31,   -6,   -22, 1,    -8,   -7,  -5,   13,   71,   88,  36,   0,    1,
    1,    14,   29,  -33,  6,    22,  23,   74,   99,   72,  -47,  1,    -33,
    30,   72,   62,  14,   29,   -15, 13,   21,   37,   -4,  0,    19,   7,
    -9,   15,   17,  12,   -10,  -15, 19,   6,    11,   6,   -2,   17,   -4,
    -4,   -6,   -15, 7,    -13,  -6,  -9,   -1,   14,   2,   12,   -14,  -16,
    6,    17,   -12, 5,    -19,  -11, 12,   -15,  -13,  -3,  15,   -11,  -16,
    -9,   2,    11,  -19,  -1,   3,   4,    20,   -13,  2,   -16,  -13,  20,
    -3,   -5,   7,   8,    -7,   10,  -16,  -14,  -15,  11,  -6,   17,   11,
    12,   -7,   -14, -3,   11,   -15, 0,    -9,   -12,  15,  -2,   0,    -19,
    5,    -18,  -19, -10,  -13,  -13, -2,   9,    -4,   -13, 0,    1,    8,
    9,    -4,   -3,  5,    -15,  -19, -15,  -7,   -5,   -14, -17,  -3,   -9,
    -10,  -15,  10,  5,    -6,   4,   5,    -14,  -14,  -9,  3,    -19,  20,
    -10,  -5,   5,   -7,   -12,  3,   6,    -4,   -1,   -19, -7,   -8,   -18,
    -6,   -16,  -4,  12,   -18,  -11, -13,  -3,   11,   3,   15,   8,    -10,
    6,    -1,   -1,  -83,  27,   -57, -39,  -16,  -54,  30,  37,   42,   9,
    -7,   -9,   -23, -11,  -13,  -37, 6,    -27,  15,   17,  -5,   -43,  -18,
    -26,  14,   -4,  -7,   1,    61,  39,   1,    7,    -3,  -12,  -9,   17,
    -11,  -14,  13,  55,   76,   43,  15,   36,   37,   -9,  37,   -14,  -8,
    23,   20,   40,  57,   36,   -36, -18,  -26,  54,   31,  93,   -15,  29,
    10,   38,   14,  85,   18,   -1,  50,   18,   2,    0,   -31,  -8,   -42,
    -59,  -16,  -15, 11,   23,   41,  19,   14,   -2,   -44, 18,   -3,   -23,
    0,    -13,  11,  9,    -8,   -46, 10,   -17,  -13,  16,  19,   -2,   39,
    50,   -5,   3,   3,    -4,   12,  16,   -16,  -16,  9,   15,   56,   -2,
    15,   22,   23,  -2,   -11,  -10, 22,   19,   12,   68,  73,   -16,  -72,
    -11,  2,    47,  9,    64,   -9,  26,   22,   43,   11,  55,   9,    3,
    16,   16,   2,   -5,   -27,  -23, -64,  -22,  3,    13,  -35,  -12,  -10,
    -14,  1,    20,  7,    16,   30,  -14,  21,   -21,  -13, -16,  2,    -1,
    -11,  -6,   14,  0,    -18,  52,  66,   14,   -4,   33,  31,   4,    -24,
    11,   -10,  18,  3,    59,   35,  25,   -19,  6,    -41, -19,  30,   -18,
    6,    24,   -1,  83,   63,   60,  -16,  3,    0,    29,  37,   51,   1,
    32,   -9,   17,  24,   40,   -5,  -17,  6,    -20,  -1,  15,   14,   -49,
    16,   28,   1,   14,   -44,  8,   -31,  9,    -3,   8,   -11,  -29,  23,
    19,   -13,  14,  -2,   14,   -4,  22,   -39,  9,    13,  -16,  -6,   68,
    49,   1,    32,  39,   3,    7,   10,   2,    17,   -13, -4,   55,   31,
    24,   1,    13,  -31,  16,   -14, -28,  -15,  14,   0,   26,   53,   46,
    -25,  -42,  6,   22,   63,   -45, 22,   -3,   -10,  16,  68,   -13,  -13,
    -7,   -6,   -5,  -13,  0,    -15, 5,    11,   -18,  -16, 1,    -8,   -2,
    4,    11,   -16, 4,    19,   0,   -12,  -4,   11,   16,  5,    1,    -8,
    -7,   -9,   -17, -7,   5,    3,   1,    -14,  14,   -15, 14,   1,    13,
    -14,  -19,  3,   -3,   3,    -17, -3,   17,   -14,  5,   1,    4,    8,
    -8,   -4,   -16, -19,  6,    15,  -5,   -18,  -18,  -9,  20,   2,    -1,
    -11,  -16,  -15, -13,  1,    3,   18,   -15,  -10,  -13, -7,   -13,  -8,
    -36,  23,   5,   0,    16,   -32, -17,  -10,  -11,  18,  1,    -11,  46,
    10,   -23,  -1,  24,   -9,   -2,  -13,  -35,  2,    -16, -15,  -7,   -14,
    87,   34,   43,  32,   43,   8,   -15,  -8,   -24,  13,  5,    -8,   59,
    88,   7,    10,  -31,  -2,   25,  -2,   19,   20,   -16, -15,  24,   -128,
    38,   -44,  -4,  5,    83,   74,  -28,  55,   -24,  14,  57,   46,   -42,
    -22,  21,   -36, -12,  -5,   1,   -6,   -50,  -8,   -5,  -11,  18,   15,
    31,   20,   11,  14,   -7,   7,   -25,  -12,  -14,  -28, 26,   -13,  13,
    18,   -13,  -25, 13,   -11,  -13, -14,  72,   25,   -14, 14,   4,    3,
    3,    5,    -1,  -4,   -16,  10,  35,   14,   11,   34,  3,    19,   -8,
    -30,  16,   24,  21,   37,   39,  -9,   18,   -8,   -41, -8,   1,    68,
    8,    29,   -8,  16,   -12,  38,  -14,  18,   33,   13,  -16,  -9,   -6,
    17,   36,   15,  44,   37,   1,   24,   -47,  -64,  -1,  2,    11,   8,
    -5,   10,   7,   36,   25,   -10, 2,    1,    33,   19,  19,   -12,  -7,
    -8,   19,   -41, -84,  -5,   10,  -7,   12,   3,    20,  -14,  0,    -4,
    -55,  -55,  -30, -7,   -34,  -41, 8,    -1,   4,    38,  -40,  -41,  -71,
    -105, -25,  46,  35,   41,   -16, -98,  -65,  6,    -31, -20,  -17,  -55,
    -63,  -24,  -59, -4,   -15,  -4,  0,    -19,  -77,  16,  -44,  -24,  17,
    8,    4,    11,  -14,  20,   -15, -55,  6,    -16,  -17, 0,    26,   11,
    -15,  -3,   -26, -21,  4,    -3,  7,    -11,  79,   54,  35,   -17,  29,
    -10,  -22,  22,  8,    10,   16,  -8,   9,    89,   -15, 38,   20,   12,
    26,   -21,  14,  49,   0,    -3,  37,   86,   -20,  -22, -38,  6,    38,
    59,   -11,  54,  -25,  38,   39,  68,   -15,  -55,  22,  -42};
const int32_t conv2_bias[] = {-5,  -21, -29, 12,  -9,  -50, -16, -6,  20,  28,
                              22,  24,  -11, -28, -6,  1,   18,  -18, -19, 1,
                              -14, 13,  -17, 11,  -21, 15,  -5,  -18, -16, 1,
                              -1,  -19, -2,  -6,  -29, -21, -1,  -20, -11, 12,
                              12,  -33, -10, -9,  -29, 7,   3,   -33};

void conv2_init() {
  for (int c = 0; c < conv2_filter_dims.n; c++) {
    conv2_multiplier_array[c] = conv2_multiplier;
    conv2_shift_array[c] = conv2_shift;
  }
}

const cmsis_nn_tile max2_stride = {2, 0};
const cmsis_nn_tile max2_padding = {0, 0};
const cmsis_nn_activation max2_activation = {-127, 128};
const cmsis_nn_pool_params max2_params = {max2_stride, max2_padding,
                                          max2_activation};
const cmsis_nn_dims max2_in_dims = conv2_out_dims;
const cmsis_nn_dims max2_filter_dims = {0, 1, 2, 0};
const cmsis_nn_dims max2_out_dims = {0, 1, 16, 48};


}  // namespace convolution_layer
};  // namespace kimdictor_morse_fl
#endif