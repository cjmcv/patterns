/*!
* \brief   Observer. Define a one-to-many dependency
*        between objects so that when one object changes
*        state,all its dependents are notified and updated
*        automatically.
 */

package main

import "fmt"

type Subject struct {
	observer_list []Observer
	status        int
}

func CreateSubject() *Subject {
	return &Subject{
		observer_list: make([]Observer, 0),
	}
}

func (s *Subject) Add(o Observer) {
	s.observer_list = append(s.observer_list, o)
}

func (s *Subject) Remove(i int) {
	s.observer_list = append(s.observer_list[:i], s.observer_list[i+1:]...)
}

func (s *Subject) notify() {
	for _, o := range s.observer_list {
		o.Update()
	}
}

func (s *Subject) SetState(status int) {
	s.status = status
	s.notify()
}

func (s *Subject) GetStatus() int {
	return s.status
}

/////////////

type Observer interface {
	Update()
	GetStatus() int
}

type ConcreteObserver struct {
	subject *Subject
	status  int
}

func CreateObserver(subject *Subject) *ConcreteObserver {
	return &ConcreteObserver{
		subject: subject,
	}
}

func (co *ConcreteObserver) Update() {
	co.status = co.subject.GetStatus()
}

func (co *ConcreteObserver) GetStatus() int {
	return co.status
}

func main() {
	subject := CreateSubject()
	observer1 := CreateObserver(subject)
	observer2 := CreateObserver(subject)

	subject.Add(observer1)
	subject.Add(observer2)

	fmt.Printf("subject: %d, observer1: %d, observer2: %d.\n",
		subject.GetStatus(), observer1.GetStatus(), observer2.GetStatus())

	subject.SetState(5)

	fmt.Printf("subject: %d, observer1: %d, observer2: %d.\n",
		subject.GetStatus(), observer1.GetStatus(), observer2.GetStatus())

	subject.SetState(10)

	fmt.Printf("subject: %d, observer1: %d, observer2: %d.\n",
		subject.GetStatus(), observer1.GetStatus(), observer2.GetStatus())
}
