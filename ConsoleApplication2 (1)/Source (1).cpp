# include "iGraphics.h" 
int color = 30;
int count = 0;
int ab = 0, ba = 1;
int view1 = 0;
int score = 0;
char score1[1] = { '0' };
int game = 0;
int life = 1;
char life1[1] = { '10' };
int start = 0;
FILE*fp;
double gun_x;
int gun_x1;
int plate_sy1 = 63;

double tbo = 5;
double tbt = 4;
double tbth = 3;


double x = 1024;
double tx = 1024;
double thx = 1024;

double y = rand() % 600;
double ty = rand() % 600;
double thy = rand() % 600;

double dx = 3;
//double dy = 5;
double plate_x = 250;
double plate_y = 0;
double plate_dx = 10;
double plate_sy = 63;
void animated1(){
	if (y<60)
		y = y + 60;
	if (x<0){
		x = 1024;
		y = rand() % 600;
		count++;
		life--;
		sprintf(life1, "%d", life);
	}
	x = x - 3;
	/*if(count > 4 && count < 6 )
	tbo=tbo+0.003;
	else if(count>10 && count<12)
	tbo=tbo+0.0003;*/

}
void animated2(){
	if (ty<60)
		ty = ty + 60;
	if (tx<0){
		tx = 1024;
		ty = rand() % 600;
		count++;
		life--;
		sprintf(life1, "%d", life);
	}
	tx = tx - 4;
	/*if(count > 4 && count < 6 )
	tbt=tbt+0.003;
	else if(count>10 && count<12)
	tbt=tbt+0.0003;*/
}
void animated3(){
	if (thy<60)
		thy = thy + 60;
	if (thx<0){
		thx = 1024;
		thy = rand() % 600;
		count++;
		life--;
		sprintf(life1, "%d", life);
	}
	thx = thx - 2;
	/*if(count > 4 && count < 6 )
	tbth=tbth+0.003;
	else if(count>10 && count<12)
	tbth=tbth+0.0003;*/
}
void shoot(){
	if (ab == 1){
		plate_sy += 10;



		if (plate_sy>650){
			plate_sy = 69;
			ab = 0;
		}
	}
	if (ba == 2){
		plate_sy1 += 10;
		if (plate_sy1>650){
			plate_sy1 = 69;
			ba = 0;
		}
	}
}


