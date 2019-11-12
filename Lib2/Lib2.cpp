/*
 * Copyright (c) 2015-2016 Joost Kraaijeveld. See license.txt for details.
 * For information, bug reports and additions send an e-mail to ProjectTemplate@Askesis.nl.
 *
 * Author: jkr
 */

#include "Lib2.hpp"

#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <wx/datetime.h>


/* static */ void Lib2::print()
{
	boost::gregorian::date boostToday = boost::gregorian::day_clock::local_day();
	std::cout << "Hello from Lib2 with boost::gregorian::date at " << boostToday << "!" << std::endl;
	wxDateTime wxWidgetsToday = wxDateTime::Today();
	std::cout << "Hello from Lib2 with wxDateTime at " << wxWidgetsToday.FormatDate().ToAscii() << "!" << std::endl;
}
