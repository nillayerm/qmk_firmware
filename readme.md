# Quantum Mechanical Keyboard Firmware

[![Current Version](https://img.shields.io/github/tag/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/tags)
[![Discord](https://img.shields.io/discord/440868230475677696.svg)](https://discord.gg/qmk)
[![Docs Status](https://img.shields.io/badge/docs-ready-orange.svg)](https://docs.qmk.fm)
[![GitHub contributors](https://img.shields.io/github/contributors/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/pulse/monthly)
[![GitHub forks](https://img.shields.io/github/forks/qmk/qmk_firmware.svg?style=social&label=Fork)](https://github.com/qmk/qmk_firmware/)

This is a keyboard firmware based on the [tmk\_keyboard firmware](https://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers, and more specifically, the [OLKB product line](https://olkb.com), the [ErgoDox EZ](https://ergodox-ez.com) keyboard, and the Clueboard product line.

## Documentation

* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are powered by [VitePress](https://vitepress.dev/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls).


## Modified Keyboards On This Fork

* [MF17](keyboards/magic_force/mf17/) rocking [STM32F072x8](https://www.st.com/content/st_com/en/search.html#q=STM32F072-t=products-page=1) with 64 Kbytes of flash memory, 48 MHz of clock speed, 16 KB of SRAM
```
   make magic_force/mf17:nillayerm
```

* [Winry 25tc](/keyboards/winry/winry25tc/) rocking [ATmega32u4](https://www.etechnophiles.com/atmega32u4-pinout/) with 32 Kbytes of flash memory, 48 MHz of clock speed, 2.5 KB of SRAM
```
   make winry/winry25tc:nillayerm
```

* [ID75](keyboards/ymdk/id75/) rocking [APM32F103CBT6](https://global.geehy.com/product/fifth/APM32F103) with 128 Kbytes of flash memory, 96 MHz of clock speed, 36 KB of SRAM
```
   make ymdk/id75/f103:nillayerm
```

* [M2](keyboards/monsgeek/m2/) rocking [WB32FQ95](https://www.westberrytech.com/uploads/file/WB32FQ95xx/EN_DS1905020_WB32FQ95xC_V01.pdf) with 256 Kbytes of flash memory, 96 MHz of clock speed, 36 KB of SRAM
```
   make monsgeek/m2:nillayerm
```

* [K320](/keyboards/durgod/k320/) rocking [STM32F070RBT6](https://www.st.com/en/microcontrollers-microprocessors/stm32f070rb.html) with 128 Kbytes of flash memory, 48 MHz of clock speed, 16 KB of SRAM
```
   make durgod/k320/base:nillayerm
```


## Supported Keyboards

* [Planck](/keyboards/planck/)
* [Preonic](/keyboards/preonic/)
* [ErgoDox EZ](/keyboards/ergodox_ez/)
* [Clueboard](/keyboards/clueboard/)
* [Cluepad](/keyboards/clueboard/17/)
* [Atreus](/keyboards/atreus/)

The project also includes community support for [lots of other keyboards](/keyboards/).

## Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
