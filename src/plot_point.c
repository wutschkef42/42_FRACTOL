


void    plot_point(char **data_addr, int sl, int x, int y, int color)
{
    int     *addr;

    if (!data_addr)
        return ;
    addr = (int*)(*data_addr);
    *(addr + x + sl*y) = color;       
}   