* Templates can also be declared without a definition.

* In a template definition body, when the compiler sees a template type parameter followed by scope operator and then another token, it assumes this token as a static member rather than a type member by default. Prefix the above expression with the keyword 'typename' invert this default behavior.

* A class template is instaniated when we refer to an actual template class type.
* A function template is instantiated when we call it or use it to initialize or assign to a pointer to functions.
