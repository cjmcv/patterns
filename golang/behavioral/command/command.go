/*!
* \brief   Command. Encapsulate a request as an object,thereby
*        letting you parameterize clients with different requests,
*        queue or log requests, and support undoable operations.
*
*        Invoker    =>   ( Command    =>   Receiver )
*                             |
*                        ConcreteCommand
 */

package main

import "fmt"

// Receiver.
type Engineer interface {
	Coding()
	Meeting()
}

type SoftwareEngineer struct{}

func (*SoftwareEngineer) Coding() {
	fmt.Printf("SoftwareEngineer: Writing code in C++.\n")
}

func (*SoftwareEngineer) Meeting() {
	fmt.Printf("SoftwareEngineer: Meeting1.\n")
}

type HardwareEngineer struct{}

func (*HardwareEngineer) Coding() {
	fmt.Printf("HardwareEngineer: Writing code in C.\n")
}

func (*HardwareEngineer) Meeting() {
	fmt.Printf("HardwareEngineer: Meeting2.\n")
}

// Command.
type Command interface {
	ExecuteCommand()
}

type CodingCommand struct {
	engineer Engineer
}

func (c *CodingCommand) ExecuteCommand() {
	c.engineer.Coding()
}

type MeetingCommand struct {
	engineer Engineer
}

func (m *MeetingCommand) ExecuteCommand() {
	m.engineer.Meeting()
}

// Invoker.
type Manager struct {
	command_list []Command
}

func (m *Manager) AddCommand(c Command) {
	m.command_list = append(m.command_list, c)
}

func (m *Manager) Action() {
	for _, o := range m.command_list {
		o.ExecuteCommand()
	}
}

//

func main() {

	manager := &Manager{}
	software_engineer := &SoftwareEngineer{}
	hardware_engineer := &HardwareEngineer{}

	// software_engineer to engineer => pointer to interface.
	command_one := &CodingCommand{engineer: software_engineer}
	command_two := &MeetingCommand{engineer: hardware_engineer}

	manager.AddCommand(command_one)
	manager.AddCommand(command_two)

	manager.Action()
}
