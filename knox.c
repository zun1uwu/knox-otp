#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/random.h>

int encrypt = 0;

int one_time_pad(char *in_path, char *out_path, char *key_path)
{
    FILE *fp_in = fopen(in_path, "rb");
    if (!fp_in)
        return -1;

    FILE *fp_out = fopen(out_path, "wb");
    if (!fp_out)
        return -1;

    FILE *fp_key;
    fp_key = fopen(key_path, encrypt ? "wb" : "rb");
    if (!fp_key)
        return -1;

    int c;
    while ((c = fgetc(fp_in)) != EOF)
    {
        if (encrypt) {
            char rand_c;
            getrandom(&rand_c, 1, 0);

            char enc_c = c ^ rand_c;

            fputc(enc_c, fp_out);
            fputc(rand_c, fp_key);
        } else {
            char key_c = fgetc(fp_key);

            char dec_c = c ^ key_c;

            fputc(dec_c, fp_out);
        }
    }

    fclose(fp_in);
    fclose(fp_out);
    fclose(fp_key);

    return 0;
}

void
usage(char *argv0)
{
    printf("Usage: %s [e|d] [input file] [key file]\n", argv0);
    exit(EXIT_FAILURE);
}

int
main(int argc, char* argv[])
{
    if (argc < 4)
        usage(argv[0]);

    switch (argv[1][0]) {
    case 'e':
    case 'E':
        encrypt = 1;
        break;
    case 'd':
    case 'D':
        encrypt = 0;
        break;
    default:
        usage(argv[0]);
    }

    char *in_path = argv[2];
    char *key_path = argv[3];

    char out_path[256];
    strcpy(out_path, in_path);
    strcat(out_path, encrypt ? ".enc" : ".dec");

    one_time_pad(in_path, out_path, key_path);

    return EXIT_SUCCESS;
}