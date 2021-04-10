/*!
* \brief   Chain. Avoid coupling the sender of a request to its 
*        receiver by giving more than one object a chance to 
*        handle the request.Chain the receiving objects and pass 
*        the request along the chain until an object handles it.
*
*       Action    ->    Handler
*                       |     |
*                 Handler1 -> Handler2
* 
*     Request -> ServerLevel1 -> ServerLevel2 -> ServerLevel3.
*/

#include <iostream>
#include <vector>

// Action.
class Request {
public:
  Request(int level) {
    level_ = level;
  }
  int GetLevel() {
    return level_;
  }
private:
  int level_;
};

// Handler.
class Server {
public:
  Server() : next_(NULL) {}
  void SetNextLevelServer(Server *server) {
    next_ = server;
  }
  virtual void GetRequest(Request *request) = 0;
protected:
  Server *next_;
};

// ConcreteHandler1.
class ServerLevel1 : public Server {
public:
  ServerLevel1() : level_(1) {}
  void GetRequest(Request *request) {
    if (level_ < request->GetLevel()) {
      if (next_ != NULL)
        next_->GetRequest(request);
      else
        std::cout << "The request was rejected." << std::endl;
    }
    else {
      std::cout << "The request is accepted by the Server of Level 1." << std::endl;
    }
  }
private:
  int level_;
};

// ConcreteHandler2.
class ServerLevel2 : public Server {
public:
  ServerLevel2() : level_(2) {}
  void GetRequest(Request *request) {
    if (level_ < request->GetLevel()) {
      if (next_ != NULL)
        next_->GetRequest(request);
      else
        std::cout << "The request was rejected." << std::endl;
    }
    else {
      std::cout << "The request is accepted by the Server of Level 2." << std::endl;
    }
  }
private:
  int level_;
};

// ConcreteHandler3.
class ServerLevel3 : public Server {
public:
  ServerLevel3() : level_(3) {}
  void GetRequest(Request *request) {
    if (level_ < request->GetLevel()) {
      if (next_ != NULL)
        next_->GetRequest(request);
      else
        std::cout << "The request was rejected." << std::endl;
    }
    else {
      std::cout << "The request is accepted by the Server of Level 3." << std::endl;
    }
  }
private:
  int level_;
};

int main(int argc, char *argv[]) {
  Server *server1 = new ServerLevel1();
  Server *server2 = new ServerLevel2();
  Server *server3 = new ServerLevel3();

  server1->SetNextLevelServer(server2);
  server2->SetNextLevelServer(server3);

  Request *request = new Request(3);

  // Just put the request to the lowest level.
  // You needn't know who's actually in charge of this request.
  server1->GetRequest(request);

  delete server1;
  delete server2;
  delete server3;

  return 0;
}