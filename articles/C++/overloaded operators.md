* Overloaded operators make no guarantees about the order in which operands are evaluated. In paticular, the operand-evaluation guarantees of the built-in logical AND, logical OR, and comma operators are not preserved.

* operator<< and operator>>
```C++
ret_type operator<<(type1 para1, type2 para2);
ret_type operator>>(type1 para1, type2 para2);
```

* operator==
The equality and inequality operators should almost always be defined in terms of each other. One operator should do the real work to compare objects. The other should call the one that does the read work.

* operator=
Assignment should return a reference to *this;

* operator[] _(must be member function)_
Ordinarily, a class that defines subscript needs to define two versions: one that is a nonconst member and returns a reference and one that is a const member and returns a const reference.

* operator-> must be member
* operator*
Given the following expression:
```C++
point->action
```
If 'point' is an object of a class that defines operator->, then 'point->action' is the same as 'point->operator()->action'.
These two usually need both const nonconst versions.

* operator++
* operator--
```C++
ret_type operator++(); // prefix
ret_type operator++(int); // postfix
ret_type operator--(); // prefix
ret_type operator--(int); // postfix

	classobj.operator++(); // prefix
	classobj.operator++(0); // postfix
```

* operator() _(must be member function)_

* conversion operator _(must be member function)_
Example:
```C++
struct ClassA {
	/* other members */
	operator int() const
	{ 
		/* function body */
	}
	/* other members */
};
```
A class-type conversion may be followed by another class-type conversion.



