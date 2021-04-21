/*
 * Copyright (c) 2018 Open Source Foundries Limited
 * Copyright (c) 2019-2020 Arm Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * Original code taken from mcuboot project at:
 * https://github.com/mcu-tools/mcuboot
 * Git SHA of the original version: ac55554059147fff718015be9f4bd3108123f50a
 */

#ifndef __MCUBOOT_CONFIG_H__
#define __MCUBOOT_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
 * This file is also included by the simulator, but we don't want to
 * define anything here in simulator builds.
 *
 * Instead of using mcuboot_config.h, the simulator adds MCUBOOT_xxx
 * configuration flags to the compiler command lines based on the
 * values of environment variables. However, the file still must
 * exist, or bootutil won't build.
 */
#ifndef __BOOTSIM__

#define MCUBOOT_VALIDATE_PRIMARY_SLOT
#define MCUBOOT_USE_FLASH_AREA_GET_SECTORS
#define MCUBOOT_TARGET_CONFIG "flash_layout.h"

#define MCUBOOT_HW_ROLLBACK_PROT
#define MCUBOOT_MEASURED_BOOT

/*
 * Maximum size of the measured boot record.
 *
 * Its size can be calculated based on the following aspects:
 *     - There are 5 allowed software component claims,
 *     - SHA256 is used as the measurement method for the other claims.
 * Considering these aspects, the only claim which size can vary is the type
 * of the software component with a maximum length of 12 bytes, which means
 * the boot record size can be up to 100 bytes.
 */
#define MAX_BOOT_RECORD_SZ  (100u)

/* #undef MCUBOOT_ENC_IMAGES */
/* #undef MCUBOOT_ENCRYPT_RSA */

/*
 * Cryptographic settings
 */
#define MCUBOOT_USE_MBED_TLS

/*
 * Logging
 */
#define MCUBOOT_HAVE_LOGGING    1
#define MCUBOOT_LOG_LEVEL       3

#endif /* !__BOOTSIM__ */

/*
 * Watchdog feeding
 */
#define MCUBOOT_WATCHDOG_FEED()     \
    do {                            \
        /* Do nothing. */           \
    } while (0)

#ifdef __cplusplus
}
#endif

#endif /* __MCUBOOT_CONFIG_H__ */
