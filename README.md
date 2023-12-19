# summer-research

This is a github containing the code for the Research Work between June and December 2023
Prepared by Christopher Brubaker December 2023.

## Structure
./AmbiqStudioSDK
Contains the source code and build configuration for the SparkFun Edge Board

./AmbiqStudioSDK/boards_sfe/common/examples/hm01b0_camera_uart/main.c -> File for using the SparkFun Edge Board main.c file. This was the file I was working on, attempting to connect communications to the Nucleo Board Code

./Final_MNIST_CPP_Copy
Folder for all code and the STM32CubeIDE Project for the STM32H747I-DISCO Board

./Final_MNIST_CPP_Copy/CM7/Core/Src/main.cpp -> Main file for the code that runs on the STM32H747I-DISCO Board
./Final_MNIST_CPP_Copy/CM7/Core/Src/TF       -> Contains all of the files for the functions that run inferences and stores the tensorflow model in chunks

./NucleoBoard
Folder for all code and the STM32CubeIDE Project for the NUCLEO-L476RG Board

./NucleoBoard/Hardware/ArduCAM -> Code for the ArduCAM Module, which communicates to the Board. Hookup for this is based on SPI and I2C Pins, which are in the .ioc file in ./NucleoBoard/NucleoBoard.ioc

## Information
### Putty and Serial Terminals:
For running these programs and seeing serial output, I connected the board to my computer, and used Putty to connect to the correct port number and baud rate.

### AmbiqStudioSDK - SparkFun Edge:
This is a complicated one to rebuild and program.
The guide for programming it at this link: https://learn.sparkfun.com/tutorials/using-sparkfun-edge-board-with-ambiq-apollo3-sdk/example-applications and the datasheets for it are at https://cdn.sparkfun.com/assets/d/a/7/c/d/Apollo3_Blue_MCU_Data_Sheet_v0_9_1.pdf.
This main file was the one I was in progress with at the time I stopped working on it, trying to get it to communicate with the NUCLEO-L476RG board.
I was trying to figure out how to read from the memory where the I2C communications came in, but was unsucessful for doing so.
An image of the hookup between this board and the NUCLEO-L476RG is included in the repository.

### Final_MNIST_CPP_Copy - STM32H747I-DISCO:
This is the working project for the DISCO board using the built-in camera module.
The joystick controls how the board works internally.
Left    = Take a photo, and run inference on the photo that was just taken
Right   = Not implemented
Up      = Prints the voltage to serial terminal
Down    = Was for timing a single inference, currently disabled
Pressed = Takes a photo, and shows it on the LCD screen
This works for the most part, with some issues arising with the number 9 being incredibly hard to identify.
For actually programming and coding this, it is easy to do.
Open up the project file using STM32CubeIDE, and compile the overall program, then run on board.
In order to change the model loaded, it would require changing of the internal files inside the main_functions_custom.h and main_functions_custom.cpp file.
Additionally, the model would have to be quantized and converted to a CPP array file, using tensorflows converter in their tflitemicro repository.
If any editing of the .ioc file has to be done, change the name of main.cpp to main.c, to allow for the file to be edited by the STM32CubeIDE.
Once that is done, change the main.c file back to main.cpp.
The main file has to be a main.cpp due to some of the compiler commands needed in the tensorflow files.

### NucleoBoard - NUCLEO-L476RG:
This has two main components to it: Trying to communicate with the SparkFun Edge board, as well as having communicated in the past with the ArduCAM module.
I do not have a hookup photo for this module, but I do remember it needing pullup resistors for the SDA and SCL lines of the I2C communications.
The ArduCAM module had to be modified for the NUCLEO-L476RG board, to use STM32's I2C and SPI communication protocols.
I was not able to use this module in the end due to high current draw, as well as an inability to figure out how to uncompress a jpeg image.
The documentation for the ArduCAM timing is at https://docs.arducam.com/Arduino-SPI-camera/Legacy-SPI-camera/Detailed-Data-Timing-on-Arducam-SPI-Bus/.
This does have the ability to run inferences as well, just with minor modifications needed to the code.

## Overall Overview of Work
In May, I initially started work with the STM32H747I-DISCO board in order to use their built-in FP-AI-VISION1 package.
I worked on this as well as understanding the Tensorflow library from there.
I had to take a break until July, due to some miscommunications between me and the University hiring staff.
Once I was back, I tried getting the board working, which I did end up doing, but it was not great, especially since it was expecting certain model sizes.
After this, I started to combine the FP-AI-VISION1 package with the code from Yawen's previous work, which resulted in the working Final_MNIST_CPP_Copy.
This required reading into a specific version of TensorFlow Lite for Microcontrollers (https://www.tensorflow.org/lite/microcontrollers), and downloading and using their repo from the past.
I was not able to get the current version working, due to some complications, so had to rely on the old version from Yawen's work.

## Future Work
For the future, I would advise a couple things.
1) If wanted, finish getting communications working between the SparkFun Edge Board and the NUCLEO-L476RG Board.
2) Once communications are complete, downscale the image taken on the SparkFun Edge and then transfer it via I2C over to the NUCLEO-L476RG board.
3) Run inferences on images with the new low power camera module, and measure power draw (This can only be done for the NUCLEO board).
4) Measure the current consumption of the STM32H747I-DISCO board as well, just as a comparison point (I was meaning to do this, but never got around to it).

NOTES:
The SparkFun Edge board CANNOT be powered externally.
It must be powered with a coin cell battery on the bottom, which is why I would actually move on from this board, but keep the camera in mind.
Due to the limited nature of I2C communications, I would recommend figuring out another method of communication, or a direct camera module for this project.
Additionally, the SparkFun Edge board uses a proprietary I2C communication method called QWIIC, which requires additional tending to convert and communicate properly with other I2C systems.

Because of some of these notes, I actually advise moving on from the SparkFun Edge board to one of two things:
1) Switching to a camera module board using this smaller and less power hungry camera, currently on the SparkFun Edge
2) Designing a PCB or board for either a custom camera communication module of full system, including an ARM chip

For (1), the ideal situation would be a board that is powered directly from the NUCLEO board, without having to having its own microcontroller and entire development board attached.
Finding one of these is easier said then done, and focusing on low power consumption should be emphasized.
For (2), this would allow for flexibility in design, as well as a lower power consumption, as things that are not necessary to the project could be thrown out.
