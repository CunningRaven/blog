* Templates can also be declared without a definition. _P629_

* **In a template definition, when a token, at the right side of a scope operator whose left side is a template type parameter or another class template taking the parameters of this template as its arguments, is seen, the compiler assumes, by default, this token to be a static data or function member, rather than a type member. It will invert this default behavior to put the keyword _'typename'_ before the name of the class template.** _P631_

* A class template is instaniated when we refer to an actual template class type.
* A function template is instantiated when we call it or use it to initialize or assign to a pointer to functions. _P636_

* In general, arguments are not converted to match an existing instantiation; instead, a new instance is generated. There are only two kinds of conversions that the compiler will perform rather than generating a new instantiation:
 * const conversions(just nonconst refrence to const reference conversion)
 * array or function to pointer conversions.
_P639_

* In a function template instantiation with explicit template arguments, trailing parameters may be omitted assuming these can be deduced.
_643_

* Template compilation model:
template compilation model | 
-----------|
inclusion compilation model |
separate compilation model |

From Section 7.5, GCC info pages:
```
When used with GNU ld version 2.8 or later on an ELF system such as GNU/Linux or Solaris 2, or on Microsoft Windows, G++ supports the Borland model. 
```
_P643_

* Inside the scope of the class template itself, we may use the unqualified name of the class template. _P649_

* Member function of a class template are instantiated only for functions that are used by the program. _P653_

* There're 3 kinds of friend declarations that may appear in a class template.
  * an ordinary nontemplate class or function
  * a class or function template; for example:
```C++
template <class Type> class Bar {
	// ...
	template <class T> friend class Foo1;
	template <class T> friend void templ_fcn1(const T&);
	// ...
};
```
  * a specific instance of a class or function template; for example:
```C++
template <class T> class Foo3;
template <class T> void templ_fcn3(const T&);
template <class Type> class Bar {
	// ...
	friend class Foo3<Type>;
	friend void templ_fcn3<Type>(const Type&);
	// ...
};
```
When we grant access to all instances of a given template, there need not be a declaration for that class or function in scope. Essentially, the compiler treats the friend declaration as a declaration of the class or function as well.
When we we want restrict friendship to a specific instantiation, however, then the class or function must have been declared before it can be used in a friend declaration.
_P658_

* Any class(template or otherwise) may have a member that is itself a class or function template. Such members are refered to as member templates. Member templates may not be virtual. _P660_
When a member template is a member of a class template and is defined out of latter's body, then its definition must include the class-template parameters as well as its own parameters, e.g.:
```C++
template <class T> template <class Iter>
void Queue<T>::assign(Iter beg, Iter end)
{
	destroy();
	copy_elems();
}
```
_P662_

* Each instantiation of a class template has its own static members. _P665_

* As with any other static data member, there must be a definition for the static data member that appears outside the class; e.g.:
```C++
template <class T>
size_t Foo<T>::ctr = 0;
```







  * a s
