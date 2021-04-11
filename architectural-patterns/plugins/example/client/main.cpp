#include "plugin_manager.hpp"
#include "interface.hpp"

#include <iostream>

int main() {

  pm::PluginManager pm;
  pm.RegisterType(CREATOR_TYPE(IInferenceCreator), 0, 5);

  // Load libraries
  pm.Load("..\\plugins\\RelWithDebInfo\\plugins"); // plugins

  // Get inference creators into a vector
  std::vector<IInferenceCreator*> creators;
  pm.GetCreator(creators, CREATOR_TYPE(IInferenceCreator));
  printf("creators.size = %zd.\n", creators.size());

  // Create a IInference from each provider
  std::vector<IInferenceCreator*>::iterator it;
  for (it = creators.begin(); it != creators.end(); ++it) {
    // Create a inference
    if ((*it)->key() == (std::string)"Caffe") {
      IInference* inference = (*it)->create();
      std::cout << inference->description() << std::endl;
      std::cout << "key: " << (*it)->key() << ", version: " << (*it)->version() << std::endl;
      delete inference;
    }
  }
  ////////
  pm.Unload("plugins");
  pm.GetCreator(creators, CREATOR_TYPE(IInferenceCreator));
  printf("creators.size = %zd.\n", creators.size());
  for (it = creators.begin(); it != creators.end(); ++it) {
    IInference* inference = (*it)->create();
    std::cout << inference->description() << std::endl;
    std::cout << (*it)->version() << std::endl;
    delete inference;
  }
  ////////

  pm.UnloadAll();
  std::cout << "Press any key to exit";
  return 0;
}
