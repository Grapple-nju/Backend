#ifndef EDGEMERGER_H
#define EDGEMERGER_H

#include <iostream>
#include <algorithm>
#include <ctime>
#include <limits>
#include <unordered_set>
#include <queue>

#include "../datastructures/minset.h"
#include "../../test/timer.h"
#include "../utilities/globalDefinitions.hpp"


class EdgeMerger
{
	int deltaPtr;		// index into the vector of new edges
	int oUnUdPtr;		// index into the vector of ALL edges
	int currID;			// the current vertex ID (increasing order)

	vector<char> currEvals;		// the current edge values (to check for duplicates)
	std::priority_queue<MinSet, vector<MinSet>, compare> minEdges;		// finds the minset with the minimum current vertex ID


	// FUNCTIONS
	void fillPriorityQueue(vector< vector<int> > &edgeVecsToMerge, vector< vector<char> > &valVecsToMerge,
			vector< vector<PseudoPC> > &constrVecsToMerge, vector<int> &srcDeltaEdges, vector<char> &srcDeltaVals,
			vector<PseudoPC> &srcDeltaConstrs, vector<int> &srcoUnUdEdges, vector<char> &srcoUnUdVals,
			vector<PseudoPC> &srcoUnUdConstrs, int srcID);

	bool find_val(vector<char> &evals, char val);

	void removeExtraSpace(vector<int> &srcDeltaEdges, vector<char> &srcDeltaVals,
			vector<PseudoPC> &srcDeltaConstrs, vector<int> &srcoUnUdEdges,
			vector<char> &srcoUnUdVals, vector<PseudoPC> &srcoUnUdConstrs);

	void updateMinSet(MinSet &minset, vector<int> &edges, vector<char> &vals, vector<PseudoPC> &constrs);

	void processMinSets(MinSet &srcMS, MinSet &tgtMS, vector<int> &srcEdgesToMerge,
		vector<char> &srcValsToMerge, vector<PseudoPC> &srcConstrsToMerge, vector<int> &tgtEdgesToMerge,
		vector<char> &tgtValsToMerge, vector<PseudoPC> &tgtConstrsToMerge, vector<int> &srcDeltaEdges,
		vector<char> &srcDeltaVals, vector<PseudoPC> &srcDeltaConstrs, vector<int> &srcoUnUdEdges,
		vector<char> &srcoUnUdVals, vector<PseudoPC> &srcoUnUdConstrs);

	void updateVector(int vid, char val, PseudoPC constr, vector<int> &edges, vector<char> &vals, vector<PseudoPC> &constrs, int &ptr);

	public:
	// constructor
	EdgeMerger();

	// getters
	inline int getNumNewEdges() { return deltaPtr + 1; }

	// given all new edges and their values, merge with the source creating a vector of old U new edges
	// and only new edges
	void mergeVectors(vector< vector<int> > &edgeVecsToMerge,
		vector< vector<char> > &valVecsToMerge, vector< vector<PseudoPC> > &constrVecsToMerge,
		vector<int> &srcDeltaEdges, vector<char> &srcDeltaVals, vector<PseudoPC> &srcDeltaConstrs,
		vector<int> &srcoUnUdEdges, vector<char> &srcoUnUdVals,
		vector<PseudoPC> &srcoUnUdConstrs, int srcID);
};

#endif
