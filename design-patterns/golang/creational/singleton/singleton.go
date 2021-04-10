/*!
* \brief. Singleton. Make sure there is only one instance
* of a class and that it instantiates itself and provides
* that instance to the entire system
 */

package main

import (
	"fmt"
	"sync"
	"sync/atomic"
)

type Singleton struct {
	number int32
}

var ins *Singleton
var once sync.Once

func GetInstance() *Singleton {
	// once: Make sure it's only executed once.
	once.Do(func() {
		ins = &Singleton{
			number: 1,
		}
	})
	return ins
}

func (s *Singleton) AddOne() {
	atomic.AddInt32(&s.number, 1)
}

func main() {
	instance1 := GetInstance()
	instance2 := GetInstance()

	if instance1 != instance2 {
		fmt.Printf("instance1 != instance2.\n")
	}
	fmt.Printf("number: %d.\n", instance1.number)

	instance1.AddOne()
	fmt.Printf("number: %d.\n", instance1.number)

	instance2.AddOne()
	fmt.Printf("number: %d.\n", instance1.number)
}
