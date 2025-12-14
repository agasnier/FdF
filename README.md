*This project has been created as part of the 42 curriculum by algasnie.*

# FdF

## Description
The **FdF (Fil de Fer)** project intends to represent a wireframe model in 3D. It creates a graphic representation of a relief landscape by linking various points (x, y, z) via segments, visualized through an isometric projection.

## Instruction
Run the program with a map file: ```./fdf "map_name.fdf"```

* Compilation without ```bonus``` provide the map in a isometric view with basic controls.
Basic controls include the properly escape of the program with ```ESC``` and by closing the windows.

* Compilation with ```bonus``` provide the map in a isometric view at start. Additionnals controls like: ```zoom``` ```translation``` ```rotation``` ```heatmap``` via keyboard and mouse.

### Compilation
To compile the mandatory part (fdf): ```make```

To compile the bonus part (with extended event handling): ```make bonus```

To clean all object files (.o) for both parts: ```make clean```

To clean all object files and executables: ```make fclean```

## Resources

* Subject: 42 FdF
* Graphics library: MiniLibX
* Maps: Available test maps in ```ressources/maps/```

## How it work

**Parsing and initialization:** The program first reads the ```.fdf``` file to store map coordinates (x, y, z) and colors if needed into a structure based on the map dimension. After filling of the structure the program init the mlx by creating a window at the screen size.

**(BONUS) Heatmap pre-calculation:** Before rendering, the program scans all the points for min and max Z_values. It assigns a gradient color to each point relative to its height in percentage. The start and the end color of the gradient can be set into the ```fdf_bonus.h``` file.

**Projection pipeline:** 
* Centering & Scaling: Points are centered depending on the map_size and the altitude is adjusted by a z_scale factor.

* Rotation: Matrix rotations are applied to X, Y, and Z axes. The initial rotation is set into an isometric view. The bonus allows dynamic modification of these angles via keyboard input.

* Translation & Zoom: Final 2D coordinates are scaled by a zoom factor and shifted by offsets to position the map.

**Rasterization:**
* Buffering: An image is generated in memory.

* Drawing lines: Lines are drawn between projected points with the help of the ```Bresenham's Algorithm```. Every pixel of the line is put by setting the color of this pixel. The color is chosen by the mode that is set (normal or Heatmap).

**Event Loop:**
* The program listens for keyboard and mouse events. Any input updates the view parameters and triggers an immediate re-calculation of the projection pipeline to display the updated model.

**End of the program**
* When the program exits, all of memory that is allocated for the windows, image or structure are freed correctly.

## Controls

* Keyboard:
	* ```ESC```: Close the window and quit cleanly.
	* Arrows (```Up```, ```Down```, ```Left```, ```Right```): Rotate the model.
	* ```W```, ```A```, ```S```, ```D```: Translate the model (move).
	* ```+``` / ```-```: Manipulate the height.
	* ```H```: Toggle Heatmap.

* Mouse:
	* ```Scroll UP```: Zoom in.
	* ```Scroll DOWN```: Zoom out.
