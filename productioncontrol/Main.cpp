/*
 * ProductionControl.hpp
 *      Author: Merel
 */
#include "../Config/ProjectTemplateConfig.h"

#include "ProductionControl.hpp"
#include <iostream>

int main(int argc, char **argv) {
	ProductionControl pc;
	pc.runtimeAlgorithm();
	pc.write_text();
	return 0;
}
