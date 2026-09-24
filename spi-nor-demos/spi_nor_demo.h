/*****************************************************************/ /**
* @file spi_nor_demo.h
* @brief
* @author larson.li@quectel.com
* @date 2025-05-26
*
* @copyright Copyright (c) 2023 Quectel Wireless Solution, Co., Ltd.
* All Rights Reserved. Quectel Wireless Solution Proprietary and Confidential.
*
* @par EDIT HISTORY FOR MODULE
* <table>
* <tr><th>Date <th>Version <th>Author <th>Description"
* <tr><td>2025-05-26 <td>1.0 <td>larson.li <td> Init
* </table>
**********************************************************************/
#ifndef __SPI_NOR_DEMO_H__
#define __SPI_NOR_DEMO_H__

#include "qosa_def.h"
#include "qosa_sys.h"

/*===========================================================================
 *  Macro Definition
 ===========================================================================*/

#define CONFIG_UNIRTOS_SPI_NOR_DEMO_TASK_STACK_SIZE 4096                  // Demo task stack size configuration
#define UNIR_SPI_NOR_DEMO_TASK_PRIO                 QOSA_PRIORITY_NORMAL  // Demo task priority configuration

// Pin configuration based on hardware SPI usage
#define UNIR_TEST_SPI_MOSI_PIN                      (67)
#define UNIR_TEST_SPI_MOSI_PIN_FUNC                 (1)
#define UNIR_TEST_SPI_MISO_PIN                      (28)
#define UNIR_TEST_SPI_MISO_PIN_FUNC                 (1)
#define UNIR_TEST_SPI_CLK_PIN                       (29)
#define UNIR_TEST_SPI_CLK_PIN_FUNC                  (1)

// Software CS control pin configuration
#define UNIR_TEST_SPI_CS_GPIO_NUM                   QOSA_GPIO_8
#define UNIR_TEST_SPI_CS_PIN                        (66)
#define UNIR_TEST_SPI_CS_PIN_FUNC                   (0)

// Hardware CS control pin configuration
#define UNIR_TEST_SPI_CS_HARDWARE_CS_PIN_FUNC       (1)

// SPI interface configuration used
#define UNIR_TEST_SPI_PORT                          QOSA_SPI_PORT0

/*===========================================================================
 *  Function Declaration
 ===========================================================================*/
void unir_spi_nor_demo_init(void);

#endif /* __SPI_DEMO_H__ */
