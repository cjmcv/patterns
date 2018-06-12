/*!
* \brief   Facade. Provide a unified interface to a set of
*       interfaces in a subsystem. Facade defines a higher-level
*       interface that makes the subsystem easier to use.
*/

#include <iostream>

class LetterProcess {
public:
  void WriteContext(const std::string &context) {
    std::cout << "Context: " << context.c_str() << std::endl;
  }
  void FillEnvelope(const std::string &address) {
    std::cout << "Address: " << address.c_str() << std::endl;
  }
  void PutIntoEnvelope() {
    std::cout << "Put the letter into Envelope." << std::endl;
  }
  void SendLetter() {
    std::cout << "Send Letter." << std::endl;
  }
};

// Facade. 
class PostOffice {
public:
  // A higher-level interface.
  void SendLetter(const std::string &context, const std::string &address) {
    process_.WriteContext(context);
    process_.FillEnvelope(address);
    process_.PutIntoEnvelope();
    process_.SendLetter();
  }
private:
  LetterProcess process_;
};

int main() {
  PostOffice *post_office = new PostOffice();

  const std::string context = "Hello";
  const std::string address = "Beijing";
  // Use an interface to complete the entire process of sending letter.
  post_office->SendLetter(context, address);

  delete post_office;
  return 0;
}