#ifndef VEC_2D_H
#define VEC_2D_H

#include <cmath>

struct vec{
	double x, y;

	vec(){
		x = 0;
		y = 0;
	}
	vec(double _x, double _y){
		x = _x;
		y = _y;
	}
	vec(double ax, double ay, double bx, double by){
		x = bx - ax;
		y = by - ay;
	}
	vec(vec unit, double l){
		x = unit.x * l;
		y = unit.y * l;
	}
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

	vec operator * (double c){
		x = x * c;
		y = y * c;
		return *this;
	}

	double skew(vec b){
		return x * b.y - b.x * y;
	}
	double scalar(vec b){
		return x * b.x + y * b.y;
	}

	double getLength(){
		return sqrt(x * x + y * y);
	}

	void normalize(){
		if (x == 0 && y == 0)
			return;
		double l = this->getLength();
		x /= l;
		y /= l;
	}

	bool isNull(){
		return (x == 0 && y == 0);
	}
};

double skew(vec a, vec b){
	return a.x * b.y - b.x * a.y;
}

double scalar(vec a, vec b){
	return a.x * b.x + b.y * a.y;
}

double getDist(vec a, vec b){
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
