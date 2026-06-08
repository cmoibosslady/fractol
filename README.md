# Fractol

Fractol is a common-core project and one of the three introductory graphics projects from which each student must choose one. All of the three project uses at their core the [MiniLibX](https://github.com/42Paris/minilibx-linux), a X-Window programming API, written in C.    
The goal of this project is to simulate two types of fractal, the [Mandelbrot](https://en.wikipedia.org/wiki/Mandelbrot_set) set and the [Julia](https://en.wikipedia.org/wiki/Julia_set) set. The program must let the user the ability to move in and out the fractal smoothly.

### Warnings

Due to lack of maintenance, the MiniLibX does not run on all Unix platform. This project was tested on Debian bookworm. To ensure compatibility a Docker container is provided.

### How to use
Install Docker with Docker Engine. Install X11.  
Boot the Docker container using docker compose.
```bash
xhost + 127.0.0.1
```
```bash
docker compose up -d --build
```

##### Change the type of fractal displayed

The Julia set can also be visualized. To do so change the parameters of the entrypoint (CMD) of the container (inside docker/Dockerfile) from:
```Dockerfile
CMD ["./fractol", "mandelbrot"]
```
to:
```Dockerfile
CMD ["./fractol", "julia"]
```
or (with the seed of the fractal as third and fourth parameters):
```Dockerfile
CMD ["./fractol", "julia", "0.285", "0.01"]
```


### Commands

Inside the X window, the key arrows (up, down, left, right) can be used to change the view of the fractal. The mouse/trackpad scroll can be use to zoom in and out of the fractal. Press SPACE to restore to the initial state of the fractal. 
