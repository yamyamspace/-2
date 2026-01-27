#include <stdio.h>
#include <stdlib.h>
#include <png.h>

#define WIDTH  256
#define HEIGHT 256

unsigned int image[HEIGHT][WIDTH];

/* ================= PNG LOAD ================= */
void load_png_rgba(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (!fp) { perror("fopen"); exit(1); }

    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    png_infop info = png_create_info_struct(png);

    if (setjmp(png_jmpbuf(png))) {
        fprintf(stderr, "png read error\n");
        exit(1);
    }

    png_init_io(png, fp);
    png_read_info(png, info);

    int width  = png_get_image_width(png, info);
    int height = png_get_image_height(png, info);
    int color  = png_get_color_type(png, info);
    int depth  = png_get_bit_depth(png, info);

    if (width != WIDTH || height != HEIGHT) {
        fprintf(stderr, "image must be 256x256\n");
        exit(1);
    }

    /* RGBA 8bit·ÎÅÀ */
    if (depth == 16) png_set_strip_16(png);
    if (color == PNG_COLOR_TYPE_PALETTE) png_set_palette_to_rgb(png);
    if (color == PNG_COLOR_TYPE_GRAY || color == PNG_COLOR_TYPE_GRAY_ALPHA)
        png_set_gray_to_rgb(png);
    if (!(color & PNG_COLOR_MASK_ALPHA))
        png_set_add_alpha(png, 0xFF, PNG_FILLER_AFTER);

    png_read_update_info(png, info);

    png_bytep rows[HEIGHT];
    for (int y = 0; y < HEIGHT; y++)
        rows[y] = malloc(png_get_rowbytes(png, info));

    png_read_image(png, rows);

    /* RGBA ¡ænsigned int */
    for (int y = 0; y < HEIGHT; y++) {
        png_bytep row = rows[y];
        for (int x = 0; x < WIDTH; x++) {
            png_bytep p = &row[x * 4];
            image[y][x] =
                (p[0] << 24) |
                (p[1] << 16) |
                (p[2] <<  8) |
                 p[3];
        }
        free(rows[y]);
    }

    png_destroy_read_struct(&png, &info, NULL);
    fclose(fp);
}

/* ================= ¹à f À¿ë================ */
void apply_factor(int f)
{
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            unsigned int v = image[y][x];

            unsigned int r = (v >> 24) & 0xFF;
            unsigned int g = (v >> 16) & 0xFF;
            unsigned int b = (v >>  8) & 0xFF;
            unsigned int a =  v        & 0xFF;

            r = (r * f) >> 8;
            g = (g * f) >> 8;
            b = (b * f) >> 8;

            image[y][x] =
                (r << 24) |
                (g << 16) |
                (b <<  8) |
                 a;
        }
    }
}

/* ================= PNG SAVE ================= */
void save_png_rgba(const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (!fp) { perror("fopen"); exit(1); }

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    png_infop info = png_create_info_struct(png);

    if (setjmp(png_jmpbuf(png))) {
        fprintf(stderr, "png write error\n");
        exit(1);
    }

    png_init_io(png, fp);

    png_set_IHDR(
        png, info,
        WIDTH, HEIGHT,
        8,
        PNG_COLOR_TYPE_RGBA,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT
    );

    png_write_info(png, info);

    png_bytep rows[HEIGHT];
    for (int y = 0; y < HEIGHT; y++) {
        rows[y] = malloc(WIDTH * 4);
        for (int x = 0; x < WIDTH; x++) {
            unsigned int v = image[y][x];
            rows[y][4*x+0] = (v >> 24) & 0xFF;
            rows[y][4*x+1] = (v >> 16) & 0xFF;
            rows[y][4*x+2] = (v >>  8) & 0xFF;
            rows[y][4*x+3] =  v        & 0xFF;
        }
    }

    png_write_image(png, rows);
    png_write_end(png, NULL);

    for (int y = 0; y < HEIGHT; y++)
        free(rows[y]);

    png_destroy_write_struct(&png, &info);
    fclose(fp);
}

/* ================= main ================= */
int main()
{
    load_png_rgba("smile.png");

    int f = 100;          // ¹à °è
    apply_factor(f);

    save_png_rgba("output.png");
    return 0;
}
