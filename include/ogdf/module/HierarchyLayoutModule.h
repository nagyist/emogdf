/** \file
 * \brief Declaration of interface hierarchy layout algorithms
 *        (3. phase of Sugiyama).
 *
 * \author Carsten Gutwenger
 *
 * \par License:
 * This file is part of the Open Graph Drawing Framework (OGDF).
 *
 * \par
 * Copyright (C)<br>
 * See README.txt in the root directory of the OGDF installation for details.
 *
 * \par
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * Version 2 or 3 as published by the Free Software Foundation;
 * see the file LICENSE.txt included in the packaging of this file
 * for details.
 *
 * \par
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * \par
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 * \see  http://www.gnu.org/copyleft/gpl.html
 ***************************************************************/

#pragma once

#include <ogdf/layered/Hierarchy.h>
#include <ogdf/basic/GraphCopyAttributes.h>
//#include <ogdf/layered/HierarchyLevels.h>
#include <ogdf/layered/CrossingMinInterfaces.h>

namespace ogdf {


/**
 * \brief Interface of hierarchy layout algorithms.
 *
 * \see SugiyamaLayout
 */
class OGDF_EXPORT HierarchyLayoutModule {
public:
	//! Initializes a hierarchy layout module.
	HierarchyLayoutModule() { }

	virtual ~HierarchyLayoutModule() { }

	/**
	 * \brief Computes a hierarchy layout of \a H in \a AGA
	 * @param levels is the input hierarchy.
	 * @param GA is assigned the hierarchy layout.
	 */
	void call(const HierarchyLevelsBase &levels, GraphAttributes &GA) {
		GraphCopyAttributes AGC(levels.hierarchy(),GA);
		doCall(levels,AGC);
		AGC.transform();
	}

	//
	// * \brief Computes a hierarchy layout of \a H in \a AG.
	// * @param H is the input hierarchy.
	// * @param AG is assigned the hierarchy layout.
	// */
	//void call(Hierarchy& H, GraphAttributes &AG) {
	//	GraphCopyAttributes AGC(H,AG);
	//	doCall(H,AGC);
	//	HierarchyLayoutModule::dynLayerDistance(AGC, H);
	//	HierarchyLayoutModule::addBends(AGC, H);
	//	AGC.transform();
	//}


	//
	// * \brief Computes a hierarchy layout of \a H in \a AG.
	// * @param H is the input hierarchy.
	// * @param AG is assigned the hierarchy layout.
	// * @param AGC is GraphCopyAttribute init. with H and AG
	// */
	//void call(const Hierarchy& H, GraphAttributes &, GraphCopyAttributes &AGC) {
	//	doCall(H,AGC);
	//}


	//! Adds bends to edges for avoiding crossings with nodes.
	//static void addBends(GraphCopyAttributes &AGC, HierarchyLevels &levels);

	static void dynLayerDistance(GraphCopyAttributes &AGC, HierarchyLevelsBase &levels);

private:

	//! after calling, ci (cj) contains the number of nodes of level i (j=i-1) which overlap the edge (s,t)
	static void overlap(GraphCopyAttributes &AGC, HierarchyLevelsBase &levels, node s, node t, int i, int &ci, int &cj);

protected:
	/**
	 * \brief Implements the actual algorithm call.
	 *
	 * Must be implemented by derived classes.
	 *
	 * @param levels is the input hierarchy.
	 * @param AGC    has to be assigned the hierarchy layout.
	 */
	virtual void doCall(const HierarchyLevelsBase &levels, GraphCopyAttributes &AGC) = 0;

	OGDF_MALLOC_NEW_DELETE

};


} // end namespace ogdf
