/*!
* \brief. Decorator. Attach additional responsibilities to an
*      object dynamically keeping the same interface.Decorators
*      provide a flexible alternative to subclassing for extending
*      functionality.
*
*                ----------- Pet ------------
*                |        |       |         |
*               Dog      Cat      |         |
*                               Coloring  Dressing
 */

package main

import "fmt"

// Pet interface.
type Pet interface {
	GetAttribute() string
}

// Pet2.
type Dog struct {
	attribute string
}

func (this Dog) GetAttribute() string {
	this.attribute = "Dog"
	return this.attribute
}

// Pet2.
type Cat struct {
	attribute string
}

func (this Cat) GetAttribute() string {
	this.attribute = "Cat"
	return this.attribute
}

// PetDecorator1.
type Coloring struct {
	pet       Pet
	attribute string
}

func (this Coloring) GetAttribute() string {
	this.attribute = this.pet.GetAttribute() + "-Coloring"
	return this.attribute
}

// PetDecorator2.
type Dressing struct {
	pet       Pet
	attribute string
}

func (this Dressing) GetAttribute() string {
	this.attribute = this.pet.GetAttribute() + "-Dressing"
	return this.attribute
}

func main() {
	pet_level1 := Dog{}
	// Decorate.
	pet_level2 := Coloring{pet: pet_level1}
	pet_level3 := Dressing{pet: pet_level2}

	// Result of decoration.
	fmt.Println(pet_level3.GetAttribute())
	fmt.Println(pet_level2.GetAttribute())
	fmt.Println(pet_level1.GetAttribute())

	// Case 2.
	pet2_level1 := Cat{}
	pet2_level2 := Dressing{pet: pet2_level1}
	fmt.Println(pet2_level2.GetAttribute())
}
