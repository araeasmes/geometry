#ifndef VEC_2D_H
#define VEC_2D_H

#include <cmath>

struct vec{
	double x, y;
	vec(double _x, double _y){x = _x; y = _y;}
	vec(){x = 0; y = 0;}
	~vec(){}
	vec operator + (vec b){
		x += b.x;
		y += b.y;
		return *this;
	}
	vec operator -(){
		x = -x;
		y = -y;
		return *this;
	}
	double skew(vec b){
		return x * b.y - b.x * y;
	}
	double scalar(vec b){
		return x * b.x + y * b.y;
	}
};

double skew(vec a, vec b){
	return a.x * b.y - b.x * a.y;
}

double scalar(vec a, vec b){
	return a.x * b.x + b.y * a.y;
}

double getLength(vec a, vec b){
	double tx = a.x - b.x, ty = a.y - b.y;
	return sqrt(tx * tx + ty * ty);
}

double skew(double ax, double ay, double bx, double by){
	return ax * by - bx * ay;
}

double scalar(double ax, double ay, double bx, double by){
	return ax * bx + by * ay;
}

#endif
