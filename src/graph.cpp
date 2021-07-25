#include "graph.h"
using namespace flab;

graph::graph(int _x, int _y, int _w, int _h, int _n, const char* label)
	: firstEdge(_n, 0), pointTags(_n, ""), tempSpeed(_n, zeroVector), force(_n, zeroVector),
	widgetbase(_x, _y, _w, _h, label), minLength(100) {

	if (_x < 0 || _y < 0 || _w < 0 || _h < 0) {
		throw invalid_argument("Invalid size.");
	}

	for (int i = 0; i < _n; i++) {
		pointPos.push_back(vector2D(i * 100, rand() % h));
		repres.push_back(i);
	}
}

int graph::getNumPoints() {
	return pointTags.size();
}

int graph::getRepres(int a) {
	if (repres[a] == a) {
		return a;
	}
	else {
		return repres[a] = getRepres(repres[a]);
	}
}
void graph::joinPoint(int a, int b) {
	repres[getRepres(a)] = getRepres(b);
}
bool graph::queryPoint(int a, int b) {
	return getRepres(a) == getRepres(b);
}

int graph::addPoint(string tag) {
	pointTags.push_back(tag);
	firstEdge.push_back(0);
	pointPos.push_back(vector2D(rand() % w, rand() % h));
	tempSpeed.push_back(zeroVector);
	force.push_back(zeroVector);
	repres.push_back(getNumPoints() - 1);
	return getNumPoints();
}

void graph::addEdge(int frm, int to, string tag, bool attract) {
	if (frm >= getNumPoints() || to > getNumPoints()) {
		throw out_of_range("Point out of range.");
	}

	edge nedg;
	nedg.frm = frm;
	nedg.to = to;
	nedg.tag = tag;
	nedg.nxt = firstEdge[frm];
	firstEdge[frm] = edges.size();
	edges.push_back(nedg);
	if (attract) {
		joinPoint(frm, to);
	}
}

void graph::update() {

	for (int iter_id = 1; iter_id <= 1; iter_id++) {

		for (int i = 0; i < getNumPoints(); i++) {
			tempSpeed[i] = tempSpeed[i] * 0.95;
			force[i] = zeroVector;
		}

		for (int i = 0; i < getNumPoints(); i++) {

			for (int j = 0; j < getNumPoints(); j++) {
				double d = pointPos[i].dis(pointPos[j]);
				if (d == 0) {
					continue;
				}
				if (d < minLength) {
					force[i] += (pointPos[i] - pointPos[j]).normalized() * (minLength - d) / 100;
				}
				else {
					force[i] += (pointPos[i] - pointPos[j]).normalized() * (minLength - d) / 1000;
				}
			}

			for (auto e : edges) {
				vector2D v1 = pointPos[e.frm] - pointPos[e.to];
				vector2D v2 = pointPos[e.frm] - pointPos[i];
				vector2D vm = pointPos[e.frm] - v1.normalized() * (v1.normalized() * v2);
				int xmin = min(pointPos[e.frm].x, pointPos[e.to].x);
				int xmax = max(pointPos[e.frm].x, pointPos[e.to].x);
				int ymin = min(pointPos[e.frm].y, pointPos[e.to].y);
				int ymax = max(pointPos[e.frm].y, pointPos[e.to].y);
				if (xmin<vm.x && ymin<vm.y && xmax>vm.x && ymax>vm.y) {
					double dis = vm.dis(pointPos[i]);
					if (dis == 0) {
						continue;
					}
					vector2D vec = (pointPos[i] - vm).normalized();
					if (dis < 1) {
						dis = 1;
					}
					if (dis <= 30) {
						force[i] += vec * min((100 / dis), 50);
					}
					
				}

				tempSpeed[i] = tempSpeed[i] * 0.5;
			}

			if (force[i].len() <= 0.2) {
				force[i] = zeroVector;
			}

			tempSpeed[i] += force[i];
			pointPos[i] += tempSpeed[i];
		}

		vector2D sum(0, 0), pivot(w / 4.0, h / 4.0);
		for (int i = 0; i < getNumPoints(); i++) {
			pointPos[i] += tempSpeed[i];
			sum += pointPos[i] - pivot;
		}
		sum = sum / getNumPoints();
		for (int i = 0; i < getNumPoints(); i++) {
			pointPos[i] -= sum - pivot;
		}

	}

	for (auto& i : edges) {
		line(pointPos[i.frm].x, pointPos[i.frm].y, pointPos[i.to].x, pointPos[i.to].y, RGBcol(100, 100, 100), 3, solid);
	}
	for (int i = 0; i < getNumPoints(); i++) {
		circle_fill(pointPos[i].x, pointPos[i].y, 7, RGBcol(255, 255, 255));
		circle(pointPos[i].x, pointPos[i].y, 7, RGBcol(0, 0, 0), 3, solid);
	}

}