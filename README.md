# unirtos-spi-demos

[中文](README.zh.md) | English

This repository is recommended to be used via the unirtos-cli demo workflow to ensure a consistent process for project creation, environment setup, and compilation.

## Feature Description

This demo demonstrates the basic development workflow for SPI communication on UniRTOS, and is suitable as a beginner example for SPI peripheral debugging and high-speed serial interface development.

- Demonstrates SPI pin function configuration (CS, CLK, MOSI, MISO) and channel initialization at 13 MHz
- Demonstrates loopback test with MOSI/MISO short-circuited to verify basic data integrity
- Supports multiple test cases: clock rate switching, polarity/phase (CPOL/CPHA) configuration, NSS mode switching, bit order (MSB/LSB) switching, data width switching, and large packet transmission
- Easily extensible to flash memory access, display driver interfacing, sensor data acquisition, and high-throughput data transfer

## Quick Start

### 1. Install the UniRTOS Toolchain

- [Development Preparation](https://www.quectel.com.cn/unirtos/docs?docs_page=快速上手/开发准备/开发准备.html)
- [Install the Cross-Compilation Toolchain](https://www.quectel.com.cn/unirtos/docs?docs_page=快速上手/环境搭建/环境搭建.html)
- [Install Python3](https://www.python.org/downloads/)
- [Install git](https://git-scm.com)
- Install unirtos-cli: `pip install unirtos-cli`

Once all the above tools are installed, verify the following commands are available:

```bash
python --version    # Python3
git --version
unirtos --version   # version 1.0.5 or above
unirtos-cli version # version 1.0.11 or above
```

### 2. Pull the Demo Using unirtos-cli

List available demos and versions:

```bash
unirtos-cli ls-demos
```

Create this demo project:

```bash
unirtos-cli new -r unirtos-spi-demos
```

To specify a version:

```bash
unirtos-cli new -r unirtos-spi-demos -v 1.0.0
```

### 3. Enter the Project and Build

```bash
cd unirtos-spi-demos-1.0.0
unirtos-cli env-setup
unirtos-cli build
```

## Common Commands

```bash
# Open the SDK menu configuration
unirtos-cli menuconfig

# Clean build artifacts
unirtos-cli clean
```

## Technical Community

Technical Community: https://forumschinese.quectel.com/c/66-category/66

## Contribution Guidelines

Contributions are welcome. Please follow these guidelines when submitting:
- Run a basic validation before submitting: env-setup, build, clean.
- Use clear commit messages describing the purpose of the change, its scope of impact, and verification results.
- When adding new features or changing behavior, update the README and related documentation accordingly.
- Submit bug fixes and feature improvements via Issues or Pull Requests.
