# unirtos-spi-demos

[中文](README.zh.md) | English

This repository is recommended to be used via the unirtos-cli demo workflow to ensure consistent project creation, environment setup, and build processes.

## Overview

`unirtos-spi-demos` provides a comprehensive demonstration of SPI (Serial Peripheral Interface) capabilities on UniRTOS.  
This directory focuses on SPI communication examples, covering typical scenarios from interface initialization to data transfer verification and external Flash storage access, so you can quickly understand SPI capability boundaries and choose the right solution for your product.

SPI is a widely used high-speed synchronous serial interface in embedded devices, commonly applied to Flash storage, display drivers, sensor acquisition, and inter-chip communication. UniRTOS provides a complete SPI driver framework that supports flexible pin configuration, clock rate adjustment, and multiple transfer modes. This directory provides multiple typical scenario examples for developers to reference and quickly integrate into their own product development.

## Feature Description

- Demonstrates basic **SPI communication** development workflow, including pin configuration, channel initialization, and loopback verification (see [spi-demos](./spi-demos/))
- Demonstrates **SPI NOR Flash** access, including device ID reading, sector erase, and read/write operations (see [spi-nor-demos](./spi-nor-demos/))
- Covers the complete SPI workflow: pin/channel initialization → parameter configuration (clock rate, polarity/phase, bit order, data width) → data transfer/verification
- Each sub-demo can be compiled and run independently, with full error handling and log output
- Easily extensible to display driver interfacing, sensor data acquisition, file system implementation, and FOTA upgrades

## Sub-Demo Overview

| Sub-Demo | Focus | Description |
|---|---|---|
| [spi-demos](./spi-demos/) | SPI Communication | Demonstrates SPI channel initialization and loopback transfer; covers clock rate, CPOL/CPHA, NSS mode, bit order, and data width configuration |
| [spi-nor-demos](./spi-nor-demos/) | SPI NOR Flash | Demonstrates SPI NOR Flash device ID reading, sector erase, and byte/block-level read/write |

## Selection Guide

| Scenario | Recommended Solution |
|---|---|
| Learning SPI peripheral basics or debugging SPI communication | spi-demos |
| Interfacing with external SPI Flash for storage or firmware/file system needs | spi-nor-demos |
| Interfacing with SPI-based displays, sensors, or other peripherals | spi-demos (extensible) |

## Technical Community

Forum: https://forumschinese.quectel.com/c/66-category/66

## Contributing

Contributions are welcome. Please follow these guidelines:
- Run a basic validation before submitting: env-setup, build, clean.
- Use clear commit messages describing the purpose, scope of changes, and validation results.
- Update README and related documentation when adding features or changing behavior.
- Submit bug fixes and feature improvements via Issues or Pull Requests.
