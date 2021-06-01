#pragma once
#define DLLexport
#include "dllexport.h"
#include <string>
#include <vector>

using std::move;
using std::ref;
using std::forward;
using std::vector;
using std::string;

namespace flab {

/**
 * @brief A graph wrapper class.
 * @note Point index starts from 0
*/
DLLfrm class graph {
public:
	/**
	 * @brief Create an empty graph
	*/
	graph();
	/**
	 * @brief Create a graph with n nodes and no edges
	 * @param _n Number of nodes
	*/
	graph(int _n);

	graph(const graph&);
	graph(graph&&);

	/**
	 * @brief Get number of points
	 * @return Number of points
	*/
	int getNumPoints();
	/**
	 * @brief Add a point.
	 * The newly added point will not connect with other points.
	 * @note Point index starts from 0
	 * @return Total points after adding new points.
	*/
	int addPoint();
	/**
	 * @brief Add an edge.
	 * @param frm From point
	 * @param to To point
	 * @param tag Tag of this edge
	 * @note Point index starts from 0
	*/
	void addEdge(int frm, int to, string tag);

protected:

	struct edge {
		int frm, to;
		int nxt;
		string tag;
	};
	
	int n;

	vector<edge> edges;
	vector<int> firstEdge;
	vector<string> pointTags;

};

}