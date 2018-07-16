* For non-class objects, rules same as in C apply: auto variables without initial values will be left uninitialized; non-auto variables without initial values will be initialized by filling them with zeros.
* For class objects, in the situation that no initializer presented:
  * If this class has a default constructor then use this.
  * If it has some constructors but no default constructor, a compile-time error will occur.
  * If there's no constructor in the class definition, then apply all its data members to these rules recursively.

* Put an empty () just after the type name in a new expression, the dynamically-allocated objects will be value-initialized, i.e. to be initialized just as non-auto variables.

* If we do not define a copy constructor, the compiler synthesizes one for us. The synthesized version just copies all data from initializer to the new object.

* Explicitly invoking the destructor from a non-class type is surely invalid. Like the following:
```C++
int *a = new int;
a->~int(); // compile-time error
```
It's inacceptable of course.
But it's fine if in a template definition you call the destructor of a type as template parameter and afterwards instantiate this template with a non-class type. Like the following:
```C++
template <class T>
struct my_ptr {
    T *ptr;
    my_ptr() {
        ptr = calloc(1, sizeof (T));
        if (ptr == 0) {
            throw whatever_error("...");
        }
        new (ptr) T();
    }
    ~my_ptr() {
        ptr->~T();
        free(ptr);
    }
};

my_ptr<int> mpi;
```


* Illustration of *allocator* implementation:
```C++
template <class T>
struct allocator {
    // ...
    T *allocate(size_type n) {
        void *p = calloc(n, sizeof (T));
        if (p == 0) {
            throw whatever_error("...");
        }
        return static_cast<T *>(p);
    }

    void deallocate(T *p, size_type n) {
        free(p);
    }
    
    void construct(T *p, const T &t) {
        new (p) T(t);
    }

    void destroy(T *p) {
        p->~T();
    }
    
    // ...
};
```

* Illustration of container implementation in standard library:
```C++
#define NELE_INC SOME_VALUE
template <class T>
class vector {
    // ...
    static allocate<T> alloc;
    T *dataptr;
    size_type total, used;
public:
    vector() : dataptr(0), total(0), used(0) {}
    vector(size_type n) : used(n) {
        total = ((n + NELE_INC / 2) / NELE_INC + 1) * NELE_INC;
        dataptr = alloc.allocate(total);
        T *t = new T();
        for (size_type s = 0; s < n; s++) {
            alloc.construct(&dataptr[s], *t);
        }
        delete t;
    }
    vector(size_type n, const T &t) {
        total = ((n + NELE_INC / 2) / NELE_INC + 1) * NELE_INC;
        dataptr = alloc.allocate(total);
        for (size_type s = 0; s < n; s++) {
            alloc.construct(&dataptr[s], t);
        }
    }
}
```
