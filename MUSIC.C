#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Sin(int freq);
void sinAndInvSin(int freq1, int freq2);
void sinTan(int freq);
void cosTan(int freq);
void sinSinh(int freq);
void cosCosh(int freq);
void tanSinh(int freq);
void tanCosh(int freq);
void sinCosAndSin(int freq1, int freq2);
void cosCosAndSin(int freq1, int freq2);
void sinSinhAndSin(int freq1, int freq2);
void sinCosAndSinAndTan(int freq1, int freq2, int freq3);

//keep in mind the sound() function requires an int so all the functions
//affecting a frequency have the end result put through a ceil function.
int main(){
  int inputFunc;
  int inputFreq,inputFreq2,inputFreq3;

  printf("Input a number corresponding to one of the functions from the list below\n");
  printf("1)sin					2)sinAndInvertedSin\n");
  printf("3)sinTan				4)cosTan\n");
  printf("5)sinSinh				6)cosCosh\n");
  printf("7)tanSinh				8)tanCosh\n");
  printf("9)sinCosAndSin		10)cosCosAndSin\n");
  printf("11)sinSinhAndSin		12)sinCosAndSinAndTan\n");
  scanf("%d", &inputFunc);

  printf("Input a frequency to use\n");
  scanf("%d", &inputFreq);

  if(inputFreq < 1){
	printf("Frequency too low\n");
	return 0;
  }

  switch(inputFunc){
	  case 1:
		Sin(inputFreq);
		break;
	  case 2:
		printf("Input a second frequency\n");
		scanf("%d", &inputFreq2);
		sinAndInvSin(inputFreq, inputFreq2);
		break;
	  case 3:
		sinTan(inputFreq);
		break;
	  case 4:
		cosTan(inputFreq);
		break;
	  case 5:
		sinSinh(inputFreq);
		break;
	  case 6:
		cosCosh(inputFreq);
		break;
	  case 7:
		tanSinh(inputFreq);
		break;
	  case 8:
		tanCosh(inputFreq);
		break;
	  case 9:
		printf("Input a second frequency\n");
		scanf("%d", &inputFreq2);
		sinCosAndSin(inputFreq, inputFreq2);
		break;
	  case 10:
		printf("Input a second frequency\n");
		scanf("%d", &inputFreq2);
		cosCosAndSin(inputFreq, inputFreq2);
		break;
	  case 11:
		printf("Input a second frequency\n");
		scanf("%d", &inputFreq2);
		sinSinhAndSin(inputFreq, inputFreq2);
		break;
	  case 12:
		printf("Input a second frequency\n");
		scanf("%d", &inputFreq2);
		printf("Input a third frequency\n");
		scanf("%d", &inputFreq3);
		sinCosAndSinAndTan(inputFreq, inputFreq2, inputFreq3);
		break;
	  default:
		printf("not a valid function\n");
		break;
  }

  return 0;
}

//result of a sin function affecting a frequency
void Sin(int freq){
	int degrees = 1;
	int y;
	double radians;

	//one oscilation
	while(degrees < 180) {
		//radians
		radians = (degrees*(M_PI/180));

		//freq * sinwave
		y = (int) freq*sin(radians);

		sound(abs(y));
		delay(50);

		degrees = degrees + 1;
	}

	nosound();
}

//result of a sin and inverted sin function affecting a frequency
void sinAndInvSin(int freq1, int freq2){
	int degreesY = 1;
	int degreesZ = 181;
	double radiansY, radiansZ;
	int y,z;

	//one oscilation
	while(degreesY < 180) {
		//radians
		radiansY = (degreesY*(M_PI/180));
		radiansZ = (degreesY*(M_PI/180));

		//freq * sinwave
		y = (int) freq1*sin(radiansY);
		z = (int) freq2*sin(radiansZ);

		sound(abs(y));
		delay(75);
		sound(abs(z));
		delay(75);

		degreesY = degreesY + 1;
		degreesZ = degreesZ - 1;
	}

	nosound();
}

void sinTan(int freq){
	double degrees = 1;
	int y;
	double radians;

	while(degrees < 180) {
		radians = (degrees*(M_PI/180));

		y = (int) freq*sin(tan(radians));
		sound(abs(y));
		delay(50);

		//increases by half a degree to better notice the change in frequency
		degrees = degrees + 0.5;
	}

	nosound();
}

