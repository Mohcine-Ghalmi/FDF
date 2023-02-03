# FDF
***Fil de Fer or Wire frame***
<img src="Screenshot from 2023-01-31 14-40-57.png">

***This is what Wikipedia says about Ghosts’n Goblins: (have nothing to do with tho code)***

>Ghosts’n Goblins is a platform game where the player controls a knight, named Sir Arthur, who must defeat zombies, ogres, demons, cyclops, dragons and other monsters in order to rescue Princess Prin Prin, who has been kidnapped by Satan, king of Demon World. Along the way the player can pick up new weapons, bonuses and extra suits of armor that can help in this task.

>The game is often considered very difficult by arcade standards and is commonly regarded as one of the most difficult games ever released. 

>The player can only be hit twice before losing a life (the first hit takes away Arthur’s armor, and the player must continue on wearing underwear until completing the level or finding replacement armor). If the player loses a life, they start all over again, or from the halfway point if they managed to get that far.

>Furthermore, each life can only last a fixed duration (generally around three minutes), the clock being reset at the start of a level. If the clock does run out, the player instantly loses that life.

>After defeating the final boss, but only with the cross weapon (if the player does not have the cross weapon, they will be prompted that it is needed to defeat the boss and restart at the beginning of level 5 and must repeat round 5 and 6 again regardless if the weapon is obtained immediately or not) for the first time the player is informed that the battle was a trap devised by Satan. The player must then replay the entire game on a higher difficulty level to reach the genuine final battle.

## **inpute**

<img src="Screenshot from 2023-02-01 11-57-25.png">

## **output**
<img src="Screenshot from 2023-02-01 11-57-40.png">

# **Library that we will work with is <a href="https://harm-smits.github.io/42docs/">``<mlx.h>``</a> from minilibx** 
>MiniLibX is a tiny graphics library which allows you to do the most basic things for rendering something in screens without any knowledge of X-Window and Cocoa. It provides so-called simple window creation, a questionable drawing tool, half-ass image functions and a weird event management system.

# **program struct** 
<pre>
------------------------------------------- How to do -------------------------------------------
1. read file
	- get height(how many lines) of text
	- get width(how many numbers in line)
	- allocate memory for **int by using width and height (look your ft_strsplit() )
	- read file and write number into **int matrix
			by using ft_strsplit() and atoi()
--------------
2. drawing line function (google Bresenham algorithm)
	- find by how much we need to increase x and by how much we need to increase y
		by using float. Example:
			x = 2; x1 = 4;
			y = 2; y1 = 6;
			steps for x: 2
			steps for y: 4
			that means that y should grow 2 times faster than x
			every loop step: y += 1 and x += 0.5
			after 4 steps x and y will be equal with x1, y1

				real x:y		x:y     pixels				
		start:		2.0 : 2.0		2:2        .
		step1:		2.5 : 3.0		2:3        .
		step2:		3.0 : 4.0		3:4         .
		step3:		3.5 : 5.0		3:5         .
		step4:		4.0 : 6.0		4:6          .

            that works because (float)2.5 turns to (int)2 in func. mlx_pixel_put()
--------------
3. function which draws lines beetwen every dot
	- examle:
			0->		0->		0->		0
			|		|		|		|
		
			0->		10->            10->            0
			|		|		|		|
				
			0->		10->            10->            0
			|		|		|		|
				
			0->		0->		0->		0
		'->' and '|'are lines between dots 
		every dot has two lines (right and down):	0->
                                                                 |
----------------
4. adding 3D
	- change coordinates by using isometric formulas:
		x` = (x - y) * cos(angle)
		y` = (x + y) * sin(angle) - z
	- x` and y` are coordintes in 3D format (default angle 0.8)
----------------
5. adding donuses (move, rotation, zoom)
	- when you press button on keyboard the func. mlx_key_hook(win_ptr, deal_key, NULL);
		call the func. deal_key.
	- In the deal key func. you have to change some parametrs, clear the window with
		mlx_clear_window(mlx_ptr, win_ptr); and redraw the picture
----------------
6. error handling
	- check if argc == 2
	- check if file exists: if ((fd = open(file_name, O_RDONLY) > 0))
----------------
7. fix leaks
	- type leaks a.out or leaks fdf in your shell
</pre>
<br>
<pre>
------------------------------- resourses --------------------------------
--------------- 3D ------------------------------------------
	x` = (x - y) * cos(angle);
	y` = (x + y) * sin(angle) - z;
--------------------- mlx_function ----------------------------------------
	void *mlx_ptr;
	void *win_prt;

mlx_ptr = mlx_init();
win_prt = mlx_new_window(mlx_ptr, 1000, 1000, "FDF");

mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, #color);

    mlx_key_hook(win_ptr, deal_key, NULL);
    mlx_loop(mlx_ptr);
--------------------- deal_key prototype -----------------------------------
	int		deal_key(int key, void *data);

-----------------------colors:--------------------------------
	white = 0xffffff
	red = 0xe80c0c
-----------------------frameworks:---------------------------
	-framework OpenGL -framework AppKit
</pre>

