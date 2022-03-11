//
// Created by 何剑虹 on 2021/6/24.
//

#ifndef CPP_MPC_HEX_CONV_H
#define CPP_MPC_HEX_CONV_H

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

// tallymarker_hextobin
int tallymarker_hex2bin(const char *str, uint8_t *bytes, size_t blen);

int tallymarker_bin2hex(const uint8_t *bytes, size_t blen, char *str, size_t slen);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif //CPP_MPC_HEX_CONV_H
