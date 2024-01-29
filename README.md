# Notepad
## Personal Notes.
### 

## Useful codes
### optimize iostream
```
ios_base ::sync_with_stdio(false);
cin.tie(NULL);
// cout.tie(NULL);
```
### clog switch
```
std::clog.setstate(std::ios_base::failbit);
```

## Modularity
### Function
- can do overload. 
```
int sum(int a, int b);
int sum(int a, int b, int c);
```
- Call by Value Vs. Call by Reference
`int a` vs. `int &a`

### Template
- `Any` Can be an any word: T, sometype, and so on.
```
template <class Any>
Any fn(Any a, Any b);
```
- `template <class T, class U>` is possible. (Multiple Parameters)

- Non-type template Arguments
```
template <class T, int n>
T fixed_multiply (T a) {
  return a * n;
}
```
`cout << fixed_multiply<int, 2>(10);`
output : `20`

### Namespace
```
namespace foo  { int value() {return 5;} }
namespace bar  { int value() {return 10;} }
```
`cout << foo::value();` output : `5`
`cout << bar::value();` output : `10`

using namespace is possible. e.g. `using namespace foo;`


### Structure
- Basic
```
struct Vector {
  int sz; 
  double *elem;
} // two members
```
Define a structure variable;
```
Name v;
```
Accessing a member of __.
```
v.sz = s;
```

- Pointers to structures
  - use `->` to access a member of a structure variable.
```
Vector v;
Vector *pV = &V;
int s = 10; // or cin
pV->elem = new double [s];
```

### Classes
- Basic
```
class class_name {
  access_specifier_1;
    member1;
  access_specifier_2;
    member2;
} object_names;
```

```
class Rectangle {
    int width, height;
  public:
    void set_values (int, int);
    int area (void);
}
```

- List of Access specifiers
  - private : accessible only within same class.
  - protected : accessible only within same and derived class.
  - public : free to access.
  - Default = private.

- how to make Objects:
`void Rectangle::set_values (int x, int y) { //body }`

- Constructors
  - Automatically called whenever a new object of this class is created.
  - overloading possible. 
  ```
  class_name();              // default constructor
  class_name(parameters);    // constructor with parameters
  ```

- Destructors
  - Automatically called when an object is destructed.
  - Execute required cleanup
```
~class_name();
```

- Pointers to classes
  - Use `->` to access a class member
```
Rectangle* rect = new Rectangle(3, 4);
cout << rect->area(); 
```

-Can apply template to Class