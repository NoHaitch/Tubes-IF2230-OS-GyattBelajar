#include <stdint.h>
#include "../lib-header/string.h"
#include "../file-system/fat32.h"
#include "syscall.h"

// definisi warna
#define BIOS_LIGHT_GREEN 0b1010
#define BIOS_GREY        0b0111
#define BIOS_DARK_GREY   0b1000
#define BIOS_LIGHT_BLUE  0b1001
#define BIOS_RED         0b1100
#define BIOS_BROWN       0b0110
#define BIOS_WHITE       0b1111
#define BIOS_BLACK       0b0000
void put_template();

struct CursorPosition {
    int row; // current row cursor
    int col; // current col cursor
    char buffer[2048]; // char buffer, input
    int current_length; // current length of text, initially 0
    char current_char;
    int start_col;
};

extern struct CursorPosition CP;

// current directory cluster number
extern uint32_t current_directory;

// current directory table
extern struct FAT32DirectoryTable dir_table;

// show template with path, pastikan path depannya ada /{path}
void put_template_with_path(char* path);

// Wrapper for the base interrupt
void put(char* buf, uint8_t color);

// Print starting screen text
void print_starting_screen();

// parse input, into each argument
// Return amount of argument
int inputparse (char *args_val, char args_info[3][128]);

void start_command();