/*
function iDraw() is called again and again by the system
*/
void iDraw()
{
	//place your drawing codes here	
	iClear();

	if (start == 0){
		iShowBMP(0, 0, "menu.bmp");
	}
	if (start == 1){
		if (life != 0){
			int t, t1, t2;
			t = rand() % 10 + 60;
			t1 = rand() % 20 + 60;
			t2 = rand() % 30 + 60;
			iSetTimer(t, animated1);
			iSetTimer(t1, animated2);
			iSetTimer(t2, animated3);
			iShowBMP(0, 0, "last1.bmp");
			iShowBMP2(x, y, "alien1.bmp", 255);
			//iSetColor(222,0,0);
			iShowBMP2(tx, ty, "alien1.bmp", 255);
			//iSetColor(0,0,204);
			iShowBMP2(thx, thy, "alien1.bmp", 255);
			//iSetColor(0,122,204);
			iShowBMP2(plate_x, plate_y, "gunman.bmp", 255);
			//iSetColor(89,122,45);
			if (ab == 1){
				iShowBMP2(gun_x + 12.5, plate_sy, "red1.bmp", 0);
			}
			if (ba == 2){
				iShowBMP2(gun_x1 + 12.5, plate_sy1, "red1.bmp", 0);
			}
			if ((gun_x + 12.5 >= x && gun_x + 12.5 <= x + 75) && (plate_sy >= y && plate_sy <= y + 90)){
				x = 1024;
				y = rand() % 600;
				//gun_x=1300;
				plate_sy = 63;
				ab = 0;
				score++;
				sprintf(score1, "%d", score);  //convert of score
			}
			if ((gun_x + 12.5 >= tx && gun_x + 12.5 <= tx + 75) && (plate_sy >= ty && plate_sy <= ty + 90)){
				tx = 1024;
				ty = rand() % 600;
				//gun_x=1300;
				plate_sy = 63;
				ab = 0;
				score++;
				sprintf(score1, "%d", score);  //convert of score
				printf("1\n");
			}
			if ((gun_x + 12.5 >= thx && gun_x + 12.5 <= thx + 75) && (plate_sy >= thy && plate_sy <= thy + 90)){
				thx = 1024;
				thy = rand() % 600;
				//gun_x=1300;
				plate_sy = 63;
				ab = 0;
				score++;
				sprintf(score1, "%d", score);  //convert of score
				printf("1\n");
			}
			if ((gun_x1 + 12.5 >= x && gun_x1 + 12.5 <= x + 75) && (plate_sy1 >= y && plate_sy1 <= y + 90)){
				x = 1024;
				y = rand() % 600;
				//gun_x=1300;
				plate_sy1 = 63;
				ba = 1;
				printf("1\n");
				score++;
				sprintf(score1, "%d", score);  //convert of score
			}
			if ((gun_x1 + 12.5 >= tx && gun_x1 + 12.5 <= tx + 75) && (plate_sy1 >= ty && plate_sy1 <= ty + 90)){
				tx = 1024;
				ty = rand() % 600;
				//gun_x=1300;
				plate_sy1 = 63;
				ba = 1;
				score++;
				sprintf(score1, "%d", score);  //convert of score
				printf("1\n");
			}
			if ((gun_x1 + 12.5 >= thx && gun_x1 + 12.5 <= thx + 75) && (plate_sy1 >= thy && plate_sy1 <= thy + 90)){
				thx = 1024;
				thy = rand() % 600;
				//gun_x=1300;
				plate_sy1 = 63;
				ba = 1;
				score++;
				sprintf(score1, "%d", score);  //convert of score
				printf("1\n");
			}

			//iFilledCircle(gun_x + 12.5, plate_sy, 5);
			iText(10, 650, "Press S to Shoot!!", GLUT_BITMAP_8_BY_13);
			iSetColor(89, 166, 38);
			iText(650, 650, "Score", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(730, 650, score1, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(800, 650, "LIFE", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(850, 650, life1, GLUT_BITMAP_TIMES_ROMAN_24);
			if (life == 0 && game == 1){
				fp = fopen("score.txt", "w");
				fprintf(fp, "%d", score1[0]);
				fclose(fp);
			}
			if (life <= 0 && game == 1){
				iText(500, 400, "GAME OVER", GLUT_BITMAP_TIMES_ROMAN_24);

			}
		}
		if (start == 2){
			iText(200, 500, "Pres S to shoot", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(200, 400, "Use left key to move left", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(200, 300, "Use right key to move right", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(10, 10, "Press home to go to main menu", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (start == 4){
			iShowBMP(500, 400, "now1.bmp");

		}
	}
}
/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	printf("%d   %d", mx, my);
		if ((mx >= 387 && mx <= 624) && (my >= 544 && my <= 628))
		{
			start = 1;
			//place your codes here	
		}
		if ((mx >= 387 && mx <= 624) && (my >= 390 && my <= 475))
		{
			start = 2;
			//place your codes here	
		}
		if ((mx >= 387 && mx <= 624) && (my >= 234 && my <= 320))
		{
			start = 3;
			//place your codes here	
		}
		if ((mx >= 387 && mx <= 624) && (my >= 81 && my <= 166))
		{
			start = 4;
			//place your codes here	
		}
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			//place your codes here	
		}
	}


/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 's')
	{
		if (ab == 0){
			gun_x = plate_x;
		}
		if (ab == 1){
			gun_x1 = plate_x;
			ba = 2;
		}
		ab = 1;

	}
}
//place your codes for other keys here


/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_RIGHT)
	{
		plate_x = plate_x + plate_dx;
	}
	if (key == GLUT_KEY_LEFT){
		plate_x = plate_x - plate_dx;
	}
	if (key == GLUT_KEY_HOME){
		start = 0;
	}
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here. 


	iSetTimer(30, shoot);
	iInitialize(1024, 700, "Alien Shooter");
	return 0;
}