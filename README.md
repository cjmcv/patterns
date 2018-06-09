# design-pattern

A collection of design patterns in C++ and Python.

# 23种设计模式(分三类)

## 一、创建型模式，共5种

* 单例模式：确保某一个类只有一个实例，而且自行实例化并向整个系统提供这个实例。[cpp](https://github.com/cjmcv/design-pattern/blob/master/cpp/creational/singleton.cpp)

* 工厂方法模式：定义一个用于创建对象的接口，让子类决定实例化哪一个类。工厂方法使一个类的实例化延迟到其子类。[cpp_v1](https://github.com/cjmcv/design-pattern/blob/master/cpp/creational/simple_factory.cpp)[cpp_v2](https://github.com/cjmcv/design-pattern/blob/master/cpp/creational/create_by_string.cpp)[cpp_v2](https://github.com/cjmcv/design-pattern/blob/master/cpp/creational/factor_method.cpp)

* 抽象工厂模式：为创建一组相关或相互依赖的对象提供一个接口，而且无须指定它们的具体类。[cpp](https://github.com/cjmcv/design-pattern/blob/master/cpp/creational/abstract_factory.cpp)

* 建造者模式：将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。[cpp](https://github.com/cjmcv/design-pattern/blob/master/cpp/creational/builder.cpp)

* 原型模式：用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。[cpp](https://github.com/cjmcv/design-pattern/blob/master/cpp/creational/prototype.cpp)

## 二、结构型模式，共7种

* 适配器模式：将一个类的接口变换成客户端所期待的另一种接口，从而使原本因接口不匹配而无法在一起工作的两个类能够在一起工作。[cpp](https://github.com/cjmcv/design-pattern/blob/master/cpp/structural/adapter.cpp)

* 装饰器模式：动态地给一个对象添加一些额外的职责。就增加功能来说，装饰模式相比生成子类更为灵活。[cpp](https://github.com/cjmcv/design-pattern/blob/master/cpp/structural/decorator.cpp)

* 代理模式：为其他对象提供一种代理以控制对这个对象的访问。[cpp](https://github.com/cjmcv/design-pattern/blob/master/cpp/structural/proxy.cpp)

* 外观模式：要求一个子系统的外部与其内部的通信必须通过一个统一的对象进行。门面模式提供一个高层次的接口，使得子系统更易于使用。

* 桥接模式：将抽象和实现解耦，使得两者可以独立地变化。

* 组合模式：将对象组合成树形结构以表示“部分-整体”的层次结构，使得用户对单个对象和组合对象的使用具有一致性。[cpp](https://github.com/cjmcv/design-pattern/blob/master/cpp/structural/composite.cpp)

* 享元模式：使用共享对象可有效地支持大量的细粒度的对象。

## 三、行为型模式，共11种

* 策略模式：定义一组算法，将每个算法都封装起来，并且使它们之间可以互换。[cpp](https://github.com/cjmcv/design-pattern/blob/master/cpp/behavioral/strategy.cpp)

* 模板方法模式：定义一个操作中的算法的框架，而将一些步骤延迟到子类中。使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。[cpp](https://github.com/cjmcv/design-pattern/blob/master/cpp/behavioral/template_method.cpp)

* 观察者模式：定义对象间一种一对多的依赖关系，使得每当一个对象改变状态，则所有依赖于它的对象都会得到通知并被自动更新。

* 迭代器模式：它提供一种方法访问一个容器对象中各个元素，而又不需暴露该对象的内部细节。[cpp](https://github.com/cjmcv/design-pattern/blob/master/cpp/behavioral/iterator.cpp)

* 责任链模式：使多个对象都有机会处理请求，从而避免了请求的发送者和接受者之间的耦合关系。将这些对象连成一条链，并沿着这条链传递该请求，直到有对象处理它为止。[cpp](https://github.com/cjmcv/design-pattern/blob/master/cpp/behavioral/chain.cpp)

* 命令模式：将一个请求封装成一个对象，从而让你使用不同的请求把客户端参数化，对请求排队或者记录请求日志，可以提供命令的撤销和恢复功能。[cpp](https://github.com/cjmcv/design-pattern/blob/master/cpp/behavioral/command.cpp)

* 备忘录模式：在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。这样以后就可将该对象恢复到原先保存的状态。

* 状态模式：当一个对象内在状态改变时允许其改变行为，这个对象看起来像改变了其类。

* 访问者模式：封装一些作用于某种数据结构中的各元素的操作，它可以在不改变数据结构的前提下定义作用于这些元素的新的操作。

* 中介者模式：用一个中介对象封装一系列的对象交互，中介者使各对象不需要显示地相互作用，从而使其耦合松散，而且可以独立地改变它们之间的交互。[cpp](https://github.com/cjmcv/design-pattern/blob/master/cpp/behavioral/mediator.cpp)

* 解释器模式：给定一门语言，定义它的文法的一种表示，并定义一个解释器，该解释器使用该表示来解释语言中的句子。

# 6大原则

* 单一职责原则：不要存在多于一个导致类变更的原因。

* 里氏替换原则：子类可以扩展父类的功能，但不能改变父类原有的功能。

* 依赖倒置原则：高层模块不应该依赖低层模块，二者都应该依赖其抽象；抽象不应该依赖细节；细节应该依赖抽象。

* 接口隔离原则：客户端不应该被强迫地依赖那些根本用不上的方法。

* 迪米特法则:一个对象应该对其他对象保持最少的了解。

* 开闭原则：一个软件实体如类、模块和函数应该对扩展开放，对修改关闭。