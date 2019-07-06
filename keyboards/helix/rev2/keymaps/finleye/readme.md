# Kinesis inspired layout by finleye
## Layout

![Layout](https://i.imgur.com/zcImRFq.png)

## Layers

|Priority|number|name|description|
| ---- | ---- | --- | --- |
|high|16|Adjust|Functions|
||2|Raise|Numeric charactors|
||1|Lower|Other charactors|
|low|0|Qwerty|QWERTY leyout(base)|

### Adjust (Lower + Raise)
```
 ,-----------------------------------------.             ,-----------------------------------------.
 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      | Reset|RGBRST|      |      |      |             |      |      |      |      |      |  Del |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      |      |      |Aud on|Audoff| Mac  |             | Win  |Qwerty|Colemk|Dvorak|      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
 `-------------------------------------------------------------------------------------------------'
```

## Compile

go to qmk top directory.
```
$ cd qmk_firmware
```

build
```
$ make helix/rev2:finleye
```

flash to keyboard
```
$ make helix/rev2:finleye:avrdude
```
