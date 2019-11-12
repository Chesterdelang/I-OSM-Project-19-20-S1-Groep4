/*
 * Copyright (c) 2015-2016 Joost Kraaijeveld. See license.txt for details.
 * For information, bug reports and additions send an e-mail to ProjectTemplate@Askesis.nl.
 *
 * Author: jkr
 */


#include <iostream>

#include "ProjectTemplateConfig.h"
#include "Lib1.hpp"
#include "Lib2.hpp"

int main( 	int argc,
			char** argv)
{
	std::cout << "Hello from exe1" << std::endl;
	Lib1::print();
	Lib2::print();
	return 0;
}
