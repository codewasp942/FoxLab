#include "graph.h"
using namespace flab;

graph::graph(int _x, int _y, int _w, int _h, int _n, const char* label, double targetl)
	: firstEdge(_n, 0), pointTags(_n, ""), deltaPos(_n, zeroVector),
	forceMat(_n, vector<double>(_n, 1.0)),
	widgetbase(_x, _y, _w, _h, label), targetLength(targetl) {

	for (int i = 0; i < _n; i++) {
		pointPos.push_back(vector2D(i * 100, rand() % h));
	}
}

int graph::getNumPoints() {
	return pointTags.size();
}

int graph::addPoint(string tag) {
	pointTags.push_back(tag);
	firstEdge.push_back(0);
	pointPos.push_back(vector2D(rand() % w, rand() % h));
	deltaPos.push_back(zeroVector);
	forceMat.push_back(vector<double>(getNumPoints(), 1.0));
	for (auto& i : forceMat) {
		i.push_back(1.0);
	}
	return getNumPoints();
}

void graph::addEdge(int frm, int to, string tag) {
	register edge nedg;
	nedg.frm = frm;
	nedg.to = to;
	nedg.tag = tag;
	nedg.nxt = firstEdge[frm];
	firstEdge[frm] = edges.size();
	edges.push_back(nedg);
	forceMat[frm][to] += 3;
	forceMat[to][frm] += 3;
}

void graph::update() {
	for (int i = 0; i < getNumPoints(); i++) {
		deltaPos[i] = zeroVector;
		for (int j = 0; j < getNumPoints(); j++) {
			register double d = pointPos[i].dis(pointPos[j]);
			register double err = (200 / forceMat[i][j]) - d;
			deltaPos[i] += (pointPos[i] - pointPos[j]) * err * forceMat[i][j] / 5000;
		}
		if (deltaPos[i].dis(zeroVector) < 1) {
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
		line(pointPos[i.frm].x, pointPos[i.frm].y, pointPos[i.to].x, pointPos[i.to].y,RGBcol(0,0,0),3,solid);
	}
	for (int i = 0; i < getNumPoints(); i++) {
		circle_fill(pointPos[i].x, pointPos[i].y, 7, RGBcol(255, 0, 0));
	}
}