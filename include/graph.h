#pragma once
#define DLLexport
#include "dllexport.h"
#include <string>
#include <vector>

using std::string;
using std::forward;
using std::vector;

namespace flab {

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
	int get_num();
	/**
	 * @brief Add an edge
	 * @param frm From point
	 * @param to To point
	 * @param tag Tag of this edge
	*/
	void add_edge(int frm, int to, string tag);

protected:

	struct node {
		int frm, to;
		node* nxt;
		string tag;

		node() {
			frm = to = 0;
			nxt = nullptr;
			tag = "";
		}

		template<typename tp_str>
		node(int _frm, int _to, node* _nxt, tp_str&& _tag)
			:frm(_frm), to(_to), nxt(_nxt), tag(forward(_tag)) {}
	};
	
	int n;
	vector<node*> start;

};

}