#ifndef OPTIONS_H
#define OPTIONS_H

typedef struct {
    int all;
    int almost_all;
    int use_ctime;
    int directory;
    int classify;
    int no_sort;
    int human_readable;
    int inode;
    int kilobytes;
    int long_format;
    int numeric_ids;
    int quote;
    int recursive;
    int reverse;
    int sort_size;
    int blocks;
    int sort_time;
    int use_atime;
    int raw;
} Options;

void options_init(Options *options);

int options_parse(Options *options, int argc, char *argv[]);

#endif


