# Scripple
A neural network that recognises a digit drawn on a 28 by 28 pixel grid.  
This is a remake an old number recognition model.  
The old hardcoded one is [here](https://github.com/Skwaches/Scribble).  
This one is built off a "framework" for multilayer perceptrons 
I've been working on called [Think](https://github.com/Skwaches/Think).  
Definitely not my proudest work. But hey, it kinda works!  
Data is from the [MNIST dataset](http://yann.lecun.com/exdb/mnist/)  

## Dependencies
[SDL3](https://github.com/libsdl-org/SDL) for Window creation and renderering.  
[SDL3_ttf](https://github.com/libsdl-org/SDL_ttf) for font loading and texture creation.  
`cmake` for building.  
[`Think`](https://github.com/Skwaches/Think).  
[`Inputs`](https://github.com/Skwaches/Inputs)  
[`Matrix`](https://github.com/Skwaches/Matrix)  


## Usage
Just edit the [CMakeLists.txt](CMakeLists.txt) 
so that VENDOR_DIR points to the correct folder and it should work out the box.
Executable is named **walk** _get it? Cause ~S~cripple_

> [!IMPORTANT]
Might need an Nvidia GPU unfortunately.
Will test and fix.
