#include "graph.h"
using namespace flab;

graph::graph(int _x, int _y, int _w, int _h, int _n, const char* label)
	: firstEdge(_n, 0), pointTags(_n, ""), deltaPos(_n, zeroVector),
	forceMat(_n, vector<double>(_n, 1)),
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
	deltaPos.push_back(zeroVector);
	repres.push_back(getNumPoints() - 1);
	forceMat.push_back(vector<double>(getNumPoints(), 1.0));
	for (auto& i : forceMat) {
		i.push_back(1.0);
	}
	return getNumPoints();
}

void graph::addEdge(int frm, int to, string tag, bool attract) {
	if (frm >= getNumPoints() || to > getNumPoints()) {
		throw out_of_range("Point out of range.");
	}

	register edge nedg;
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
	for (int i = 0; i < getNumPoints(); i++) {
		deltaPos[i] = zeroVector;

		for (int j = 0; j < getNumPoints(); j++) {
			register double d = pointPos[i].dis(pointPos[j]);
			if (queryPoint(i, j)) {
				if (d < minLength) {
					deltaPos[i] += (pointPos[i] - pointPos[j]) * (minLength - d) / 3000;
				}
				else {
					deltaPos[i] += (pointPos[i] - pointPos[j]) * (minLength - d) / 6000;
				}
			}
			else {
				if (d < minLength) {
					deltaPos[i] += (pointPos[i] - pointPos[j]) * (minLength - d) / 5000;
				}
				else {
					deltaPos[i] += (pointPos[i] - pointPos[j]) * (minLength - d) / 500000;
				}
			}
		}

		for (auto e : edges) {
			register vector2D v1 = pointPos[e.frm] - pointPos[e.to];
			register vector2D v2 = pointPos[e.frm] - pointPos[i];
			register vector2D vm = pointPos[e.frm] - v1.normalized() * (v1.normalized() * v2);
			register int xmin = min(pointPos[e.frm].x, pointPos[e.to].x);
			register int xmax = max(pointPos[e.frm].x, pointPos[e.to].x);
			register int ymin = min(pointPos[e.frm].y, pointPos[e.to].y);
			register int ymax = max(pointPos[e.frm].y, pointPos[e.to].y);
			if (xmin<vm.x && ymin<vm.y && xmax>vm.x && ymax>vm.y) {
				register double dis = vm.dis(pointPos[i]);
				if (dis == 0) {
					continue;
				}
				register vector2D vec = pointPos[i] - vm;
				deltaPos[i] += vec.normalized() * (1 / dis);
			}
		}

		if (deltaPos[i].len() < 1) {
			deltaPos[i] = zeroVector;
		}
		pointPos[i] += deltaPos[i];
	}

	register vector2D sum(0, 0), pivot(w/4.0, h/4.0);
	for (int i = 0; i < getNumPoints(); i++) {
		pointPos[i] += deltaPos[i];
		sum += pointPos[i] - pivot;
	}
	sum = sum / getNumPoints();

	for (int i = 0; i < getNumPoints(); i++) {
		pointPos[i] -= (sum - pivot)/4.0;
	}
	
	for (auto &i : edges) {
		line(pointPos[i.frm].x, pointPos[i.frm].y, pointPos[i.to].x, pointPos[i.to].y, RGBcol(100, 100, 100), 3, solid);
	}
	for (int i = 0; i < getNumPoints(); i++) {
		circle_fill(pointPos[i].x, pointPos[i].y, 7, RGBcol(255, 255, 255));
		circle(pointPos[i].x, pointPos[i].y, 7, RGBcol(0, 0, 0), 3, solid);
	}
}