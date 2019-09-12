# RubiksCube
An open-ended windows application which displays a Rubik's cube being solved given a valid cube from a user.

The executable begins by showing a user a basic rubik's cube set out as seen in figure 1. The white face is initially considered the `Front` side due to its alignment. To its right are the `Right` side in blue and the `Back` side in yellow sides. Above the white face is the top face in orange and below is the bottom side in red. and a set of buttons to interact with as shown in Figure 1.

See version 1 [here](res/readme/Version1.0/README.md)
(commit hash 36226e0f325396eb4b9d75c30bb032b830e82d40)

Version 2
(commit hash 8306ea0b85bd3372f89a850820814e7947c9f8c7)

It works better now. from version 1 I implemented a reasonable threading system for the rendering and the actions to be performed. Also got out of the inheritance nightmare that was version 1. Made code a lot more succinct.

How to use:
Clone repo and open in Visual Studio's