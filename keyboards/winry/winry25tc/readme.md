# Winry 25-key RGB Backlight Hot Swap Mechanical Keyboard

Keyboard from
* [SpiderIsland on AliExpress(reseller)](https://a.aliexpress.com/_dVJsSpR). Seller provides [kbfirmware](https://kbfirmware.com/) JSON config that was converted to QMK.



* Keyboard Maintainer: [andrzejressel](https://github.com/andrzejressel)
* Hardware Availability: 
https://aliexpress.com/item/1005001523579896.html
https://item.taobao.com/item.htm?id=599731303104
* Printing on the PCB alludes to how it would have been called originally, 'DEBROGLIE Lightning-25'. Now it's categorized under 'Winry' family nonetheless.
* [pnetmon](https://github.com/pnetmon/winry25tf) has studied this keyboard extensively and shared the detailed information.

Make example for this keyboard (after setting up your build environment):

    make winry/winry25tc:default

**Reset Key**: Located on the other side of the keyboard.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).


## LED
* LED top side (top view)
```
         ││
        ┌┘└┐
,-------┴──┴-------------.
| 20 | 21 | 22 | 23 | 24 |
|----+----+----+----+----|
| 19 |  6 |  7 |  8 |  9 |
|----+----+----+----+----|
| 18 |  5 |  0 |  1 | 10 |
|----+----+----+----+----|
| 17 |  4 |  3 |  2 | 11 |
|----+----+----+----+----|
| 16 | 15 | 14 | 13 | 12 |
`------------------------'

```

* LED down side (top view)
```
         ││
        ┌┘└┐
,-------┴──┴-------------.
|    | 32 |    | 25 |    |
|----+----+----+----+----|
| 31 |    |    |    | 26 |
|----+----+----+----+----|
|    |    |    |    |    |
|----+----+----+----+----|
| 30 |    |    |    | 27 |
|----+----+----+----+----|
|    | 29 |    | 28 |    |
`------------------------'
```
