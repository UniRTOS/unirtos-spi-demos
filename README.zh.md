# unirtos-spi-demos

中文 | [English](README.md)

本仓库推荐通过 unirtos-cli 的 demo 工作流使用，以保证创建、环境拉取和编译流程一致。

## 概述

`unirtos-spi-demos` 用于展示 UniRTOS 下 SPI（Serial Peripheral Interface）能力的整体方案。  
该目录聚焦 SPI 通信相关示例，覆盖从接口初始化、数据收发验证到外部 Flash 存储访问的典型场景，便于快速理解 SPI 能力边界与方案选型方向。

SPI 是嵌入式设备中广泛使用的高速同步串行接口，常用于 Flash 存储、显示屏驱动、传感器采集及芯片间通信。UniRTOS 提供了完整的 SPI 驱动框架，支持灵活的引脚配置、时钟频率调整及多种传输模式。本目录提供多个典型场景示例，供开发者参考选型并快速集成到自己的产品开发中。

## 功能描述

- 演示基础 **SPI 通信** 开发流程，包括引脚配置、通道初始化及回环验证（见 [spi-demos](./spi-demos/)）
- 演示 **SPI NOR Flash** 访问，包括设备 ID 读取、扇区擦除及读写操作（见 [spi-nor-demos](./spi-nor-demos/)）
- 统一覆盖 SPI 全流程：引脚/通道初始化 → 参数配置（时钟频率、极性/相位、位序、数据位宽）→ 数据收发/验证
- 各子 Demo 均可独立编译运行，并包含完整的错误处理与日志输出
- 便于扩展为显示屏驱动接口、传感器数据采集、文件系统实现及 FOTA 升级等场景

## 子 Demo 说明

| 子 Demo | 聚焦方向 | 说明 |
|---|---|---|
| [spi-demos](./spi-demos/) | SPI 通信 | 演示 SPI 通道初始化与回环传输，覆盖时钟频率、CPOL/CPHA、NSS 模式、位序及数据位宽配置 |
| [spi-nor-demos](./spi-nor-demos/) | SPI NOR Flash | 演示 SPI NOR Flash 设备 ID 读取、扇区擦除及字节/块级读写 |

## 选型参考

| 场景 | 推荐方案 |
|---|---|
| 学习 SPI 外设基础或调试 SPI 通信 | spi-demos |
| 对接外部 SPI Flash，满足存储或固件/文件系统需求 | spi-nor-demos |
| 对接基于 SPI 的显示屏、传感器等外设 | spi-demos（可扩展） |

## 技术社区

技术社区：https://forumschinese.quectel.com/c/66-category/66

## 贡献指南

欢迎参与共建，建议按以下方式提交：
- 提交前先执行一次基础验证：env-setup、build、clean。
- 使用清晰的提交说明，描述改动目的、影响范围和验证结果。
- 新增功能或行为变化时，同步更新 README 与相关文档。
- 通过 Issue 或 Pull Request 提交问题修复与功能改进。
