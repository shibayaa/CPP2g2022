#include <iostream>
#include <string>
using namespace std;
#include "Chapter4.h"

double getBmi(const HealthCheck *phc) {
  return getBmi(phc->height, phc->weight);
}
