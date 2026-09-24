/*****************************************************************/ /**
* @file spi_nor_demo.c
* @brief
* @author larson.li@quectel.com
* @date 2025-05-26
*
* @copyright Copyright (c) 2023 Quectel Wireless Solution, Co., Ltd.
* All Rights Reserved. Quectel Wireless Solution Proprietary and Confidential.
*
* @par EDIT HISTORY FOR MODULE
* <table>
* <tr><th>Date <th>Version <th>Author <th>Description
* <tr><td>2025-05-26 <td>1.0 <td>larson.li <td> Init
* </table>
**********************************************************************/
#include "qosa_sys.h"
#include "qcm_spi_nor.h"
#include "qosa_gpio.h"
#include "qosa_def.h"
#include "qosa_log.h"
#include <string.h>
#include "spi_nor_demo.h"
#include "qosa_pinctrl.h"
#include "unirtos_app_init_registry.h"

/*===========================================================================
 *  Macro Definition
 ===========================================================================*/

#define QOS_LOG_TAG LOG_TAG_DEMO

/*===========================================================================
 *  Variate
 ===========================================================================*/
static qosa_task_t g_unir_spi_nor_demo_task = QOSA_NULL;

/*===========================================================================
 *  Static API Functions
 ===========================================================================*/
/**
 * @brief SPI NOR Flash Demo Function
 *
 * This function demonstrates the basic operations of SPI NOR Flash, including initialization, erase, write, and read operations.
 * The main operation flow is as follows:
 * 1. Initialize SPI pins and interface;
 * 2. Read Flash ID;
 * 3. Erase specified area;
 * 4. Write specific data to different addresses;
 * 5. Read data from corresponding addresses and print for verification.
 *
 * @param ctx Task context pointer (unused)
 * @return No return value
 */
