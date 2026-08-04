# Scripple
A neural network that recognises a digit drawn on a 28 by 28 pixel grid.  
This is a remake an old number recognition model.  
The old hardcoded one is [here](https://github.com/Skwaches/Scribble).  
This one is built off a _framework_ for multilayer perceptrons 
I've been working on called [Think](https://github.com/Skwaches/Think).  
Definitely not my proudest work. But hey, it kinda works!  
Data is from the [MNIST dataset](http://yann.lecun.com/exdb/mnist/)  

## Dependencies
* [SDL3](https://github.com/libsdl-org/SDL) for Window creation and renderering
* [SDL3_ttf](https://github.com/libsdl-org/SDL_ttf) for font loading and texture creation.
* [Think](https://github.com/Skwaches/Think)
* [Inputs](https://github.com/Skwaches/Inputs)
* [Matrix](https://github.com/Skwaches/Matrix)
* cmake

## Usage
Just edit the [CMakeLists.txt](CMakeLists.txt) 
so that VENDOR_DIR points to the correct folder.
Use cmake and make to build it, it should work out the box.
Executable is named **walk** _get it? Cause ~S~cripple_

>[!TIP]
[Matrix](https://github.com/Skwaches/Matrix) can run on an Nvidia GPU.  
It'll probably be a bit faster with it.  

