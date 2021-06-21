#pragma once
#define DLLexport
#include "dllexport.h"
#include "widgetbase.h"
#include "vector2D.h"
#include <string>
#include <vector>
#include <iostream>

/**
 * @file graph.h
 * @brief Graph class
 */

namespace flab {

using std::move;
using std::ref;
using std::forward;
using std::vector;
using std::string;

/**
 * @brief A graph display wrapper class.
 * @note Point index starts from 0
*/
DLLfrm class graph :public widgetbase {
public:
	/**
	 * @brief Create a graph with n nodes and no edges , point position will be random.
	 * @param _x X coordinate
	 * @param _y Y coordinate
	 * @param _w Wide
	 * @param _h Height
	 * @param _n Number of nodes
	 * @param label label of the widget
	*/
	graph(int _x, int _y, int _w, int _h, int _n = 0, const char* label = 0L);

	/**
	 * @brief Get number of points
	 * @return Number of points
	*/
	int getNumPoints();
	/**
	 * @brief Add a point.
	 * The newly added point will not connect with other points.
	 * @param tag Tag of the new point
	 * @return Total points after adding new points.
	*/
	int addPoint(string tag = "");
	/**
	 * @brief Add an edge.
	 * @param frm From point
	 * @param to To point
	 * @param tag Tag of this edge
	 * @param attract Attract two points
	*/
	void addEdge(int frm, int to, string tag = "", bool attract = 1);

protected:

	struct edge {
		int frm, to;
		int nxt;
		string tag;
	};
	
	double minLength;

	vector<edge> edges;

	vector<int> firstEdge;
	vector<string> pointTags;
	vector<vector2D> pointPos;
	vector<int> repres;

	vector<vector<double> > forceMat;

	void update();

private:

	vector<vector2D> deltaPos;

	// union-find disjoint sets
	int getRepres(int a);
	void joinPoint(int a, int b);
	bool queryPoint(int a, int b);

};

}