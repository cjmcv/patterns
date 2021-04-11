#include <config.hpp>
#include <icreator.hpp>
#include "Plugin1.hpp"
#include "Plugin2.hpp"

#include <vector>

PM_CONNECTOR
void connect(std::vector<pm::ICreator*> *provider_vec) {
  provider_vec->push_back(new CaffeCreator());
  provider_vec->push_back(new TFCreator());
}