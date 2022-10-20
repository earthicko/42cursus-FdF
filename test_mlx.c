#include "mlx.h"
#include <stdio.h>
#include <unistd.h>

int	similar(int a, int b)
{
	if (-1 <= a - b && a - b <= 1)
		return 1;
	return 0;
}

void	putdot_to_img(char *addr, int size, int bpp, int x, int y, unsigned int color)
{
	printf("addr + %d bytes + %d bytes\n", size * y, x * bpp / 8);
	*(int *)(addr + size * y + x * bpp / 8) = color;
	printf("putdot (%d, %d) [%p]\n", x, y, (addr + size * y) + x * bpp / 8);
}

void	putline_to_img_recur(void *mlx, void *win, char *addr, int size_line, int bits_per_pixel, int sx, int sy, int ex, int ey)
{
	int mx = (sx + ex) / 2;
	int my = (sy + ey) / 2;
	if (similar(sx, ex) && similar(sy, ey))
		return ;
	printf("(%d, %d) <-> (%d, %d) ==> (%d, %d)\n", sx, sy, ex, ey, mx, my);
	putdot_to_img(addr, size_line, bits_per_pixel, mx, my, 0xFFFFFFFF);
	putline_to_img_recur(mlx, win, addr, size_line, bits_per_pixel, sx, sy, mx, my);
	putline_to_img_recur(mlx, win, addr, size_line, bits_per_pixel, mx, my, ex, ey);
}

void	putline_to_img(void *mlx, void *win, int sx, int sy, int ex, int ey)
{
	void *img = mlx_new_image(mlx, 500, 500);
	int bits_per_pixel;
	int size_line;
	int endian;
	char *addr = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	printf("addr: %p\n", addr);
	printf("%d %d %d\n", bits_per_pixel, size_line, endian);
	putline_to_img_recur(mlx, win, addr, size_line, bits_per_pixel, sx, sy, ex, ey);
	printf("putline complete\n");
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	printf("putimg complete\n");
	mlx_destroy_image(mlx, img);
}

int	main(void)
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 500, 500, "Test");

	putline_to_img(mlx, win, 250, 250, 398, 183);

	mlx_loop(mlx);
	return (0);
}
