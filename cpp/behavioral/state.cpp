/*!
* \brief   State. Allow an object to alter its behavior 
*       when its internal state changes.The object will 
*       appear to change its class.
*
*         Context       <===>       TCPState
*            |                       |    |
*        TCPContext           TCPListen  TCPAccepted  
*                            TCPConnected  TCPClose
*/

#include <iostream>
#include <string>

// Context.
// Define the interface required by the client,
// and be responsible for switching state.
class Context {
public:
  virtual void SetState(int state_num) = 0;
  virtual void Request() = 0;
};

// State.
class TCPState {
public:
  virtual void Handle(Context*) = 0;
};

// ConcreteState.
class TCPClose : public TCPState {
public:
  void Handle(Context *context) {
    std::cout << "TCP STAT Close.\n";
    context->SetState(0);
  }
};

// ConcreteState.
class TCPListen :public TCPState {
public:
  void Handle(Context *context) {
    std::cout << "TCP STAT Listening.\n";
    context->SetState(1);
  }
};

// ConcreteState.
class TCPAccepted :public TCPState {
public:
  void Handle(Context *context) {
    std::cout << "TCP STAT Accepted.\n";
    context->SetState(2);
  }
};

// ConcreteState.
class TCPConnected : public TCPState {
public:
  void Handle(Context *context) {
    std::cout << "TCP STAT Connected.\n";
    context->SetState(3);
  }
};

// ConcreteContext.
class TCPContext : public Context {
public:
  TCPContext(TCPState* state) {
    this->state_ = state;
  }
  ~TCPContext() {
    if (NULL != state_)
      delete state_;
  }
  void SetState(int state_num) {
    if (NULL != state_)
      delete state_;
    switch (state_num) {
    case 1:
      this->state_ = new TCPAccepted(); break;
    case 2:
      this->state_ = new TCPConnected(); break;
    case 3:
      this->state_ = new TCPClose(); break;
    default: // 0 or default
      this->state_ = new TCPListen(); break;
    }
  }
  void Request() {
    state_->Handle(this);
  }
private:
  TCPState* state_;
};

int main() {
  Context* context = new TCPContext(new TCPListen());

  // The internal state will be changed by the request.
  context->Request();
  context->Request();
  context->Request();
  context->Request();

  std::cout << " ** " << std::endl;

  context->Request();
  context->Request();
  context->Request();
  context->Request();

  delete context;
}