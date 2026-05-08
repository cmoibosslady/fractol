# Fractol

Fractol is a common-core project and one of the three introductory graphics projects from which each student must choose one. All of the three project uses at their core the [MiniLibX](https://github.com/42Paris/minilibx-linux), a X-Window programming API, written in C.    
The goal of this project is to simulate two types of fractal, the [Mandelbrot](https://en.wikipedia.org/wiki/Mandelbrot_set) set and the [Julia](https://en.wikipedia.org/wiki/Julia_set) set. The program must let the user the ability to move in and out the fractal smoothly.

### Warnings

Due to lack of maintenance, the MiniLibX does not run on all Unix platform. This project was tested on macOS and RaspberryPiOS (with Raspberry Pi 5) with X11.

### How to use
Download the correct version of the MiniLibX (macOS or Linux), compile the project and the MiniLibX and run the binary with: 
```bash
make
```

Delete the objects with: 
``` bash
make clean
```
Delete the objects, the binary and the MinilibX with:
```bash
make fclean
```

### Commands

Inside the X window, the key arrows (up, down, left, right) can be used to change the view of the fractal. The mouse/trackpad scroll can be use to zoom in and out of the fractal.
