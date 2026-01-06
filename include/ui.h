#ifndef UI_H
#define UI_H

#define ARRAY_LEN(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef enum{
	MENU,
	CLOCK
}CurrentPage;

void DrawUI();
void load_background();
void unload_background();
void update_background();

#endif