static void unir_spi_nor_demo_process(void *ctx)
{
    int          ret = 0;
    qosa_uint8_t data_buf[1024] = {0};
    int          i = 0;
    qosa_bool_t  demo_pass = QOSA_FALSE;

    QOSA_UNUSED(ctx);

    // Delay 5 seconds to prevent log loss
    qosa_task_sleep_sec(5);

    // Configure SPI pin functions: MOSI, MISO, CLK
    qosa_pin_set_func(UNIR_TEST_SPI_MOSI_PIN, UNIR_TEST_SPI_MOSI_PIN_FUNC);
    qosa_pin_set_func(UNIR_TEST_SPI_MISO_PIN, UNIR_TEST_SPI_MISO_PIN_FUNC);
    qosa_pin_set_func(UNIR_TEST_SPI_CLK_PIN, UNIR_TEST_SPI_CLK_PIN_FUNC);

    QLOGV("SPI INIT !!!");
    // Initialize SPI NOR Flash interface
    ret = qcm_spi_nor_init(UNIR_TEST_SPI_PORT, QOSA_SPI_CLK_812_5KHZ);
    if (ret != 0)
    {
        QLOGE("SPI INIT FAILED, ret = %d", ret);
        goto exit;
    }
    // Configure chip select pin function and initialize as GPIO output high level
    qosa_pin_set_func(UNIR_TEST_SPI_CS_PIN, UNIR_TEST_SPI_CS_PIN_FUNC);
    qosa_gpio_init(UNIR_TEST_SPI_CS_GPIO_NUM, QOSA_GPIO_DIRECTION_OUTPUT, QOSA_GPIO_PULL_NONE, QOSA_GPIO_LEVEL_HIGH);
    // Read NOR Flash ID information
    ret = qcm_spi_nor_read_id(UNIR_TEST_SPI_PORT, data_buf);
    if (ret != 0)
    {
        QLOGE("read id failed, ret = %d", ret);
        goto exit;
    }

    // Erase 136KB space starting from address 0 (includes 2 blocks and 2 sectors)
    ret = qcm_spi_nor_erase(UNIR_TEST_SPI_PORT, 0, 0x22000);  // Erase 136KB starting from address 0, 2 block erase and 2 sector erase
    if (ret != 0)
    {
        QLOGE("erase failed, ret = %d", ret);
        goto exit;
    }
    qosa_memset(data_buf, 0x55, sizeof(data_buf));
    // Write data filled with 0x55 to address 0
    ret = qcm_spi_nor_write(UNIR_TEST_SPI_PORT, data_buf, 0, sizeof(data_buf));
    if (ret != 0)
    {
        QLOGE("write failed, addr = 0x%x, ret = %d", 0, ret);
        goto exit;
    }
    qosa_memset(data_buf, 0xAA, sizeof(data_buf));
    // Write data filled with 0xAA to address 0x10000
    ret = qcm_spi_nor_write(UNIR_TEST_SPI_PORT, data_buf, 0x10000, sizeof(data_buf));
    if (ret != 0)
    {
        QLOGE("write failed, addr = 0x10000, ret = %d", ret);
        goto exit;
    }
    qosa_memset(data_buf, 0xA5, sizeof(data_buf));
    // Write data filled with 0xA5 to address 0x20000
    ret = qcm_spi_nor_write(UNIR_TEST_SPI_PORT, data_buf, 0x20000, sizeof(data_buf));
    if (ret != 0)
    {
        QLOGE("write failed, addr = 0x20000, ret = %d", ret);
        goto exit;
    }
    qosa_memset(data_buf, 0x5A, sizeof(data_buf));
    // Write data filled with 0x5A to address 0x21000
    ret = qcm_spi_nor_write(UNIR_TEST_SPI_PORT, data_buf, 0x21000, sizeof(data_buf));
    if (ret != 0)
    {
        QLOGE("write failed, addr = 0x21000, ret = %d", ret);
        goto exit;
    }
    qosa_memset(data_buf, 0x00, sizeof(data_buf));
    // Read data from address 0 and print first 1024 bytes
    ret = qcm_spi_nor_read(UNIR_TEST_SPI_PORT, data_buf, 0, sizeof(data_buf));
    if (ret != 0)
    {
        QLOGE("read failed, addr = 0x%x, ret = %d", 0, ret);
        goto exit;
    }
    for (i = 0; i < 1024; i++)
    {
        QLOGD("[NORFLASH]=====read[%d]: 0x%x \r\n", i, data_buf[i]);
    }

    qosa_memset(data_buf, 0x00, sizeof(data_buf));
    // Read data from address 0x10000 and print first 1024 bytes
    ret = qcm_spi_nor_read(UNIR_TEST_SPI_PORT, data_buf, 0x10000, sizeof(data_buf));
    if (ret != 0)
    {
        QLOGE("read failed, addr = 0x10000, ret = %d", ret);
        goto exit;
    }
    for (i = 0; i < 1024; i++)
    {
        QLOGD("[NORFLASH]=====read[%d]: 0x%x \r\n", i, data_buf[i]);
    }
    qosa_memset(data_buf, 0x00, sizeof(data_buf));
    // Read data from address 0x20000 and print first 1024 bytes
    ret = qcm_spi_nor_read(UNIR_TEST_SPI_PORT, data_buf, 0x20000, sizeof(data_buf));
    if (ret != 0)
    {
        QLOGE("read failed, addr = 0x20000, ret = %d", ret);
        goto exit;
    }
    for (i = 0; i < 1024; i++)
    {
        QLOGD("[NORFLASH]=====read[%d]: 0x%x \r\n", i, data_buf[i]);
    }
    qosa_memset(data_buf, 0x00, sizeof(data_buf));
    // Read data from address 0x21000 and print first 1024 bytes
    ret = qcm_spi_nor_read(UNIR_TEST_SPI_PORT, data_buf, 0x21000, sizeof(data_buf));
    if (ret != 0)
    {
        QLOGE("read failed, addr = 0x21000, ret = %d", ret);
        goto exit;
    }
    for (i = 0; i < 1024; i++)
    {
        QLOGD("[NORFLASH]=====read[%d]: 0x%x \r\n", i, data_buf[i]);
    }

    demo_pass = QOSA_TRUE;

exit:
    if (demo_pass == QOSA_TRUE)
    {
        QLOGV("SPI NOR demo success");
    }
    else
    {
        QLOGE("SPI NOR demo failed, ret = %d", ret);
    }
}
void unir_spi_nor_demo_init(void)
{
    QLOGV("enter UniRTOS spi nor DEMO !!!");
    if (g_unir_spi_nor_demo_task == QOSA_NULL)
    {
        qosa_task_create(
            &g_unir_spi_nor_demo_task,
            CONFIG_UNIRTOS_SPI_NOR_DEMO_TASK_STACK_SIZE,
            UNIR_SPI_NOR_DEMO_TASK_PRIO,
            "spi_nor_demo",
            unir_spi_nor_demo_process,
            QOSA_NULL,
            1
        );
    }
}
UNIRTOS_APP_EXPORT(320, "spi_nor_demo", unir_spi_nor_demo_init);
