/*!
* \brief   Observer. Define a one-to-many dependency 
*        between objects so that when one object changes
*        state,all its dependents are notified and updated
*        automatically.
*
*          Subject      <->       Observer
*             |                      |                        
*     ConcreteSubject          ConcreteObserver  
*/

#include <iostream>
#include <list>

class Observer {
public:
  virtual void Update() = 0;
  virtual int GetState() = 0;
};

class Subject {
public:
  virtual void Add(Observer *) = 0;
  virtual void Remove(Observer *) = 0;
  virtual void Notify() = 0;
  virtual void SetState(int state) = 0;
  virtual int GetState() = 0;
};

class ConcreteObserver : public Observer {
public:
  ConcreteObserver(Subject *subject) : subject_(subject), status_(0){}

  void Update() {
    status_ = subject_->GetState();
  }
  int GetState() {
    return status_;
  }

private:
  Subject *subject_;
  int status_;
};

class ConcreteSubject : public Subject {
public:
  ConcreteSubject() : status_(0) {}
  void Add(Observer *observer) {
    observer_list_.push_back(observer);
  }
  void Remove(Observer *observer) {
    observer_list_.remove(observer);
  }
  void Notify() {
    std::list<Observer *>::iterator it = observer_list_.begin();
    while (it != observer_list_.end()) {
      (*it)->Update();
      ++it;
    }
  }

  void SetState(int state) {
    status_ = state;
  }
  int GetState() {
    return status_;
  }
private:
  std::list<Observer *> observer_list_;
  int status_;
};

int main() {
  // Create Subject
  Subject *subject = new ConcreteSubject();

  // Create Observer
  Observer *observer1 = new ConcreteObserver(subject);
  Observer *observer2 = new ConcreteObserver(subject);
 
  printf("subject: %d, observer1: %d, observer2: %d.\n", 
    subject->GetState(), observer1->GetState(), observer2->GetState());
  // Register the observer
  subject->Add(observer1);
  subject->Add(observer2);

  // Change the state
  subject->SetState(2);
  subject->Notify();

  // The status of the observer changes as the subject changes.
  printf("subject: %d, observer1: %d, observer2: %d.\n",
    subject->GetState(), observer1->GetState(), observer2->GetState());

  // Unregister the observer
  subject->Remove(observer2);

  subject->SetState(3);
  subject->Notify();

  printf("subject: %d, observer1: %d, observer2: %d.\n",
    subject->GetState(), observer1->GetState(), observer2->GetState());

  delete observer1;
  delete observer2;
  delete subject;
}