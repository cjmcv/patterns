/*!
* \brief   Facade. Provide a unified interface to a set of
*       interfaces in a subsystem. Facade defines a higher-level
*       interface that makes the subsystem easier to use.
 */

package main

import "fmt"

type LetterProcessor interface {
	WriteContext(contex string)
	FillEnvelope(address string)
	SendLetter()
}

type Letter struct {
	contex  string
	address string
}

func CreateLetter() *Letter {
	return &Letter{}
}

func (le *Letter) WriteContext(contex string) {
	le.contex = contex
}

func (le *Letter) FillEnvelope(address string) {
	le.address = address
}

func (le *Letter) CheckLetter() {
	fmt.Printf("CheckLetter -> Address: %s. Context: %s.\n", string(le.address), string(le.contex))
}

//////

type Sender interface {
	SendLetter(contex string, address string)
}

type PostOfficer struct {
	letter *Letter
}

func CreatePostOfficer() *PostOfficer {
	return &PostOfficer{
		letter: CreateLetter(),
	}
}

func (po *PostOfficer) SendLetter(contex string, address string) {
	po.letter.WriteContext(contex)
	po.letter.FillEnvelope(address)
	po.letter.CheckLetter()
}

//////

func main() {
	officer := CreatePostOfficer()
	officer.SendLetter("Nice to meet you", "Guangzhou")
	officer.SendLetter("nice to meet you too", "Beijing")
}
