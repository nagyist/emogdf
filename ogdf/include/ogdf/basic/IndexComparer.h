/** \file
 * \brief IndexComparer definition
 *
 * \author Stephan Beyer
 *
 * \par License:
 * This file is part of the Open Graph Drawing Framework (OGDF).
 *
 * \par
 * Copyright (C)<br>
 * See README.md in the OGDF root directory for details.
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
 * License along with this program; if not, see
 * http://www.gnu.org/copyleft/gpl.html
 */

#pragma once

#include <ogdf/basic/comparer.h>

namespace ogdf {

/**
 * @brief The IndexComparer compares entities like nodes, edges, adjacency entries, based on their index.
 *
 * @ingroup comparer
 */
template<typename T>
class IndexComparer
{
public:
	IndexComparer()
	{
	}

	int compare(const T &a, const T &b) const
	{
		return a->index() - b->index();
	}

	OGDF_AUGMENT_COMPARER(T)
};

}
