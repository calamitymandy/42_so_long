/* everything can be in main in 5 steps:
1 check errors & leaks
  - errors nb of args
  - malloc structure game (1 big struct)
  - extension file .ber check that is okay
  - mlx_init() check errors
  - open file % read map: get_next_line(), open(), close
  - check if map is rectangle
  - check if characters are correct
  - check if there is only walls on borders
  - check all xpm are ok: mlx_new_widow(), mlx_xpm_file_to_image()
  - Function exit() ->
        - window: mlx_destroy_window()
        - mlx: mlx_destroy_display() + free()
        - sprites: mlx_destroy_image()
    End of function exit: free()

2 Initialisation of structure
  - put everything we declare at NULL or 0 & declare mlx_init()

3 Render
  - analyse map and print the elements mlx_put_image_to_window()

4 keyboard interaction
  - mlx_key_hook(), choose a function to implement ft_event_key():
        - insert code to validate if the action is ok and if the character
          can move
bonus: mlx_string_put(): print on screen number of movements

5 loop to make the map stay more than 1 second:
  - mlx_loop()
  - mlx_hook() function to close window with the cross
*/

