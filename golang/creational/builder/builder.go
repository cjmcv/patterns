/*!
* \brief. Builder. Separate the construction of a complex
*       object from its representation so that the same
*       construction process can create different
*       representations.
 */

package main

import (
	"fmt"
)

type AnimalBuilder interface {
	BuildSpecies()
	BuildColor()
}

type LionBuilder struct{}

func (*LionBuilder) BuildSpecies() {
	fmt.Printf("Build species: Lion.\n")
}

func (*LionBuilder) BuildColor() {
	fmt.Printf("Build color: yellow.\n")
}

type TigerBuilder struct{}

func (*TigerBuilder) BuildSpecies() {
	fmt.Printf("Build species: Tiger.\n")
}

func (*TigerBuilder) BuildColor() {
	fmt.Printf("Build color: orange.\n")
}

////

type Director struct {
	builder AnimalBuilder
}

func (d *Director) Create() {
	d.builder.BuildSpecies()
	d.builder.BuildColor()
}

//
func main() {
	lion := &LionBuilder{}
	tiger := &TigerBuilder{}

	fmt.Printf("Director 1.\n")
	director1 := &Director{builder: lion}
	director1.Create()

	fmt.Printf("Director 2.\n")
	director2 := &Director{builder: tiger}
	director2.Create()
}
