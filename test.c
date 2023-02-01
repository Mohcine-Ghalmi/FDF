#include <mlx.h>

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500,"mlx 42");
    mlx_loop(win_ptr);
}