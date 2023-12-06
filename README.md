# FdF

**FdF** is a simple 3D height-map renderer project. It enables the rendering of models, where the color of each point is determined by its relative height within the map. The project includes features like model rotation, camera control for zoom and translation, as well as support for color gradients.

![Screenshot from 2023-09-16 05-32-03](https://github.com/hheghine/FdF/assets/119530584/c6394ce5-9848-40a7-9e35-50a68dffe7ba)




## Features

### Current Features

- Simple file format definition using an array of space-separated integers.
- `keys: ↑/↓/←/→` transitions
- `keys: +/-` zoom
- `keys: 4/6` 3D rotations 
- `keys: 8/2` move the z axis
- `key: z` top view

  
| 3D View                                                                                      |  Top View                                                                                        |
|----------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------|
| ![3d](https://github.com/hheghine/FdF/assets/119530584/f6f1c0ab-b53d-4c66-863f-bfdde53e2935) | ![Top](https://github.com/hheghine/FdF/assets/119530584/7f055794-5c23-46f3-8b2a-17c579860042)    |

| Z_UP                                                                                         | Z_DOWN                                                                                           |
|----------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------|
|![z_up](https://github.com/hheghine/FdF/assets/119530584/c2dee0ab-7d70-463b-8032-e7eb4790adc6)|![z_down](https://github.com/hheghine/FdF/assets/119530584/df20f1e1-5cde-4130-80c0-bd1c1623cc30)  |


### Compatibility

- MacOs
- Linux
- Win11 

## Compiling and Running

1. Compile the executable by running `make`. The resulting executable will be generated.
2. Run the program using `./fdf [map]`, where `[map]` should be replaced with the path to the map file you wish to visualize.
3. A set of sample maps can be found in the `maps` directory. Notably, `maps/42.fdf` is a popular choice for testing.

## Conclusion

**FdF** is a straightforward 3D height-map renderer that allows users to visualize and interact with models. It offers rotation, camera control, color gradients, and various planned features to enhance the experience further. By compiling and running the program, you can explore the provided sample maps and create your own height-map visualizations.


| That's the spirit!                                                                           |                                                                                                  |
|----------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------|
|![bmth](https://github.com/hheghine/FdF/assets/119530584/541797d0-50d9-455d-bfee-b3c660ab0c0e)| ![misfits](https://github.com/hheghine/FdF/assets/119530584/d6aec71d-f2e1-4fac-b3f1-418b0127c9b7)|



![Screenshot from 2023-09-16 05-45-08](https://github.com/hheghine/FdF/assets/119530584/b139951b-70fc-4487-9683-94fdacb403ae)

![Screenshot from 2023-09-18 04-21-22](https://github.com/hheghine/FdF/assets/119530584/db548e76-bb55-4422-983a-c8e39656f96d)

![Screenshot from 2023-09-16 05-36-36](https://github.com/hheghine/FdF/assets/119530584/e3abf443-22b4-4908-b10a-da46309aacf5)
