#ifndef HELPERS_H
#define HELPERS_H

#include <fstream>
#include "building.h"
#include "job.h"
#include "graph.h"
#include "dictionary.h"

void displayMainMenu();
int readMaintenanceJobs(string filename, Job*& arr);
Graph<string> readMap(string filename);
Dictionary<Building> readBuildings(string filename);

#endif