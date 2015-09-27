#ifndef GEOM_2D_H
#define GEOM_2D_H

#include <vector>
#include "vec2d.h"
#include <iostream>

inline int weakMod(int k, int n){
	return k > n ? n - k : k;
}

struct Polygon{
	std::vector<vec> coords;
	Polygon(){}
	~Polygon(){}

	void add_coord(vec c){
		coords.push_back(c);
	}
	void add_coord(double x, double y){
		coords.push_back(vec(x, y));
	}

	bool intersect(Polygon b, bool first = true){
		double length, left1, left2, right1, right2, tmp_i, 
			tmp_j, ax, ay, bx, by, projection, pr_2;
		bool init_1, init_2;
		for (int i = 0; i < coords.size(); i++){
			init_1 = true, init_2 = true;
			tmp_i = weakMod(i + 1, coords.size());
			ax = coords[tmp_i].x - coords[i].x;
			ay = coords[tmp_i].y - coords[i].y;
			length = getLength(coords[i], coords[tmp_i]);

			if (length == 0)
				continue;
			std::cout << i << " - " << tmp_i << "\n" << "A :\n";
			for (int j = 0; j < coords.size(); j++){
				bx = coords[j].x - coords[i].x;
				by = coords[j].y - coords[i].y;
				projection = skew(ax, ay, bx, by) / length;
				std::cout << j << " : " << projection << std::endl;

				if (init_1)
					right1 = left1 = projection, init_1 = false;
				else if (projection > right1)
						right1 = projection;
					else if (projection < left1)
						left1 = projection;
			}
			std::cout << "B :\n";
			for (int j = 0; j < b.coords.size(); j++){
				bx = b.coords[j].x - coords[i].x;
				by = b.coords[j].y - coords[i].y;
				projection = skew(ax, ay, bx, by) / length;
				std::cout << j << " : " << projection << std::endl;

				if (init_2)
					right2 = left2 = projection, init_2 = false;
				else if (projection > right2)
						right2 = projection;
					else if (projection < left2)
						left2 = projection;
			}
			std::cout << left1 << " " << right1 << " - " << left2 << " " << right2 << std::endl;
			if (right1 < left2 || right2 < left1)
				return false;
		}
		if (first)
			return b.intersect(*this, false);
		else
			return true;
	}
};

#endif