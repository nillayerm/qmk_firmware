# Idobao x YMDK ID75

![Idobao x YMDK ID75](https://i.imgur.com/bhVfzrzh.jpg)

A 75-key, 5-row ortholinear keyboard with per-key and underglow RGB LEDs.

* Keyboard Maintainer: [The QMK Community](https://github.com/qmk)
* Hardware Supported: [Idobao x YMDK ID75](https://www.aliexpress.com/item/3256804537842097.html). **This is not the same PCB as `idobao/id75` or `ymdk/ymd75`.**
  This keyboard has had multiple PCB revisions, some of which may not work with the firmware in this repository. **Check your PCB before flashing.**
  * `f103`: (Geehy APM32F103CBT6, uf2boot)
  * `rp2040`: (RP2040, rp2040)
* Hardware Availability: [YMDK](https://ymdkey.com/products/id75-75-keys-ortholinear-layout-qmk-anodized-aluminum-case-plate-hot-swappable-hot-swap-type-c-pcb-mechanical-keyboard-kit), [AliExpress (YMDK Store)](https://www.aliexpress.com/item/2255800125183974.html), [Amazon](https://www.amazon.com/Ortholinear-Anodized-Aluminum-hot-swappable-Mechanical/dp/B07ZQ8CD88)

Make example for this keyboard (after setting up your build environment):

    make ymdk/id75/f103:default
    make ymdk/id75/rp2040:default

Flashing example for this keyboard:

    make ymdk/id75/f103:default:flash
    make ymdk/id75/rp2040:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the top left key and plug in the keyboard. This will also clear the emulated EEPROM, so it is a good first step if the keyboard is misbehaving.
* **Physical reset button**: Press the button on the back of the PCB twice in quick succession.
* **Keycode in layout**: Press the key mapped to `QK_BOOT`. In the pre-supplied keymaps it is on the second layer, in the bottom-right corner.

After entering the bootloader through one of the three methods above, the keyboard will appear as a USB mass storage device. If the CLI is unable to find this device, the compiled `.uf2` file can be manually copied to it. The keyboard will reboot on completion with the new firmware loaded.
- `f103`: The volume name is `MT.KEY`.
- `rp2040`: The volume name is `RPI-RP2`.

## LED
* LED top side (top view)
```
        ││
       ┌┘└┐
   ┌───┴┬─┴──┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
   │ 74 │ 73 │ 72 │ 71 │ 70 │ 69 │ 68 │ 67 │ 66 │ 65 │ 64 │ 63 │ 62 │ 61 │ 60 │
   ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   │ 59 │ 58 │ 57 │ 56 │ 55 │ 54 │ 53 │ 52 │ 51 │ 50 │ 49 │ 48 │ 47 │ 46 │ 45 │
   ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   │ 44 │ 43 │ 42 │ 41 │ 40 │ 39 │ 38 │ 37 │ 36 │ 35 │ 34 │ 33 │ 32 │ 31 │ 30 │
   ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   │ 29 │ 28 │ 27 │ 26 │ 25 │ 24 │ 23 │ 22 │ 21 │ 20 │ 19 │ 18 │ 17 │ 16 │ 15 │
   ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   │ 14 │ 13 │ 12 │ 11 │ 10 │  9 │  8 │  7 │  6 │  5 │  4 │  3 │  2 │  1 │  0 │
   └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
```

* LED down side (top view)
```
        ││
       ┌┘└┐
   ┌───┴┬─┴──┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
   │    │    │    │    │    │    │    │    │    │    │    │    │    │    │    │
   ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   │    │  7 │    │  8 │    │  9 │    │ 10 │    │ 11 │    │ 12 │    │ 13 │    │
   ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   │    │    │    │    │    │    │    │    │    │    │    │    │    │    │    │
   ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   │    │  6 │    │  5 │    │  4 │    │  3 │    │  2 │    │  1 │    │  0 │    │
   ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   │    │    │    │    │    │    │    │    │    │    │    │    │    │    │    │
   └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘
```
