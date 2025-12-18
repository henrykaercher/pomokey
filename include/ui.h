#ifndef UI_H
#define UI_H

typedef enum{
	MENU,
	CLOCK
}CurrentPage;

void DrawUI(CurrentPage *current_page);

#endif
