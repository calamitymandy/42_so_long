#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path = "./mysticdoor.xpm";
	int		img_width;
	int		img_height;

	img_width = 500;
	img_height = 500;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "images");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);
}