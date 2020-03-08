/*!
* \brief. Factory method.
*
* \pattern. Define an interface for creating an object,
*         but let subclasses decide which class to
*         instantiate.Factory Method lets a class defer
*         instantiation to subclasses
*
*          Animal     < = >   AnimalFactory
*            |
*        AnimalBase            |        |
*         |     |
*       Lion   Tiger    LionFactory   TigerFactory
*
* \note. Inheritance does not exist in Go, so an anonymous combination is used.
 */

package main

import (
	"fmt"
)

// 方法接口
type Animal interface {
	SetAge(int)
	GetInfo()
}

// AnimalFactory, 工厂接口，Create返回的是Animal接口.
type AnimalFactory interface {
	Create() Animal
}

// AnimalBase. Animal接口实现的基类，封装公用方法
type AnimalBase struct {
	age int
}

func (o *AnimalBase) SetAge(age int) {
	o.age = age
}

// LionFactory.
type LionFactory struct{}

func (LionFactory) Create() Animal {
	return &Lion{
		AnimalBase: &AnimalBase{},
	}
}

// Lion. 相当于Animal接口下AnimalBase的派生类
type Lion struct {
	*AnimalBase
}

func (o Lion) GetInfo() {
	fmt.Println("Species: Lion, Age:", o.age)
}

// TigerFactory.
type TigerFactory struct{}

func (TigerFactory) Create() Animal {
	return &Tiger{
		AnimalBase: &AnimalBase{},
	}
}

// Tiger.
type Tiger struct {
	*AnimalBase
}

func (o Tiger) GetInfo() {
	fmt.Println("Species: Tiger, Age:", o.age)
}

//
func main() {
	var factory AnimalFactory

	factory = LionFactory{}
	animal := factory.Create()
	animal.SetAge(5)
	animal.GetInfo()

	factory = TigerFactory{}
	animal = factory.Create()
	animal.GetInfo()
}
