<img src="images/title.png" width="30%" align="center"/>

Apocalypse is a simple game developed in C/C++ using SDL2 library for video rendering, event handling, threads etc.

## Getting started

Currently, the game is still under development and looks like this:

<img src="images/screenshot.png" width="100%" float="right"/>

The graphics are not completed yet and most of the image above is just placeholder for future graphics.

### Requirements

To build an run this project on linux, you must have installed on your computer the following packages

```
libsdl2-2.0-0
libsdl2-dev
libsdl2-image-2.0-0
libsdl2-image-dev
libsdl2-ttf-2.0-0
libsdl2-ttf-dev
```

# Build

On Deabian/Ubuntu, these packages can be installed with the command

```
$ sudo apt-get install ibsdl2-2.0-0 libsdl2-dev libsdl2-image-2.0-0 libsdl2-image-dev libsdl2-ttf-2.0-0 libsdl2-ttf-dev
```

Then, on the repository root, you should run

```
$ make
```

Now exist a new executable file on the root, `apocalypse.o`, run this file and the game will launch.

## Built With

* [SDL2.0](https://https://www.libsdl.org/) - Simple DirectMedia Layer
* [Retro Gaming font](https://www.dafont.com/pt/vasily.d7345) - Font used in game
* [tinyxml2](https://leethomason.github.io/tinyxml2/) - Library used for opening XML files
* [Tiled map editor](https://www.mapeditor.org/) - Map editor

## Authors

* **Ícaro Freire** - *Programming and game logic* - [ivfreire](https://github.com/ivfreire)

## License

This project is licensed under the GNU License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* [SDL Game Development](https://books.google.com.br/books/about/SDL_Game_Development.html?id=SbmfrHIlhK4C&printsec=frontcover&source=kp_read_button&redir_esc=y#v=onepage&q&f=false) - Shaun Mitchell
* Hat tip to the Hackerspace team of IFUSP (Institute of Physics of the University of São Paulo).
