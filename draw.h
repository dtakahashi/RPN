void dot(int x,int y ,int c);
void line_xy(int x0,int y0,int x1,int y1,int color);
void line_yx(int x0,int y0,int x1,int y1,int color);
int line_pattern(int x0,int y0,int x1,int y1);
void draw_line(int x0,int y0,int x1,int y1,int color);
void init();
void show();
void save(char *out_file);
void load(char *in_file);
void point(int x0, int y0, int color);
void rect(int x0, int y0, int x1, int y1, int color);
void fill_rect(int x0, int y0, int x1, int y1, int color);
void draw_tri(int x0, int y0, int x1, int y1, int x2, int y2, int color);
void double_point(int x1, int x2, int y,int color); 