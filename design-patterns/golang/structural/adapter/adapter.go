/*!
* \brief. Adapter. Convert the interface of a class into
*      another interface clients expect.Adapter lets classes
*      work together that couldn't otherwise because of
*      incompatible interfaces.
 */

package main

import "fmt"

// The target interface.
type Target interface {
	Request()
}

// The interface that needs to be adapted.
type IAdaptee interface {
	SpecificRequest()
}

// Adaptee.
type Adaptee struct{}

func (*Adaptee) SpecificRequest() {
	fmt.Printf("Adaptee::SpecificRequest().\n")
}

// Adapter.
type ObjectAdapter struct {
	adaptee IAdaptee
}

func NewObjectAdapter(adaptee IAdaptee) Target {
	return &ObjectAdapter{
		adaptee: adaptee,
	}
}

func (oa *ObjectAdapter) Request() {
	oa.adaptee.SpecificRequest()
}

// Adapter v2.
type ObjectAdapter2 struct {
	IAdaptee
}

func (oa *ObjectAdapter2) Request() {
	oa.IAdaptee.SpecificRequest()
}

func main() {
	// Only function SpecificRequest() can be called,
	// but all you need is function Request().
	adaptee := &Adaptee{}
	adaptee.SpecificRequest()

	// You call Request() now.
	adapter := NewObjectAdapter(adaptee)
	adapter.Request()

	// v2
	adapter2 := &ObjectAdapter{adaptee}
	adapter2.Request()
}
