FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
	&& apt-get install -y --no-install-recommends \
		build-essential \
		clang \
		make \
		pkg-config \
		xorg-dev \
		libx11-dev \
		libxext-dev \
		libxrandr-dev \
		libxrender-dev \
		libxfixes-dev \
		libxi-dev \
		libxinerama-dev \
		libxpm-dev \
		libxmu-dev \
		libbsd-dev \
		libgl1-mesa-dev \
		libglu1-mesa-dev \
		mesa-utils \
	&& rm -rf /var/lib/apt/lists/*

WORKDIR /app/fract

COPY . /app/fract

RUN make -C minilibx-linux && make

ENV DISPLAY=:0

CMD ["./fractol", "mandelbrot"]
