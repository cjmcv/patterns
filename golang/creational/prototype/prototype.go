/*!
* \brief   Prototype.Specify the kinds of objects to
*        create using a prototypical instance,and
*        create new objects by copying this prototype.
*
*      client     = >      Prototype
*                          |      |
*           ConcretePrototypeA   ConcretePrototypeA
 */

package main

import "fmt"

type Prototype interface {
	PrintInfo()
	Clone() Prototype
}

////

type ConcretePrototypeA struct {
	id int
}

func (c *ConcretePrototypeA) PrintInfo() {
	fmt.Printf("This is ConcretePrototypeA with id: %d.\n", c.id)
}

func (c *ConcretePrototypeA) Clone() Prototype {
	return &ConcretePrototypeA{id: c.id}
}

////

type ConcretePrototypeB struct {
	id int
}

func (c *ConcretePrototypeB) PrintInfo() {
	fmt.Printf("This is ConcretePrototypeB with id: %d.\n", c.id)
}

func (c *ConcretePrototypeB) Clone() Prototype {
	return &ConcretePrototypeB{id: c.id}
}

func main() {

	a := &ConcretePrototypeA{}
	b := &ConcretePrototypeB{}
	b2 := &ConcretePrototypeB{id: 2}

	// You have no idea what the Concrete Prototype you created.
	// But if using copy construction directly, you need to know
	// the Concrete Prototype you want to create.
	ca := a.Clone()
	cb := b.Clone()
	cb2 := b2.Clone()

	ca.PrintInfo()
	cb.PrintInfo()
	cb2.PrintInfo()

	cb3 := cb2.Clone()
	cb3.PrintInfo()
}
