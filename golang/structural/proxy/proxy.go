/*!
* \brief. Proxy. Provide a surrogate or placeholder for
*         another object to control access to it.
*
*                 Subject
*                 |     |
*       RealSubject <-  Proxy
 */

package main

import "fmt"

type Subject interface {
	Request()
}

////

type RealSubject struct{}

func (r *RealSubject) Request() {
	fmt.Printf("RealSubject Request.\n")
}

////

type Proxy struct {
	subject Subject
}

func (p *Proxy) Request() {
	p.subject.Request()
}

func main() {

	subject := &RealSubject{}
	proxy := &Proxy{subject: subject}

	proxy.Request()
}
