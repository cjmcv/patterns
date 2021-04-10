/*!
* \brief   Visitor. Represent an operation to be performed
*       on the elements of an object structure. Visitor lets
*       you define a new operation without changing the classes
*       of the elements on which it operates.
*
*  	          <Element>                 <Visitor>
*              Engineer       <==>         HR
*                 |                      |    |
*          SoftwareEngineer   IncomeVisitor  VacationVisitor
 */

package main

import "fmt"

// Element interface
type Engineer interface {
	ShowIncome()
	ShowVacation()

	Accept(HR)
}

// Vistor interface
type HR interface {
	Visit(Engineer)
}

// ConcreteElement
type SoftwareEngineer struct {
	name     string
	income   int
	vacation int
}

func CreateSoftwareEngineer(name string, income int, vacation int) Engineer {
	return &SoftwareEngineer{
		name:     name,
		income:   income,
		vacation: vacation,
	}
}

func (se *SoftwareEngineer) Accept(h HR) {
	h.Visit(se)
}

func (se *SoftwareEngineer) ShowIncome() {
	fmt.Printf("%s 's income: %d.\n", se.name, se.income)
}

func (se *SoftwareEngineer) ShowVacation() {
	fmt.Printf("%s 's vacation: %d.\n", se.name, se.vacation)
}

// ConcreteVisitor.
type IncomeVisitor struct{}

func (iv *IncomeVisitor) Visit(e Engineer) {
	e.ShowIncome()
}

type VacationVisitor struct{}

func (iv *VacationVisitor) Visit(e Engineer) {
	e.ShowVacation()
}

func main() {
	engineer_tom := CreateSoftwareEngineer("Tom", 25000, 14)
	engineer_jimmy := CreateSoftwareEngineer("Jimmy", 36000, 6)

	hr1 := &IncomeVisitor{}
	hr2 := &VacationVisitor{}

	engineer_tom.Accept(hr1)
	engineer_tom.Accept(hr2)

	engineer_jimmy.Accept(hr1)
	engineer_jimmy.Accept(hr2)
}
