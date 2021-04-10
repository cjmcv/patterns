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
  virtual void Initialize(int state_num) = 0;
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
  TCPContext() {
    state_ = NULL;
    state_accepted_ = NULL;
    state_connected_ = NULL;
    state_close_ = NULL;
    state_listen_ = NULL;
  }

  ~TCPContext() {
    if (state_accepted_ != NULL) {
      delete state_accepted_;
      state_accepted_ = NULL;
    }
    if (state_connected_ != NULL) {
      delete state_connected_;
      state_connected_ = NULL;
    }
    if (state_close_ != NULL) {
      delete state_close_;
      state_close_ = NULL;
    }
    if (state_listen_ != NULL) {
      delete state_listen_;
      state_listen_ = NULL;
    }
  }

  void Initialize(int state_num) {
    SetState(state_num);
  }

  void SetState(int state_num) {
    switch (state_num) {
    case 1:
      if(state_accepted_ == NULL)
        state_accepted_ = new TCPAccepted(); 
      this->state_ = state_accepted_;
      break;
    case 2:
      if(state_connected_ == NULL)
        state_connected_ = new TCPConnected(); 
      this->state_ = state_connected_;
      break;
    case 3:
      if (state_close_ == NULL)
        state_close_ = new TCPClose();
      this->state_ = state_close_;
      break;
    default: // 0 or default
      if (state_listen_ == NULL)
        state_listen_ = new TCPListen();
      this->state_ = state_listen_;
	    break;
    }
  }
  void Request() {
    state_->Handle(this);
  }

private:
  TCPState* state_;

  TCPState* state_accepted_;
  TCPState* state_connected_;
  TCPState* state_close_;
  TCPState* state_listen_;
};

int main() {
  Context* context = new TCPContext();
  context->Initialize(0);

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