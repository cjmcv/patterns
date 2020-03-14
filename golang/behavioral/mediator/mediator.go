/*!
* \brief   Mediator.Define an object that encapsulates how
*       a set of objects interact.Mediator promotes loose
*       coupling by keeping objects from referring to each
*       other explicitly,and it lets you vary their interaction
*       independently.
*
*     ( Renter and Landlord communicate through HouseMediator.
*       So Renter and Landlord don't need to meet each other. )
*
*        Person     <=>     Mediator     <=>    Person
*          |                   |                  |
*        Renter           HouseMediator        Landlord
 */

package main

import (
	"fmt"
)

type Person interface {
	SetMediator(mediator Mediator)
	SendMessage(message string)
	GetMessage(message string)
}

type Mediator interface {
	SetRenter(person Person)
	SetLandlord(person Person)
	Send(person Person, message string)
}

//

type Renter struct {
	mediator Mediator
}

func (r *Renter) SetMediator(mediator Mediator) {
	r.mediator = mediator
	r.mediator.SetRenter(r)
}

func (r *Renter) SendMessage(message string) {
	r.mediator.Send(r, message)
}

func (*Renter) GetMessage(message string) {
	fmt.Printf("Renter gets the message：%s", message)
}

//

type Landlord struct {
	mediator Mediator
}

func (l *Landlord) SetMediator(mediator Mediator) {
	l.mediator = mediator
	l.mediator.SetLandlord(l)
}

func (l *Landlord) SendMessage(message string) {
	l.mediator.Send(l, message)
}

func (l *Landlord) GetMessage(message string) {
	fmt.Printf("Landlord gets the message：%s", message)
}

//

type HouseMediator struct {
	renter   Person
	landlord Person
}

func (hm *HouseMediator) SetRenter(person Person) {
	hm.renter = person
}

func (hm *HouseMediator) SetLandlord(person Person) {
	hm.landlord = person
}

func (hm *HouseMediator) Send(person Person, message string) {
	if person == hm.renter {
		hm.landlord.GetMessage(message)
	} else {
		hm.renter.GetMessage(message)
	}
}

//
func main() {
	mediator := &HouseMediator{}
	renter := &Renter{}
	landlord := &Landlord{}

	renter.SetMediator(mediator)
	landlord.SetMediator(mediator)

	landlord.SendMessage("I have a house for rent.\n")
	renter.SendMessage("How much is it a month.\n")
	landlord.SendMessage("One dollar.\n")
	renter.SendMessage("Done.\n")
}
