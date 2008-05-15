/*
 * This file part of makedict - convertor from any
 * dictionary format to any http://xdxf.sourceforge.net
 * Copyright (C) 2005-2006 Evgeniy <dushistov@mail.ru>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

//$Id: dummy_generator.cpp 66 2007-04-07 17:47:53Z mrcoder1234 $

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <cstdlib>
#include <string>

#include "file.hpp"

#include "generator.hpp"

namespace {

	class DummyGenerator : public GeneratorBase {
	public:
		DummyGenerator(): GeneratorBase(true) {	       
			set_format(DUMMY_FORMAT_NAME);
			set_version("dummy_generator, version 1.0");
		}
	protected:
		int generate() { return EXIT_SUCCESS; }
		bool on_prepare_generator(const std::string&,
					  const std::string&) {
			return true;
		}
		bool on_have_data(const StringList& keys,
				  const std::string& data);

	};

	REGISTER_GENERATOR(DummyGenerator,dummy);


	bool DummyGenerator::on_have_data(const StringList& keys,
					  const std::string& data)
	{
		for (StringList::const_iterator p = keys.begin(); p != keys.end(); ++p) {
			StdOut << "key: " << *p << "\n";
			if (!StdOut)
				return false;
		}
		StdOut << "data: " << data << "\n";
		if (!StdOut)
			return false;
		return true;
	}
}

#ifdef DUMMY_GENERATOR_ALONE
int main(int argc, char *argv[])
{
	return DummyGenerator().run(argc, argv);
}
#endif
