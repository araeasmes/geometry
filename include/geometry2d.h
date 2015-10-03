#ifndef GEOM_2D_H
#define GEOM_2D_H

#include <vector>
#include "vec2d.h"
#include <iostream>

inline int weakMod(int k, int n){
	return k >= n ? k - n : k;
}

bool intersectLine(double l1, double r1, double l2, double r2, double &ans){
	if (r1 < l2 || r2 < l1)
		return false;
	else{
		ans = r1 - l2;
		if (ans < 0)
			ans = r2 - l1;
		return true;
	}
}

struct Polygon{
	std::vector<vec> vertices;
	Polygon(){}
	~Polygon(){}

	void add_coord(vec c){
		vertices.push_back(c);
	}
	void add_coord(double x, double y){
		vertices.push_back(vec(x, y));
	}

	//	!		SHOULD BE CALLED FROM THE MOVABLE OBJECT		!
	vec intersect(Polygon b, bool first = true){
		double length, left1, left2, right1, right2, tmp_i, 
			tmp_j, ax, ay, bx, by, projection, pr_2, tmp_length = 0, min_length;
		
		bool init_1, init_2, min_length_init = true;

		vec vec_ans, vec_tmp;
		//possible optimization (init_1, init_2 -> init)
		for (int i = 0; i < vertices.size(); i++){
			init_1 = true, init_2 = true;
			tmp_i = weakMod(i + 1, vertices.size());

			length = getDist(vertices[i], vertices[tmp_i]);
			if (length == 0)
				continue;

			ax = vertices[tmp_i].x - vertices[i].x;
			ay = vertices[tmp_i].y - vertices[i].y;
			// this way cuz coords are listed counterclock-wise
			vec_tmp = vec(ay, -ax);
			std::cout << i << " - " << tmp_i << "\n" << "A :\n";
			for (int j = 0; j < vertices.size(); j++){
				bx = vertices[j].x - vertices[i].x;
				by = vertices[j].y - vertices[i].y;
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
			for (int j = 0; j < b.vertices.size(); j++){
				bx = b.vertices[j].x - vertices[i].x;
				by = b.vertices[j].y - vertices[i].y;
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
			if (!intersectLine(left1, right1, left2, right2, tmp_length)){
				return vec(0, 0);
			} else {
			//possible optimization (separate if for bool)
				if (tmp_length < min_length || min_length_init)
					min_length = tmp_length,
					vec_ans = vec_tmp,
					min_length_init = false;
			}

		}
		if (first){
			vec_tmp = b.intersect(*this, false);
			if (vec_tmp.getLength() < min_length)
				return vec_tmp;
			else
				vec_ans * min_length * (first ? -1 : 1);
		}else
			//possble optimization
			return vec_ans * min_length * (first ? -1 : 1);
	}

	void addVec(vec m){
		for (int i = 0; i < vertices.size(); i++)
			vertices[i].x += m.x,
			vertices[i].y += m.y;
	}
};

#endif
