#include <mlx.h>

	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/*
we pass the bits_per_pixel, line_length and endian variables by reference
These will be set accordingly by MiniLibX as per described above.
Now we have the image address, but still no pixels. 

But the bytes are not aligned, this means that the line_length differs 
from the actual window width. We therefore should ALWAYS calculate the 
memory offset using the line length set by mlx_get_data_addr.

We can calculate it very easily by using the following formula:
int offset = (y * line_length + x * (bits_per_pixel / 8));
*/

void    my_mlx_pixel_put(t_data *data, int x, int y, int color) {
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	drawCircle(t_data img, int x0, int y0, int radius) {
	int x;
	int y;
	int err;

	x = radius;
	y = 0;
	err = 0;
	while (x >= y) {
		my_mlx_pixel_put(&img, x0 + x, y0 + y, 0xFFFFFF);
		my_mlx_pixel_put(&img, x0 + y, y0 + x, 0xFFFFFF);
		my_mlx_pixel_put(&img, x0 - y, y0 + x, 0xFFFFFF);
		my_mlx_pixel_put(&img, x0 - x, y0 + y, 0xFFFFFF);
		my_mlx_pixel_put(&img, x0 - x, y0 - y, 0xFFFFFF);
		my_mlx_pixel_put(&img, x0 - y, y0 - x, 0xFFFFFF);
		my_mlx_pixel_put(&img, x0 + y, y0 - x, 0xFFFFFF);
		my_mlx_pixel_put(&img, x0 + x, y0 - y, 0xFFFFFF);
		if (err <= 0) {
            y += 1;
            err += 2*y + 1;
        }

        if (err > 0) {
            x -= 1;
            err -= 2*x + 1;
        }
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	int	x0;
	int	y0;
	int radius;

	x0 = 250;
	y0 = 250;
	radius = 50;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Circle");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	drawCircle(img, x0, y0, radius);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

/*while (x < 315)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}*/