void cosTan(int freq){
	double degrees = 1;
	double radians;
	int y;

	while(degrees < 180) {
		radians = (degrees*(M_PI/180));

		y = (int) freq*cos(tan(radians));
		sound(abs(y));
		delay(50);

		degrees = degrees + 0.5;
	}

	nosound();
}

void sinSinh(int freq){
	double degrees = 1;
	double radians;
	int y;

	while(degrees < 180) {
		radians = (degrees*(M_PI/180));

		y = (int) freq*sin(sinh(radians));
		sound(abs(y));
		delay(50);

		degrees = degrees + 0.5;
	}

	nosound();
}

void cosCosh(int freq){
	double degrees = 1;
	double radians;
	int y;

	while(degrees < 180) {
		radians = (degrees*(M_PI/180));

		y = (int) freq*cos(cosh(radians));
		sound(abs(y));
		delay(50);

		degrees = degrees + 0.5;
	}

	nosound();
}

void tanSinh(int freq){
	double degrees = 1;
	double radians;
	int y;

	while(degrees < 180) {
		radians = (degrees*(M_PI/180));

		y = (int) freq*tan(sinh(radians));
		sound(abs(y));
		delay(50);

		degrees = degrees + 0.5;
	}

	nosound();
}

void tanCosh(int freq){
	double degrees = 1;
	double radians;
	int y;

	while(degrees < 180) {
		radians = (degrees*(M_PI/180));

		y = (int) freq*tan(cosh(radians));
		sound(abs(y));
		delay(50);

		degrees = degrees + 0.5;
	}

	nosound();
}

void sinCosAndSin(int freq1, int freq2){
	int degreesY = 1;
	//int degreesZ = 181;
	double radiansY;
    //double radiansZ;
	int y,z;

	while(degreesY < 180) {
		radiansY = (degreesY*(M_PI/180));
		//radiansZ = (degreesZ*(M_PI/180));

		y = (int) freq1*sin(cos(radiansY));
		z = (int) freq2*sin(radiansY);

		sound(abs(y));
		delay(75);
		sound(abs(z));
		delay(75);

		degreesY = degreesY + 1;
		//degreesZ = degreesZ - 1;
	}

	nosound();
}

void cosCosAndSin(int freq1, int freq2){
	int degreesY = 1;
	//int degreesZ = 181;
	double radiansY, radiansZ;
	int y,z;

	while(degreesY < 180) {
		radiansY = (degreesY*(M_PI/180));
		//radiansZ = (degreesZ*(M_PI/180));

		y = (int) freq1*cos(cos(radiansY));
		z = (int) freq2*sin(radiansY);

		sound(abs(y));
		delay(75);
		sound(abs(z));
		delay(75);

		degreesY = degreesY + 1;
		//degreesZ = degreesZ - 1;
	}

	nosound();
}

void sinSinhAndSin(int freq1, int freq2){
	int degreesY = 1;
	//int degreesZ = 181;
	double radiansY;
    //double radiansZ;
	int y,z;

	while(degreesY < 180) {
		radiansY = (degreesY*(M_PI/180));
		//radiansZ = (degreesZ*(M_PI/180));

		y = (int) freq1*sin(sinh(radiansY));
		z = (int) freq2*sin(radiansY);

		sound(abs(y));
		delay(75);
		sound(abs(z));
		delay(75);

		degreesY = degreesY + 1;
		//degreesZ = degreesZ - 1;
	}

	nosound();
}

void sinCosAndSinAndTan(int freq1, int freq2, int freq3){
	int degreesY = 1;
	//int degreesZ = 181;
	double radiansY;
    //double radiansZ;
	int y,z,h;

	while(degreesY < 180) {
		radiansY = (degreesY*(M_PI/180));
		//radiansZ = (degreesZ*(M_PI/180));

		y = (int) freq1*sin(cos(radiansY));
		z = (int) freq2*sin(radiansY);
		h = (int) freq3*tan(radiansY);

		sound(abs(y));
		delay(75);
		sound(abs(z));
		delay(75);
		sound(abs(h));
		delay(75);

		degreesY = degreesY + 1;
		//degreesZ = degreesZ - 1;
	}

	nosound();
}