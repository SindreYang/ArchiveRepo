#ifndef LINEDRAW_H
#define LINEDRAW_H
void set_rgba(SDL_Surface *surface, Uint32 x, Uint32 y, Uint32 col);
inline void set_rgba(SDL_Surface *surface, Uint32 x, Uint32 y, Uint32 col);

void draw_ptr(SDL_Surface *surface, int x1, int y1, int x2, int y2, Uint32 nedle_col, Uint32 aa_col);

void draw_line(SDL_Surface *surface, int x1, int y1, int x2, int y2, const Uint32 line_col);

#endif
