#pragma once
//#include<winuser.h>
//window's size
int w = GetSystemMetrics(SM_CXSCREEN);
int h = GetSystemMetrics(SM_CYSCREEN);

//color code
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN  3
#define RED  4
#define MAGENTA  5
#define BROWN  6;
#define LIGHTGRAY  7
#define DARKGRAY  8
#define LIGHTBLUE  9
#define LIGHTGREEN  10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA  13
#define YELLOW  14
#define WHITE  15
//text direction code
//constexpr auto HORIZ_DIR = 0;

//text font code
#define BOLD_FONT  10

//app title
//const char* title = "Phan Mem Quan Ly Thu Vien";

// fill style code
#define EMPTY_FILL  0
#define SOLID_FILL 1


//BUTTON

#define ENTER 13
#define ESC 27
#define TAB 9
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define BACKSPACE 8