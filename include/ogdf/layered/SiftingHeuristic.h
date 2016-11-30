/** \file
 * \brief Declaration of class SiftingHeuristic
 *
 * \author Till Schäfer
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

#include <ogdf/module/LayerByLayerSweep.h>
#include <ogdf/layered/CrossingsMatrix.h>


namespace ogdf
{


//! The sifting heuristic for 2-layer crossing minimization.
/**
 * @ingroup gd-layered-crossmin
 */
class OGDF_EXPORT SiftingHeuristic : public LayerByLayerSweep
{
public:
	//! Creates a new instance of the sifting heuristic with default option settings.
	SiftingHeuristic();

	//! Creates a new instance of the sifting heuristic with the same option settings as \a crossMin.
	SiftingHeuristic(const SiftingHeuristic &crossMin);

	~SiftingHeuristic();

	//! Returns a new instance of the sifting heuristic with the same option settings.
	virtual LayerByLayerSweep *clone() const override
	{
		return new SiftingHeuristic(*this);
	}

	//! Enumerates the different sifting strategies
	enum Strategy { left_to_right, desc_degree, random };

	//! Initializes crossing minimization for hierarchy \a H.
	virtual void init (const HierarchyLevels &levels) override;

	//! Calls the sifting heuristic for level \a L.
	virtual void call (Level &L) override;

	//! Does some clean-up after calls.
	virtual void cleanup () override;

	//! Get for \a Strategy.
	Strategy strategy() const {
		return m_strategy;
	}

	/**
	 * \brief Set for \a Strategy.
	 *
	 * @param strategy is the \a Strategy to be set
	 */
	void strategy (Strategy strategy) {
		m_strategy = strategy;
	}

private:
	CrossingsMatrix *m_crossingMatrix;
	Strategy m_strategy;
};


} // end namespace ogdf