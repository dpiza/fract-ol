# Fract-ol

![42-Badge](https://img.shields.io/badge/%C3%89cole-42SP-blue)![C-Badge](https://img.shields.io/badge/Language-C-lightgrey)[![42Unlicense](https://img.shields.io/badge/License-42Unlicense-yellowgreen)](https://github.com/gcamerli/42unlicense)

<img src="https://github.com/dpiza/resources/blob/master/imgs/Widelbrot.gif?raw=true"/>


## Description

The term fractal was first used by mathematician Benoit Mandelbrot in 1974,
he based it on the Latin word fractus, meaning "broken" or "fractured".
A fractal is an abstract mathematical object, like a curve or a surface, which has a similar
pattern whatever the scale.

Fract-ol however, is just a fractal browser.

## Goals

This is the first project in which we use the graphical library [`miniLibX`](https://github.com/42Paris/minilibx-linux).
This project also gives the opportunity to make use of the mathematical notion of complex numbers and to take a peek at the concept of optimization in computer graphics.


## Mandatory

• The software should offer the Julia set and the Mandelbrot set.

• Mouse wheel zooms in and out.

• Use at least a few colors to show the depth of each fractal.

• A parameter is passed on the command line to define what type of fractal will be
viewed. If no parameter is provided, or if the parameter is invalid, the program
displays a list of available parameters and exits properly.


## Bonus

• One more different fractal.

• The zoom follows the actual mouse position.

• In addition to the zoom: moving with the arrows.

• Make the color range shift.


## Usage

To compile the program, run:

```
$ make
```

Execute the software, providing the name of the fractal set and the seed, when necessary:
```
$ ./fractol Julia -0.73 0.14
```
Avaliable sets:
```
Mandelbrot
Julia
Celtic
Burning-Ship
```
Controls:
```
[W][A][S][D]: 		move screen
[E][Q]|[SCROLL]:	zoom in and out
[+][-]:			control iteration
[C][V]:			control seed (for Julia sets)
[SPACE]:		psychedelite
[R]:			reset fractal
[H]:			show menu
```
## License

This work is published under the terms of [42 Unlicense](https://github.com/gcamerli/42unlicense)
