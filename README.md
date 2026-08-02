# Scripple
A neural network that recognises a digit drawn on a 28 by 28 pixel grid.
This is a remake of the number recognition model
I had hardcoded a couple months ago called [Scribble](https://github.com/Skwaches/Scribble).
It is built off a "framework" for multilayer perceptrons
I've been working on called [Think](https://github.com/Skwaches/Think).
Definitely not my proudest work.
But hey, it kinda works!
Data is from the [MNIST dataset](http://yann.lecun.com/exdb/mnist/)

## Dependencies
`SDL3`
`SDL3_ttf`
`cmake`
`Think` [Look here](https://github.com/Skwaches/Think).
`Inputs` [Look here](https://github.com/Skwaches/Inputs)
`Matrix` [Too much ?](https://github.com/Skwaches/Matrix)

## Usage
Just edit the [CMakeLists.txt](CMakeLists.txt) 
so that VENDOR_DIR points to the correct folder and it should work out the box.
Executable is named **walk** _get it? Cause ~S~cripple_

## Note
Might need an Nvidia GPU unfortunately.
Will test and fix.
